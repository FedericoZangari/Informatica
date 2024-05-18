#include <string>
#include <sstream>
using namespace std;

struct evento{
	double p1[4];
	double p2[4];
	bool segnale;
	double massainv;
};

void print_and_clear_buffer(stringstream &ss);

evento *load(int &n, int &s, int &b);

double media(evento v[], int n);

double devstd(evento w[], int n, double med);

double max(evento v[], int n);

double min(evento v[], int n);

double calcmass(evento a);

void sort(evento *v, int n);


