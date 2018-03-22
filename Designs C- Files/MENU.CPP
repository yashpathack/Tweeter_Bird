#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<process.h>

void main()
{int gd=DETECT, gm;
int button=-1,x,y;
int n=4;
char ch;
int a=25,b[5]={-25,25,75,150,200};
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
menu();
showmouse();
viewport2();

while(1)
{
arrow(a,b,n);
delay(50);
clearviewport();
getmousepos(&button,&x,&y);
while(kbhit())
{ch=getch();
if(ch=='w')
{if(n==0)
n=4;
n--;
sound(200);
delay(100);
nosound();
}
else if(ch=='s')
{ if(n==4)
n=0;
n++;
sound(200);
delay(100);
nosound();

}
}

if(x>=200 && y>=150 && x<=400 && y<=185)
{if(button==1)
{button=-1;
exit(0);
}
}
else if(x>=210 && y>=205 && x<=490 && y<=245)
{
if( button==1)
{button=-1;
exit(0);
}
}
else if(x>=210 && y>=265 && x<=500 && y<=310)
{
if(button==1)
{button=-1;
exit(0);
}
}
else if(x>=220 && y>=325 && x<=485 && y<=370)
{if(button==1)
{button=-1;
exit(0);
}
}
else if(x>=255 && y>=380 && x<=450 && y<=475)
{if(button==1)
{button=-1;
exit(0);
}
}
else if(x>=580 && y>=10 && x<=620 && y<=50)
{if(button==1)
{button=-1;
exit(0);
}
}

}
getch();
closegraph();
}