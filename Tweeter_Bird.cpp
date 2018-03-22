#include<fstream.h>
#include<conio.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<string.h>
#include<graphics.h>

union REGS i,o;
void showmouse()
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
//----------------------------------------------------------
class object
{
int x[20],y[20];
public:
void bird(int x[],int y[],int &p,int &a1,int &b);
void dbox();
};
//----------------------------------------------------------
void thank()
{setcolor(2);
settextstyle(4,0,9);
outtextxy(100,50,"Thank You");
outtextxy(100,150,"For Playing");
outtextxy(100,250,"This Game.");
}
//----------------------------------------------------------
void registration(char x[])
{//Outer body
setcolor(9);
setfillstyle(2,1);
bar3d(100,100,550,240,6,1);
//Inner body
//Search your name(x,y)
setcolor(3);
setfillstyle(1,11);
bar(250,160,535,200);
setcolor(2);
settextstyle(4,0,4);
outtextxy(250,110,"Enter your name");

setcolor(0);
settextstyle(4,0,3);

outtextxy(250,160,x);
//save button
setcolor(12);
setfillstyle(1,4);
bar3d(400,250,500,275,3,1);
setcolor(1);
settextstyle(1,0,4);
outtextxy(420,241,"Save");


}

 /*--------------------------- load function --------------------------*/
void load()
{
   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");

   errorcode = graphresult();
   if (errorcode != grOk)
   { clrscr();
   printf("GRAPHICS ERROR: %s\n", grapherrormsg(errorcode));
   printf(" PRESS ANY KEY TO EXIT or RESTART THE PROGRAME.");
   getch();
   }
}

