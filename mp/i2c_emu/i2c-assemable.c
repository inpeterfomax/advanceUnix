

/* Inlcudes ------------------------------------------------------------------*/
#include "SI2C.h"
#include "delay.h"


/* defines ------------------------------------------------------------------*/

#define Slave_Address_W 0xa0
#define Slave_Address_R 0xa1

#define Byte_Address 0x00

#define SDA_PORT GPIOE
#define SDA_PIN  GPIO_PIN_2
#define SDA_HIGH() GPIO_WriteHigh(SDA_PORT,SDA_PIN)
#define SDA_LOW()  GPIO_WriteLow(SDA_PORT,SDA_PIN)

#define SCL_PORT GPIOE
#define SCL_PIN  GPIO_PIN_1
#define SCL_HIGH() GPIO_WriteHigh(SCL_PORT,SCL_PIN)
#define SCL_LOW()  GPIO_WriteLow(SCL_PORT,SCL_PIN)

#define SDA_READ() GPIO_ReadInputPin(SDA_PORT,SDA_PIN)



/* function ------------------------------------------------------------------*/



/*******************************************************************************
* Function Name  : SI2C_GPIOConfigration
* Description    : ?????I2C???? 
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/

  
void SI2C_GPIOConfigration(void)
{
  GPIO_Init(SDA_PORT,SDA_PIN,GPIO_MODE_OUT_OD_LOW_FAST); //SDA????
  GPIO_Init(SCL_PORT,SCL_PIN,GPIO_MODE_OUT_PP_LOW_FAST); //SCL????
  /*I2C????????*/
  SDA_HIGH();
  SCL_HIGH();  
}

/*******************************************************************************
* Function Name  : SI2C_Start
* Description    : I2C???? 
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/

void SI2C_Start(void)
{
  SDA_HIGH(); 
  
  SCL_HIGH();
  //delay(10);         
 // nop();       //??????????4.7us
  //nop();

  
  SDA_LOW();  //??????????4us
 // nop();
 // nop();

    
  
  SCL_LOW();  //?????????

}



/*******************************************************************************
* Function Name  : SI2C_Stop
* Description    : I2C???? 
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/

void SI2C_Stop(void)
{
  
  SDA_LOW();
  
  SCL_HIGH();  //????????
 // nop();
 // nop();       //????????4us
           
  
  SDA_HIGH();  //????
 // nop();
 // nop();

  

    
}


/*******************************************************************************
* Function Name  : SI2C_SendAck
* Description    : ????ACK 
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void SI2C_SendAck(void)
{
  SDA_LOW();
  SCL_HIGH();
  //nop(); 
 // nop(); 

  SCL_LOW(); 
  SDA_HIGH(); 
}


/*******************************************************************************
* Function Name  : SI2C_SendNAck
* Description    : ????ACK 
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void SI2C_SendNAck(void)
{
  SDA_HIGH();
  SCL_HIGH();
 // nop();
 // nop();

  SCL_LOW();
  SDA_LOW();
  
}

/*******************************************************************************
* Function Name  : SI2C_SendByte
* Description    : I2C?????? 
* Input          : SendByte ???????
* Output         : None
* Return         : None
*******************************************************************************/
void SI2C_SendByte(u8 SendByte)
{ 
  u8 i;
  
  for( i = 0 ; i < 8 ; i ++)
  {
    
    (((SendByte & 0x80) == 0x80) ? SDA_HIGH():SDA_LOW());
    
    SCL_HIGH();
    //nop();
    //nop();

    
    SCL_LOW();
    SendByte = SendByte << 1;
  }
}

/*******************************************************************************
* Function Name  : Test_Ack
* Description    : ??????? 
* Input          : None
* Output         : None
* Return         : FALSE or TRUE
*******************************************************************************/
int Test_Ack(void)
{
   SDA_HIGH(); /*???????????ACK????*/
   SCL_HIGH();
  // nop();
  // nop();

   
   if (SDA_READ())
   {
     SCL_LOW();
     SDA_LOW();
    // nop();
    // nop();

     return FALSE;
         
   }
   else
   {
     
     SDA_LOW();
     SCL_LOW();
    // nop();
    // nop();

     return TRUE;
   }
  
}

/*******************************************************************************
* Function Name  : SI2C_ReadByte
* Description    : I2C?????? 
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/

u8 SI2C_ReadByte(void)
{
  u8 readbyte = 0;
  u8 i ;
  
  for( i = 0; i < 8 ; i ++ )
  {
   readbyte = readbyte << 1;
   
   SDA_HIGH(); 
   SCL_HIGH();
   
    // nop();
   //  nop();

   
    if(SDA_READ())
    {
      readbyte |= 0x01;
            
    }
    
    SCL_LOW();
    
   //  nop();
   //  nop();

  }
  
  return readbyte;
  
}

/*******************************************************************************
* Function Name  : SI2C_Write24c02
* Description    : SI2C_Write24c02 operation
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/ 
void SI2C_Write24c02(u8 data)
{
 
  SI2C_Start();
  SI2C_SendByte(Slave_Address_W);
  Test_Ack();
  SI2C_SendByte(Byte_Address);
  Test_Ack();
  
  SI2C_SendByte(data);
  Test_Ack();
  
  SI2C_Stop();
  
  delay(1000);
   
}

/*******************************************************************************
* Function Name  : I2C_Read24c02
* Description    : I2C_Read24c02 operation
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/     
u8 SI2C_Read24c02(void)
{
  u8 con;
  SI2C_Start();
  SI2C_SendByte(Slave_Address_W);
  Test_Ack();
  SI2C_SendByte(Byte_Address);
  Test_Ack();
  
  SI2C_Start();
  SI2C_SendByte(Slave_Address_R);
  Test_Ack();
  
  con = SI2C_ReadByte();
  
  SI2C_SendNAck();
  
  SI2C_Stop();
  
  return con;
  
}



/********************************END OF FILE***********************************/




