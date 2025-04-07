#include "knjiga.h"
using namespace std;

int Knjiga::cnt = 0;

Knjiga::Knjiga(string title, string autor)
{
	this->title = title;
	this->autor = autor;
	id = cnt++;
}

string Knjiga::getTitle() const
{
	return title;
}

string Knjiga::getAutor() const
{
	return autor;
}

int Knjiga::getID() const
{
	return id;
}

Knjiga* Knjiga::operator!()
{

	return new Knjiga(this->getTitle(), this->getAutor());
}


ostream& operator<<(ostream& os, Knjiga* k)
{
	os << "KNJIGA:" << k->getID() << ": naslov " << k->getTitle() << "-" << k->getAutor() << endl;
	return os;
}
