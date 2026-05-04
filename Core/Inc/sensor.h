/*
 * sensor.h
 *
 *  Created on: Mar 31, 2026
 *      Author: Manish C
 */

#ifndef INC_SENSOR_H_
#define INC_SENSOR_H_

float run_ai_model(void);
void update_sensor_buffer(void);
void ai_fill_input(int8_t* src, int size);  // ✅ match the definition
ai_i8* get_ai_input_buffer(void);
float ai_get_output(void);

//void  log_data_uart(void);
#endif /* INC_SENSOR_H_ */

//#endif /* INC_SENSOR_H_ */
