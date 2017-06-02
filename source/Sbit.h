//*****************Sbit.h********************** 
sbit LCD_CS=P1^0;
sbit LCD_DS=P1^1;
sbit LCD_SCK=P1^2;
sbit LCD_P=P1^7;
//LCD
sbit trig=P1^3;
sbit echo=P1^4;
//Distance
sbit row1=P0^0;  
sbit row2=P0^1;  
sbit row3=P0^2;  
sbit row4=P0^3;  
sbit col1=P0^4;  
sbit col2=P0^5;  
sbit col3=P0^6;  
sbit col4=P0^7;
sbit Is_press=P3^2;
//Key
sbit Moto_Run=P1^5;
//Moto
sbit Position_OK=P1^6;
//Position
sbit DS1302_cs=P2^0;
sbit DS1302_data=P2^1;
sbit DS1302_clk=P2^2; 
sbit ACC0=ACC^0;
sbit ACC7=ACC^7;
//Time
sbit Rec=P2^3;
sbit Play=P2^4;
//Rec&Play


