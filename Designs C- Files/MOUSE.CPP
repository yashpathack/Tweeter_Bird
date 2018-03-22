#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<process.h>
#include<stdio.h>
union REGS i,o;
void detectmouse()
{i.x.ax=0;
int86(0x33,&i,&o);
if(o.x.ax==0)
{cout<<"Mouse failed to initialise";
}
else
{cout<<"Mouse sucessfully initialise";
}
}
void Showmouse()
{
i.x.ax=1;
int86(0x33,&i,&o);
}
void getmousepos(int *button,int *x,int *y)
{i.x.ax=3;
int86(0x33,&i,&o);
*button = o.x.bx;
*x=o.x.cx;
*y=o.x.dx;
}
void write(char x[20])
{
rectangle(100,50,300,100);
outtextxy(120,60,x);
}
void viewport()
{setviewport(102,52,getmaxx()-342,getmaxy()-382,1);
}
void main()
{int gd=DETECT,gm;
char array[20]={"what's up"};
int button,x,y,i=0;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
detectmouse();
Showmouse();
setcolor(1);
write(array);
while(!kbhit())
{getmousepos(&button,&x,&y);
if(button==1 && x>=100 && x<=300 && y<=100 && y>=50)
{
//viewport();
restorecrtmode();
cout<<"enter your name"<<endl;
cin>>array;
setgraphmode(getgraphmode());
write(array);


}
}
getch();
closegraph();
}