#include<reg51.h>

sbit m1_i1=P2^0;
sbit m1_i2=P2^1;
sbit m2_i1=P2^2;
sbit m2_i2=P2^3;
sbit b1=P0^0;
sbit b2=P0^1;

void delay(unsigned int t)
{
	int i,j;
	for(i=0;i<t;i++)
	{
		for(j=0;j<1000;j++);
	}
}

void main(void)
{
	 P2=0x00; // Set all bits of Port 2 as low (output mode)
   P0=0xFF; // Set all bits of Port 0 as high impedance (input mode)
	
	while(1)
	{
		if(b1==1&&b2==0) // clockwise direction for motor1 & motor2
		{
			m1_i1=1;
			m1_i2=0;
			m2_i1=1;
			m2_i2=0;
		}
		else if(b1==0&&b2==1)  // anti-clockwise direction for motor1 & motor2
		{
			m1_i1=0;
			m1_i2=1;
			m2_i1=0;
			m2_i2=1;
		}
		else  // stops
		{
			m1_i1=0;
			m1_i2=0;
			m2_i1=0;
			m2_i2=0;
		}
		delay(500);
	}
}