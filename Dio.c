/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *       Author:  Mahmoud Badr
 *         File:  GPIO_Program.c
 *        Layer:  MCAL
 *       Module:  GPIO
 *      Version:  1.00
 *
 *  Description:  Implementation of GPIO Driver
 *
 *********************************************************************************************************************/

#include <stdint.h>
#include "TM4C123xx.h"
#include "Dio.h"

static GPIO_RegDef_t* GPIO_Arr[DIO_PIN_NUM]={GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOF};

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    Dio_PortType Local_Port=ChannelId/DIO_PORT_PIN_NUM;
    Dio_ChannelType Local_Pin=ChannelId%DIO_PORT_PIN_NUM;
    uint8_t Local_RegNum=1<<Local_Pin;
    Dio_LevelType Local_ReadVal;
    if(ChannelId<DIO_PIN_NUM)
    {
        Local_ReadVal=(Dio_LevelType)((GPIO_Arr[Local_Port]->DATA[Local_RegNum])>>Local_Pin);
    }
    else
    {
        /*Send DIO_E_PARAM_INVALID_CHANNEL_ID to DET*/
    }
    return Local_ReadVal;
}

void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType Level)
{
    Dio_PortType Local_Port=ChannelId/DIO_PORT_PIN_NUM;
    Dio_ChannelType Local_Pin=ChannelId%DIO_PORT_PIN_NUM;
    uint8_t Local_RegNum=1<<Local_Pin;
    if(ChannelId<DIO_PIN_NUM)
    {
        /*if the pin not input Write it*/
        if(((GPIO_Arr[Local_Port]->DIR)&Local_Pin)!=STD_LOW)
        {
            GPIO_Arr[Local_Port]->DATA[Local_RegNum]=(uint32_t)(Level<<Local_Pin);
        }
        else
        {

        }
    }
    else
    {
        /*Send DIO_E_PARAM_INVALID_CHANNEL_ID to DET*/
    }
}

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
    Dio_PortLevelType Local_Level;
    if(PortId<DIO_PORT_NUM)
    {
        Local_Level=(Dio_PortLevelType)(GPIO_Arr[PortId]->DATA[DIO_PORT_RW]);
    }
    else
    {
        /*Report DIO_E_PARAM_INVALID_PORT_ID to DET*/
    }
    return Local_Level;
}

void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level)
{
    /*Get the Index of the output data using the pins with output direction*/
    uint32_t Local_OutputSets=(uint32_t)(((uint8_t)(GPIO_Arr[PortId]->DIR))<<2U);
    if(PortId<DIO_PORT_NUM)
    {
        GPIO_Arr[PortId]->DATA[DIO_PORT_RW]=(uint32_t)Level;
    }
    else
    {
        /*Report DIO_E_PARAM_INVALID_PORT_ID to DET*/
    }
}
