#ifndef _cvecara_h
#define _cvecara_h
#include "buket.h"
#include <iostream>
#include <string>
using namespace std;

class Cvecara {
	struct Elem {
		Buket* buket; Elem* next; Elem(Buket* buket, Elem* next = nullptr) {
			this->buket = buket;
			this->next = next;
		}
	};
	Elem* list;
	int income,numb;
	void copy(const Cvecara& c);
	void move(Cvecara& c);
	void obrisi();
	friend void swap(Cvecara& a, Cvecara& b);

public:
	Cvecara();
	Cvecara(const Cvecara& c);
	Cvecara(Cvecara&& c);
	void addBuket(Buket* b);
	void prodaja(int k);
	Cvecara& operator=(Cvecara c);
	ostream& Print(ostream& os, Cvecara& c);
	friend ostream& operator<<(ostream& os, Cvecara& c);
	~Cvecara();

};
#endif
