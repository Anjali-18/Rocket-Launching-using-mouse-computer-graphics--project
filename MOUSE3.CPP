#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<time.h>

union REGS i, o;

int initmouse()
{
   i.x.ax = 0;
   int86(0X33, &i, &o);
   return ( o.x.ax );
}

void showmouseptr()
{
   i.x.ax = 1;
   int86(0X33, &i, &o);
}

void getmousepos(int *button, int *x, int *y)
{
   i.x.ax = 3;
   int86(0X33, &i, &o);

   *button = o.x.bx;
   *x = o.x.cx;
   *y = o.x.dx;
}
//text and rocket functions
void text()
{
	int gd=DETECT;
	time_t curtime;
	int gm,i;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	cleardevice();

	time(&curtime);

	settextstyle(0,EMPTY_FILL,1);
	setcolor(YELLOW);
	outtextxy(50,50,"I");
	outtextxy(50,60,"S");
	outtextxy(50,70,"R");
	outtextxy(50,80,"O");
	settextstyle(0,EMPTY_FILL,1);
	setcolor(GREEN);
	outtextxy(100,50,"Indian Space");
	outtextxy(100,70,"Research Organisation");
	setcolor(WHITE);
	outtextxy(50,120,"WELCOME TO INDIAN SPACE RESEARCH ORGANISATION");
	delay(150);
	outtextxy(50,150,"PSLV C-44 IS READY TO LAUNCH ON :");
	delay(150);
	outtextxy(50,180,ctime(&curtime));
	delay(150);
	outtextxy(50,210,"IT CARRIES TWO SATELLITES TO BE INJECTED IN DESIGNATED ORBITS");
	delay(150);
	setcolor(RED);
	outtextxy(50,240,"PAYLOAD WEIGHT=> 741.2 KILOGRAMS");
	delay(150);
	outtextxy(50,270,"LAUNCH SITE => SHAR,SRIHARIKOTA");
	delay(150);
	outtextxy(50,300,"OVERALL HEIGHT => 44.4 METRES");
	delay(150);
	outtextxy(50,330,"MAXIMUM VELOCITY ACHIEVABLE => 7740 m/s");
	delay(150);
	outtextxy(50,360,"ALTITUDE: 450 KILOMETRES");
	delay(150);
	settextstyle(0,EMPTY_FILL,1);

	outtextxy(50,390,"CLICK ANYWHERE TO INITIATE LAUNCH OF PSLV C44");



	clrscr();
}
void rocket()
{
	int i,j,k;
	setcolor(BLUE);
	for(i=30;i<=400;i++)
	{
		setcolor(BLUE);
		arc(500-i,200+i,0,120,200);
		arc(500-i,200+i,0,120,300);
		arc(500-i,200+1,0,120,400);
		arc(500-i,200+i,0,120,500);
		setcolor(GREEN);
		settextstyle(0,EMPTY_FILL,1);
		outtextxy(318,330-i,"P");
		outtextxy(318,340-i,"S");
		outtextxy(318,350-i,"L");
		outtextxy(318,360-i,"V");
		outtextxy(310,385-i,"C44");
		//ROCKET
		setcolor(WHITE);
		outtextxy(10,400+i,"EARTH");
		for(j=0;j<=7;j++)
		{
			setcolor(RED);
			circle(320,300-i,0+j);
		}
		for(k=0;k<=15;k++)
		{
			setcolor(YELLOW);
			circle(300,410-i,0+k);
			circle(340,410-i,0+k);
			circle(320,410-i,0+k);
			circle(280,410-i,0+k);
			circle(360,410-i,0+k);
		}
		setcolor(WHITE);
		line(0,420+i,620,420+i);
		line(340,400-i,340,320-i);
		line(300,400-i,300,320-i);
		line(330,370-i,330,330-i);
		line(310,370-i,310,330-i);
		line(310,330-i,330,330-i);
		line(310,370-i,330,370-i);
		line(300,380-i,340,380-i);
		line(270,400-i,370,400-i);
		line(270,400-i,300,380-i);
		line(340,380-i,370,400-i);
		line(300,320-i,340,320-i);
		line(300,320-i,320,300-i);
		line(340,320-i,320,300-i);
		delay(50);
		cleardevice();
	}
	setcolor(GREEN);
	settextstyle(0,EMPTY_FILL,4);
	outtextxy(50,100,"CONGRATULATIONS");
	outtextxy(50,200,"MISSION");
	outtextxy(50,300,"SUCCESSFUL");
	getch();
}


main()
{
   int gd = DETECT, gm, status, button, x, y;
   char array[50];

   initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
   settextstyle(DEFAULT_FONT,0,2);

   status = initmouse();

   if ( status == 0 )
      printf("Mouse support not available.\n");
   else
   {
      showmouseptr();

      getmousepos(&button,&x,&y);

      while(!kbhit())
      {
	 getmousepos(&button,&x,&y);

	 if( button == 1 )
	 {
	    button = -1;
	    cleardevice();
	    sprintf(array,"Left Button clicked x = %d y = %d",x,y);
	    outtext(array);
	    text();
	    rocket();
	 }
	 else if( button == 2 )
	 {
	    button = -1;
	    cleardevice();
	    sprintf(array,"Right Button clicked x = %d y = %d",x,y);
	    outtext(array);
	    text();
	    rocket();
	 }

      }
   }

   getch();
   return 0;
}