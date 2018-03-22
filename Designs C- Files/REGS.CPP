#include<iostream.h>
#include<graphics.h>
#include<conio.h>
void registration()
{//Outer body
setcolor(9);
setfillstyle(2,1);
bar3d(100,100,550,350,6,1);
//Inner body
//Search your name(x,y)
setcolor(3);
rectangle(250,160,535,200);
setfillstyle(2,11);
floodfill(255,162,3);
//enter your name
setcolor(3);
rectangle(250,285,530,325);
setfillstyle(2,11);
floodfill(255,286,3);
//save button
setcolor(12);
setfillstyle(2,4);
bar3d(400,360,500,385,3,1);
//help button(circles)
//Outer circle
setcolor(2);
circle(135,135,20);
setfillstyle(7,2);
floodfill(135,135,2);
//Inner circe()
setcolor(12);
circle(135,135,10);
setfillstyle(1,12);
floodfill(135,135,12);

}
void main()
{int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
registration();
getch();
closegraph();
}