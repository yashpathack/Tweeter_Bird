#include<graphics.h>
#include<conio.h>
#include<dos.h>
void updownbutton()
{
setcolor(0);
settextstyle(10,1,7);
outtextxy(420,100,">");

setcolor(0);
settextstyle(10,1,7);
outtextxy(420,330,"<");
}
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

void About()
{setcolor(1);
setfillstyle(2,1);
floodfill(5,5,1);
rectangle(0,0,getmaxx(),getmaxy());
setfillstyle(1,14);
bar(5,450,635,475);

//Upper roller (rectangle)
setcolor(9);
rectangle(100,50,550,90);
setfillstyle(2,3);
floodfill(101,51,9);

//Elipse1(upperleft)
setcolor(4);
ellipse(100,70,0,360,10,20);
setfillstyle(7,12);
floodfill(101,71,4);

//Ellipse2(upper right)
ellipse(550,70,0,360,10,20);
setfillstyle(7,12);
floodfill(551,71,4);

//Middle Rectangle(sheet)
setcolor(7);
setlinestyle(0,1,3);
rectangle(100,93,550,387);
setfillstyle(1,7);
floodfill(200,100,7);

//Bottom Rectangle(Bottom roller)
setcolor(9);
setlinestyle(0,1,1);
rectangle(100,390,550,410);
setfillstyle(2,3);
floodfill(101,391,9);

//Ellipse3(Bottom left)
setcolor(4);
ellipse(100,400,0,360,5,10);
setfillstyle(7,12);
floodfill(102,402,4);
//Ellipse4(Bottom Right)
setcolor(4);
ellipse(550,400,0,360,5,10);
setfillstyle(7,12);
floodfill(552,402,4);

setcolor(9);
settextstyle(1,0,7);
outtextxy(250,100,"Help");

updownbutton();
backbutton();
exitbutton();

}
void main()
{int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
About();
getch();
closegraph();
}