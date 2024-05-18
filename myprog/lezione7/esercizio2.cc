#include <iostream>
using namespace std;

void print_array( int a[], int n){
	for(int i=0; i<n; i++){
		cout << a[i] << endl;}
	}
	
int max_array( int a[], int n){
	int max=a[0];
	for(int i=0; i<n; i++){
		if(a[i]>max) max=a[i];
		}
	return max;
	}

int min_array( int a[], int n){
	int min=a[0];
	for(int i=0; i<n; i++){
		if(a[i]<min) min=a[i];
		}
	return min;
	}

void min_max_array( int a[], int n){
	int min=a[0];
	int max=a[0];
	for(int i=0; i<n; i++){
		if(a[i]<min) min=a[i];
		if(a[i]>max) max=a[i];
		}
	cout << "Il max e': " << max << endl;
	cout << "Il min e': " << min << endl;
	}

void sort_array(int a[], int n){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(a[i]>a[j]){
				int tmp= a[i];
				a[i]=a[j];
				a[j]=tmp;}
			}
		}
	for(int i=0; i<n; i++)
		cout << a[i] <<endl;
	}
			
int main(){
	int v[10]= {9, 2, 1, 3, 4, 7, 0, 11, 20, 5};
	
	print_array(v, 10);
	cout << "Il max e': " << max_array(v, 10) << endl;
	cout << "Il min e': " << min_array(v, 10) << endl;
	min_max_array(v, 10);
	sort_array(v, 10);
	return 0;
	
}
