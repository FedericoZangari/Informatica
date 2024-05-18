#include <string>
#include <sstream>
using namespace std;

struct ione{
	float x, y, r;
	int carica;
};

struct elettrone{
	float x, y, vx, vy, fx, fy;
	bool free;
};



void print_and_clear_buffer(stringstream &ss);

ione *loadione(int &n);

void printione(ione v[], int n, stringstream &ss);

elettrone *loadelet(int &n);

void printelet(elettrone v[], int n, stringstream &ss);

float dist(float x1, float y1, float x2, float y2);

int gotcha(elettrone *el, ione ions[], int nions);

/*
void printpart(part v[], int i, int n, stringstream &ss);



int dentro(buca b, part p[], int n);

void assignment(buca v, part p[], int n);

void sort(buca *v, int n);

double media(evento v[], int n);

double devstd(evento w[], int n, double med);

double max(evento v[], int n);

double min(evento v[], int n);

double calcmass(evento a);


*/

