#include <string>
#include <sstream>
using namespace std;

struct part{
	float x, y;
	int c;
	float m;
};

struct buca{
	float xc, yc, rad;
	char lab;
	int n_part;
	part *v_part;
};

void print_and_clear_buffer(stringstream &ss);

buca *loadbuca(int &n);

void printbuca(buca v[], int n, int type, stringstream &ss);

part *loadpart(int &n);

void printpart(part v[], int i, int n, stringstream &ss);

float dist(float x1, float y1, float x2, float y2);

int dentro(buca b, part p[], int n);

void assignment(buca v, part p[], int n);

void sort(buca *v, int n);
/*
double media(evento v[], int n);

double devstd(evento w[], int n, double med);

double max(evento v[], int n);

double min(evento v[], int n);

double calcmass(evento a);


*/

