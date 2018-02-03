#include<graphics.h>
#include<stdio.h>
#include<conio.h>
//************************************************
int g=0;
struct block
{ int x1,y1,x2,y2,l,b;
};
struct block c,b;
//**********************************************


//**********************************************
int check()
{  if(b.x1>c.x1)
   {
    if(((b.x1-c.x1)<=c.l)&&(c.y1>=350))
	return 1;
   }
   if(b.x1<c.x1)
   {
    if(((c.x1-b.x1)<=c.l)&&(c.y1>=350))
	return 1;
   }

     return 0;
}

//**************************************************
/*char* score(int a)
{  int i=10;
   char ch[]="SCORE- ";
   while(i>6)
   { if(a!=0)
     { ch[i]=(char)((a%10)+48);
       a=a/10;
     }
     else
      ch[i]='0';
     i--;
   }
   ch[11]='\0';
   return (ch);
} */
//**************************************************
void jdisp()
{
       sound(1100);
      do
       { delay(60); //60
	cleardevice();
	setcolor(BLUE);
	line(100,400,500,400);
	setcolor(BLUE);
	c.y1=c.y1-20;
	b.x1=b.x1-c.b;
	b.x2=b.x2-c.b;
	circle(c.x1,c.y1,c.l);
	setfillstyle(1,YELLOW);
      floodfill(c.x1,c.y1,BLUE);
      setcolor(BLUE);
      rectangle(b.x1,b.y1,b.x2,b.y2);
      setfillstyle(1,RED);
      floodfill(b.x1+1,b.y1+1,BLUE);
      nosound();
      if(check()==1)
      {  g=1; break;}
      if(b.x1<=100)
      {	 b.x1=490;  b.x2=500;
	 b.y1=360;  b.y2=400; }
      }while(c.y1>270);

      if(g!=1){
      do
       {delay(60);
	cleardevice();
	setcolor(BLUE);
	line(100,400,500,400);
	setcolor(BLUE);
	c.y1=c.y1+20;
	b.x1=b.x1-c.b;
	b.x2=b.x2-c.b;
	circle(c.x1,c.y1,c.l);
	setfillstyle(1,YELLOW);
	floodfill(c.x1,c.y1,BLUE);
	setcolor(BLUE);
	rectangle(b.x1,b.y1,b.x2,b.y2);
	setfillstyle(1,RED);
	floodfill(b.x1+1,b.y1+1,BLUE);
	if(check()==1)
      {  g=1; break;}
      if(b.x1<=100)
      {	 b.x1=490;  b.x2=500;
	 b.y1=360;  b.y2=400; }
     }while(c.y1<390);}
}
//**********************************************

void initial()
{ c.l=10;     b.x1=490;  b.x2=500;
c.x1=150;   b.y1=360;  b.y2=400;
c.y1=390;   b.l=40;    b.b=10;
c.b=6; //speed 6,12,18
c.x2=0;
}


//**********************************************


void main()
{  int gd=DETECT,gm;
char ch;



  clrscr();
  initgraph(&gd,&gm,"C:\\TC\\bgi");
  setbkcolor(WHITE);
  l:
    initial();
      setcolor(BLUE);
      line(100,400,500,400);
      setcolor(BLUE);
      circle(c.x1,c.y1,c.l);
      setfillstyle(1,YELLOW);
      floodfill(c.x1,c.y1,BLUE);
      setcolor(BLUE);
      rectangle(b.x1,b.y1,b.x2,b.y2);
      setfillstyle(1,RED);
      floodfill(b.x1+1,b.y1+1,BLUE);
      settextstyle(3,0,1);
      outtextxy(100,410,"Press space to Jump!");
      outtextxy(360,410,"Press x to exit!");
    //  setcolor(YELLOW);
      //settextstyle(3,0,1);
     // outtextxy(250,100,score(c.x2));
      delay(100);
      sound(1000);
      delay(300);
      nosound();
      delay(100);
      sound(1000);
      delay(300);
      nosound();
      delay(100);
      sound(1000);
      delay(300);
      nosound();
      delay(100);
      sound(1200);
      delay(500);
      nosound();





  do{
   while (!kbhit())
   {

      delay(60);
      cleardevice();
      b.x1=b.x1-c.b;
      b.x2=b.x2-c.b;
      setcolor(BLUE);
      line(100,400,500,400);
      setcolor(BLUE);
      circle(c.x1,c.y1,c.l);
      setfillstyle(1,YELLOW);
      floodfill(c.x1,c.y1,BLUE);
      setcolor(BLUE);
      rectangle(b.x1,b.y1,b.x2,b.y2);
      setfillstyle(1,RED);
      floodfill(b.x1+1,b.y1+1,BLUE);
      settextstyle(3,0,1);
      outtextxy(100,410,"Press space to Jump!");
      outtextxy(360,410,"Press x to exit!");
      fflush(stdin);
      if(check()==1)
      {  g=1; break;}
      if(b.x1<=100)
      {	 b.x1=490;  b.x2=500;
	 b.y1=360;  b.y2=400; }

   }
   if(g==1)
     break;
   ch=getch();
   if(ch==' ')
    jdisp();
   if(ch=='x')
     break;
   if(ch=='s')
   { if(c.b<18)
       c.b+=6;
   }

   }while(g==0);
      sound(1000);
      delay(500);
      sound(900);
      delay(500);
      sound(800);
      delay(500);
      nosound();
      setcolor(RED);
      settextstyle(3,0,1);
      outtextxy(200,200,"!!!! Press R to restart !!!!");
      ch=getch();
      cleardevice();
      if(ch=='r')
	goto l;

      closegraph();


}