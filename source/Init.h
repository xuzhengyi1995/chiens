//*****************Init.h********************** 


void Moto_Init() 
{
     Position_OK=1;
     if (Position_OK==0) return;
     Moto_1(-1);
}
void Main_Init()
{
     delay_s(100);
     LCD_Init();//LCD初始化
     delay_s(100);
     LCD_W_String(1,0,"Please wait..."); 
     Rec=0;//停止录音 
     Play=0;//停止放音
     Delay_L();//稳定延迟 
     EA=1;  
     EX0=1;  
     IT0=1;
     Moto_Run=1;//停止电机 
     Moto_Init();//转盘归位 
     Display_Init();//显示初始化 
     DS1302_init();//时间模块初始化
     //Write_Time(1200); //默认开机12点 
}
