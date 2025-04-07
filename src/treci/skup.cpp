#include "skup.h"

Skup::Skup(string str){
	
	int n= str.length();
	Elem* p=skup,*novi=nullptr;
	for (int i = 0; i < n; i++) {
		bool flag = this->provera(str[i]);
		if (!skup) p= skup = new Elem(str[i], skup);
		else if(flag) {
			novi = new Elem(str[i]);
			p->next = novi;
			p = novi;
		}
	}
}

bool Skup::provera(char k)
{
	Elem* p = skup, *prev=nullptr;
	int flag = 1;
	while (p) {
		if (p->a == k) flag = 0;
		prev = p;
		p = p->next;
	}
	return flag;
}
Skup& Skup::operator+=(char k)
{
	bool flag = this->provera(k);
	Elem* p = skup,*novi=nullptr;
	if (flag) {
		while (p->next) {
			p = p->next;
		}
		novi = new Elem(k);
		p->next = novi;
		p = novi;
	}
	return *this;
}
bool Skup::operator()(char k)
{
	bool flag = this->provera(k);
	return !flag;
}
void Skup::Print()
{
	Elem* p = skup;
	while (p) {
		cout << p->a;
		p = p->next;
	}
	cout << endl;
}
Skup::~Skup()
{
	obrisi();
}

void Skup::obrisi()
{
	Elem* p;
	while (skup) {
		p = skup;
		skup = skup->next;
		delete p;
	}
}