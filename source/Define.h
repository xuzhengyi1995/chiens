#define uchar unsigned char
#define uint unsigned int
typedef unsigned int DWORD;
typedef unsigned char WORD; 

//******************MAIN**************************
void Moto_1(int how);
void Give(unsigned int Enter_Time);

//******************Time.h********************** 
void DS1302_init();//ds1302��ʼ�� 
void DS1302_write(unsigned char DS1302_temp);  //д��һ���ֽ�  
uchar DS1302_read(void); //��һ�ֽ� 
void DS1302_write_time(int command,int dat);//д�� 
uchar DS1302_read_time(int command);//��ȡ 
void long_ds1302_delay();  //����ʱ
void short_ds1302_delay(); //����ʱ
unsigned int Read_Time(); //����ʱ��
void Write_Time(unsigned int time); //д��ʱ�� 

//****************Display.h************************
void Delay_L(); //���ӳ�
void Display_Init(); //��������ʾ
void Set_Time_Display(); //����ʱ����ʾ
void Set_Time_Check(unsigned int S_Time); //ʱ����
void Set_Time(unsigned int Enter_Time); //ʱ������
void Set_Do_Display(); //����Ͷʳʱ����ʾ 
void Set_Do_Check(unsigned int SD_1,unsigned  int SD_2);  //ʱ���� 
void Set_Do_Time(unsigned int Enter_Time); //����Ͷʳʱ�� 
void Rec_Do(unsigned int Enter_Time); //����¼�� 
void Set_Do_Number(unsigned int Enter_Time); //����Ȯ���� 
void Give_Run_Display(); //����ʱ��ʾ 
void Give_Display(); //������ʾ 

//******************LCD.h*************************
void delay_s(int s); //С�ӳ� 
void Send_byte(WORD s_data); //����һ�ֽ����� 
void Write_Cmd(WORD c_data); //д���� 
void Write_Data(WORD d_data); //д����
void LCD_Init(); //LCD��ʼ��
void LCD_Init_G(); //ͼ�γ�ʼ��
void LCD_Clear_String(); //���ַ� 
void LCD_W_String(WORD Line,WORD Space,char *d_string); //д�ַ������ڼ��У��ռ����ַ���ַ��
void LCD_Write_Int(WORD line,WORD space,DWORD number); //��ʾ���� 
void Display_S_All(WORD *Data_G); //��ʾȫ��ͼ��

//******************Distance.h********************
unsigned int Get_Distance();
unsigned int Sure_Distance();
void D_Delay();

//******************Init.h************************
void Moto_Init(); //�����λ 
void Main_Init(); //�ϵ��λ
