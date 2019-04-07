/**
************************************************************
* @file         gizwits_product.c
* @brief        Gizwits control protocol processing, and platform-related hardware initialization 
* @author       Gizwits
* @date         2017-07-19
* @version      V03030000
* @copyright    Gizwits
*
* @note         Gizwits is only for smart hardware
*               Gizwits Smart Cloud for Smart Products
*               Links | Value Added | Open | Neutral | Safety | Own | Free | Ecology
*               www.gizwits.com
*
***********************************************************/
#include <stdio.h>
#include <string.h>
#include "gizwits_product.h"
#include "usart.h"
#include "SysTick.h"


extern uint8_t wifi_sta;
uint32_t timerMsCount;

/** Current datapoint */
dataPoint_t currentDataPoint;

/**@} */
/**@name Gizwits User Interface
* @{
*/

/**
* @brief Event handling interface

* Description:

* 1. Users can customize the changes in WiFi module status

* 2. Users can add data points in the function of event processing logic, such as calling the relevant hardware peripherals operating interface

* @param [in] info: event queue
* @param [in] data: protocol data
* @param [in] len: protocol data length
* @return NULL
* @ref gizwits_protocol.h
*/
int8_t gizwitsEventProcess(eventInfo_t *info, uint8_t *gizdata, uint32_t len)
{
  uint8_t i = 0;
  dataPoint_t *dataPointPtr = (dataPoint_t *)gizdata;
  moduleStatusInfo_t *wifiData = (moduleStatusInfo_t *)gizdata;
  protocolTime_t *ptime = (protocolTime_t *)gizdata;
  
#if MODULE_TYPE
  gprsInfo_t *gprsInfoData = (gprsInfo_t *)gizdata;
#else
  moduleInfo_t *ptModuleInfo = (moduleInfo_t *)gizdata;
#endif

  if((NULL == info) || (NULL == gizdata))
  {
    return -1;
  }

  for(i=0; i<info->num; i++)
  {
    switch(info->event[i])
    {

      case EVENT_START:
        currentDataPoint.valueSTART = dataPointPtr->valueSTART;
        GIZWITS_LOG("Evt: EVENT_START %d\n", currentDataPoint.valueSTART);
        switch(currentDataPoint.valueSTART)
        {
          case START_VALUE0:
            //user handle
            break;
          case START_VALUE1:
            //user handle
            break;
          case START_VALUE2:
            //user handle
            break;
          case START_VALUE3:
            //user handle
            break;
          case START_VALUE4:
            //user handle
            break;
          case START_VALUE5:
            //user handle
            break;
          case START_VALUE6:
            //user handle
            break;
          case START_VALUE7:
						 GPIO_ResetBits(GPIOC,GPIO_Pin_4);
            //user handle
            break;
          case START_VALUE8:
            //user handle
            break;
          case START_VALUE9:
            //user handle
            break;
          case START_VALUE10:
            //user handle
            break;
          case START_VALUE11:
            //user handle
            break;
          case START_VALUE12:
            //user handle
            break;
          case START_VALUE13:
            //user handle
            break;
          case START_VALUE14:
            //user handle
            break;
          case START_VALUE15:
            //user handle
            break;
          case START_VALUE16:
            //user handle
            break;
          case START_VALUE17:
            //user handle
            break;
          case START_VALUE18:
            //user handle
            break;
          case START_VALUE19:
            //user handle
            break;
          default:
            break;
        }
        break;
      case EVENT_END:
        currentDataPoint.valueEND = dataPointPtr->valueEND;
        GIZWITS_LOG("Evt: EVENT_END %d\n", currentDataPoint.valueEND);
        switch(currentDataPoint.valueEND)
        {
          case END_VALUE0:
            //user handle
            break;
          case END_VALUE1:
            //user handle
            break;
          case END_VALUE2:
            //user handle
            break;
          case END_VALUE3:
            //user handle
            break;
          case END_VALUE4:
            //user handle
            break;
          case END_VALUE5:
            //user handle
            break;
          case END_VALUE6:
            //user handle
            break;
          case END_VALUE7:
            //user handle
            break;
          case END_VALUE8:
            //user handle
            break;
          case END_VALUE9:
            //user handle
            break;
          case END_VALUE10:
            //user handle
            break;
          case END_VALUE11:
            //user handle
            break;
          case END_VALUE12:
            //user handle
            break;
          case END_VALUE13:
            //user handle
            break;
          case END_VALUE14:
            //user handle
            break;
          case END_VALUE15:
            //user handle
            break;
          case END_VALUE16:
            //user handle
            break;
          case END_VALUE17:
            //user handle
            break;
          case END_VALUE18:
            //user handle
            break;
          case END_VALUE19:
            //user handle
            break;
          default:
            break;
        }
        break;



      case WIFI_SOFTAP:
        break;
      case WIFI_AIRLINK:
        break;
      case WIFI_STATION:
        break;
      case WIFI_CON_ROUTER:
 
        break;
      case WIFI_DISCON_ROUTER:
 
        break;
      case WIFI_CON_M2M: wifi_sta=1;//wifi已连接
 
        break;
      case WIFI_DISCON_M2M: wifi_sta=0;//wifi已断开
        break;
      case WIFI_RSSI:
        GIZWITS_LOG("RSSI %d\n", wifiData->rssi);
        break;
      case TRANSPARENT_DATA:
        GIZWITS_LOG("TRANSPARENT_DATA \n");
        //user handle , Fetch data from [data] , size is [len]
        break;
      case WIFI_NTP:
        GIZWITS_LOG("WIFI_NTP : [%d-%d-%d %02d:%02d:%02d][%d] \n",ptime->year,ptime->month,ptime->day,ptime->hour,ptime->minute,ptime->second,ptime->ntp);
        break;
      case MODULE_INFO:
            GIZWITS_LOG("MODULE INFO ...\n");
      #if MODULE_TYPE
            GIZWITS_LOG("GPRS MODULE ...\n");
            //Format By gprsInfo_t
      #else
            GIZWITS_LOG("WIF MODULE ...\n");
            //Format By moduleInfo_t
            GIZWITS_LOG("moduleType : [%d] \n",ptModuleInfo->moduleType);
      #endif
    break;
      default:
        break;
    }
  }

  return 0;
}

