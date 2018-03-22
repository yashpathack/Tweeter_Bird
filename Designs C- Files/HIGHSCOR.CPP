#include<iostream.h>
#include<graphics.h>
#include<conio.h>
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
void Highscore()
{int d[22]={150,500,500,150,150,175,475,475,175,175,50,125,170,170,125,50,600,525,480,480,525,600};
int s[22]={50,50,95,95,50,100,100,400,400,100,250,100,100,400,400,250,250,400,400,100,100,250};
int cords[]={d[0],s[0],d[1],s[1],d[2],s[2],d[3],s[3],d[4],s[4]};
int cords1[]={d[5],s[5],d[6],s[6],d[7],s[7],d[8],s[8],d[9],s[9]};
int cords2[]={d[10],s[10],d[11],s[11],d[12],s[12],d[13],s[13],d[14],s[14],d[15],s[15]};
int cords3[]={d[16],s[16],d[17],s[17],d[18],s[18],d[19],s[19],d[20],s[20],d[21],s[21]};

setcolor(1);
setlinestyle(0,1,3);
setfillstyle(2,1);
floodfill(5,5,1);
rectangle(0,0,getmaxx(),getmaxy());
setfillstyle(1,14);
bar(5,450,635,475);

//Highscore
setcolor(1);
setlinestyle(0,0,3);
setfillstyle(1,14);
fillpoly(5,cords);

setcolor(1);
settextstyle(1,0,5);
outtextxy(220,45,"HighScore");

//Score Board
setcolor(1);
setfillstyle(1,7);
fillpoly(5,cords1);
/* //left pentagon
setfillstyle(2,3);
fillpoly(6,cords2);
//Right pentagon
setfillstyle(2,3);
fillpoly(6,cords3);
*/
backbutton();
exitbutton();
}
void main()
{int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
Highscore();
getch();
closegraph();
}