#include<iostream.h>
#include<graphics.h>
#include<conio.h>
void main()
{int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
int x[50]={100,100,94,104,85,74,94,121,114,110,121,120,115,115,120,113,123,125,115,113};;
int y[50]= {235,215,222,227,243,230,222,217,222,212,217,217,220,215,217,232,230,235,240,232};
int cords[]={x[2],y[2],x[3],y[3],x[4],y[4],x[5],y[5],x[6],y[6]};
int cords1[]={x[7],y[7],x[8],y[8],x[9],y[9],x[10],y[10]};
int cords2[]={x[11],y[11],x[12],y[12],x[13],y[13],x[14],y[14]};
int cords3[]={x[15],y[15],x[16],y[16],x[17],y[17],x[18],y[18],x[19],y[19]};
//Body
setcolor(6);
arc(x[0],y[0],10,165,35);
arc(x[1],y[1],195,350,35);
setfillstyle(2,6);
floodfill(102,222,6);
//WINGS
setcolor(2);
drawpoly(5,cords);
setfillstyle(6,14);
floodfill(96,233,2);
//eye
drawpoly(4,cords1);
setfillstyle(1,1);
floodfill(118,217,2);
//pupil
setcolor(3);
fillpoly(4,cords2);
setfillstyle(1,1);
floodfill(119,217,3);
//mouth
drawpoly(5,cords3);
setfillstyle(1,4);
floodfill(120,233,3);
getch();
closegraph();
}