#include <string>
#include <sstream>
using namespace std;

struct sfera{
	float diam;
	char col;
	float exact;
	float atoll;
	float discr;
};

void print_and_clear_buffer(stringstream &ss);

sfera *load(int &n, int &b, int &g, int &r);

void print(sfera v[], int n, int type, stringstream &ss);

void sort(sfera v[], int n, int b);

sfera *justblu(sfera v[], int n, int &b);

float max(sfera v[], int n);

float min(sfera v[], int n);
/*
double media(evento v[], int n);

double devstd(evento w[], int n, double med);



double calcmass(evento a);

void sort(evento *v, int n);
*/

