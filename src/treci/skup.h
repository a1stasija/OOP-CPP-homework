#ifndef _skup_h_
#define _skup_h_

#include <iostream>
#include <string>

using namespace std;

class Skup {
	struct Elem {
		char a; Elem* next; Elem(char a, Elem* next = nullptr) {
			this->a = a;
			this->next = next;
		}
	};
	Elem* skup;
	void obrisi();

public: 
	Skup(string str);
	Skup(const Skup& s) = delete;
	Skup& operator=(const Skup& s) = delete;
	Skup& operator+=(char k);
	bool operator()(char k);//jel ovako
	bool provera(char k);
	void Print();
	~Skup();
};
#endif