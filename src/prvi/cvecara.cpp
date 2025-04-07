#include "cvecara.h"

void Cvecara::copy(const Cvecara& c)
{
	Elem* curr = c.list;
	while (curr) {
		list = new Elem(curr->buket, list);
		curr = curr->next;
	}
	income = c.income;
	numb = c.numb;
}

void Cvecara::move(Cvecara& c)
{
	list = c.list;
	c.list = nullptr;
	income = c.income;
	numb = c.numb;
}

void Cvecara::obrisi()
{
	while (list) {
		Elem* curr = list;
		list = list->next;
		delete curr;
	}
}

Cvecara::Cvecara()
{
	list = nullptr;
	income = 1000;
	numb = 0;
}

Cvecara::Cvecara(const Cvecara& c)
{
	copy(c);

}

Cvecara::Cvecara(Cvecara&& c)
{
	move(c);
}

ostream& Cvecara::Print(ostream& os, Cvecara& c)
{
	os << "zarada=" << this->income << "RSD" << endl;
	Elem* curr=this->list;
	while (curr) {
		os << *curr->buket << endl;
		curr = curr->next;
	}
	return os;
}

Cvecara::~Cvecara()
{
	obrisi();
}

void Cvecara::addBuket(Buket* b)
{
	if (b->Profit()< b->getNabavna() * 0.2 || income<b->getNabavna()) return;
	if (numb > 0) {
			if (list->buket->getProdajna() > b->getNabavna()) list = new Elem(b, list);
			else {
				Elem* prev = list;
				while (prev->next) {
					if (prev->next->buket->getProdajna() > b->getProdajna()) {
						prev->next = new Elem(b, prev->next);
					}
					prev = prev->next;
				}
			}
		}
	else
		list = new Elem(b, list);
		numb++;
		income -= b->getNabavna();
}

void Cvecara::prodaja(int k)
{
	if (k <= 0 || k> numb) cout << "Nevalidna pozicija";
	Elem* prev = nullptr, *curr = this->list, *p=nullptr;
	if (k == 1) {
		income += curr->buket->getProdajna();
		p = list;
		p->next=nullptr; 
		if (numb == 1) list = curr = nullptr;
		else list = list->next;
		delete p;
		numb--;
	}
	while (k && curr) {
		if (k == 1) {
			prev->next = curr->next;
			income += curr->buket->getProdajna();
			curr->next = nullptr;
			delete curr;
			numb--;
		}
		else{
			prev = curr;
			curr = curr->next;
		}
		k--;
	}

}

Cvecara& Cvecara::operator=(Cvecara c)
{
	swap(*this, c);
	return *this;

}

void swap(Cvecara& a, Cvecara& b)
{
	std::swap(a.list, b.list);
	std::swap(a.income, b.income);
	std::swap(a.numb, b.numb);

}

ostream& operator<<(ostream& os, Cvecara& c)
{
	return c.Print(os, c);
}
