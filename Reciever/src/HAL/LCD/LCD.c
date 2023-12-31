
/********************************************************************************/
/**    File Name: LCD.c                                                          */
/**                                                                             */
/**  Description: Implementation of the LED contain configuration for the module                            */
/**-----------------------------------------------------------------------------*/
/**  CODING LANGUAGE :  C                                                       */
/**  TARGET          :  STM32F401CCG6                                           */
/**-----------------------------------------------------------------------------*/
/**               C O P Y R I G H T                                             */
/**-----------------------------------------------------------------------------*/
/** Copyright (c) 2023 by Rana Hossny .       All rights reserved.              */
/**                                                                             */
/**-----------------------------------------------------------------------------*/
/**               A U T H O R   I D E N T I T Y                                 */
/**-----------------------------------------------------------------------------*/
/** ShortName    Name                      Company                              */
/** --------     ---------------------     -------------------------------------*/
/** Rana     Rana Hossny                 ain shams university.               */
/**-----------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                               */
/**-----------------------------------------------------------------------------*/
/** Date        Version   Author       Description                              */
/** ----------  --------  ------      ------------------------------------------*/
/** 9/09/2023   0.1       Rana Hossny   Initial Creation                        */
/********************************************************************************/
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "../../MCAL/SYSTICK/SYSTICK.h"
#include "../../MCAL/GPIO/GPIO.h"
#include "LCD.h"
#include "LCD_cfg.h"
#include "LCD_priv.h"
/********************************************************************************/
/**    File Name: LCD_cfg.C                                                    */
/**                                                                             */
/**  Description: Implementation of the LED contain configuration for the module                            */
/**-----------------------------------------------------------------------------*/
/**  CODING LANGUAGE :  C                                                       */
/**  TARGET          :  STM32F401CCG6                                           */
/**-----------------------------------------------------------------------------*/
/**               C O P Y R I G H T                                             */
/**-----------------------------------------------------------------------------*/
/** Copyright (c) 2023 by Rana Hossny .       All rights reserved.              */
/**                                                                             */
/**-----------------------------------------------------------------------------*/
/**               A U T H O R   I D E N T I T Y                                 */
/**-----------------------------------------------------------------------------*/
/** ShortName    Name                      Company                              */
/** --------     ---------------------     -------------------------------------*/
/** Rana     Rana Hossny                 ain shams university.               */
/**-----------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                               */
/**-----------------------------------------------------------------------------*/
/** Date        Version   Author       Description                              */
/** ----------  --------  ------      ------------------------------------------*/
/** 9/09/2023   0.1       Rana Hossny   Initial Creation                        */
/********************************************************************************/
#include "../../LIB/STD_Types.h"
#include "../../MCAL/GPIO/GPIO.h"
#include "LCD_cfg.h"
#include "LCD_priv.h"



static tenuErrorStatus LCD_enuHelp(uint8 u8LcdNumCpy , uint8 u8LcdDataCmdCpy) ;

