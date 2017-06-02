#define uchar unsigned char
#define uint unsigned int
typedef unsigned int DWORD;
typedef unsigned char WORD; 

//******************MAIN**************************
void Moto_1(int how);
void Give(unsigned int Enter_Time);

//******************Time.h********************** 
void DS1302_init();//ds1302初始化 
void DS1302_write(unsigned char DS1302_temp);  //写入一个字节  
uchar DS1302_read(void); //读一字节 
void DS1302_write_time(int command,int dat);//写入 
uchar DS1302_read_time(int command);//读取 
void long_ds1302_delay();  //长延时
void short_ds1302_delay(); //短延时
unsigned int Read_Time(); //返回时间
void Write_Time(unsigned int time); //写入时间 

//****************Display.h************************
void Delay_L(); //大延迟
void Display_Init(); //主程序显示
void Set_Time_Display(); //设置时间显示
void Set_Time_Check(unsigned int S_Time); //时间检查
void Set_Time(unsigned int Enter_Time); //时间设置
void Set_Do_Display(); //设置投食时间显示 
void Set_Do_Check(unsigned int SD_1,unsigned  int SD_2);  //时间检查 
void Set_Do_Time(unsigned int Enter_Time); //设置投食时间 
void Rec_Do(unsigned int Enter_Time); //设置录音 
void Set_Do_Number(unsigned int Enter_Time); //设置犬类型 
void Give_Run_Display(); //运行时显示 
void Give_Display(); //进入显示 

//******************LCD.h*************************
void delay_s(int s); //小延迟 
void Send_byte(WORD s_data); //发送一字节数据 
void Write_Cmd(WORD c_data); //写命令 
void Write_Data(WORD d_data); //写数据
void LCD_Init(); //LCD初始化
void LCD_Init_G(); //图形初始化
void LCD_Clear_String(); //清字符 
void LCD_W_String(WORD Line,WORD Space,char *d_string); //写字符串（第几行，空几格，字符地址）
void LCD_Write_Int(WORD line,WORD space,DWORD number); //显示数字 
void Display_S_All(WORD *Data_G); //显示全屏图像

//******************Distance.h********************
unsigned int Get_Distance();
unsigned int Sure_Distance();
void D_Delay();

//******************Init.h************************
void Moto_Init(); //电机归位 
void Main_Init(); //上电归位
