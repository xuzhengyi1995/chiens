//*****************Display.h********************** 

unsigned int Set_Time_1=1210,Set_Time_2=1800;
unsigned char How_Many=2;

void Delay_L()
{
     int i,j;
     for (i=0;i<200;i++)
         for (j=0;j<3000;j++);
}

void Display_Init()
{
     LCD_Clear_String();
     LCD_W_String(1,0,"时间：");
     LCD_W_String(2,0,"一投：");
     LCD_Write_Int(2,3,Set_Time_1/100);
     LCD_W_String(2,4,":");
     if (Set_Time_1%100==0) LCD_W_String(2,5,"00"); else LCD_Write_Int(2,5,Set_Time_1%100);
     LCD_W_String(3,0,"二投：");
     LCD_Write_Int(3,3,Set_Time_2/100);
     LCD_W_String(3,4,":");
     if (Set_Time_2%100==0) LCD_W_String(3,5,"00"); else LCD_Write_Int(3,5,Set_Time_2%100);
     LCD_W_String(4,0,"犬类型：");
     if (How_Many==1) LCD_W_String(4,4,"小型犬"); else if (How_Many==2) LCD_W_String(4,4,"中型犬"); else LCD_W_String(4,4,"大型犬");
}
 
void Set_Time_Display()
{
     LCD_Clear_String();
     LCD_W_String(1,0,"现在时间：");
     LCD_Write_Int(2,0,Read_Time()/100);
     LCD_W_String(2,2,":");
     if (Read_Time()%100==0) LCD_W_String(2,3,"00"); else LCD_Write_Int(2,3,Read_Time()%100);
     LCD_W_String(2,2,":");
     LCD_Write_Int(2,3,Read_Time()%100);
     LCD_W_String(3,0,"调整时间：");
}

void Set_Time_Check(unsigned int S_Time)
{
     LCD_Clear_String();
     if ((S_Time>2359)||(S_Time%100>59))
     {
                     LCD_W_String(1,0,"时间错误！");
                     Delay_L();
                     return;
     }
     else
     {
                     LCD_W_String(1,0,"设置成功！");
                     Write_Time(S_Time);
                     Delay_L();
                     return;
     }
}
     
