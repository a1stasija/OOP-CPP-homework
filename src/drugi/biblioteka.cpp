#include "biblioteka.h"

void Biblioteka::copy(const Biblioteka& b)
{
	name = b.name;
	cap = b.cap;
	num = b.num;
	knjige = new Knjiga*[cap = b.cap];
	for (int i = 0; i < cap; i++)
		knjige[i] = b.knjige[i];
}

void Biblioteka::move(Biblioteka& b)
{
	name = b.name;
	cap = b.cap;
	num = b.num;
	knjige = b.knjige;
	b.knjige = nullptr;

}

void Biblioteka::obrisi()
{	
	delete[] knjige;
	knjige = nullptr;
	num = 0;
}


Biblioteka::Biblioteka(string name, int cap)
{
	this->name = name;
	this->cap = cap;
	num = 0;
	knjige = new Knjiga*[cap];
}

Biblioteka::Biblioteka(const Biblioteka& b)
{
	copy(b);
}

Biblioteka::Biblioteka(Biblioteka&& b)
{
	move(b);
}

Biblioteka& Biblioteka::operator=(Biblioteka b)
{
	swap(*this, b);
	return *this;

}
string Biblioteka::getName() const
{
	return name;
}

int Biblioteka::getCap() const
{
	return cap;
}

int Biblioteka::getNum() const
{
	return num;
}

Biblioteka& Biblioteka::operator+=(Knjiga& k)
{
	if (num == cap) return*this;
	knjige[num] = !k;
	num++;
	return *this;
}

Knjiga* Biblioteka::find(int id)
{
	for (int i = 0; i < cap; i++) {
		if ((knjige[i]->getID()) == id) return knjige[i];
	}
	return nullptr;
}

Biblioteka::~Biblioteka()
{
	obrisi();
}

void swap(Biblioteka& a, Biblioteka& b)
{
	std::swap(a.name, b.name);
	std::swap(a.cap, b.cap);
	std::swap(a.num, b.num);
	std::swap(a.knjige, b.knjige);

}

ostream& operator<<(ostream& os, Biblioteka b)
{
	os << "BIBLIOTEKA " << b.getName() << b.getNum() << "/" << b.getCap() << endl;
	for (int i = 0; i < b.getNum(); i++) {
		os << b.knjige[i] << endl;
	}
	return os;
}
