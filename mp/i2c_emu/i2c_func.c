
#include"i2c_func.h"

#define SDA 254                         //data pin
#define SCL 255                         //clock pin  
#define OUTP 1                           
#define INP 0                           

int i2c_start()  
{  
	set_gpio_direction(SDA, OUTP);
	set_gpio_direction(SCL, OUTP);

	set_gpio_value(SDA, 1);               
	set_gpio_value(SCL, 1);              
	delay();
	set_gpio_value(SDA, 0);
	delay();  
}  
void i2c_stop()  
{  
	set_gpio_value(SCL, 1);  
	set_gpio_direction(SDA, OUTP);  
	set_gpio_value(SDA, 0);  
	delay();  
	set_gpio_value(SDA, 1);             
}  

/*   

*/  
unsigned char i2c_read_ack()  
{  
	unsigned char r;  
	set_gpio_direction(SDA, INP);          
	set_gpio_value(SCL,0);             
	r = get_gpio_value(SDA);                
	delay();  
	set_gpio_value(SCL,1);             
	delay();  
	return r;  
}  
/* I2C· */  
int i2c_send_ack()  
{  
	set_gpio_direction(SDA, OUTP);           
	set_gpio_value(SCL,0);             
	set_gpio_value(SDA, 0);              
	delay();  
	set_gpio_value(SCL,1);              
	delay();  
}  
/* I2C */  
void i2c_write_byte(unsigned char b)  
{  
	int i;  
	set_gpio_direction(SDA, OUTP);  
	for (i=7; i>=0; i--) {  
		set_gpio_value(SCL, 0); 
		delay();  
		set_gpio_value(SDA, b & (1<<i));  
		set_gpio_value(SCL, 1);            
		delay();  
	}  
	i2c_read_ack();        
}  

unsigned char i2c_read_byte()  
{  
	int i;  
	unsigned char r = 0;  
	set_gpio_direction(SDA, INP);  
	for (i=7; i>=0; i--) {  
		set_gpio_value(SCL, 0);      
		delay();  
		r = (r <<1) | get_gpio_value(SDA);    
		set_gpio_value(SCL, 1);        
		delay();  
	}  
	i2c_send_ack();                
	return r;  
}  
/*  
 
*/  
void i2c_read(unsigned char addr, unsigned char* buf, int len)  
{  
	int i;  
	unsigned char t;  
	i2c_start();                       
	 
	t = (addr << 1) | 1;                   
	i2c_write_byte(t);  

	for (i=0; i<len; i++)  
		buf[i] = i2c_read_byte();  
	i2c_stop();                    
}  
/*  
  
*/  
void i2c_write (unsigned char addr, unsigned char* buf, int len)  
{  
	int i;  
	unsigned char t;  
	i2c_start();                     
	 
	t = (addr << 1) | 0;              
	i2c_write_byte(t);  
	//
	for (i=0; i<len; i++)  
		i2c_write_byte(buf[i]);  
	i2c_stop();                     
}