/**
* User data acquisition

* Here users need to achieve in addition to data points other than the collection of data collection, can be self-defined acquisition frequency and design data filtering algorithm

* @param none
* @return none
*/
void userHandle(void)
{
 /*
    currentDataPoint.valueCurrentPoint = ;//Add Sensor Data Collection
    currentDataPoint.valueObstacle = ;//Add Sensor Data Collection

    */
	 static u8 t=0;
   if(wifi_sta)
	 {
	      t++;
		    if(t==10)
				{
            t=0;
            gizwitsGetNTP();//请求网络时间
					
				}
				delay_ms(100);
	 }
	 else{
	 
	   if(t!=0)t=0;	
	 }
}

/**
* Data point initialization function

* In the function to complete the initial user-related data
* @param none
* @return none
* @note The developer can add a data point state initialization value within this function
*/
void userInit(void)     //初始化
{
    memset((uint8_t*)&currentDataPoint, 0, sizeof(dataPoint_t));
    
    /** Warning !!! DataPoint Variables Init , Must Within The Data Range **/ 
    
      currentDataPoint.valueSTART = 0 ;
      currentDataPoint.valueEND = 0;
      currentDataPoint.valueCurrentPoint = 1;
      currentDataPoint.valueObstacle = 0;
    

}


/**
* @brief  gizTimerMs

* millisecond timer maintenance function ,Millisecond increment , Overflow to zero

* @param none
* @return none
*/
void gizTimerMs(void)
{
    timerMsCount++;
}

/**
* @brief gizGetTimerCount

* Read system time, millisecond timer

* @param none
* @return System time millisecond
*/
uint32_t gizGetTimerCount(void)
{
    return timerMsCount;
}

/**
* @brief mcuRestart

* MCU Reset function

* @param none
* @return none
*/
void mcuRestart(void)
{
     //_set_FAULTMASK(1);
	  // NVIC_SystemReset();//复位
}
/**@} */

/**
* @brief TIMER_IRQ_FUN

* Timer Interrupt handler function

* @param none
* @return none
*/
void TIMER_IRQ_FUN(void)
{
  gizTimerMs();
}

/**
* @brief UART_IRQ_FUN

* UART Serial interrupt function ，For Module communication

* Used to receive serial port protocol data between WiFi module

* @param none
* @return none
*/
void UART_IRQ_FUN(void)
{
  uint8_t value = 0;
  //value = USART_ReceiveData(USART2);//STM32 test demo
  gizPutData(&value, 1);
}


/**
* @brief uartWrite

* Serial write operation, send data to the WiFi module

* @param buf      : Data address
* @param len       : Data length
*
* @return : Not 0,Serial send success;
*           -1，Input Param Illegal
*/
int32_t uartWrite(uint8_t *buf, uint32_t len)
{
    uint32_t i = 0;
    
    if(NULL == buf)
    {
        return -1;
    }
    
    #ifdef PROTOCOL_DEBUG
    GIZWITS_LOG("MCU2WiFi[%4d:%4d]: ", gizGetTimerCount(), len);
    for(i=0; i<len; i++)
    {
        GIZWITS_LOG("%02x ", buf[i]);
    }
    GIZWITS_LOG("\n");
    #endif

    for(i=0; i<len; i++)
    {
			 //USART_SendData(UART, buf[i]);//STM32 test demo
        //Serial port to achieve the function, the buf[i] sent to the module
			  // 实现串口发送函数，将buf[i]发送给模组
			  USART_SendData(USART3, buf[i]);
			  while(USART_GetFlagStatus(USART3, USART_FLAG_TC) == RESET);//循环发送，直到发送完毕
        if(i >=2 && buf[i] == 0xFF)
        {
          //Serial port to achieve the function, the 0x55 sent to the module
					//实现串口发送函数，将0x55发送给模组
          //USART_SendData(UART, 0x55);//STM32 test demo
					USART_SendData(USART3, 0x55);
					while(USART_GetFlagStatus(USART3, USART_FLAG_TC) == RESET);//循环发送，直到发送完毕
        }
    }


    
    return len;
}

