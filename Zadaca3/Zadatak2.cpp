#include <iostream>
using namespace std;

class node
{
public:
	int value;
	node* _prev;
	node* _next;

	node(){}
	node(int val, node* prev, node* next);

	// pristupi elementima
	int key() const {return val;}
	node* prev() {return _prev; }
	node* next() {return _next; }
};

class list
{
public:
// konstruktori
	list();
	list(const list&);
	// pristup elementima 
	node* front(); // vraća pokazivač na prvi element liste
	node* back(); // vraća pokazivač na zadnji element liste
	void print(); // ispis elemenata liste
	// modifikatori liste
	void push_front(cvor *x); // dodajte element na početak liste
	node* pop_front(); // vraća i briše element s početka liste
	void push_back(cvor *x); // na kraj liste stavlja element x
	node* pop_back(); // s kraja liste briše i vraća element 

	void insert(node* prev, node* x); // ubacuje novi čvor x iza čvora prev
	void erase(node* x); // brišu se čvor x iz liste
	void clear(); // metoda briše elemente liste
	// operacije
	void sort(); // sortira elemente liste po vrijednosti node.value
	void reverse(); // obrni redoslijed elemenata u listi
	// ostali detalji implementacije su proizvoljni 
	// ...
};

int main()
{
	list L;
	for(int i=0;i<10;i++)
	{
		int val = rand()%10;
		node x(rand()%10,NULL,NULL);
		node y(rand()%10,NULL,NULL);

		L.push_back(x);
		L.push_front(y);
	}

	L.remove(L.front()->next()->next());
	L.print();
	L.sort();
	L.print();
	L.reverse();
	L.print();
	L.clear();

	return 1;
}