#include "buket.h"
#include "cvet.h"

Buket::Buket()
{
	list = nullptr;
}



Buket::Buket(Buket&& b)
{
	move(b);
}

Buket& Buket::operator=(Buket b)
{
	swapop(*this, b);
	return *this;

}



int Buket::Profit()
{
	return this->getProdajna()-this->getNabavna();
}



void Buket::Sort()
{
	int n = len(this->list) - 1;

	while (n--)
	{
		Elem* curr = list;
		while (curr->next != nullptr)
		{
			if (curr->cvet->Name() > curr->next->cvet->Name())
			{
				swap(curr, curr->next);

			}
				curr = curr->next;
		}
	}

}

int Buket::getNabavna() const
{
	int sum = 0;
	Elem* curr = list;
	while (curr) {
		sum+=curr->cvet->Buy();
		curr = curr->next;
	}
	return sum;
}

Buket::~Buket()
{
	obrisi();
}

int Buket::getProdajna() const
{
	int sum = 0;
	Elem* curr = list;
	while (curr) {
		sum += curr->cvet->Sell();
		curr = curr->next;
	}
	return sum;
}

void swapop(Buket& a, Buket& b)
{
	std::swap(a.list, b.list);

}

ostream& Print(ostream& os, Buket& b){
	b.Sort();//bubble sort po krit naziv
	Buket::Elem* p = b.list;
	if (p == nullptr) os << "Nema liste";
	else os << "(";
	if (p != nullptr && p->next == nullptr)
		os << *p->cvet << ")";

	while (p->next){
		if (p->cvet != (p->next)->cvet) {
			os << *p->cvet;
			p = p->next;
			os << ",";
		}
		
		else {
			p = p->next;
			if (p->next == nullptr) {
				os << *p->cvet << ")";
			}
		}

	}
	os << b.getProdajna() << "RSD" << endl;
	return os;
}

void Buket::copy(const Buket& b)
{
	Elem* curr = b.list;
	while (curr) {
		list = new Elem (curr->cvet, list);
		curr = curr->next;
	}
}

void Buket::move(Buket& b)
{
	list = b.list;
	b.list = nullptr;
}

void Buket::obrisi()
{
	while (list) {
		Elem* curr = list;
		list = list->next;
		delete curr;
	}
}

Buket::Buket(const Buket& b)
{
	copy(b);

}

void Buket::Add(Cvet* cvet)
{
	list = new Elem(cvet, list);
}



ostream& operator<<(ostream& os, Buket& b)
{
	return Print(os, b);
}
void Buket::swap(Elem *curr, Elem *next)
{
	Cvet *temp = curr->cvet;
	curr->cvet = next->cvet;
	next->cvet = temp;
}
int Buket::len(Elem* list)
{
	Elem* temp = list;
	int i = 0;
	while (temp != nullptr)
	{
		i++;
		temp = temp->next;
	}

	return i;
}
