#include "rec.h"

void Rec::obrisi()
{
	Elem* p;
	while (rec) {
		p = rec;
		rec = rec->next;
		delete p;
	}
}

void Rec::copy(const Rec& r)
{
	Elem* curr = r.rec, *novi=nullptr,*p=nullptr;
	while (curr) {
		if (curr == r.rec) {
			p = rec = new Elem(curr->a);
		}
		else {
			novi = new Elem(curr->a);
			p->next = novi;
			p = novi;
		}
		curr = curr->next;
	}	
}

void Rec::move(Rec& r)
{
	rec = r.rec;
	r.rec = nullptr;

}

Rec::Rec(string str)
{
	int n = str.length();
	Elem* p = rec, * novi = nullptr;
	for (int i = 0; i < n; i++) {
		bool flag = provera(str[i]);
		if(flag){
		if (!rec) p = rec = new Elem(str[i], rec);
		else {
			novi = new Elem(str[i]);
			p->next = novi;
			p = novi;
		}
		}
	}
}

Rec::Rec(const Rec& r)
{
	copy(r);
}

Rec::Rec(Rec&& r)
{
	move(r);
}

Rec& Rec::operator=(Rec r)
{
	swap(*this, r);
	return *this;

}

int Rec::operator+()
{
	int n = 0;
	Elem* p = rec;
	while (p) {
		n++;
		p = p->next;
	}
	return n;
}

int Rec::operator~()
{
	int n = 0;
	Elem* p = rec;
	while (p->next) {
		if (samoglasnikm.find(p->a) < samoglasnikm.length() || samoglasnikv.find(p->a) < samoglasnikv.length()) {
			n++;
			if (sonantm.find(p->next->a) < sonantm.length() || sonantv.find(p->next->a) < sonantv.length()) {
				p = p->next;
			}
			if (p->next) p = p->next;
			else break;
		}
		else if (sonantm.find(p->a) < sonantm.length() || sonantv.find(p->a) < sonantv.length()) {
			if (!(samoglasnikm.find(p->next->a) < samoglasnikm.length() || samoglasnikv.find(p->next->a) < samoglasnikv.length())) { n++; }
			p = p->next;
		}
		else p = p->next;
	}
	if (samoglasnikm.find(p->a) < samoglasnikm.length() || samoglasnikv.find(p->a) < samoglasnikv.length()) n++;
	return n;
}

int Rec::operator()(int n)
{
	int pos;
	int num= ~*this;
	if (abs(n) > num) return -1;
	if (n >= 0) {
		pos=pretraga(n);
	}
	else {
		int k;
		k = (num+n);
		pos=pretraga(k);
	}
	return pos;
}

int Rec::pretraga(int n)
{
	Elem* p = rec;
	int pos = 0,k=0;
	while(p->next){
	if (samoglasnikm.find(p->a) < samoglasnikm.length() || samoglasnikv.find(p->a) < samoglasnikv.length()) {
		if (n == k) return pos;
		k++;
		if (sonantm.find(p->next->a) < sonantm.length() || sonantv.find(p->next->a) < sonantv.length()) {
			p = p->next;
			pos++;
		}
		if (p->next) {
			p = p->next;
			pos++;
		}
		else break;
	}
	else if (sonantm.find(p->a) < sonantm.length() || sonantv.find(p->a) < sonantv.length()) {
		if (!(samoglasnikm.find(p->next->a) < samoglasnikm.length() || samoglasnikv.find(p->next->a) < samoglasnikv.length())) { if (n == k) return pos; k++; }
		p = p->next;
		pos++;
	}
	else {
		p = p->next; 
		pos++;
	}
}
if (samoglasnikm.find(p->a) < samoglasnikm.length() || samoglasnikv.find(p->a) < samoglasnikv.length()) { if (n == k) return pos; k++; }
}

Rec::~Rec()
{
	obrisi();
}

bool Rec::provera(char k)
{
	if ((k >= 65 && k <= 90) || (k >= 97 && k <= 122)) return true;
	else return false;
}

void swap(Rec& a, Rec& b)
{
	std::swap(a.rec, b.rec);

}

bool operator^(Rec r1, Rec r2)
{
	int n1, n2;
	n1 = ~r1;
	n2 = ~r2;
	Rec::Elem* p1 = r1.rec, * p2 = r2.rec;
	int br1, br2;
	br1 = +r1;
	br2 = +r2;
	int pos1, pos2;
	if (n1 == 1 || n2 == 1) {
		if (n1 == 1 && n2 == 1) {
			if (br1 != br2) return false;
			else {
				while (p1) {
					if (p1->a != p2->a && abs(p1->a - p2->a) != 32) return false;
					p1 = p1->next;
					p2 = p2->next;
				}
				return true;
			}
		}
		else if (n1 == 1) {
			pos1 = 0;
			pos2 = r2(-1);
			while (pos2) {
				p2 = p2->next;
				pos2--;
			}
			if ((br1 - pos1) != (br2 - pos2)) return false;
			while (p1) {
				if (p1->a != p2->a && abs(p1->a - p2->a) != 32) return false;
				p1 = p1->next;
				p2 = p2->next;
			}
			return true;
		}
		else {
			pos2 = 0;
			pos1 = r1(-1);
			while (pos1) {
				p1 = p1->next;
				pos1--;
			}
			if ((br1 - pos1) != (br2 - pos2)) return false;
			while (p1) {
				if (p1->a != p2->a && abs(p1->a - p2->a) != 32) return false;
				p1 = p1->next;
				p2 = p2->next;
			}
			return true;

		}
	}
	else {
		pos1 = r1(-2);
		pos2 = r2(-2);
		if ((br1 - pos1) != (br2 - pos2)) return false;
		while (pos1) {
			p1 = p1->next;
			pos1--;
		}
		while (pos2) {
			p2 = p2->next;
			pos2--;
		}
		while (p1) {
			if (p1->a != p2->a && abs(p1->a - p2->a) != 32) return false;
			p1 = p1->next;
			p2 = p2->next;
		}
		return true;
	}
}

istream& operator>>(istream& is, Rec& r1)
{
	r1.obrisi();
	string s;
	is >> s;
	Rec temp(s);
	r1 = temp;
	return is;
}

ostream& operator<<(ostream& os, Rec& r1)
{
	Rec::Elem* curr = r1.rec;
	while (curr) {
		os << curr->a;
		curr = curr->next;
	}
	return os;
}

