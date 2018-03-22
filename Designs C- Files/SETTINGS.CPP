#include<iostream.h>
#include<conio.h>
#include<graphics.h>
void backbutton()
{int x[4]={25,50,50,25};
int y[4]={50,25,75,50};
int cords[]={x[0],y[0],x[1],y[1],x[2],y[2],x[3],y[3]};

setfillstyle(2,12);
fillpoly(4,cords);
}
void exitbutton()
{
//Exit button
setcolor(4);
circle(600,30,20);
setfillstyle(1,4);
floodfill(600,30,4);

setcolor(14);
settextstyle(4,0,5);
outtextxy(587,4,"X");
}

void settings()
{int u[40]={215,500,475,200,215,200,515,515,200,200,205,510,510,205,205,400,450,450,400,400,455,505,505,455,455,205,510,510,205,205,205,510,510,205,205,400,490,490,400,400};
int v[40]={50,50,100,100,50,125,125,375,375,125,150,150,200,200,150,155,155,195,195,155,155,155,195,195,155,210,210,260,260,210,270,270,320,320,270,350,350,370,370,350};

int cords[]={u[0],v[0],u[1],v[1],u[2],v[2],u[3],v[3],u[4],v[4]};
int cords1[]={u[5],v[5],u[6],v[6],u[7],v[7],u[8],v[8],u[9],v[9]};
int cords2[]={u[10],v[10],u[11],v[11],u[12],v[12],u[13],v[13],u[14],v[14]};
int cords3[]={u[15],v[15],u[16],v[16],u[17],v[17],u[18],v[18],u[19],v[19]};
int cords4[]={u[20],v[20],u[21],v[21],u[22],v[22],u[23],v[23],u[24],v[24]};
int cords5[]={u[25],v[25],u[26],v[26],u[27],v[27],u[28],v[28],u[29],v[29]};
int cords6[]={u[30],v[30],u[31],v[31],u[32],v[32],u[33],v[33],u[34],v[34]};
int cords7[]={u[35],v[35],u[36],v[36],u[37],v[37],u[38],v[38],u[39],v[39]};

setcolor(1);
setfillstyle(2,1);
floodfill(5,5,1);
rectangle(0,0,getmaxx(),getmaxy());
setfillstyle(1,14);
bar(5,450,635,475);

//Settings
setcolor(3);
setlinestyle(0,1,3);
setfillstyle(1,3);
fillpoly(5,cords);

setcolor(1);
settextstyle(1,0,6);
outtextxy(250,38,"Settings");

//Menu outerbody(rectangle)
setcolor(7);
setfillstyle(1,7);
fillpoly(5,cords1);

//Menu Innerbody
//Sound(outer body)
setcolor(8);
setfillstyle(1,8);
fillpoly(5,cords2);

setcolor(14);
settextstyle(1,0,5);
outtextxy(215,150,"Sound");

//Sound(Inner body)(ON Button)
setcolor(10);
setfillstyle(1,10);
fillpoly(5,cords3);

setcolor(4);
settextstyle(1,0,4);
outtextxy(405,155,"On");

//Sound(Inner body)(OFF Button)
setcolor(7);
setfillstyle(1,7);
fillpoly(5,cords4);

setcolor(4);
settextstyle(1,0,4);
outtextxy(460,155,"Off");

//Difficulty Mode
setcolor(8);
setfillstyle(1,8);
fillpoly(5,cords5);

setcolor(14);
settextstyle(1,0,5);
outtextxy(205,210,"Difficulty Mode");

//Design Mode
setcolor(8);
setfillstyle(1,8);
fillpoly(5,cords6);

setcolor(14);
settextstyle(1,0,5);
outtextxy(215,270,"Design Mode");

//Save
setcolor(3);
setcolor(4);
setfillstyle(1,12);
fillpoly(5,cords7);

setcolor(1);
settextstyle(1,0,3);
outtextxy(420,345,"Save");

backbutton();
exitbutton();
}
void main()
{int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
settings();
getch();
closegraph();
}