//----------------------------------------------------------
void viewport()
{
setviewport(5,15,getmaxx()-5,getmaxy()-15,1);
}
//----------------------------------------------------------
void viewport1()
{setviewport(150,360,getmaxx()-189,getmaxy()-5,1);
}
//----------------------------------------------------------
void viewport2()
{setviewport(125,150,getmaxx()-464,getmaxy()-54,1);
}
//----------------------------------------------------------
void viewport3()
{setviewport(0,0,getmaxx(),getmaxy(),1);
clearviewport();
}
//----------------------------------------------------------
void viewport4()
{setviewport(105,100,getmaxx()-94,getmaxy()-95,1);
}
//----------------------------------------------------------
void Play();
void Rabout();
void Rhelp();
void Menuscreen();
//----------------------------------------------------------
void enter()
{
ofstream fw;
fw.open("name.txt");
char array[20]={"Please click here"};
int button,x,y,i=0;
showmouse();
setcolor(1);
registration(array);
while(1)
{
while(!kbhit())
{s:
getmousepos(&button,&x,&y);
if(x>=250 && y>=160 && x<=535 && y<=200)
{if(button==1)
{button=-1;
sound(200);
delay(50);
nosound();
restorecrtmode();
cout<<"enter your name"<<endl;
cin>>array;
setgraphmode(getgraphmode());
registration(array);
showmouse();
sound(200);
delay(50);
nosound();
goto s;
}
}

else if(x>=400 && y>=250 && x<=500 && y<=275)
{
if( button==1)
{button=-1;
fw<<array;
sound(200);
delay(50);
nosound();
goto x;
}
}

}
}
x:
}
void e()
{
viewport3();
clearviewport();
enter();
}
//----------------------------------------------------------
void s(int i,int a[])
{ sound(a[i]);
delay(200);
nosound();
}
//----------------------------------------------------------
void soundo()
{randomize();
int i,j;
int a[6]={20,300,30,400,500,800};
for(i=0;i<=2;i++)
{
for(j=0;j<=5;j++)
{
 s(j,a);
}
}
for(i=2;i>=0;i--)
{
for(j=5;j>=0;j--)
{
 s(j,a);
}
}
}
//----------------------------------------------------------
void frame()
{//frame
setfillstyle(2,1);
bar(0,0,640,480);
}
//----------------------------------------------------------
void backbutton()
{int x[4]={25,50,50,25};
int y[4]={50,25,75,50};
int cords[]={x[0],y[0],x[1],y[1],x[2],y[2],x[3],y[3]};

setfillstyle(2,12);
fillpoly(4,cords);
}
//----------------------------------------------------------
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
//----------------------------------------------------------
void gbox()
{setfillstyle(5,3);
bar(25,150,450,400);
setfillstyle(1,7);
bar(50,175,425,375);
setcolor(1);
settextstyle(4,0,5);
outtextxy(150,175,"Get Ready!");
setcolor(1);
settextstyle(1,0,4);
outtextxy(110,250,"Press and hold 'W'");
outtextxy(110,280,"key to move up.");
outtextxy(110,325,"Press W to START");
}
//----------------------------------------------------------
void updownbutton()
{
setcolor(0);
settextstyle(10,1,7);
outtextxy(300,0,">");

setcolor(0);
settextstyle(10,1,7);
outtextxy(300,235,"<");
}
//----------------------------------------------------------
void Bar()
{
setfillstyle(1,7);
bar(0,0,getmaxx(),getmaxy());
}
//----------------------------------------------------------
void help()
{
setcolor(4);
settextstyle(1,0,7);
outtextxy(150,0,"Help");
setcolor(1);
settextstyle(4,0,4);
outtextxy(5,75,"Objective:");
setcolor(0);
settextstyle(1,0,2);
outtextxy(2,110,"Fly and cross obstacles to make highscore.");
setcolor(1);
settextstyle(4,0,4);
outtextxy(5,150,"How To Play:");
setcolor(0);
settextstyle(1,0,2);
outtextxy(5,190,"Press and hold ' W ' to move up.");
outtextxy(5,210,"Release key to come down.");
}
//----------------------------------------------------------
void About()
{
setcolor(1);
setfillstyle(2,1);
floodfill(5,5,1);
rectangle(0,0,getmaxx(),getmaxy());
setfillstyle(1,14);
bar(0,460,639,479);
setcolor(1);
settextstyle(2,0,5);
outtextxy(10,460,"To go Back to the menu screen press B respectively");
outtextxy(400,460,"// To Exit from game press X ");

//Upper roller (rectangle)
setlinestyle(0,1,1);
setfillstyle(2,3);
bar(100,50,550,90);

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
setfillstyle(2,3);
bar(100,390,550,410);

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


backbutton();
exitbutton();
}
//----------------------------------------------------------
void about()
{setcolor(3);
settextstyle(4,0,7);
outtextxy(125,0,"About");
setcolor(0);
settextstyle(1,0,1);
outtextxy(5,100,"This  game  'Tweeter Bird'  designed  and");
outtextxy(5,125,"programmed by Sumit Sharma is an graphics");
outtextxy(5,150,"animated game.This game is about a bird who");
outtextxy(5,175,"has to cross the obstacles(the walls) during his");
outtextxy(5,200,"flying. It is an interesting fun game.This short");
outtextxy(5,225,"featured game may be played by the children");
outtextxy(5,250,"their relaxation time.");
}
//----------------------------------------------------------
void arrow(int &x,int y[],int &n)
{
setcolor(14);
settextstyle(10,0,5);
outtextxy(x,y[n],">");
}
//----------------------------------------------------------
void loading(int &n,int n1[4],int &j,int k)
{ int  x=150,y=75,a=0,b=300;
char str[50];
setcolor(n1[j]);
if(b-n<0)
{n=-n;
j++;
if(j==4)
j=0;
}
//Loading Animation
setlinestyle(0,1,1);
arc(x,y,a-n,b-n,30);
arc(x,y,a-n,b-n,31);
arc(x,y,a-n,b-n,32);
arc(x,y,a-n,b-n,33);
arc(x,y,a-n,b-n,34);
//Percentage
setcolor(3);
settextstyle(4,0,2);
sprintf(str,"%d%",k);
outtextxy(130,60,str);
}
//----------------------------------------------------------
void Starting()
{
int x[131]={50,150,150,115,115,85,85,50,50,165,165,180,180,200,200,215,215,230,230,150,150,165,250,295,295,260,260,285,285,260,260,295,295,250,250,315,360,360,325,325,350,350,325,325,360,360,315,315,375,475,475,440,440,410,410,375,375,490,535,535,500,500,525,525,500,500,535,535,490,490,550,610,610,565,615,600,565,565,550,550,560,600,560,560,150,225,225,155,225,225,150,150,160,210,210,160,160,160,210,210,160,160,250,275,275,250,250,300,365,365,315,390,365,315,315,300,300,310,355,310,310,400,475,475,400,400,415,450,450,415,415};
int y[131]={50,50,75,75,175,175,75,75,50,100,160,160,125,125,160,160,100,100,175,175,100,100,75,75,90,90,120,120,135,135,160,160,175,175,75,75,75,90,90,120,120,135,135,160,160,175,175,75,50,50,75,75,175,175,75,75,50,75,75,90,90,120,120,135,135,160,160,175,175,75,75,75,125,125,175,175,135,175,175,75,85,85,115,85,225,225,265,275,285,325,325,225,235,235,260,270,235,285,295,315,315,285,225,225,325,325,225,225,225,275,275,325,325,285,325,325,225,235,235,260,235,225,250,300,325,225,250,250,300,300,250};

int cords[]={x[0],y[0],x[1],y[1],x[2],y[2],x[3],y[3],x[4],y[4],x[5],y[5],x[6],y[6],x[7],y[7],x[8],y[8]};
int cords1[]={x[9],y[9],x[10],y[10],x[11],y[11],x[12],y[12],x[13],y[13],x[14],y[14],x[15],y[15],x[16],y[16],x[17],y[17],x[18],y[18],x[19],y[19],x[20],y[20],x[21],y[21]};
int cords2[]={x[22],y[22],x[23],y[23],x[24],y[24],x[25],y[25],x[26],y[26],x[27],y[27],x[28],y[28],x[29],y[29],x[30],y[30],x[31],y[31],x[32],y[32],x[33],y[33],x[34],y[34]};
int cords3[]={x[35],y[35],x[36],y[36],x[37],y[37],x[38],y[38],x[39],y[39],x[40],y[40],x[41],y[41],x[42],y[42],x[43],y[43],x[44],y[44],x[45],y[45],x[46],y[46],x[47],y[47]};
int cords4[]={x[48],y[48],x[49],y[49],x[50],y[50],x[51],y[51],x[52],y[52],x[53],y[53],x[54],y[54],x[55],y[55],x[56],y[56]};
int cords5[]={x[57],y[57],x[58],y[58],x[59],y[59],x[60],y[60],x[61],y[61],x[62],y[62],x[63],y[63],x[64],y[64],x[65],y[65],x[66],y[66],x[67],y[67],x[68],y[68],x[69],y[69]};
int cords6[]={x[70],y[70],x[71],y[71],x[72],y[72],x[73],y[73],x[74],y[74],x[75],y[75],x[76],y[76],x[77],y[77],x[78],y[78],x[79],y[79]};
int cords7[]={x[80],y[80],x[81],y[81],x[82],y[82],x[83],y[83]};
int cords8[]={x[84],y[84],x[85],y[85],x[86],y[86],x[87],y[87],x[88],y[88],x[89],y[89],x[90],y[90],x[91],y[91]};
int cords9[]={x[92],y[92],x[93],y[93],x[94],y[94],x[95],y[95],x[96],y[96]};
int cords10[]={x[97],y[97],x[98],y[98],x[99],y[99],x[100],y[100],x[101],y[101]};
int cords11[]={x[102],y[102],x[103],y[103],x[104],y[104],x[105],y[105],x[106],y[106]};
int cords12[]={x[107],y[107],x[108],y[108],x[109],y[109],x[110],y[110],x[111],y[111],x[112],y[112],x[113],y[113],x[114],y[114],x[115],y[115],x[116],y[116]};
int cords13[]={x[117],y[117],x[118],y[118],x[119],y[119],x[120],y[120]};
int cords14[]={x[121],y[121],x[122],y[122],x[123],y[123],x[124],y[124],x[125],y[125]};
int cords15[]={x[126],y[126],x[127],y[127],x[128],y[128],x[129],y[129],x[130],y[130]};
//T1
setcolor(4);
setlinestyle(0,1,3);
drawpoly(9,cords);
setfillstyle(5,12);
floodfill(100,100,4);
delay(100);
//W
setcolor(1);
drawpoly(13,cords1);
setfillstyle(4,9);
floodfill(225,150,1);
delay(100);
//E1
setcolor(2);
drawpoly(13,cords2);
setfillstyle(5,10);
floodfill(275,125,2);
delay(100);
//E2
drawpoly(13,cords3);
setfillstyle(5,10);
floodfill(325,125,2);
delay(100);
//T2
setcolor(4);
drawpoly(9,cords4);
setfillstyle(5,12);
floodfill(425,100,4);
delay(100);
//E3
setcolor(2);
drawpoly(13,cords5);
setfillstyle(5,10);
floodfill(500,125,2);
delay(100);
//R1 Outer body
setcolor(14);
drawpoly(10,cords6);
//R1 Inner body
drawpoly(4,cords7);
setfillstyle(2,14);
floodfill(600,100,14);
setcolor(11);
delay(100);
//B Outer body
drawpoly(8,cords8);
//B Inner body(1)
drawpoly(5,cords9);
setfillstyle(5,11);
floodfill(220,250,11);
//B Inner body(2)
drawpoly(5,cords10);
setfillstyle(5,11);
floodfill(220,300,11);
delay(100);
//I
setcolor(12);
drawpoly(5,cords11);
setfillstyle(5,4);
floodfill(270,250,12);
delay(100);
//R2 Outer body
setcolor(14);
drawpoly(10,cords12);
//R2 Inner body
drawpoly(4,cords13);
setfillstyle(2,14);
floodfill(350,250,14);
delay(100);
//D Outer body
setcolor(5);
drawpoly(5,cords14);
//D Inner body
drawpoly(5,cords15);
setfillstyle(2,13);
floodfill(425,310,5);
//Powered By
setcolor(11);
settextstyle(1,0,2);
outtextxy(425,325,"Powered By Ucreanto");

}
//----------------------------------------------------------
void Highscore()
{char ch;
int x,y,button=-1;
int d[22]={150,500,500,150,150,175,475,475,175,175,50,125,170,170,125,50,600,525,480,480,525,600};
int s[22]={50,50,95,95,50,100,100,400,400,100,250,100,100,400,400,250,250,400,400,100,100,250};
int cords[]={d[0],s[0],d[1],s[1],d[2],s[2],d[3],s[3],d[4],s[4]};
int cords1[]={d[5],s[5],d[6],s[6],d[7],s[7],d[8],s[8],d[9],s[9]};
frame();

viewport3();
clearviewport();
setcolor(1);
setlinestyle(0,1,3);
setfillstyle(2,1);
floodfill(5,5,1);
rectangle(0,0,getmaxx(),getmaxy());
setfillstyle(1,14);
bar(0,460,639,479);
setcolor(1);
settextstyle(2,0,5);
outtextxy(10,460,"To go Back to the menu screen press B respectively");
outtextxy(400,460,"// To Exit from game press X ");

//Highscore
setcolor(1);
setlinestyle(0,0,3);
setfillstyle(1,14);
fillpoly(5,cords);

setcolor(1);
settextstyle(4,0,5);
outtextxy(220,45,"HighScore");

//Score Board
setcolor(1);
setfillstyle(1,7);
fillpoly(5,cords1);

setcolor(4);
settextstyle(1,0,4);
outtextxy(200,100,"Name");

setcolor(4);
settextstyle(1,0,4);
outtextxy(375,100,"Score");

backbutton();
exitbutton();

while(1)
{
while(kbhit())
{ch=getch();
if(ch=='x')
exit(0);
else if(ch=='b')
{
sound(200);
delay(100);
nosound();
viewport3();
clearviewport();
Menuscreen();
}
}

while(!kbhit())
{
getmousepos(&button,&x,&y);
if(x>=25 && y>=25 && x<=50 && y<=75)
{if(button==1)
{button=-1;
viewport3();
clearviewport();
sound(200);
delay(100);
nosound();
Menuscreen();
}
}
else if(x>=580 && y>=10 && x<=620 && y<=50)
{if(button==1)
{button=-1;
sound(200);
delay(100);
nosound();
exit(0);
}
}
}

}

}
//----------------------------------------------------------
void menu()
{int a[30]={210,510,480,215,210,200,500,470,215,200,210,465,490,205,210,210,465,500,200,210,220,460,485,210,220,253,450,440,280,255};
int b[30]={50,50,105,90,50,150,150,195,185,150,205,205,245,240,205,265,265,310,305,265,325,330,360,370,325,380,375,415,430,380};
int cords1[]={a[5],b[5],a[6],b[6],a[7],b[7],a[8],b[8],a[9],b[9]};
int cords2[]={a[10],b[10],a[11],b[11],a[12],b[12],a[13],b[13],a[14],b[14]};
int cords3[]={a[15],b[15],a[16],b[16],a[17],b[17],a[18],b[18],a[19],b[19]};
int cords4[]={a[20],b[20],a[21],b[21],a[22],b[22],a[23],b[23],a[24],b[24]};
int cords5[]={a[25],b[25],a[26],b[26],a[27],b[27],a[28],b[28],a[29],b[29]};
setcolor(1);
setlinestyle(0,1,3);
setfillstyle(2,1);
floodfill(5,5,1);
rectangle(0,0,getmaxx(),getmaxy());
//Down dialog box
setfillstyle(1,14);
bar(0,460,639,479);
setcolor(1);
settextstyle(2,0,5);
outtextxy(10,460,"To Move UP or DOWN press W or S respectively");
outtextxy(360,460,"// To Enter any option press E");


//Tweeter Bird
setcolor(11);
settextstyle(4,0,8);
outtextxy(110,35,"Tweeter Bird");

//Continue
setcolor(6);
setfillstyle(1,9);
setlinestyle(0,1,3);
fillpoly(5,cords1);

setcolor(14);
settextstyle(8,0,5);
outtextxy(240,140,"Continue");

//Newgame
setcolor(6);
setfillstyle(1,3);
setlinestyle(0,1,3);
fillpoly(5,cords2);

setcolor(14);
settextstyle(8,0,5);
outtextxy(240,187,"Newgame");

//High score
setcolor(6);
setfillstyle(1,3);
setlinestyle(0,1,3);
fillpoly(5,cords3);

setcolor(14);
settextstyle(8,0,5);
outtextxy(240,250,"HighScore");

//Help
setcolor(6);
setfillstyle(1,3);
setlinestyle(0,1,3);
fillpoly(5,cords4);

setcolor(14);
settextstyle(8,0,5);
outtextxy(290,310,"Help");

//About
setcolor(6);
setfillstyle(1,11);
setlinestyle(0,1,3);
fillpoly(5,cords5);

setcolor(14);
settextstyle(8,0,5);
outtextxy(300,365,"About");

exitbutton();
}
//----------------------------------------------------------
void Menuscreen()
{int button=-1,x,y;
int n=1;
char ch=NULL;
int a=25,b[5]={-25,25,75,150,200};
menu();
showmouse();
viewport2();

while(1)
{
arrow(a,b,n);
delay(50);
clearviewport();
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
else if(ch=='x')
{
sound(200);
delay(100);
nosound();
exit(0);
}

if(n==0)
{if(ch=='e')
{Play();
sound(200);
delay(100);
nosound();
}
}
else if(n==1)
{if(ch=='e')
{Play();
sound(200);
delay(100);
nosound();
 }
}
else if(n==2)
{
if(ch=='e')
{
sound(200);
delay(100);
nosound();
Highscore();
 }
}
else if(n==3)
{
if(ch=='e')
{
sound(200);
delay(100);
nosound();
Rhelp();
 }
}
else if(n==4)
{if(ch=='e')
{
sound(200);
delay(100);
nosound();
Rabout();
 }
}
}
while(!kbhit())
{arrow(a,b,n);
getmousepos(&button,&x,&y);
if(x>=210 && y>=150 && x<=470 && y<=195)
{if(button==1)
{button=-1;
Play();
sound(200);
delay(100);
nosound();
}
}
else if(x>=210 && y>=205 && x<=480 && y<=245)
{
if( button==1)
{button=-1;
Play();
sound(200);
delay(100);
nosound();

}
}
else if(x>=210 && y>=265 && x<=470 && y<=310)
{
if( button==1)
{button=-1;
sound(200);
delay(100);
nosound();
Highscore();
}
}
else if(x>=220 && y>=325 && x<=485 && y<=360)
{if(button==1)
{button=-1;
sound(200);
delay(100);
nosound();
Rhelp();
}
}

else if(x>=250 && y>=380 && x<=440 && y<=430)
{if(button==1)
{button=-1;
sound(200);
delay(100);
nosound();
Rabout();
}
}

else if(x>=580 && y>=10 && x<=620 && y<=50)
{if(button==1)
{button=-1;
sound(200);
delay(100);
nosound();
clearviewport();
viewport3();
thank();
sound(300);
delay(1000);
nosound();
exit(0);
}
}
}

}
}
//----------------------------------------------------------
void Rhelp()
{char ch;
int x,y,button=-1;
viewport3();
frame();
About();
viewport4();
clearviewport();
Bar();
help();

while(1)
{
while(kbhit())
{ch=getch();
if(ch=='x')
exit(0);
else if(ch=='b')
{
sound(200);
delay(100);
nosound();
viewport3();
clearviewport();
Menuscreen();
}

}

while(!kbhit())
{
getmousepos(&button,&x,&y);
if(x>=25 && y>=25 && x<=50 && y<=75)
{if(button==1)
{button=-1;
viewport3();
clearviewport();
sound(200);
delay(100);
nosound();
Menuscreen();
}
}
else if(x>=580 && y>=10 && x<=620 && y<=50)
{if(button==1)
{button=-1;
sound(200);
delay(100);
nosound();
clearviewport();
viewport3();
thank();
sound(300);
delay(1000);
nosound();
exit(0);
}
}
}

}
}

