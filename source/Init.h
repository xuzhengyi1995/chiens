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
     LCD_Init();//LCD��ʼ��
     delay_s(100);
     LCD_W_String(1,0,"Please wait..."); 
     Rec=0;//ֹͣ¼�� 
     Play=0;//ֹͣ����
     Delay_L();//�ȶ��ӳ� 
     EA=1;  
     EX0=1;  
     IT0=1;
     Moto_Run=1;//ֹͣ��� 
     Moto_Init();//ת�̹�λ 
     Display_Init();//��ʾ��ʼ�� 
     DS1302_init();//ʱ��ģ���ʼ��
     //Write_Time(1200); //Ĭ�Ͽ���12�� 
}
