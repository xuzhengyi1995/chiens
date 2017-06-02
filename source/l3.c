//***********************MAIN****************************
#include<reg51.h>
#include<string.h>
//*******************************************************
#include<Define.h> 
#include<Sbit.h>
#include<LCD.h>
#include<Distance.h>
#include<Time.h>
#include<Init.h> 
#include<Display.h>   
/*******************************************************
                      LCD部分
********************************************************
void LCD_Init()//LCD初始化 
void LCD_Init_G()//图形初始化
void LCD_Clear_String()//清字符
void LCD_W_String(WORD,WORD,*char)//写字符串（第几行，空几格，字符地址）
void Display_S_All(*WORD)//显示全屏图像（字地址）
void LCD_Write_Int(WORD line,WORD space,DWORD number)//显示数字 
********************************************************
                    超声波部分
********************************************************
unsigned int Get_Distance()//返回数值为整数1位小数
unsigned int Sure_Distance()//确定返回 
********************************************************
                   时钟部分
********************************************************
void Ds1302_Init(void)//初始化
void Write_Time(unsigned int value)//写时间
unsigned int Read_Time()//读时间               
********************************************************/
unsigned int Wait_Time=15;
unsigned char p=0;

void Moto_1(int how) //电机转一圈 
{
     Moto_Run=0;
     delay_s(10);
     if (how!=-1) LCD_W_String(2,0,"开始投食！");
     Delay_L();
     Position_OK=1;
     while(Position_OK==1);
     Moto_Run=1;
     delay_s(10);
     if (how!=-1) LCD_W_String(2,0,"开始投食！");
     delay_s(20);
     return;
}


void Give(unsigned int Enter_Time) //喂食 
{
     unsigned char i;
     unsigned int d,t;
     EA=0;
     Give_Display();
     while(1)
     {
             t=Read_Time()-Enter_Time;
             d=Sure_Distance();
             delay_s(20);
             LCD_Write_Int(2,3,d);
             LCD_W_String(2,6,"  ");
             delay_s(20);
             LCD_Write_Int(4,0,t);
             delay_s(20);
             Play=1;//开始放音 
             Play=0;
             if (d<200)
             {
                                    Give_Run_Display();
                                    Play=0;//停止放音 
                                    p=1;
                                    for (i=0;i<How_Many;i++)
                                    {
                                        delay_s(100);
                                        LCD_Write_Int(3,0,i+1);
                                        LCD_W_String(3,2,"            ");
                                        delay_s(200);
                                        Moto_1(i);
                                        delay_s(100);
                                        Give_Run_Display();
                                    }
                                    EA=1;
                                    return;
             }
             if (t>Wait_Time) {EA=1;return;}
             delay_s(200);
     }
}
                                    


//******************键盘中断****************************
void int0_Button(void) interrupt 0
{
     if (Is_press==0)
     {
                     delay_s(10);
                     if (Is_press==0)
                     {
                                             row1=0;row2=1;row3=1;row4=1;  
                                             if(col4==0){delay_s(200);Set_Time(Read_Time());delay_s(200);Display_Init();return;}
                  
                                             row1=1;row2=0;row3=1;row4=1;  
                                             if(col4==0){delay_s(200);Set_Do_Time(Read_Time());delay_s(200);Display_Init();return;}
  
                                             row1=1;row2=1;row3=0;row4=1;  
                                             if(col4==0){delay_s(200);Rec_Do(Read_Time());delay_s(200);Display_Init();return;}
  
                                             row1=1;row2=1;row3=1;row4=0;  
                                             if(col4==0)delay_s(200);{Set_Do_Number(Read_Time());delay_s(200);Display_Init();return;}
                     }
                                     
     }
}


//******************主程序*****************************
void main()
{
     int time;
     Main_Init();
     while(1)
     {
             row1=0;row2=0;row3=0;row4=0;  
             col1=1;col2=1;col3=1;col4=1;
             time=Read_Time();
             delay_s(20);
             LCD_Write_Int(1,3,time/100);
             LCD_W_String(1,4,":");
             LCD_Write_Int(1,5,time%100);
             LCD_W_String(1,6,":");          
             LCD_Write_Int(1,7,second);
             if (((time==Set_Time_1)||(time==Set_Time_2))&&(p==0)) 
             {
                  delay_s(20);
                  Give(Read_Time());
                  delay_s(100);
                  Display_Init();
             }
             if (((time-Set_Time_1>10)&&(time-Set_Time_1<100))||(time>Set_Time_2)) p=0;
             delay_s(70);
     }
     
}                    