//----------------------------------------------------------
void Rabout()
{char ch;
int x,y,button=-1;
viewport3();
frame();
About();
viewport4();
clearviewport();
Bar();
about();

while(1)
{
while(kbhit())
{ch=getch();
if(ch=='x')
exit(0);
else if(ch=='b')
{
sound(200);
delay(100);
nosound();
viewport3();
clearviewport();
Menuscreen();
}
}
while(!kbhit())
{
getmousepos(&button,&x,&y);
if(x>=25 && y>=25 && x<=50 && y<=75)
{if(button==1)
{button=-1;
viewport3();
clearviewport();
sound(200);
delay(100);
nosound();
Menuscreen();
}
}
else if(x>=580 && y>=10 && x<=620 && y<=50)
{if(button==1)
{button=-1;
sound(200);
delay(100);
nosound();
clearviewport();
viewport3();
thank();
sound(300);
delay(1000);
nosound();
exit(0);
}
}
}

}
}
//----------------------------------------------------------
void startingscreen()
{
int n1[4]={12,11,2,14};
int i=0,j=0,k=0;
char ch;
Starting();
soundo();
viewport1();
delay(500);

while(1)
{
loading(i,n1,j,k);
delay(200);
i=i+10;
k++;
clearviewport();
while(kbhit())
{ch=getch();
}
if(ch=='x')
{ clearviewport();
viewport3();
thank();
sound(300);
delay(1000);
nosound();
exit(0);
}
else if(k==101)
{sound(200);
delay(200);
nosound();
break;
}
}
}
//----------------------------------------------------------
//outer boundary
void Frame()
{ viewport3();
clearviewport();
//outer surface
setcolor(1);
rectangle(0,0,640,480);
setfillstyle(1,1);
floodfill(4,4,1);

//bottom
setfillstyle(1,14);
bar(0,465,getmaxx(),getmaxy());

//Upper
setfillstyle(1,14);
bar(0,0,getmaxx(),13);

}
//----------------------------------------------------------
void scoreboard()
{
setfillstyle(1,14);
bar(225,0,430,15);

}
//----------------------------------------------------------
void score(int &count)
{ scoreboard();
settextstyle(2,0,5);
setcolor(1);
char a[40];
sprintf(a,"Score : %d",count);
outtextxy(230,0,a);
outtextxy(320,0,"HighScore: ");
}
void downboard()
{
setcolor(14);

//left rectangle
setfillstyle(1,14);
bar(0,415,140,428);

//right rectangle
setfillstyle(1,14);
bar(480,415,628,getmaxy()-51);
}
//----------------------------------------------------------
void downboardshow()
{downboard();
setcolor(1);
settextstyle(2,0,5);
outtextxy(3,415,"Press X To Exit");
outtextxy(483,415,"Press 'W' To fly");
}
//----------------------------------------------------------
void cactus(int x[],int y[],int &i,int &j,int &k)
{
if(x[1]-i<=0)
{i=0;
x[0]=600;
x[1]=630;
y[1]=random(399)-150;
y[2]=y[1]+150;

if(y[1]<0)
{y[2]=150;
}

}
else if(x[3]-j<=0)
{j=0;
x[2]=600;
x[3]=630;

y[5]=random(399)-150;
y[6]=y[5]+150;

if(y[5]<0)
{y[6]=140;
}
}
else if(x[5]-k<=0)
{
k=0;
x[4]=600;
x[5]=630;
y[9]=random(399)-150;
y[10]=y[9]+150;

if(y[9]<0)
{y[10]=150;
}
}
setcolor(2);
setlinestyle(0,1,3);
setfillstyle(5,2);

//cactus pair 1
bar(x[0]-i,y[0],x[1]-i,y[1]);
bar(x[0]-i,y[2],x[1]-i,y[3]);

//cactus pair 2
bar(x[2]-j,y[4],x[3]-j,y[5]);
bar(x[2]-j,y[6],x[3]-j,y[7]);

//cactus pair 3
bar(x[4]-k,y[8],x[5]-k,y[9]);
bar(x[4]-k,y[10],x[5]-k,y[11]);
}
//----------------------------------------------------------
void rock(int x[],int &l,int &m,int &n)
{
int y[2]={400,449};
//outer body
setcolor(8);
setfillstyle(6,8);
bar(0,400,629,452);
//Inner body
//rock1
setcolor(7);
setfillstyle(5,7);
bar(x[0]-l,y[0],x[1]-l,y[1]);
//rock2
setfillstyle(5,7);
bar(x[2]-m,y[0],x[3]-m,y[1]);
//rock3
setfillstyle(5,7);
bar(x[4]-n,y[0],x[5]-n,y[1]);
if(x[1]-l<=0)
{l=0;
x[0]=x[4];
x[1]=x[5];
}
else if(x[3]-m<=0)
{m=0;
x[2]=x[4];
x[3]=x[5];
}
else if(x[5]-n<=0)
n=0;
}
//----------------------------------------------------------
inline void object::bird(int x[],int y[],int &p,int &a1,int &b)
{
int cords[]={x[2],y[2]+p,x[3],y[3]+p,x[4],y[4]+p,x[5],y[5]+p,x[6],y[6]+p};
int cords1[]={x[7],y[7]+p,x[8],y[8]+p,x[9],y[9]+p,x[10],y[10]+p};
int cords2[]={x[11],y[11]+p,x[12],y[12]+p,x[13],y[13]+p,x[14],y[14]+p};
int cords3[]={x[15],y[15]+p,x[16],y[16]+p,x[17],y[17]+p,x[18],y[18]+p,x[19],y[19]+p};
//Body
setlinestyle(0,1,1);
setcolor(6);
arc(x[0],y[0]+p,10,165,35);
arc(x[1],y[1]+p,195,350,35);
setfillstyle(2,4);
floodfill(x[0]+2,y[0]+2+p,6);
//WINGS
setcolor(2);
setfillstyle(6,14);
fillpoly(5,cords);

//eye
setfillstyle(1,1);
fillpoly(4,cords1);

//pupil
setcolor(3);
setfillstyle(1,8);
fillpoly(4,cords2);

//mouth
setfillstyle(1,4);
fillpoly(5,cords3);

b=(y[0]+y[1]+2*p)/2;
a1=(x[0]+x[1])/2;
}
//----------------------------------------------------------
void object::dbox()
{setfillstyle(5,3);
bar(75,50,500,300);
setfillstyle(1,7);
bar(100,75,475,275);
setcolor(1);
settextstyle(4,0,8);
outtextxy(110,120,"Game over");
}
//----------------------------------------------------------
void rect()
{
setfillstyle(2,1);
bar(0,0,getmaxx(),getmaxy());
}
//----------------------------------------------------------
void PlayScreen()
{

Frame();
viewport();
clearviewport();
setbkcolor(1);
int x[6]={220,250,410,440,610,640};
int y[12]={0,120,280,400,0,120,280,400,0,120,280,400};
int a[6]={0,200,225,400,425,629};
int a1=0;
int b=0;
int d[20]={100,100,94,104,85,74,94,121,114,110,121,120,115,115,120,113,123,125,115,113};
int s[20]={235,215,222,227,243,230,222,217,222,212,217,217,220,215,217,232,230,235,240,232};
int i=0,j=0,k=0;
int l=0,m=0,n=0;
int p=0;
int count=0;
char ch;
object ob;

cactus(x,y,i,j,k);
rock(a,l,m,n);
score(count);
downboardshow();
gbox();
ob.bird(d,s,p,a1,b);

while(1)
{while(kbhit())
{ch=getch();
if(ch=='w')
goto a;
}
}
a:
//Motion Control Loop
while(1)
{
ob.bird(d,s,p,a1,b);
cactus(x,y,i,j,k);
rock(a,l,m,n);
score(count);
downboardshow();

i=i+4;
j=j+4;
k=k+4;
l=l+3;
m=m+3;
n=n+3;
delay(40);
clearviewport();
while(kbhit())
{ch=getch();

if(ch=='w'&&b-25>0)
p=p-20;
}
if(b+25>=400)
break;
else if(x[0]-i<=a1+35 && x[1]-i>=a1-35)
{
if(b-25>=y[0] && b-25<=y[1])
break;
else if(b+25>=y[2] && b+25<=y[3])
break;
}
else if(x[2]-j<=a1+35 && x[3]-j>=a1-35)
{
if(b-25>=y[4] && b-25<=y[5])
break;
else if(b+25>=y[6] && b+25<=y[7])
break;
}
else if(x[4]-k<=a1+35 && x[5]-k>=a1-35)
{
if(b-25>=y[8] && b-25<=y[9])
break;
else if(b+25>=y[10] && b+25<=y[11])
break;
}
else if(x[1]-i==62 || x[3]-j==64 || x[5]-k==62)
count++;
if(ch=='x')
break;
else
p=p+5;
}
setbkcolor(0);
setviewport(0,0,getmaxx(),getmaxy(),1);
clearviewport();
rect();
ob.dbox();
}
void Play()
{
char ch;
viewport3();
clearviewport();
PlayScreen();
while(1)
{
while(kbhit())
{ ch=getch();
if(ch=='e');
{
viewport3();
clearviewport();
Menuscreen();
}

}
}
}
//----------------------------------------------------------
void main()
{
load();
startingscreen();
viewport3();
clearviewport();
e();
viewport3();
clearviewport();
Menuscreen();
getch();
closegraph();
}