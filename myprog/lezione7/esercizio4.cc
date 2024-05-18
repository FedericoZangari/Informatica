#include <iostream>
#include <math.h>
using namespace std;

const double r=1, xc=1, yc=1;

double distanza(double x, double y){
	double d;
	d= sqrt( pow(x-xc,2) + pow(y-yc,2) );
	return d;
	}

void check_circle(double x2, double y2, bool &status){
	if(distanza(x2, y2)<= r)
		status= true;
	}
	
int main(){
	double x1, y1;
	bool state=false;
	
	for(;;){
	if(cin.eof()) break;
	cout << "inserire le coordinate del punto" << endl;
	cout << "x: ";
	cin >> x1;
	cout << "y: ";
	cin >> y1;
	
	check_circle(x1, y1, state);
	cout << state << endl;
	}
	
	return 0;
}
