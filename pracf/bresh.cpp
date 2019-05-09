#include<iostream>
#include<graphics.h>

void drawline(int xs, int ys, int xe, int ye)
{
	int x, y ,dx, dy, c1, c2, d;

	dx = xe - xs;
	dy = ye - ys;

	c1 = 2*(dy-dx);
	c2 = 2*(dy);

	d = 2*dy - dx;

	x = xs;
	y = ys;

	putpixel(x, y, WHITE);

	while(x<=xe)
	{
		x = x + 1;
		if(d<0)
			d = d + c2;
		else
		{
			d = d+ c1;
			y = y + 1;
		}
	putpixel(x, y, WHITE);	
	}	
}

void drawline_greater(int xs, int ys, int xe, int ye) // m > 1
{
	int x, y ,dx, dy, c1, c2, d;

	dx = xe - xs;
	dy = ye - ys;

	c1 = 2*(dx-dy);
	c2 = 2*(dx);

	d = 2*dx - dy;

	x = xs;
	y = ys;

	putpixel(x, y, WHITE);

	while(y<=ye)
	{
		y = y + 1;
		if(d<0)
			d = d + c2;
		else
		{
			d = d+ c1;
			x = x + 1;
		}
	putpixel(x, y, WHITE);	
	}	
}

void draw(int x1, int y1, int x2, int y2)
{
	float m;
	m = (float)(y2-y1)/(float)(x2-x1);

	if(m < 1)
		drawline(x1, y1, x2, y2);
	else
		drawline_greater(x1, y1, x2, y2); 
}

int main()
{
	int gd=DETECT,gm;
	initgraph(&gd, &gm, NULL);
	draw(30, 30, 100, 30);
	draw(30, 30, 30, 100);
	draw(100, 30, 100, 100);
	draw(30,100, 100, 100);

	getch();
	closegraph();
	return 0;

}
