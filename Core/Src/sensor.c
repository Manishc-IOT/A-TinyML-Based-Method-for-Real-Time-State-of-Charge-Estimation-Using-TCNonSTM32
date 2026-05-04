/*
 * Sensors.c (FINAL INT8 VERSION)
 */
#include "main.h"
#include "ai_platform.h"
#include "network.h"
#include "app_x-cube-ai.h"

extern ai_handle network;
//extern ai_i8 data_in_1[];  // direct access to X-CUBE-AI input buffer
//static float soc_prev = -1;
// =============================
// 🔥 MODEL QUANTIZATION PARAMS
// =============================


#define OUTPUT_SCALE  0.00398333f
#define OUTPUT_ZERO  -128

#include "main.h"
#include "math.h"
#include "ai_platform.h"
#include "app_x-cube-ai.h"

extern ADC_HandleTypeDef hadc1;
#include "sensor.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

extern UART_HandleTypeDef huart2;

extern float soc;
float voltage     = 0.0f;
float current     = 0.0f;
float temperature = 0.0f;
// Add this at top of sensor.c
float vdda ;
//#define VREFINT_CAL_ADDR  ((uint16_t*)0x1FFF75AA)  // STM32L4 factory calibration address
//#define VREFINT_CAL_VREF  3000  // mV (factory calibration done at 3.0V)

//float get_vdda(void)
//{
//    // Read internal reference voltage
//    ADC_ChannelConfTypeDef sConfig = {0};
//    sConfig.Channel      = ADC_CHANNEL_VREFINT;
//    sConfig.Rank         = ADC_REGULAR_RANK_1;
//    sConfig.SamplingTime = ADC_SAMPLETIME_247CYCLES_5;
//    sConfig.SingleDiff   = ADC_SINGLE_ENDED;
//    sConfig.OffsetNumber = ADC_OFFSET_NONE;
//    sConfig.Offset       = 0;
//    HAL_ADC_ConfigChannel(&hadc1, &sConfig);
//
//    HAL_ADC_Start(&hadc1);
//    HAL_ADC_PollForConversion(&hadc1, 100);
//    uint32_t vrefint_raw = HAL_ADC_GetValue(&hadc1);
//    HAL_ADC_Stop(&hadc1);
//
//    // Calculate actual VDDA
//     vdda = (VREFINT_CAL_VREF * (*VREFINT_CAL_ADDR)) / (float)vrefint_raw / 1000.0f;
//    return vdda;
//}


float get_vdda(void)
{
    ADC_ChannelConfTypeDef sConfig = {0};

    sConfig.Channel      = ADC_CHANNEL_VREFINT;
    sConfig.Rank         = ADC_REGULAR_RANK_1;
    sConfig.SamplingTime = ADC_SAMPLETIME_247CYCLES_5;
    sConfig.SingleDiff   = ADC_SINGLE_ENDED;
    sConfig.OffsetNumber = ADC_OFFSET_NONE;
    sConfig.Offset       = 0;

    HAL_ADC_ConfigChannel(&hadc1, &sConfig);

    HAL_Delay(2);   // ✅ VERY IMPORTANT (stabilization)

    // 🔹 Dummy conversion (discard)
    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, 100);
    HAL_ADC_GetValue(&hadc1);
    HAL_ADC_Stop(&hadc1);

    // 🔹 Actual conversion
    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, 100);
    uint32_t vrefint_raw = HAL_ADC_GetValue(&hadc1);
    HAL_ADC_Stop(&hadc1);

    vdda = (VREFINT_CAL_VREF * (*VREFINT_CAL_ADDR)) / (float)vrefint_raw / 1000.0f;

    return vdda;
}


// At top of sensor.c - replace old externs with these:
//extern void ai_fill_input(float* src, int size);
extern int  ai_run_inference(void);

extern float ai_get_output(void);
//extern ai_i8 data_in_1[];
//extern ai_i8 data_out_1[];


//extern ai_buffer* get_ai_input(void);
//extern ai_buffer* get_ai_output(void);

#define WINDOW_SIZE 10
#define FEATURES 3
float v_i=0.0f;
float i_i=0.0f;
float t_i=0.0f;
float sensor_buffer[WINDOW_SIZE][FEATURES];
int8_t ai_input_buffer[WINDOW_SIZE*FEATURES];

#define V_MEAN 3.3611f
#define V_STD  0.3597f

#define I_MEAN 3.2929f
#define I_STD  0.1529f

#define T_MEAN 24.1391f
#define T_STD  1.5913f


#define INPUT_SCALE   0.05231499f
#define INPUT_ZERO    62


/* ACS712 constants */
#define ACS_OFFSET 2.33f
#define ACS_SENSITIVITY 0.1f

/* NTC constants */
float r_load = 7400.0f;
float r_ntc = 0.0f;
float v_supply = 3.6f;
float b_param = 3900.0f;
float t0 = 298.15f;
float tempk = 0.0f;
float v_actual = 0.0f;

