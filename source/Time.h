//*****************Time.h**********************

uchar year,month,date,hour,minute,second,week;//定义变量

void short_ds1302_delay()
{
  uchar i;
  for(i=0;i<5;i++);
}

void long_ds1302_delay()
{
  uchar i;
  for(i=0;i<25;i++);
}

void DS1302_write(unsigned char DS1302_temp)  //写入一个字节 
{
  uchar i,temp;
  long_ds1302_delay();
  temp=DS1302_temp;
  for(i=0;i<8;i++)
  {
    DS1302_data=temp&0x01;
 short_ds1302_delay();
 DS1302_clk=1;
 short_ds1302_delay();
 DS1302_clk=0;
 temp=temp>>1;
  }
}

unsigned char DS1302_read(void) //读一字节 
{
  uchar i,temp;
  long_ds1302_delay();
  temp=0;
  for(i=0;i<8;i++)
  {
    temp=temp>>1;
 if(DS1302_data==1)
   temp=temp+0x80;
 DS1302_clk=1;
 short_ds1302_delay();
 DS1302_clk=0;
 short_ds1302_delay();
  }
  return temp;
}


void DS1302_init()
{
  uchar i;
  DS1302_write_time(0x8e,0x00);    //允许写操作

  DS1302_cs=0;

  DS1302_clk=0;
  short_ds1302_delay();
  DS1302_cs=1;
  DS1302_write(0x81);
  DS1302_data=1;
  i=DS1302_read();
  DS1302_cs=0;
  short_ds1302_delay();
  DS1302_clk=1;
  second=((i>>4)&0x07)*10+(i&0x0f);

  DS1302_clk=0;
  short_ds1302_delay();
  DS1302_cs=1;
  DS1302_write(0x80);
  DS1302_data=1;
  DS1302_write(0x7f&i);
  DS1302_cs=0;
  short_ds1302_delay();
  DS1302_clk=1; 
  
  DS1302_clk=0;    //充电设置
  short_ds1302_delay();
  DS1302_cs=1;
  DS1302_write(0x90);
  DS1302_data=1;
  //DS1302_write(0xa6);    //允许充电,一个二极管 4k电阻
  DS1302_write(0x00);    //禁止充电
  DS1302_cs=0;
  short_ds1302_delay();
  DS1302_clk=1;  
   
  DS1302_write_time(0x8e,0x80);    //禁止写操作
}

unsigned char DS1302_read_time(int command)
{
  uchar i;
  DS1302_clk=0;
  short_ds1302_delay();
  DS1302_cs=1;
  DS1302_write(command);
  DS1302_data=1;
  i=DS1302_read();
  DS1302_cs=0;
  short_ds1302_delay();
  DS1302_clk=1;
  return i;
}
unsigned int Read_Time()
{
  uchar i;
  DS1302_cs=0;

  //读取second
  i=DS1302_read_time(0x81);
  second=((i>>4)&0x07)*10+(i&0x0f);

  //读取分minute
  i=DS1302_read_time(0x83);
  minute=((i>>4)&0x07)*10+(i&0x0f);

  //读取时hour
  i=DS1302_read_time(0x85);
  hour=((i>>4)&0x03)*10+(i&0x0f);

  //读取日date
  i=DS1302_read_time(0x87);
  date=((i>>4)&0x03)*10+(i&0x0f);

  //读取月份month
  i=DS1302_read_time(0x89);
  month=((i>>4)&0x01)*10+(i&0x0f);

  //读取周week
  i=DS1302_read_time(0x8b);
  week=i&0x07;

  //读取年份year
  i=DS1302_read_time(0x8d);
  year=((i>>4)&0x0f)*10+(i&0x0f);
  return hour*100+minute;
}


void DS1302_write_time(int command,int dat)
{
  DS1302_clk=0;
  short_ds1302_delay();
  DS1302_cs=1;
  DS1302_write(command);
  DS1302_data=1;
  DS1302_write(dat);
  DS1302_cs=0;
  short_ds1302_delay();
  DS1302_clk=1;
}

void Write_Time(unsigned int time)
{

  minute=time%100;
  hour=time/100;
  second=0;
  DS1302_write_time(0x8e,0x00);    //允许写操作
  DS1302_cs=0;  
  DS1302_write_time(0x80,0x7f&(((second/10)<<4)+(second%10)));  //写second
  DS1302_write_time(0x82,0x7f&(((minute/10)<<4)+(minute%10)));  //minute 
  DS1302_write_time(0x84,0x3f&(((hour/10)<<4)+(hour%10)));  //hour
  DS1302_write_time(0x86,0x3f&(((date/10)<<4)+(date%10)));  //date
  DS1302_write_time(0x88,0x1f&(((month/10)<<4)+(month%10))); //month
  DS1302_write_time(0x8a,0x07&week); //week
  DS1302_write_time(0x8c,((year/10)<<4)+(year%10)); //year
  DS1302_write_time(0x8e,0x80);    //禁止写操作
}
