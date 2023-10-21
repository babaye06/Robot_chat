/*
 * lidar.h
 *
 *  Created on: 19 oct. 2023
 *      Author: Bastien T
 */
#ifndef LIDAR_H_
#define LIDAR_H_

#include <stdint.h>

typedef enum lidar_command_enum
{
	CMD_START      = 0xA560,
	CMD_STOP       = 0xA565,
	CMD_GET_INFO   = 0xA590,
	CMD_GET_STATUS = 0xA591,
	CMD_RESTART    = 0xA580,

} Lidar_command_t;

typedef int (* lidar_transmit_t)(uint16_t cmd);
typedef int (* lidar_receive_t)(uint8_t *p_data, uint16_t size);

typedef struct lidar_serial_struct
{
	lidar_transmit_t transmit;
	lidar_receive_t receive;
} lidar_serial_t;

typedef struct lidar_struct
{

	// driver uart
	lidar_serial_t serial_drv;

    // angle, distance
	float angle;
	float distance;

} lidar_t;

int lidar_start_scanning(lidar_t * lidar);
int lidar_stop_scanning(lidar_t * lidar);
int lidar_get_infos(lidar_t * lidar);
int lidar_get_status(lidar_t * lidar);
int lidar_restart(lidar_t * lidar);

#endif /* LIDAR_H_ */