float v_v =0.0f;
float adc_v = 0.0f;
float v_c =0.0f;
float adc_i = 0.0f;
float v_t =0.0f;
float adc_t = 0.0f;

//extern float ai_get_output(void);
//static int buffer_filled = 0;
//uint32_t Read_ADC_Channel(uint32_t channel)
//{
//    ADC_ChannelConfTypeDef sConfig = {0};
//
//    sConfig.Channel = channel;
//    sConfig.Rank = ADC_REGULAR_RANK_1;
//    sConfig.SamplingTime = ADC_SAMPLETIME_247CYCLES_5;  // Long sampling
//
//    HAL_ADC_ConfigChannel(&hadc1, &sConfig);
//
//    HAL_ADC_Start(&hadc1);
//    HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
//    uint32_t value = HAL_ADC_GetValue(&hadc1);
//    HAL_ADC_Stop(&hadc1);
//
//    return value;
//}

/* ---------------- VOLTAGE ---------------- */

/* ---------------- VOLTAGE (A1 = PA1 = ADC_CHANNEL_6) ---------------- */
/* ---------------- VOLTAGE (A1 = PA1 = ADC_CHANNEL_6) ---------------- */
float read_voltage()
{
    HAL_ADC_Stop(&hadc1);
    float vdda = get_vdda();  // get actual supply voltage

    ADC_ChannelConfTypeDef sConfig = {0};
    sConfig.Channel      = ADC_CHANNEL_10;
    sConfig.Rank         = ADC_REGULAR_RANK_1;
    sConfig.SamplingTime = ADC_SAMPLETIME_247CYCLES_5;
    sConfig.SingleDiff   = ADC_SINGLE_ENDED;
    sConfig.OffsetNumber = ADC_OFFSET_NONE;
    sConfig.Offset       = 0;
    HAL_ADC_ConfigChannel(&hadc1, &sConfig);

    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, 100);
    HAL_ADC_GetValue(&hadc1);   // ❗ discard first sample

    HAL_ADC_Stop(&hadc1);

//     actual read
    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, 100);
    adc_v = HAL_ADC_GetValue(&hadc1);
    HAL_ADC_Stop(&hadc1);

    v_v     = (adc_v * vdda) / 4095.0f;  // uses real VDDA ✅
//    v_v = (adc_v*3.3)/4095.0f;
    voltage = v_v * 2.0f;                 // voltage divider x2


    return voltage;
}
/* ---------------- CURRENT (A2 = PA3 = ADC_CHANNEL_8) ---------------- */
float read_current()
{
    ADC_ChannelConfTypeDef sConfig = {0};
    sConfig.Channel      = ADC_CHANNEL_7;
    sConfig.Rank         = ADC_REGULAR_RANK_1;
    sConfig.SamplingTime = ADC_SAMPLETIME_247CYCLES_5;
    HAL_ADC_ConfigChannel(&hadc1, &sConfig);

    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
    adc_i = HAL_ADC_GetValue(&hadc1);
    HAL_ADC_Stop(&hadc1);

    v_c     = (float)(adc_i * 3.3 *2) / 4095.0f;
//    v_actual = v_c *2; //voltage divider/
     current = (v_c - 2.5) / ACS_SENSITIVITY;

//     float vv_i =(current - 3.2930f) / 0.1501f;;
//    if (norm < 0.0f) norm = 0.0f;
//    if (norm > 1.0f) norm = 1.0f;
    return current;
}

