#ifndef _rec_h_
#define _rec_h_
#include <iostream>
#include <string>
using namespace std;


class Rec {
	struct Elem {
		char a; Elem* next; Elem(char a, Elem* next = nullptr) {
			this->a = a;
			this->next = next;
		}
	};
	Elem* rec;
	void obrisi();
	void copy(const Rec& r);
	void move(Rec& r);
	const string samoglasnikm = "aeiou";
	const string samoglasnikv = "AEIOU";
	const string sonantm = "lnr";
	const string sonantv = "LNR";
	friend void swap(Rec& a, Rec& b);

public:
	Rec(string str);
	Rec(const Rec& r);
	Rec(Rec&& r);
	Rec& operator=(Rec r);
	bool provera(char k);
	int operator+();
	int operator~();
	int operator()(int n);
	int pretraga(int n);
	friend bool operator^(Rec r1, Rec r2);
	friend istream& operator>>(istream& is, Rec& r1);
	friend ostream& operator<<(ostream& os, Rec& r1);
	~Rec();
};

#endif
