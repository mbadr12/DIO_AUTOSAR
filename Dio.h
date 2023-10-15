/*
 * Dio.h
 *
 *  Created on: Oct 14, 2023
 *      Author: eme
 */

#ifndef DIO_H_
#define DIO_H_

#define DIO_PIN_NUM         64U

#define DIO_PORT_NUM        6U

#define DIO_PORT_RW       255U

#define STD_HIGH            1U

#define STD_LOW             0U

#define DIO_PORT_PIN_NUM    8U

typedef uint8_t Dio_ChannelType;

typedef uint8_t Dio_PortType;

typedef uint8_t Dio_LevelType;

typedef uint8_t Dio_PortLevelType;

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType Level);

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);

void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level);

#endif /* DIO_H_ */