void LCD_voidInit(void)
{
	uint8 u8CntrLoc ;
	uint8 u8CmdLoc  ;
	for (u8CntrLoc = 0 ; u8CntrLoc < LCD_MAX_NUM ; u8CntrLoc++)
	{

		MSTK_voidDelayMsec(300);
		if (LCD_astrCfg[u8CntrLoc].strLcdOpcfg.u8Mode == LCD_u8MODE_8BIT)
		{

			u8CmdLoc = 0x30|LCD_astrCfg[u8CntrLoc].strLcdOpcfg.u8PanLine <<3 |
						    LCD_astrCfg[u8CntrLoc].strLcdOpcfg.u8CharFont<<2 ;
			LCD_enuWriteCmd(u8CntrLoc , u8CmdLoc);



		   MSTK_voidDelayMsec(20);
			u8CmdLoc = 0x08 |LCD_astrCfg[u8CntrLoc].strLcdOpcfg.u8Display <<2 |
                             LCD_astrCfg[u8CntrLoc].strLcdOpcfg.u8Cursor  <<1 |
							 LCD_astrCfg[u8CntrLoc].strLcdOpcfg.u8Blink   <<0 ;

			LCD_enuWriteCmd(u8CntrLoc , u8CmdLoc);
		    MSTK_voidDelayMsec(20);

			LCD_enuWriteCmd(u8CntrLoc , LCD_u8CLEAR);
		     MSTK_voidDelayMsec(20);

			u8CmdLoc = 0x04|LCD_astrCfg[u8CntrLoc].strLcdOpcfg.u8Increment   <<1 |
						    LCD_astrCfg[u8CntrLoc].strLcdOpcfg.u8DisplayShift<<0 ;

			LCD_enuWriteCmd(u8CntrLoc , u8CmdLoc);

			 MSTK_voidDelayMsec(20);

		}
		else
		{

				LCD_enuWriteCmd(u8CntrLoc , 0x20);
				 MSTK_voidDelayMsec(20);
				LCD_enuWriteCmd(u8CntrLoc , 0x20);
				 MSTK_voidDelayMsec(20);
				u8CmdLoc = 0x00|LCD_astrCfg[u8CntrLoc].strLcdOpcfg.u8PanLine <<7 |
						        LCD_astrCfg[u8CntrLoc].strLcdOpcfg.u8CharFont<<6 ;

				LCD_enuWriteCmd(u8CntrLoc , u8CmdLoc );
				 MSTK_voidDelayMsec(20);

				LCD_enuWriteCmd(u8CntrLoc , 0x00 );
				 MSTK_voidDelayMsec(20);

				u8CmdLoc = 0x80|LCD_astrCfg[u8CntrLoc].strLcdOpcfg.u8Display <<6 |
						        LCD_astrCfg[u8CntrLoc].strLcdOpcfg.u8Cursor  <<5 |
								LCD_astrCfg[u8CntrLoc].strLcdOpcfg.u8Blink   <<4 ;

				LCD_enuWriteCmd(u8CntrLoc , u8CmdLoc );
				 MSTK_voidDelayMsec(20);

				LCD_enuWriteCmd(u8CntrLoc , 0x00 );
			    MSTK_voidDelayMsec(20);
				LCD_enuWriteCmd(u8CntrLoc , 0x10 );
				 MSTK_voidDelayMsec(20);

				LCD_enuWriteCmd(u8CntrLoc , 0x00 );
			    MSTK_voidDelayMsec(20);

				u8CmdLoc = 0x40|LCD_astrCfg[u8CntrLoc].strLcdOpcfg.u8Increment    <<5 |
						        LCD_astrCfg[u8CntrLoc].strLcdOpcfg.u8DisplayShift <<4 ;

				LCD_enuWriteCmd(u8CntrLoc , u8CmdLoc );
			     MSTK_voidDelayMsec(20);


		}

	}
}



