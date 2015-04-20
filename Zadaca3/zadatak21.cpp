#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

class Node
{
public:
	int value;
	Node* _prev;
	Node* _next;

	Node(){}
	Node(int val, Node* prev, Node* next){
		value = val;
		_prev = prev;
		_next = next;
	};

	// pristupi elementima
	int key() const {return value;}
	Node* prev() {return _prev; }
	Node* next() {return _next; }
};

class List
{
public:
// konstruktori
	Node * _front;
	Node * _back;

	List(){
		_back = NULL;
		_front = NULL;
	};
	List(const List&);
	// pristup elementima 
	Node* front(){ return _front; }; // vraća pokazivač na prvi element Liste
	
	Node* back(){ return _back; }; // vraća pokazivač na zadnji element Liste
	void print(){
		Node * temp = new Node();
		temp = _front;
		while(temp != NULL){
			cout << "<-" << temp -> key() << "->";
			temp = temp -> _next;
		}
		cout << endl;
	}; // ispis elemenata Liste
	// modifikatori Liste
	void push_front(Node *node){ // dodajte element na početak Liste
		Node * newNode = new Node();
		newNode -> value = node -> value;

		newNode -> _next = _front;
		
		if(_front == NULL) _back = newNode; 
		else _front -> _prev = newNode;

		_front = newNode;
	};

	Node* pop_front(){ // vraća i briše element s početka Liste
		if(_front ->_next != NULL){
			Node * temp = _front;
			_front = _front -> _next;
			_front -> _prev = NULL;
			return temp;
		}
		else if(_front != NULL){
			Node *temp = _front;
			_front = NULL;
			return temp;
		}
	};
	void push_back(Node *node){ // na kraj Liste stavlja element x
		Node * newNode = new Node();
		newNode -> value = node -> value;

		newNode -> _prev = _back;

		if(_back == NULL) _front = newNode;
		else _back -> _next = newNode;

		_back = newNode;
	};
	Node* pop_back(){ // s kraja Liste briše i vraća element
		Node * temp = _back;
		if(_back -> _prev != NULL){
			_back = _back -> _prev;
			_back -> _next = NULL;
		}
		else if(_back != NULL){
			_back = NULL;
		}
		return temp;
	};
	void insert(Node* node, Node* newNode){ // ubacuje novi čvor x iza čvora node
		newNode -> _prev = node;
		newNode -> _next = node -> _next;
		if (node -> _next == NULL) _back = newNode;
		else node -> _next -> _prev = newNode;
		node -> _next = newNode;
	};
	void erase(Node* node); // brišu se čvor x iz Liste
	void clear(){// metoda briše elemente Liste
		if(_front)
			while(_front)
				pop_front;
	}; 
	// operacije
	void sort(){  // sortira elemente Liste po vrijednosti Node.value
		if(_front != NULL || _front -> _next != NULL){
			Node * tmp = _front; //vozimo se kroz niz
			Node * temp = new Node();

			bool sortirano = 0;
			while (!sortirano){
				sortirano = 1;
				tmp = _front;

				while (tmp -> _next != NULL){
					if((tmp -> value) > (tmp -> _next -> value)){
						sortirano = 0;
						temp -> value = tmp -> value;
						tmp -> value = tmp -> _next -> value;
						tmp -> _next -> value = temp -> value;
					}
					tmp = tmp -> _next;
				}
			}
		}
	};
	void reverse(){// obrni redoslijed elemenata u Listi
	if( _front==NULL || _front -> _next == NULL) return;
		Node *parent = _front;
		Node *me = _front -> _next;
		Node *child = me -> _next;

		_front -> _next = NULL;
		me -> _next = _front;

		while( child != NULL){
			me -> _next = parent;
			parent = me;
			me = child;
			child = child -> _next;
		}

		_front = me;
		_front -> _next = parent;
	}; 
	// ostali detalji implementacije su proizvoljni 
	// ...
};

int main()
{
	srand(time(0));
	List L;
	for(int i=0;i<10;i++)
	{
		int val = rand()%10;
		Node* x = new Node(rand()%10,NULL,NULL);
		Node* y = new Node(rand()%10,NULL,NULL);

		L.push_back(x);
		L.push_front(y);
	}

//	L.remove(L.front()->next()->next());
	L.print();
	L.pop_back();L.pop_back();L.pop_back();
	L.pop_front();L.pop_front();L.pop_front();L.pop_front();
	L.print();
	L.sort();
	L.print();
	L.reverse();
	L.print();
	L.clear();
	L.print();
/**/
	return 1;
}