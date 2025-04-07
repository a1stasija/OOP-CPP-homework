#include <iostream>
#include "cvet.h"
#include "buket.h"
#include "cvecara.h"
using namespace std;

int main() {
	Cvet cvet1("Ruza", 2, 3), cvet2("Ljubicica",3,5), cvet3("Ruza", 2, 3), cvet4("Orhideja", 100, 3);
	bool cmp = cvet1 == cvet2;
	cout << cmp<<endl;
	Buket b1, b2,b3;
	b1.Add(&cvet1);
	b1.Add(&cvet2);
	b1.Add(&cvet1);
	b2.Add(&cvet3);
	b3.Add(&cvet4);
	b3.Add(&cvet1);
	cmp = b1 > b2;
	cout << cmp<<endl;
	cout << b1;
	Cvecara c1, c2;
	c1.addBuket(&b1);
	c1.addBuket(&b2);
	c1.addBuket(&b3);
	cout << c1;
	c1.prodaja(2);
	cout << c1;

}