void Set_Time(unsigned int Enter_Time)
{
     unsigned int x=1000,Set_Time=0;
     unsigned char s=0;
     Set_Time_Display();
     while(1)
     {
             if (Read_Time()-Enter_Time>1) return;
             if (s==2)
             {
                      s=s+1;
                      LCD_W_String(4,s,":");
             }
             row1=0;row2=1;row3=1;row4=1;  
             if(col1==0)
             {
                        delay_s(100);
                        if ((col1==0)&&(x>0)) 
                        {
                                     while(col1==0);
                                     Set_Time=Set_Time+1*x;
                                     x=x/10;
                                     s=s+1;
                                     LCD_W_String(4,s,"1");
                        }  
             }
             else if(col2==0)
             {
                        delay_s(100);
                        if ((col2==0)&&(x>0))  
                        {
                                     while(col2==0);
                                     Set_Time=Set_Time+2*x;
                                     x=x/10;
                                     s=s+1;
                                     LCD_W_String(4,s,"2");
                        } 
             }   
             else if(col3==0)
             {
                        delay_s(100);
                        if ((col3==0)&&(x>0))  
                        {
                                     while(col3==0);
                                     Set_Time=Set_Time+3*x;
                                     x=x/10;
                                     s=s+1;
                                     LCD_W_String(4,s,"3");
                        }
             }    
             
             row1=1;row2=0;row3=1;row4=1;  
             if(col1==0)
             {
                        delay_s(100);
                        if ((col1==0)&&(x>0)) 
                        {
                                     while(col1==0);
                                     Set_Time=Set_Time+4*x;
                                     x=x/10;
                                     s=s+1;
                                     LCD_W_String(4,s,"4");
                        } 
             }
             else if(col2==0)
             {
                        delay_s(100);
                        if ((col2==0)&&(x>0))  
                        {
                                     while(col2==0);
                                     Set_Time=Set_Time+5*x;
                                     x=x/10;
                                     s=s+1;
                                     LCD_W_String(4,s,"5");
                        } 
             }   
             else if(col3==0)
             {
                        delay_s(100);
                        if ((col3==0)&&(x>0))  
                        {
                                     while(col3==0);
                                     Set_Time=Set_Time+6*x;
                                     x=x/10;
                                     s=s+1;
                                     LCD_W_String(4,s,"6");
                        }
             } 
        
      
             row1=1;row2=1;row3=0;row4=1;  
             if(col1==0)
             {
                        delay_s(100);
                        if ((col1==0)&&(x>0)) 
                        {
                                     while(col1==0);
                                     Set_Time=Set_Time+7*x;
                                     x=x/10;
                                     s=s+1;
                                     LCD_W_String(4,s,"7");
                        } 
             }
             else if(col2==0)
             {
                        delay_s(100);
                        if ((col2==0)&&(x>0))  
                        {
                                     while(col2==0);
                                     Set_Time=Set_Time+8*x;
                                     x=x/10;
                                     s=s+1;
                                     LCD_W_String(4,s,"8");
                        } 
             }   
             else if(col3==0)
             {
                        delay_s(100);
                        if ((col3==0)&&(x>0))  
                        {
                                     while(col3==0);
                                     Set_Time=Set_Time+9*x;
                                     x=x/10;
                                     s=s+1;
                                     LCD_W_String(4,s,"9");
                        }
             }  
        
      
             row1=1;row2=1;row3=1;row4=0;  
             if(col1==0)
             {
                        delay_s(100);
                        if (col1==0) 
                        {
                                     while(col1==0);
                                     Set_Time_Check(Set_Time);
                                     return;
                        } 
             }
             else if(col2==0)
             {
                        delay_s(100);
                        if ((col2==0)&&(x>0))  
                        {
                                     while(col2==0);
                                     Set_Time=Set_Time+0*x;
                                     x=x/10;
                                     s=s+1;
                                     LCD_W_String(4,s,"0");
                        } 
             }   
             else if(col3==0)
             {
                        delay_s(100);
                        if (col3==0) 
                        {
                                     while(col3==0);
                                     return;                        
                        }
             }  
      }
}


void Set_Do_Display()
{
     LCD_Clear_String();
     LCD_W_String(1,0,"第一次喂食时间：");
     LCD_W_String(3,0,"第二次喂食时间：");
}

void Set_Do_Check(unsigned int SD_1,unsigned  int SD_2)
{
     LCD_Clear_String();
     if (SD_1>SD_2) {LCD_W_String(1,0,"不允许第一次时间");LCD_W_String(2,0,"早于第二次");Delay_L();return;}
     if (((SD_1>2359)||(SD_2>2359))||((SD_1%100>59)||(SD_2%100>59)))
     {
                     LCD_W_String(1,0,"时间错误！");
                     Delay_L();
                     return;
     }
     else
     {
                     LCD_W_String(1,0,"设置成功！");
                     Set_Time_1=SD_1;
                     Set_Time_2=SD_2;
                     Delay_L();
                     return;
     }
}

