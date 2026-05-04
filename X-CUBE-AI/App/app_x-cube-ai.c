
/**
  ******************************************************************************
  * @file    app_x-cube-ai.c
  * @author  X-CUBE-AI C code generator
  * @brief   AI program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

 /*
  * Description
  *   v1.0 - Minimum template to show how to use the Embedded Client API
  *          model. Only one input and one output is supported. All
  *          memory resources are allocated statically (AI_NETWORK_XX, defines
  *          are used).
  *          Re-target of the printf function is out-of-scope.
  *   v2.0 - add multiple IO and/or multiple heap support
  *
  *   For more information, see the embeded documentation:
  *
  *       [1] %X_CUBE_AI_DIR%/Documentation/index.html
  *
  *   X_CUBE_AI_DIR indicates the location where the X-CUBE-AI pack is installed
  *   typical : C:\Users\<user_name>\STM32Cube\Repository\STMicroelectronics\X-CUBE-AI\7.1.0
  */

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#if defined ( __ICCARM__ )
#elif defined ( __CC_ARM ) || ( __GNUC__ )
#endif

/* System headers */
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>

#include "app_x-cube-ai.h"
#include "main.h"
#include "ai_datatypes_defines.h"
#include "network.h"
#include "network_data.h"

/* USER CODE BEGIN includes */
extern UART_HandleTypeDef huart2;
/* USER CODE END includes */

/* IO buffers ----------------------------------------------------------------*/

#if !defined(AI_NETWORK_INPUTS_IN_ACTIVATIONS)
AI_ALIGNED(4) ai_i8 data_in_1[AI_NETWORK_IN_1_SIZE_BYTES];
ai_i8* data_ins[AI_NETWORK_IN_NUM] = {
data_in_1
};
#else
ai_i8* data_ins[AI_NETWORK_IN_NUM] = {
NULL
};
#endif

#if !defined(AI_NETWORK_OUTPUTS_IN_ACTIVATIONS)
AI_ALIGNED(4) ai_i8 data_out_1[AI_NETWORK_OUT_1_SIZE_BYTES];
ai_i8* data_outs[AI_NETWORK_OUT_NUM] = {
data_out_1
};
#else
ai_i8* data_outs[AI_NETWORK_OUT_NUM] = {
NULL
};
#endif

/* Activations buffers -------------------------------------------------------*/

AI_ALIGNED(32)
static uint8_t pool0[AI_NETWORK_DATA_ACTIVATION_1_SIZE];

ai_handle data_activations0[] = {pool0};

/* AI objects ----------------------------------------------------------------*/

static ai_handle network = AI_HANDLE_NULL;

static ai_buffer* ai_input;
static ai_buffer* ai_output;

static void ai_log_err(const ai_error err, const char *fct)
{
  /* USER CODE BEGIN log */
  if (fct)
    printf("TEMPLATE - Error (%s) - type=0x%02x code=0x%02x\r\n", fct,
        err.type, err.code);
  else
    printf("TEMPLATE - Error - type=0x%02x code=0x%02x\r\n", err.type, err.code);

  do {} while (1);
  /* USER CODE END log */
}

static int ai_boostrap(ai_handle *act_addr)
{
  ai_error err;

  /* Create and initialize an instance of the model */
  err = ai_network_create_and_init(&network, act_addr, NULL);
  if (err.type != AI_ERROR_NONE) {
    ai_log_err(err, "ai_network_create_and_init");
    return -1;
  }

  ai_input = ai_network_inputs_get(network, NULL);
  ai_output = ai_network_outputs_get(network, NULL);

#if defined(AI_NETWORK_INPUTS_IN_ACTIVATIONS)
  /*  In the case where "--allocate-inputs" option is used, memory buffer can be
   *  used from the activations buffer. This is not mandatory.
   */
  for (int idx=0; idx < AI_NETWORK_IN_NUM; idx++) {
	data_ins[idx] = ai_input[idx].data;
  }
#else
  for (int idx=0; idx < AI_NETWORK_IN_NUM; idx++) {
	  ai_input[idx].data = data_ins[idx];
  }
#endif

#if defined(AI_NETWORK_OUTPUTS_IN_ACTIVATIONS)
  /*  In the case where "--allocate-outputs" option is used, memory buffer can be
   *  used from the activations buffer. This is no mandatory.
   */
  for (int idx=0; idx < AI_NETWORK_OUT_NUM; idx++) {
	data_outs[idx] = ai_output[idx].data;
  }
#else
  for (int idx=0; idx < AI_NETWORK_OUT_NUM; idx++) {
	ai_output[idx].data = data_outs[idx];
  }
#endif

  return 0;
}

static int ai_run(void)
{
  ai_i32 batch;

  batch = ai_network_run(network, ai_input, ai_output);
  if (batch != 1) {
    ai_log_err(ai_network_get_error(network),
        "ai_network_run");
    return -1;
  }

  return 0;
}

