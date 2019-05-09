#include<iostream>
#include<graphics.h>
using namespace std;

void drawcircle(int x, int y, int xc, int yc)
{
	putpixel(xc+x,yc+y,RED);
	putpixel(xc-x,yc+y,RED);
	putpixel(xc+x,yc-y,RED);
	putpixel(xc-x,yc-y,RED);
	putpixel(xc+y,yc+x,RED);
	putpixel(xc-y,yc+x,RED);
	putpixel(xc+y,yc-x,RED);
	putpixel(xc-y,yc-x,RED);
}

int main()
{
	int gd=DETECT, gm;
	initgraph(&gd, &gm, NULL);

	int x, y, d;				//1
	int xc = 200, yc = 240, r = 100;	//2

	d = 3 - 2*r;				//3
	x=0, y=r;				//4	
					

	drawcircle(x, y, xc, yc); 		//5

	while(x<=y)				//6
	{
		x++;
		if(d<0)
			d=d+4*x+6;
		else
		{
			d=d+4*(x-y)+10;
			y--;
		}
	drawcircle(x, y, xc, yc);
	}

	getch();
	closegraph();
	return 0;
}