void Set_Do_Time(unsigned int Enter_Time)
{
     unsigned int x=1000,Set_Time_T_1=0,Set_Time_T_2=0,Set_Time=0;
     unsigned char s=0,s_1=2;
     Set_Do_Display();
     while(1)
     {
             if (Read_Time()-Enter_Time>1) return;
             if (s==5)
             {
                      if (s_1==2)
                      {
                                 Set_Time_T_1=Set_Time;
                                 Set_Time=0;
                                 x=1000;
                                 s_1=4;
                                 s=0;
                      }
                      else
                      {
                                 Set_Time_T_2=Set_Time;
                                 x=0;
                      }
             }
             if (s==2)
             {
                      s=s+1;
                      LCD_W_String(s_1,s,":");
             }
             row1=0;row2=1;row3=1;row4=1;  
             if(col1==0)
             {
                        delay_s(100);
                        if ((col1==0)&&(x>0)) 
                        {
                                     while(col1==0);
                                     Set_Time=Set_Time+1*x;
                                     x=x/10;
                                     s=s+1;
                                     LCD_W_String(s_1,s,"1");
                        }  
             }
             else if(col2==0)
             {
                        delay_s(100);
                        if ((col2==0)&&(x>0))  
                        {
                                     while(col2==0);
                                     Set_Time=Set_Time+2*x;
                                     x=x/10;
                                     s=s+1;
                                     LCD_W_String(s_1,s,"2");
                        } 
             }   
             else if(col3==0)
             {
                        delay_s(100);
                        if ((col3==0)&&(x>0))  
                        {
                                     while(col3==0);
                                     Set_Time=Set_Time+3*x;
                                     x=x/10;
                                     s=s+1;
                                     LCD_W_String(s_1,s,"3");
                        }
             }    
             
             row1=1;row2=0;row3=1;row4=1;  
             if(col1==0)
             {
                        delay_s(100);
                        if ((col1==0)&&(x>0)) 
                        {
                                     while(col1==0);
                                     Set_Time=Set_Time+4*x;
                                     x=x/10;
                                     s=s+1;
                                     LCD_W_String(s_1,s,"4");
                        } 
             }
             else if(col2==0)
             {
                        delay_s(100);
                        if ((col2==0)&&(x>0))  
                        {
                                     while(col2==0);
                                     Set_Time=Set_Time+5*x;
                                     x=x/10;
                                     s=s+1;
                                     LCD_W_String(s_1,s,"5");
                        } 
             }   
             else if(col3==0)
             {
                        delay_s(100);
                        if ((col3==0)&&(x>0))  
                        {
                                     while(col3==0);
                                     Set_Time=Set_Time+6*x;
                                     x=x/10;
                                     s=s+1;
                                     LCD_W_String(s_1,s,"6");
                        }
             } 
        
      
             row1=1;row2=1;row3=0;row4=1;  
             if(col1==0)
             {
                        delay_s(100);
                        if ((col1==0)&&(x>0)) 
                        {
                                     while(col1==0);
                                     Set_Time=Set_Time+7*x;
                                     x=x/10;
                                     s=s+1;
                                     LCD_W_String(s_1,s,"7");
                        } 
             }
             else if(col2==0)
             {
                        delay_s(100);
                        if ((col2==0)&&(x>0))  
                        {
                                     while(col2==0);
                                     Set_Time=Set_Time+8*x;
                                     x=x/10;
                                     s=s+1;
                                     LCD_W_String(s_1,s,"8");
                        } 
             }   
             else if(col3==0)
             {
                        delay_s(100);
                        if ((col3==0)&&(x>0))  
                        {
                                     while(col3==0);
                                     Set_Time=Set_Time+9*x;
                                     x=x/10;
                                     s=s+1;
                                     LCD_W_String(s_1,s,"9");
                        }
             }  
        
      
             row1=1;row2=1;row3=1;row4=0;  
             if(col1==0)
             {
                        delay_s(100);
                        if (col1==0) 
                        {
                                     while(col1==0);
                                     Set_Do_Check(Set_Time_T_1,Set_Time_T_2);
                                     return;
                        } 
             }
             else if(col2==0)
             {
                        delay_s(100);
                        if ((col2==0)&&(x>0))  
                        {
                                     while(col2==0);
                                     Set_Time=Set_Time+0*x;
                                     x=x/10;
                                     s=s+1;
                                     LCD_W_String(s_1,s,"0");
                        } 
             }   
             else if(col3==0)
             {
                        delay_s(100);
                        if (col3==0) 
                        {
                                     while(col3==0);
                                     return;                        
                        }
             }  
      }
}

