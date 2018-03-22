#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdio.h>
#include<process.h>

void viewport1()
{setviewport(150,360,getmaxx()-189,getmaxy()-5,1);
}
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
settextstyle(1,0,2);
outtextxy(425,325,"Powered By Ucreanto");

}
void loading(int &n,int n1[4],int &j,int p[8],int k)
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
void main()
{int gd=DETECT,gm;

int n1[4]={12,11,2,14};
int i=0,j=0,k=0;
char ch;
int p[8]={0,10,30,45,50,60,80,100};
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
Starting();
viewport1();
delay(500);
while(1)
{
loading(i,n1,j,p,k);
delay(40);
i=i+10;
k++;
clearviewport();
while(kbhit())
{ch=getch();
}
if(ch=='x')
exit(0);
else if(k==101)
break;
}
getch();
closegraph();
}