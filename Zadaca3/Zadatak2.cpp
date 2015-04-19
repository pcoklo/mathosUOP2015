#include <iostream>
#include <cstdlib>
using namespace std;

class node
{
public:
	int value;		//podatak / key / data /woteva
	node* _prev;	//pokazivač na prethodni čvor
	node* _next;	//pokazivać na sljedeći čvor

	node();
	node(int val, node* prev, node* next);
	node(const node & N);

	// pristupi elementima / metode
	int key() const {return value;}
	node* prev() {return _prev; }
	node* next() {return _next; }
};

class list	//papira(ne)
{
protected:
	node* _head;
	node* _tail;
public:
// konstruktori
	list();
	list(const list & L);
	~list();
	// pristup elementima 
	node* front(); // vraća pokazivač na prvi element liste
	node* back(); // vraća pokazivač na zadnji element liste
	void print(); // ispis elemenata liste
	// modifikatori liste
	void push_front(node &x); // dodajte element na početak liste
	node* pop_front(); // vraća i briše element s početka liste
	void push_back(node &x); // na kraj liste stavlja element x
	node* pop_back(); // s kraja liste briše i vraća element 

	void insert(node* prev, node &x); // ubacuje novi čvor x iza čvora prev
	void erase(node &x); // brišu se čvor x iz liste
	void clear(); // metoda briše elemente liste
	// operacije
	void sort(); // sortira elemente liste po vrijednosti node.value
	void reverse(); // obrni redoslijed elemenata u listi
	// ostali detalji implementacije su proizvoljni 
	// ...
};

node::node(){
	value = 0;
	_next = NULL;
	_prev = NULL;
}

node::node(int val, node* prev, node* next){
	value = val;
	_prev = prev;
	_next = next;
}

node::node(const node & N){
	this->value = N.value;
	this->_prev = N._prev;
	this->_next = N._next;
}

list::list(){
	_head = NULL;
	_tail = NULL;
}

list::~list(){
	if(_head)
		while(_head)
			pop_front();
}

node* list::front(){return _head;}
node* list::back(){return _tail;}

void list::print(){
	if(_head){
		node *tmp = _head;
		while(tmp){
			cout << tmp -> value << "\t";
			tmp = tmp -> _next; 
		}
	}
	cout << endl;
}

void list::push_front(node &x){
	node * newNode = new node();
	newNode -> value = x.value;
	newNode -> _next = _head;

	if(_head != NULL){
		_head -> _prev = newNode;
	}
	else{
		_tail = newNode;
	}
	_head = newNode;
	_head -> _prev = NULL;
}

node* list::pop_front(){
	if(_head -> _next){
		_head = _head -> _next;
		_head -> _prev = NULL;
	}
	else if(_head){
		_head = NULL;
	}
}

void list::push_back(node &x){
	node * newNode = new node();
	newNode -> value = x.value;
	newNode -> _prev = _tail;

	if(_tail != NULL){
		_tail -> _next = newNode;
	}
	else{
		_head = newNode;
	}
	_tail = newNode;
	_tail -> _next = NULL;
}

node* list::pop_back(){
	if(_tail -> _prev){
		_tail = _tail -> _prev;
		_tail -> _next = NULL;
	}
	else if(_tail){
		_tail = NULL;
	}
}

void list::insert(node* prev, node &x){}
void list::erase(node &x){}
void list::clear(){}

void list::sort(){}
void list::reverse(){}


int main()
{
	list L;
	for(int i=0;i<2;i++)
	{
		node x(i,NULL,NULL);
		node y(i,NULL,NULL);

		L.push_back(x);
		L.push_front(y);
	}

//	L.remove(L.front()->next()->next());
	cout << "Pocetak: " << L.front() -> value << endl;
	cout << "Kraj: " << L.back() -> value << endl;
	L.print();
//	L.sort();
//	L.print();
//	L.reverse();
//	L.print();
//	L.clear();

	return 1;
}