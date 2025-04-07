#ifndef _knjiga_h_
#define _knjiga_h_
#include <iostream>
#include <string>
using namespace std;

class Knjiga {
	string title, autor;
	static int cnt;
	int id;

public:
	Knjiga(string title, string autor);
	string getTitle() const;
	string getAutor() const;
	int getID() const;
	Knjiga(const Knjiga& k) = delete;
	Knjiga& operator=(const Knjiga& k)=delete;
	friend ostream& operator<<(ostream& os, Knjiga* k);
	Knjiga* operator!(); //posto je unarni op mora ovako


};
#endif