/* ---------------- TEMPERATURE (A3 = PA4 = ADC_CHANNEL_9) ---------------- */
float read_temperature()
{
	float vdda = get_vdda();
    ADC_ChannelConfTypeDef sConfig = {0};
    sConfig.Channel      = ADC_CHANNEL_9;
    sConfig.Rank         = ADC_REGULAR_RANK_1;
    sConfig.SamplingTime = ADC_SAMPLETIME_247CYCLES_5;
    HAL_ADC_ConfigChannel(&hadc1, &sConfig);

    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
    adc_t = HAL_ADC_GetValue(&hadc1);
    HAL_ADC_Stop(&hadc1);

    v_t   = (adc_t * vdda) / 4095.0f;
    r_ntc = (v_t * r_load) / (v_supply - v_t);
//    tempk = (t0 * b_param) / (t0 * log(r_ntc / r_load) + b_param);
    tempk = (t0 * b_param) / (b_param - t0 * logf(r_ntc / 10000.0f));
    float tempc = tempk - 273.15f;
    temperature = tempc*1.12 ;

//    float vv_t = (temperature - 24.1390f) / 1.5910f;
//    if (norm < 0.0f) norm = 0.0f;
//    if (norm > 1.0f) norm = 1.0f;
    return temperature;
}
// =============================
// 🔹 BUFFER UPDATE
// =============================
//void update_sensor_buffer()
//{
//    for(int i=0;i<WINDOW_SIZE-1;i++)
//    {
//        for(int j=0;j<3;j++)
//            sensor_buffer[i][j] = sensor_buffer[i+1][j];
//    }
//
//    sensor_buffer[WINDOW_SIZE-1][0] = read_voltage();
//    sensor_buffer[WINDOW_SIZE-1][1] = read_current();
//    sensor_buffer[WINDOW_SIZE-1][2] = read_temperature();
//}
void update_sensor_buffer()
{
    char msg[80];
    int v_int, v_dec, i_int, i_dec, t_int, t_dec;

    for(int i = 0; i < WINDOW_SIZE-1; i++)
        for(int j = 0; j < 3; j++)
            sensor_buffer[i][j] = sensor_buffer[i+1][j];

    sensor_buffer[WINDOW_SIZE-1][0] = read_voltage();
    sensor_buffer[WINDOW_SIZE-1][1] = read_current();
    sensor_buffer[WINDOW_SIZE-1][2] = read_temperature();

    // 🔍 DEBUG — print latest sensor values
    v_int = (int)sensor_buffer[WINDOW_SIZE-1][0];
    v_dec = (int)((sensor_buffer[WINDOW_SIZE-1][0] - v_int) * 100);
    i_int = (int)sensor_buffer[WINDOW_SIZE-1][1];
    i_dec = (int)((sensor_buffer[WINDOW_SIZE-1][1] - i_int) * 100);
    t_int = (int)sensor_buffer[WINDOW_SIZE-1][2];
    t_dec = (int)((sensor_buffer[WINDOW_SIZE-1][2] - t_int) * 100);

    sprintf(msg, "V=%d.%02d I=%d.%02d T=%d.%02d\r\n",
            v_int, v_dec, i_int, i_dec, t_int, t_dec);
    HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), 100);
}

// =============================
// 🔥 PREPARE INPUT (INT8)
// =============================
void prepare_ai_input()
{
    int8_t *input = ai_input_buffer;
    int i;
    char msg[80];

    for(i = 0; i < WINDOW_SIZE; i++)
    {
        float v_norm = (sensor_buffer[i][0] - V_MEAN) / V_STD;
        float i_norm = (sensor_buffer[i][1] - I_MEAN) / I_STD;
        float t_norm = (sensor_buffer[i][2] - T_MEAN) / T_STD;

        input[i*3 + 0] = (int8_t)fmaxf(-128, fminf(127, roundf(v_norm / INPUT_SCALE) + INPUT_ZERO));
        input[i*3 + 1] = (int8_t)fmaxf(-128, fminf(127, roundf(i_norm / INPUT_SCALE) + INPUT_ZERO));
        input[i*3 + 2] = (int8_t)fmaxf(-128, fminf(127, roundf(t_norm / INPUT_SCALE) + INPUT_ZERO));

        sprintf(msg, "IN0: %d %d %d\r\n", input[0], input[1], input[2]);
        HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), 100);
    }

    sprintf(msg, "WRITTEN: %d %d %d\r\n", input[0], input[3], input[6]);
    HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), 100);

    ai_fill_input(ai_input_buffer, WINDOW_SIZE * FEATURES);
}
//void prepare_ai_input()
//{
//    char msg[80];
//    int8_t *input = (int8_t*)ai_input_buffer;
//
//    for(int i = 0; i < WINDOW_SIZE; i++)
//    {
//        float v_norm = (sensor_buffer[i][0] - V_MEAN) / V_STD;
//        float i_norm = (sensor_buffer[i][1] - I_MEAN) / I_STD;
//        float t_norm = (sensor_buffer[i][2] - T_MEAN) / T_STD;
//
//        input[i*3 + 0] = (int8_t)fmaxf(-128, fminf(127, roundf(v_norm / INPUT_SCALE) + INPUT_ZERO));
//        input[i*3 + 1] = (int8_t)fmaxf(-128, fminf(127, roundf(i_norm / INPUT_SCALE) + INPUT_ZERO));
//        input[i*3 + 2] = (int8_t)fmaxf(-128, fminf(127, roundf(t_norm / INPUT_SCALE) + INPUT_ZERO));
//
//        // 🔍 print only first row
//        if(i == 0)
//        {
//            sprintf(msg, "norm: v=%d i=%d t=%d | q: v=%d i=%d t=%d\r\n",
//                (int)(v_norm*100), (int)(i_norm*100), (int)(t_norm*100),
//                input[0], input[1], input[2]);
//            HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), 100);
//        }
//    }
//
//    ai_fill_input((float*)ai_input_buffer, WINDOW_SIZE * FEATURES);
//}
// =============================
// 🔥 RUN MODEL
// =============================
float run_ai_model()
{
    float soc;

    update_sensor_buffer();
    prepare_ai_input();
    ai_run_inference();

    soc = ai_get_output();  // already returns real SOC %

    if(soc > 100.0f) soc = 100.0f;
    if(soc <   0.0f) soc =   0.0f;

    return soc;
}