static tenuErrorStatus LCD_enuHelp(uint8 u8LcdNumCpy , uint8 u8LcdDataCmdCpy)
{
	tenuErrorStatus enuErrorStateLoc = E_OK ;
	uint8 u8CntrLoc ;

	if(LCD_astrCfg[u8LcdNumCpy].strLcdPinCfg.u8EnableLatch>=0 && LCD_astrCfg[u8LcdNumCpy].strLcdPinCfg.u8EnableLatch<=15){
			MGPIO_u8SetPinVal(GPIO_PORTA,LCD_astrCfg[u8LcdNumCpy].strLcdPinCfg.u8EnableLatch, GPIO_HIGH );

		}
		else{
			MGPIO_u8SetPinVal(GPIO_PORTB,LCD_astrCfg[u8LcdNumCpy].strLcdPinCfg.u8EnableLatch-16, GPIO_HIGH );
		}

	if(LCD_astrCfg[u8LcdNumCpy].strLcdPinCfg.u8ReadWrite>=0 && LCD_astrCfg[u8LcdNumCpy].strLcdPinCfg.u8ReadWrite<=15){
			MGPIO_u8SetPinVal(GPIO_PORTA,LCD_astrCfg[u8LcdNumCpy].strLcdPinCfg.u8ReadWrite, GPIO_LOW );
		}
		else{
			MGPIO_u8SetPinVal(GPIO_PORTB,LCD_astrCfg[u8LcdNumCpy].strLcdPinCfg.u8ReadWrite-16, GPIO_LOW );
		}


		if (LCD_astrCfg[u8LcdNumCpy].strLcdOpcfg.u8Mode == LCD_u8MODE_8BIT)
		{
			  for (u8CntrLoc = 0 ; u8CntrLoc < 8 ; u8CntrLoc++)
			  {
				if(LCD_astrCfg[u8LcdNumCpy].strLcdPinCfg.u8DataPinMapping[u8CntrLoc]>=0 && LCD_astrCfg[u8LcdNumCpy].strLcdPinCfg.u8DataPinMapping[u8CntrLoc]<=15){
						MGPIO_u8SetPinVal(GPIO_PORTA,LCD_astrCfg[u8LcdNumCpy].strLcdPinCfg.u8DataPinMapping[u8CntrLoc], GET_BIT(u8LcdDataCmdCpy, u8CntrLoc)  );
					}
				else{
						MGPIO_u8SetPinVal(GPIO_PORTB,LCD_astrCfg[u8LcdNumCpy].strLcdPinCfg.u8DataPinMapping[u8CntrLoc]-16, GET_BIT(u8LcdDataCmdCpy, u8CntrLoc)  );
					}

			  }
		}
		else if (LCD_astrCfg[u8LcdNumCpy].strLcdOpcfg.u8Mode == LCD_u8MODE_4BIT)
		{
			for (u8CntrLoc = 4 ; u8CntrLoc < 8 ; u8CntrLoc++)
			{
				if(LCD_astrCfg[u8LcdNumCpy].strLcdPinCfg.u8DataPinMapping[u8CntrLoc]>=0 && LCD_astrCfg[u8LcdNumCpy].strLcdPinCfg.u8DataPinMapping[u8CntrLoc]<=15){
						MGPIO_u8SetPinVal(GPIO_PORTA,LCD_astrCfg[u8LcdNumCpy].strLcdPinCfg.u8DataPinMapping[u8CntrLoc], GET_BIT(u8LcdDataCmdCpy, u8CntrLoc)  );
					}
				else{
						MGPIO_u8SetPinVal(GPIO_PORTB,LCD_astrCfg[u8LcdNumCpy].strLcdPinCfg.u8DataPinMapping[u8CntrLoc]-16, GET_BIT(u8LcdDataCmdCpy, u8CntrLoc)  );
					}

			}

		}
		else
		{
			enuErrorStateLoc = E_NOK_CONFIG_PARM_ERROR ;
		}

			if(LCD_astrCfg[u8LcdNumCpy].strLcdPinCfg.u8EnableLatch>=0 && LCD_astrCfg[u8LcdNumCpy].strLcdPinCfg.u8EnableLatch<=15){
			MGPIO_u8SetPinVal(GPIO_PORTA,LCD_astrCfg[u8LcdNumCpy].strLcdPinCfg.u8EnableLatch, GPIO_LOW);
		}
		else{
			MGPIO_u8SetPinVal(GPIO_PORTB,LCD_astrCfg[u8LcdNumCpy].strLcdPinCfg.u8EnableLatch-16, GPIO_LOW );
		}

	return enuErrorStateLoc ;
}

tenuErrorStatus LCD_enuWriteCmd (uint8 u8LcdNumCpy , uint8 u8CmdCpy)
{

	tenuErrorStatus enuErrorStateLoc = E_OK ;
	if (u8LcdNumCpy < LCD_MAX_NUM )

	{

		if(LCD_astrCfg[u8LcdNumCpy].strLcdPinCfg.u8RegisterSelect>=0 && LCD_astrCfg[u8LcdNumCpy].strLcdPinCfg.u8RegisterSelect<=15){
			MGPIO_u8SetPinVal(GPIO_PORTA,LCD_astrCfg[u8LcdNumCpy].strLcdPinCfg.u8RegisterSelect, GPIO_LOW );
		}
		else {

			MGPIO_u8SetPinVal(GPIO_PORTB,LCD_astrCfg[u8LcdNumCpy].strLcdPinCfg.u8RegisterSelect-16, GPIO_LOW );

		}

		enuErrorStateLoc = LCD_enuHelp(u8LcdNumCpy , u8CmdCpy );
	}
	else
	{

		enuErrorStateLoc = E_NOK_PARAM_OUT_OF_RANGE ;
	}


	return enuErrorStateLoc ;
}


