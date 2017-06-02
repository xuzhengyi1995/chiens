//*****************Distance.h********************** 
#include <intrins.h>

void D_Delay()
{
     unsigned int i;
     for (i=0;i<60;i++);

}
unsigned int Get_Distance()
{
         unsigned int distance;
         unsigned int count;

         trig=0;
	     _nop_();_nop_();_nop_();_nop_();_nop_();
	     _nop_();_nop_();_nop_();_nop_();_nop_();
	     _nop_();_nop_();_nop_();_nop_();_nop_();
         //-------------------------------------------
	     trig=1;
	     _nop_();_nop_();_nop_();_nop_();_nop_();
	     _nop_();_nop_();_nop_();_nop_();_nop_();
	     _nop_();_nop_();_nop_();_nop_();_nop_();
	     trig=0;
         //-------------------------------------------
         while (!echo);
         count=0;
         while (echo){count++;}
         distance=count*1.029;
         return distance;
}

unsigned int Sure_Distance()
{
         int i;
         unsigned int s=0;
         for (i=0;i<10;i++)
         {
             s=s+Get_Distance();
             D_Delay();
         }
         return s/10;
}
