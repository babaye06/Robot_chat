/*
 * lidar.c
 *
 *  Created on: 19 oct. 2023
 *      Author: Bastien T
 */

#include "lidar.h"

int lidar_start_scanning(lidar_t * lidar)
{
	lidar->serial_drv.transmit(CMD_START);
	//HAL_UART_Transmit(&huart1, CMD_START, 1, HAL_MAX_DELAY);
	return 0;
}

int lidar_stop_scanning(lidar_t * lidar)
{
	lidar->serial_drv.transmit(CMD_STOP);
	return 0;
}
int lidar_get_infos(lidar_t * lidar)
{
	lidar->serial_drv.transmit(CMD_GET_INFO);
	//Il faut ensuite mettre les infos dans la struct : lidar ->model = info recup etc..
	return 0;
}

int lidar_get_status(lidar_t * lidar)
{
	lidar->serial_drv.transmit(CMD_GET_STATUS);
	return 0;
}
int lidar_restart(lidar_t * lidar)
{
	lidar->serial_drv.transmit(CMD_RESTART);
	return 0;
}
