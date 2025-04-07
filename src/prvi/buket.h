#ifndef _buket_h
#define _buket_h

#include "cvet.h"
using namespace std;

class Buket {
	struct Elem {Cvet* cvet; Elem* next; Elem(Cvet* cvet, Elem* next = nullptr) {
			this->cvet = cvet;
			this->next = next;
		}
	};
	Elem* list;

	void copy(const Buket& b);
	void move(Buket& b);
	void obrisi();
	friend void swapop(Buket& a, Buket& b);

	public:
		Buket();
		Buket(const Buket &b);
		Buket(Buket&& b);
		Buket& operator=(Buket b);
		void Add(Cvet* cvet);
		int Profit();
		friend ostream& Print(ostream& os, Buket& b);
		void Sort();
		friend ostream& operator <<(ostream& os, Buket& b);
		int getNabavna() const;
		int getProdajna() const;
		friend bool operator>(Buket& b1, Buket& b2);
		friend ostream& operator<<(ostream& os,Buket& b);
		void swap(Elem *curr, Elem *next);
		int len(Elem* list);
		~Buket();

};
#endif