void Rec_Do(unsigned int Enter_Time)
{
     LCD_Clear_String();
     LCD_W_String(1,0,"按确定录音，再次"); 
     LCD_W_String(2,0,"按确定停止！");
     LCD_W_String(4,0,"确定");
     LCD_W_String(4,6,"取消");
     while(1)
     {
             if (Read_Time()-Enter_Time>1) {Rec=0;return;}
             row1=1;row2=1;row3=1;row4=0; 
             if(col1==0)
             {
                        delay_s(100);
                        if (col1==0) 
                        {
                                     while(col1==0);
                                     Rec=~Rec;
                                     if (Rec==1) LCD_W_String(3,0,"录音中..."); else {LCD_W_String(3,0,"停止      ");Play=0;Play=1;Delay_L();return;}
                        } 
             }
             else if(col3==0)
             {
                        delay_s(100);
                        if (col3==0) 
                        {
                                     while(col3==0);
                                     return;                        
                        }
             }  
     } 
}


void Set_Do_Number(unsigned int Enter_Time)
{
     unsigned ht=2;
     LCD_W_String(1,0,"请选择犬的类型：");
     LCD_W_String(2,0,"１××小型犬××");
     LCD_W_String(3,0,"２××中型犬××");
     LCD_W_String(4,0,"３××大型犬××");
     LCD_W_String(How_Many+1,1,"▲→");
     LCD_W_String(How_Many+1,6,"←▲");
     while(1)
     {
             if (Read_Time()-Enter_Time>1) return;
             row1=0;row2=1;row3=1;row4=1; 
             if(col1==0)
             {
                        delay_s(100);
                        if (col1==0)
                        {
                                      while(col1==0);
                                      LCD_W_String(2,1,"▲→");
                                      LCD_W_String(2,6,"←▲");
                                      LCD_W_String(3,1,"××");
                                      LCD_W_String(3,6,"××");
                                      LCD_W_String(4,1,"××");
                                      LCD_W_String(4,6,"××");                                      
                                      ht=1;
                        }  
             }
             else if(col2==0)
             {
                  delay_s(100);
                  if (col2==0)
                  {
                                      while(col2==0);
                                      LCD_W_String(3,1,"▲→");
                                      LCD_W_String(3,6,"←▲");
                                      LCD_W_String(2,1,"××");
                                      LCD_W_String(2,6,"××");
                                      LCD_W_String(4,1,"××");
                                      LCD_W_String(4,6,"××"); 
                                      ht=2;
                  } 
             }   
             else if(col3==0)
             {
                  delay_s(100);
                  if (col3==0)
                  {
                                      while(col3==0);
                                      LCD_W_String(4,1,"▲→");
                                      LCD_W_String(4,6,"←▲");
                                      LCD_W_String(3,1,"××");
                                      LCD_W_String(3,6,"××");
                                      LCD_W_String(2,1,"××");
                                      LCD_W_String(2,6,"××"); 
                                      ht=3;
                  } 
             }     
     
             row1=1;row2=1;row3=1;row4=0; 
             if(col1==0)
             {
                        delay_s(100);
                        if (col1==0) 
                        {
                             How_Many=ht;
                             return;            
                        }
             }
             else if(col3==0)
             {
                  delay_s(100);
                  if (col3==0) 
                  {
                       while(col3==0);
                       return;                        
                  }
             }
     }  
}

void Give_Run_Display()
{
     LCD_Clear_String();
     LCD_W_String(1,0,"宠物到达！");
     LCD_W_String(2,0,"开始投食！");
} 
      
void Give_Display()
{
     LCD_Clear_String();
     LCD_W_String(1,0,"投食时间到！"); 
     LCD_W_String(2,0,"距离："); 
     LCD_W_String(3,0,"逝去时间："); 
     LCD_W_String(4,4,"分钟"); 
}
