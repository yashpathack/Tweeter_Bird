#include<iostream.h>
#include<stdlib.h>
#include<process.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
//Game class contains frame function,object function
class Game
{
public:
void frame()
{
setcolor(3);
rectangle(0,0,640,480);
setfillstyle(2,1);
floodfill(1,1,3);
setcolor(2);
rectangle(0,0,640,25);
rectangle(0,450,640,480);
setfillstyle(11,3);
floodfill(1,1,2);
floodfill(1,451,2);
setfillstyle(11,3);

setcolor(8);
rectangle(0,400,640,450);
setfillstyle(8,7);
floodfill(4,402,8);
  }
  void object(int i, int x, int y, int x1, int y1);
  void bird(int a,int b);
};
void viewport()
{setviewport(5,30,getmaxx()-5,getmaxy()-90,1);

}
void Game :: object(int i, int x,int y,int x1,int y1)
{
rectangle(x-i,y,x1-i,y1);
}
void Game :: bird(int a,int b)
{
circle(a,b,30);
delay(25);
}


void main()

{     randomize();
int gm,gd=DETECT;
char ch;
Game ob,ob1;


initgraph(&gd,&gm,"c:\\turboc3\\bgi");
ob.frame();
viewport();
int x=getmaxx()-40,y=0,x1=getmaxx(),y1=150;
int x2=getmaxx()-40,y2=y1+170,x3=getmaxx(),y3=getmaxy();
int x4=getmaxx()-400,y4=0,x5=getmaxx()-360,y5=150;
int x6=getmaxx()-400,y6=y5+170,x7=getmaxx()-360,y7=getmaxy();
int a=100,b=0;
setcolor(3);
rectangle(0,0,getmaxx(),getmaxy());
clearviewport();
setfillstyle(5,1);
int i=0,j=0;
floodfill(1,1,3);
while(1)
{
ob.bird(a,b);
ob.object(i,x,y,x1,y1);
ob.object(i,x2,y2,x3,y3);
i++;
ob1.object(j,x4,y4,x5,y5);
ob1.object(j,x6,y6,x7,y7);
j++;
delay(20);
clearviewport();
if(!kbhit())
{
b=b+4;
}
while(kbhit())
{
ch=getch();
if(ch=='x')
{exit(0);
}
else if(ch=='w')
{b=b-14;
}
}
if(b==getmaxy()-25)
{exit(0);
}
 if(x1-i==0 && x3-i==0)
{ i=0;
y1=random(225);
y2=y1+170;
}
}
 if(x5-j==0 && x7-j==0)
{ j=0;
y5=random(225);
y6=y5+170;

}
getch();
closegraph();
}