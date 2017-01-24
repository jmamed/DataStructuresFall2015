#include <stdio.h>
void main ()
 {
    int temp,integer,count=0,i,cnd=0;
    char ascii[10]={0};
    printf("enter a number");
    scanf("%d",&integer);
     if(integer>>31)
     {
     /*CONVERTING 2's complement value to normal value*/
     integer=~integer+1;
     for(temp=integer;temp!=0;temp/=10,count++);
     ascii[0]=0x2D;
     count++;
     cnd=1;
     }
     else
     for(temp=integer;temp!=0;temp/=10,count++);
     for(i=count-1,temp=integer;i>=cnd;i--)
     {

        ascii[i]=(temp%10)+0x30;
        temp/=10;
     }
    printf("\n count =%d ascii=%s ",count,ascii);

 }
