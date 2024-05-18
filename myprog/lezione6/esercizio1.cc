#include <iostream>
using namespace std;

int main(){
	
	double v[5]={2,5,10,20,50};
	double w[5]={10,-5,3,1,100};
	
	for(int i=0; i<5; i++)
		cout << "v[" << i<< "] = " << v[i] << endl;
	
	for(int i=0; i<5; i++)
		cout << "w[" << i<< "] = " << w[i] << endl;
	
	double s[5];
	
	for(int i=0; i<5; i++)
		s[i]=v[i];
	
	for(int i=0; i<5; i++){
		s[i]=v[i] + w[i];
		cout << "s[" << i<< "] = " << s[i] << endl;
		}
	
	return 0;
}
