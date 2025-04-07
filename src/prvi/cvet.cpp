#include "cvet.h"
#include "buket.h"
//umesto print fje treba da imas preklapanje operatora <<

Cvet::Cvet(string name, int buy, int sell)
{
	this->name = name;
	this->buy = buy;
	this->sell = sell;
}

string Cvet::Name() const
{
	return name;
}

int Cvet::Sell() const
{
	return sell;
}

int Cvet::Buy() const
{
	return buy;
}

int Cvet::Profit()
{
	return this->sell-this->buy;
}




bool operator==(Cvet& cvet1, Cvet& cvet2)
{
	return cvet1.name == cvet2.name;
}

ostream& operator<<(ostream& os, Cvet& c)
{
	return os << c.name;
}

bool operator>(Buket& b1, Buket& b2)
{
	return b1.getProdajna() > b2.getProdajna();
}
