#include "skup.h"
#include "rec.h"
using namespace std;

int main() {
	/*Skup s("mama");
	s += 'a';
	s += 'k';
	bool p1, p2;
	p1 = s('k');
	p2 = s('h');
	s.Print();
	cout << p1;
	cout << p2;
	Rec rec1("Rec5"), rec2("Ocena"), rec3("Klavijatura"), rec4("Ana"), rec5("Na"), rec6("Sauna"), rec7("Moana");
	int n;
	n = +rec1;
	cout << n<<endl;
	n = ~rec2;
	cout << n << endl;
	n = ~rec3;
	cout << n << endl;
	n = rec3(0);
	cout << n << endl;
	n = rec3(-1);
	cout << n << endl; 
	bool rima1 = rec1 ^ rec2; //0
	cout << rima1 << endl;
	bool rima2= rec2 ^ rec4; //0
	cout << rima2 << endl;
	bool rima3 = rec4 ^ rec7; //1
	cout << rima3 << endl;
	cin >> rec1;
	cout << rec1;
	*/
	Rec r1("Pica"), r2("Banana");
	bool rima1 = r1 ^ r2;
	if (rima1) cout << "Rimuju se"<<endl;
	else cout << "Ne rimuju se"<<endl;
	Rec r3("Pneumonoultramicroscopicsilicovolcanoconiosis");
	int br = +r3;
	cout << br;
}