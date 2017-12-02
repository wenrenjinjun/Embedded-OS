/**
 ******************************************************************************
 * @file      bspLib.c
 * @brief     C Source file of bspLib.c.
 * @details   This file including all API functions's implement of bspLib.c.	
 * @copyright  Copyright(C), JunGeGe
 ******************************************************************************
 */
 
/*-----------------------------------------------------------------------------
 Section: Includes
 ----------------------------------------------------------------------------*/
#include <bsp_config.h>
#if (BOARD_BUILD_VER == BOARD_STM32F3_Wildfire)

#include "cpu\stm32f10x.h"
#include "cpu\system_stm32f10x.h"

/*-----------------------------------------------------------------------------
 Section: Type Definitions
 ----------------------------------------------------------------------------*/
/* NONE */

/*-----------------------------------------------------------------------------
 Section: Constant Definitions
 ----------------------------------------------------------------------------*/
/* NONE */ 

/*-----------------------------------------------------------------------------
 Section: Global Variables
 ----------------------------------------------------------------------------*/
/* NONE */

/*-----------------------------------------------------------------------------
 Section: Local Variables
 ----------------------------------------------------------------------------*/
/* NONE */

/*-----------------------------------------------------------------------------
 Section: Local Function Prototypes
 ----------------------------------------------------------------------------*/
/* NONE */

/*-----------------------------------------------------------------------------
 Section: Global Function Prototypes
 ----------------------------------------------------------------------------*/
/* NONE */

/*-----------------------------------------------------------------------------
 Section: Function Definitions
 ----------------------------------------------------------------------------*/

/**
 ******************************************************************************
 * @brief   ��ʼ��bsp  //todo:ʹ�û���д
 *          (a)��ס�жϣ�
 *          (b)����Cache��
 *          (c)��ʼ���������Ĵ�����һȱʡֵ;(�ر��ڲ����Ź�,�������ã�
 *          (d)ʹ����ʧЧ��?
 *          (e)������������жϣ�
 * @return  None
 ******************************************************************************
 */
void
bspHwInit(void)
{
//    CPU_IntDis();
//    bsp_close_watchdog();    //�������оƬ����Ҫ�رտ��Ź�
    SystemInit();
}

void
Delay( volatile int nCount)     //�򵥵���ʱ����
{
    for(; nCount != 0; nCount--);
}

/*
 * ��������LED_GPIO_Config
 * ����  ������LED�õ���I/O��
 * ����  ����
 * ���  ����
 */
void
LED_GPIO_Config(void)
{
    /*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
    GPIO_InitTypeDef GPIO_InitStructure;

    /*����GPIOC������ʱ��*/
    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC, ENABLE);

    /*ѡ��Ҫ���Ƶ�GPIOC����*/
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5;

    /*��������ģʽΪͨ���������*/
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;

    /*������������Ϊ50MHz */
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

    /*���ÿ⺯������ʼ��GPIOC*/
    GPIO_Init(GPIOC, &GPIO_InitStructure);

    /* �ر�����led�� */
    GPIO_SetBits(GPIOC, GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5);
}

void LED1(char a)
{
    if (a)
    {
        GPIO_SetBits(GPIOC,GPIO_Pin_3);
    }
    else
    {
        GPIO_ResetBits(GPIOC,GPIO_Pin_3);
    }
}

void LED2(char a)
{
    if (a)
       {
           GPIO_SetBits(GPIOC,GPIO_Pin_4);
       }
       else
       {
           GPIO_ResetBits(GPIOC,GPIO_Pin_4);
       }

}

void LED3(char a)
{
    if (a)
       {
           GPIO_SetBits(GPIOC,GPIO_Pin_5);
       }
       else
       {
           GPIO_ResetBits(GPIOC,GPIO_Pin_5);
       }

}

#endif

/*----------------------------bspLib.c--------------------------------*/