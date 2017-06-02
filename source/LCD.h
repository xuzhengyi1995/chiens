//*****************LCD.h**********************



void delay_s(int s)//小延迟 
{
     int i,j;
     for (i=0;i<s;i++)
         for (j=0;j<123;j++);
}

void Send_byte(WORD s_data)//发送一字节数据 
{
     int i;
     for (i=0;i<8;i++)
     {
         if ((s_data<<i)&0x80)
         {
             LCD_DS=1;
         }
         else
         {
             LCD_DS=0;
         }
         LCD_SCK=0;
         LCD_SCK=1;
     }
}

void Write_Cmd(WORD c_data)//写命令 
{
     LCD_CS=1;
     Send_byte(0xf8);
     Send_byte(c_data&0xf0);
     Send_byte((c_data<<4)&0xf0);
     delay_s(1);
     LCD_CS=0;
}

void Write_Data(WORD d_data)//写数据 
{
     LCD_CS=1;
     Send_byte(0xfa);
     Send_byte(d_data&0xf0);
     Send_byte((d_data<<4)&0xf0);
     delay_s(1);
     LCD_CS=0;
}

void LCD_Init()//LCD初始化 
{
     //PSB接地
     LCD_P=0;
     Write_Cmd(0x30);
     Write_Cmd(0x04);
     Write_Cmd(0x0C);
     Write_Cmd(0x01);
}

void LCD_Init_G()//图形初始化 
{
     Write_Cmd(0x34);
}
     
void LCD_Clear_String()//清字符 
{
     Write_Cmd(0x01);
}
 
void LCD_W_String(WORD Line,WORD Space,char *d_string)//写字符串（第几行，空几格，字符地址） 
{
     WORD i=0;
     WORD length=strlen(d_string);
     Write_Cmd(0x30);
     if (Line==1)
     {
        Write_Cmd(0x80+Space);
     }
     else
     {
         if (Line==2)
         {
            Write_Cmd(0x90+Space);
         }
         else
         {
             if(Line==3)
             {
                Write_Cmd(0x88+Space);
             }
             else
             {
                 if (Line==4)
                 {
                    Write_Cmd(0x98+Space);
                 }
             }
         }
     }
     
     for (i=0;i<length;i++)
     {
         Write_Data(*(d_string+i));
     }
}

void LCD_Write_Int(WORD line,WORD space,DWORD number)//显示数字 
{
     char strs[6]={"0"};
     char t;
     int s=0,i;
     if (number<10) 
     {
                    strs[0]='0';
                    strs[1]=number+48;
                    LCD_W_String(line,space,strs);
                    return;
     }
     while (number>0)
     {
           strs[s]=(number%10+48);
           number=number/10;
           s++;
     }
     s--;
     for (i=0;i<(s+1)/2;i++)
     {
         t=strs[i];
         strs[i]=strs[s-i];
         strs[s-i]=t;
     }
	  LCD_W_String(line,space,strs);
}

void Display_S_All(WORD *Data_G)//显示全屏图像 
{
     WORD i,j;
     Write_Cmd(0x34);

     for (i=0;i<32;i++)
     {
         Write_Cmd(0x80+i);
         Write_Cmd(0x80);
         for (j=0;j<16;j++)
         {
             Write_Data(*Data_G);
             Data_G++;
         }
     }
     
     for (i=0;i<32;i++)
     {
         Write_Cmd(0x80+i);
         Write_Cmd(0x88);
         for (j=0;j<16;j++)
         {
             Write_Data(*Data_G);
             Data_G++;
         }
     }  
	 Write_Cmd(0x36);
}
