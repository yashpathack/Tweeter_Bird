#include<iostream.h>
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
{setviewport(5,30,getmaxx()-5,getmaxy()-85,1);

}
void Game :: object(int i, int x,int y,int x1,int y1)
{
bar(x-i,y,x1-i,y1);
}
void Game :: bird(int a,int b)
{
circle(a,b,30);
delay(25);
}


void main()
{int gm,gd=DETECT;
char ch;
Game ob;

initgraph(&gd,&gm,"c:\\turboc3\\bgi");
ob.frame();
viewport();
int m, x=getmaxx()-40,y=0,x1=getmaxx(),y1=150,x2=getmaxx()-40,y2=300,x3=getmaxx(),y3=getmaxx();
int a=100,b=0,d,s;
setcolor(3);
rectangle(0,0,getmaxx(),getmaxy());
clearviewport();
setfillstyle(5,1);
int i=0;
floodfill(1,1,3);
while(1)
{
ob.bird(a,b);
ob.object(i,x,y,x1,y1);
ob.object(i,x2,y2,x3,y3);
i++;
delay(40);
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
if(b==getmaxy()-159)
exit(0);
else if(x-i<=a+30 && x1-i>=a-30)
{

if(b-30>=0 && b+30<=y1 || b-25<=y1)
exit(0);
}

if(x1-i==0 && x3-i==0)
{ i=0;
}
}
getch();
closegraph();
}