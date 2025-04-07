#ifndef _biblioteka_h_
#define _biblioteka_h_

#include "knjiga.h"
#include <iostream>
#include <string>

using namespace std;

class Biblioteka {
	string name;
	int cap, num;
	Knjiga** knjige;
	void copy(const Biblioteka& b);
	void move(Biblioteka& b);
	void obrisi();
	friend void swap(Biblioteka& a, Biblioteka& b);

public:
	Biblioteka(string name, int cap);
	Biblioteka(const Biblioteka& b);
	Biblioteka(Biblioteka&& b);
	Biblioteka& operator=(Biblioteka b);
	string getName() const;
	int getCap() const;
	int getNum() const;
	Knjiga* operator!();
	Biblioteka& operator+=(Knjiga& k);
	Knjiga* find(int id);
	friend ostream& operator<<(ostream& os, Biblioteka b);
	~Biblioteka();

};
#endif
