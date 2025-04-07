#ifndef _cvet_h
#define _cvet_h
//naziv fja malo slovo
#include <iostream>
#include <string>
using namespace std;

class Cvet {
	string name;
	int buy, sell;
public:
	Cvet(string name, int buy, int sell);
	string Name() const;
	int Sell() const;
	int Buy() const;
	friend bool operator== (Cvet& cvet1, Cvet& cvet2);
	int Profit();
	friend ostream& operator <<(ostream& os, Cvet& c);






};
#endif