/* USER CODE BEGIN 2 */
//#define OUTPUT_SCALE  0.00398333f
//#define OUTPUT_ZERO   -128
extern UART_HandleTypeDef huart2;

int acquire_and_process_data(ai_i8* data[])
{
  return 0;
}

int post_process(ai_i8* data[])
{
  return 0;
}

//void ai_fill_input(float* src, int size)
//{
//    float* dst = (float*)ai_input[0].data;
//
//    for(int i = 0; i < size; i++)
//    {
//        dst[i] = src[i];
//    }
//}

//void ai_fill_input(int8_t* src, int size)
//{
//    int8_t* dst = (int8_t*)ai_input[0].data;  // ✅ int8 destination
//    int8_t* s   = (int8_t*)src;               // ✅ int8 source
//
//    for(int i = 0; i < size; i++)
//        dst[i] = s[i];
//}

//int ai_run_inference(void)
//{
////	 MX_X_CUBE_AI_Process();
//	return ai_run();
//}


//float ai_get_output(void)
//{
//    int8_t raw = ((int8_t*)ai_output[0].data)[0];
//
//    // dequantization
//    float out = (raw - OUTPUT_ZERO) * OUTPUT_SCALE;
//
//    return out;
//}

#define OUTPUT_SCALE  0.01276274f
#define OUTPUT_ZERO   39

#define SOC_MEAN      69.42773f
#define SOC_STD       26.26312f    // replace with actual value from Colab
void ai_fill_input(int8_t* src, int size)
{
    int i;
    int8_t* dst = (int8_t*)data_ins[0];
    for(i = 0; i < size; i++)
        dst[i] = src[i];

    ai_input[0].data  = data_ins[0];
    ai_output[0].data = data_outs[0];
}

int ai_run_inference(void)
{
    ai_input[0].data  = data_ins[0];
    ai_output[0].data = data_outs[0];
    return ai_run();
}

float ai_get_output(void)
{
    char msg[50];
    int8_t raw;
    float out;
    float real_soc;
    int soc_int;
    int soc_dec;

    raw = ((int8_t*)data_outs[0])[0];

    sprintf(msg, "RAW = %d\r\n", raw);
    HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), 100);

    out = (raw - OUTPUT_ZERO) * OUTPUT_SCALE;
    real_soc = (out * SOC_STD) + SOC_MEAN;

    soc_int = (int)real_soc;
    soc_dec = (int)((real_soc - soc_int) * 100);

    sprintf(msg, "SOC = %d.%02d%%\r\n", soc_int, soc_dec);
    HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), 100);

    return real_soc;
}
//float ai_get_output(void)
//{
//    char msg[50];
//    int8_t raw;
//    float out;
//    float real_soc;
//    int soc_int;
//    int soc_dec;
//
//    raw = ((int8_t*)ai_output[0].data)[0];
//    sprintf(msg, "OUTBUF ADDR = %08lX\r\n", (unsigned long)ai_output[0].data);
//    HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), 100);
//    sprintf(msg, "RAW = %d\r\n", raw);
//    HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), 100);
//
//    out = (raw - OUTPUT_ZERO) * OUTPUT_SCALE;       // dequantize
//    real_soc = (out * SOC_STD) + SOC_MEAN;          // reverse StandardScaler
//
//    soc_int = (int)real_soc;
//    soc_dec = (int)((real_soc - soc_int) * 100);
//
//    sprintf(msg, "SOC = %d.%02d%%\r\n", soc_int, soc_dec);
//    HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), 100);
//
//    return real_soc;
//}
/* USER CODE END 2 */

/* Entry points --------------------------------------------------------------*/

void MX_X_CUBE_AI_Init(void)
{
    /* USER CODE BEGIN 5 */
  printf("\r\nTEMPLATE - initialization\r\n");

  ai_boostrap(data_activations0);
    /* USER CODE END 5 */
}

void MX_X_CUBE_AI_Process(void)
{
    /* USER CODE BEGIN 6 */
  int res = -1;

  printf("TEMPLATE - run - main loop\r\n");

  if (network) {

    do {
      /* 1 - acquire and pre-process input data */
      res = acquire_and_process_data(data_ins);
      /* 2 - process the data - call inference engine */
      if (res == 0)
        res = ai_run();
      /* 3- post-process the predictions */
      if (res == 0)
        res = post_process(data_outs);
    } while (res==0);
  }

  if (res) {
    ai_error err = {AI_ERROR_INVALID_STATE, AI_ERROR_CODE_NETWORK};
    ai_log_err(err, "Process has FAILED");
  }

    /* USER CODE END 6 */
}
#ifdef __cplusplus
}
#endif
