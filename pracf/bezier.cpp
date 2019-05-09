#include<iostream>
#include<graphics.h>
using namespace std;

int main()
{
int gd=DETECT, gm;
initgraph(&gd, &gm, NULL);
int i;
float u, cx, cy, px[4],py[4];

for(i=0; i<=3; i++)
{
	cout<<"\nEnter coordinate of px";
	cin>>px[i];
	cout<<"\nEnter coordinate of py";
	cin>>py[i];
}

for(u=0.0; u<=1.0; u=u+0.005)
{
	cx = (px[0]*pow(1-u,3)) + (3*px[1]*pow(1-u,2)) + (3*px[2]*pow(u,2)*(1-u)) + (px[3]*pow(u,3)); 
	cy = (py[0]*pow(1-u,3)) + (3*py[1]*pow(1-u,2)) + (3*py[2]*pow(u,2)*(1-u)) + (py[3]*pow(u,3));
	putpixel(cx, cy, YELLOW);
}

getch();
closegraph();
return 0;
}
