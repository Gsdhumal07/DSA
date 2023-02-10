#include<graphics.h>
#include<conic.h>
#include<dos.h>
#include<stdlib.h>

int main(){
	int gd=DETECT , gm , midx , midy;
	initgraph(&gd , &gm ,"C:\\TURBOC\\BGI");
	midx=getmaxx()/2;
	midy=getmaxy()/2;
	setcolor(red);
	settexstyle(SCRIPT_FONT , HORIZ_DIR ,3);
	settextjustify(CENTER_TEXT ,CENNTER_TEXT);
	outtextxy(midx , midy-10 ,"Traffic Light Simulation");
	outterxtxy(midx ,midy+10 , "Press any key to Start ");
	getch();
	cleardevice();
	setcolor(WHITE);
	
}
