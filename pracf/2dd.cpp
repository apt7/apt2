#include<iostream>
#include<graphics.h>
using namespace std;

class trans
{
	public:
	int gd=DETECT, gm;
	float x1, y1, x2, y2;
	float xf1, yf1, xf2, yf2;
	int tx, ty;
	float sx, sy;
	float xf4, yf4;
	float ang, angle;	

	void translation();
	void scaling();
	void rotation();
};

void trans :: translation()	
{
	cout<<"\nTRANSLATION";
	cout<<"\n Enter coordinates x1 y1 x2 y2 for line: ";
	cin>>x1>>y1>>x2>>y2;
	cout<<"Enter Translation factor: ";
	cin>>tx>>ty;

	xf1 = x1 + tx;
	yf1 = y1 + ty;
	xf2 = x2 + tx;
	yf2 = y2 + ty;

	initgraph(&gd, &gm, NULL);
	setcolor(WHITE);
	line(x1, y1, x2, y2);
	setcolor(YELLOW);
	line(xf1, yf1, xf2, yf2);
	getch();
	closegraph();
}

void trans :: scaling()	
{
	cout<<"\nSCALING";
	cout<<"\n Enter coordinates x1 y1 x2 y2 for rectangle: ";
	cin>>x1>>y1>>x2>>y2;
	cout<<"Enter Scaling factor: ";
	cin>>sx>>sy;

	xf1 = x1 * sx;
	yf1 = y1 * sy;
	xf2 = x2 * sx;
	yf2 = y2 * sy;

	initgraph(&gd, &gm, NULL);
	setcolor(WHITE);
	rectangle(x1, y1, x2, y2);
	setcolor(YELLOW);
	rectangle(xf1, yf1, xf2, yf2);
	getch();
	closegraph();	
}

void trans :: rotation()
{
	cout<<"\n\t\tROTATION\n";
        cout<<"Enter coordinates of line x1 ,y1: \n";
        cin>>x1>>y1;
        cout<<"Enter coordinates of line x2, y2: \n";
        cin>>x2>>y2;
        cout<<"Enter the angle: \n";
        cin>>ang;
	angle = (ang * 3.14 )/180;
	xf4 = x2 - (((x2-x1)*cos(angle))-((y2-y1)+sin(angle))); 
	yf4 = y2 - (((x2-x1)*sin(angle))+((y2-y1)*cos(angle)));

	initgraph(&gd, &gm, NULL);
	setcolor(WHITE);
	line(x1, y1, x2, y2);
	setcolor(YELLOW);
	line(x1, y1, xf4, yf4);	
	getch();
	closegraph();
}
	
int main()
{
	int ch;
	int con;
    	trans obj;
	cout<<"\t\t\n";
	cout<<"\t\t 2D-TRANSFORMATION TECHNIQUES \n";
	menu:
	cout<<"\nMENU\n1.Translation\n2.Rotation\n3.Scaling\nEnter your choice\n";
	cin>>ch;
    	switch(ch)
    	{
        	case 1:
        	obj.translation();
        	break;
        	case 2:
        	obj.rotation();
        	break;
        	case 3:
        	obj.scaling();
        	break;
        	default:
        	cout<<"Invalid choice.\nDo you want to continue(y/n)?";
        	cin>>con;
        	if(con=='y')
        	goto menu;
        	else
        	break;
    	}
    	return 0;
}