tenuErrorStatus LCD_enuWriteChar (uint8 u8LcdNumCpy , uint8 u8DataCpy)
{
	tenuErrorStatus enuErrorStateLoc = E_OK ;


	if (u8LcdNumCpy < LCD_MAX_NUM )
	{
		if(LCD_astrCfg[u8LcdNumCpy].strLcdPinCfg.u8RegisterSelect>=0 && LCD_astrCfg[u8LcdNumCpy].strLcdPinCfg.u8RegisterSelect<=15){

			MGPIO_u8SetPinVal(GPIO_PORTA,LCD_astrCfg[u8LcdNumCpy].strLcdPinCfg.u8RegisterSelect, GPIO_HIGH );
		}

		else{
			MGPIO_u8SetPinVal(GPIO_PORTB,LCD_astrCfg[u8LcdNumCpy].strLcdPinCfg.u8RegisterSelect-16, GPIO_HIGH );
		}
		LCD_enuHelp(u8LcdNumCpy, u8DataCpy);

	}
	else
	{
		enuErrorStateLoc = E_NOK_PARAM_OUT_OF_RANGE ;
	}

	return enuErrorStateLoc ;

}


tenuErrorStatus LCD_enuWriteData (uint8 u8LcdNumCpy , uint8 *  pu8DataCpy , uint8 u8SizeCpy)
{
	int i=0;
	for(i=0;i<u8SizeCpy;i++){
		LCD_enuWriteChar (u8LcdNumCpy , pu8DataCpy[i]);
	}
}


tenuErrorStatus LCD_enuCreateCustChar (uint8 u8LcdNumCpy , uint8 *pu8PatternCpy , uint8 u8LocationCpy)
{
	tenuErrorStatus enuErrorStateLoc = E_OK ;
	uint8 u8CntrLoc;
	if(u8LcdNumCpy < LCD_MAX_NUM && u8LocationCpy < 9)
	{
		LCD_enuWriteCmd(u8LcdNumCpy , 0x40+(u8LocationCpy * 8 ));

		for (u8CntrLoc = 0 ;u8CntrLoc < 8 ; u8CntrLoc++ )
		{
			LCD_enuWriteChar(u8LcdNumCpy ,pu8PatternCpy[u8CntrLoc] );
		}

	}
	else
	{
		enuErrorStateLoc = E_NOK_PARAM_OUT_OF_RANGE ;
	}

	return enuErrorStateLoc ;

}



void LCD_enuWritenumber(uint8 u8LcdNumCpy, float32 pu8DataCpy)
{
    // Check if the number is negative
    int isNegative = 0;
    if (pu8DataCpy < 0)
    {
        isNegative = 1;
        pu8DataCpy = -pu8DataCpy; // Use the absolute value
    }

    // Count digits in the integer part of the number
    int integerPart = (int)pu8DataCpy;
    int digitCount = 1;
    while (integerPart / 10 != 0)
    {
        digitCount++;
        integerPart /= 10;
    }

    // Add one more for the negative sign if applicable
    if (isNegative)
    {
        digitCount++;
    }

    // Declare a character array to store the result
    char arr[digitCount];

    // Separate integer into digits and store them in the array
    int index = 0;
    do
    {
        arr[index++] = (char)((int)pu8DataCpy % 10 + '0');
        pu8DataCpy /= 10;
    } while ((int)pu8DataCpy != 0);

    // Add the negative sign if applicable
    if (isNegative)
    {
        arr[index] = '-';
    }

    // Reverse the array
    int i, j;
    char temp;
    for (i = 0, j = index; i < j; i++, j--)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // Display the characters on the LCD
    for (i = 0; i <= index; i++)
    {
        LCD_enuWriteChar(u8LcdNumCpy, arr[i]);
    }
}


