#include<graphics.h>
#include<dos.h>
#include<conio.h>
#include<dos.h>
#include<stdio.h>
#include<process.h>
void loading(int &n,int n1[4],int &j,int p[8],int k)
{ int  x=300,y=425,a=0,b=300;
char str[50];
setcolor(n1[j]);
if(b-n<0)
{n=-n;
j++;
if(j==4)
j=0;
}
//Loading Animation
arc(x,y,a-n,b-n,30);
arc(x,y,a-n,b-n,31);
arc(x,y,a-n,b-n,32);
arc(x,y,a-n,b-n,33);
arc(x,y,a-n,b-n,34);
//Percentage
setcolor(3);
settextstyle(4,0,2);
sprintf(str,"%d%",k);
outtextxy(280,410,str);
//Powered By
settextstyle(4,0,2);
outtextxy(450,325,"Powered By Ucreanto");
}
void main()
{int gd=DETECT,gm;
int n1[4]={12,11,2,14};
int i=0,j=0,k=0;
char ch;
int p[8]={0,10,30,45,50,60,80,100};
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
while(1)
{
loading(i,n1,j,p,k);
delay(40);
i=i+10;
k++;
clearviewport();
while(kbhit())
{ch=getch();
}
if(ch=='x')
exit(0);
}
getch();
closegraph();
}