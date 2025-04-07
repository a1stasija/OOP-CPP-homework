#include <iostream>
#include <string>
#include "knjiga.h"
#include "biblioteka.h"

int main() {
	Knjiga k1("Glupost", "Alexlmao");
	Knjiga* k3;
	k3 = !k1;
	cout << k3 << endl;
	/*Biblioteka b1("Laza Kostic", 100);
	b1 += k1;
	b1 += k2;
	k3 = b1.find(3);
	cout << k3 << endl;
	cout << b1;*/


}