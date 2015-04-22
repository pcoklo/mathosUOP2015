#include <iostream>
#include <cstdlib>

using namespace std;

class Node{
public:
	int value;
	Node* _prev;
	Node* _next;

	Node();
	Node(int value, Node* prev, Node* next);// pristupi elementima
	
	int key() const { return value;}
	Node* prev() { return _prev; }
	Node* next() { return _next; }
};

class List{
public:
	Node * _head;
	Node * _tail;
// konstruktori
	List();

	// pristup elementima
	Node* head(){ return _head; };// vraća pokazivač na prvi element Liste
	Node* tail(){ return _tail; };// vraća pokazivač na zadnji element Liste
	void print();// ispis elemenata Liste
	
	// modifikatori Liste
	void push_front(Node *node); // dodajte element na početak Liste
	Node* pop_front();// vraća i briše element s početka Liste
	void push_back(Node *node); // na kraj Liste stavlja element node
	Node* pop_back();// s kraja Liste briše i vraća element
	void insert(Node* node, Node* newNode);// ubacuje novi čvor node iza čvora node
	void erase(Node* node);// brišu se čvor node iz Liste

	void clear();// metoda briše elemente Liste

	// operacije
	void sort();// sortira elemente Liste po vrijednosti Node.value
	void reverse();// obrni redoslijed elemenata u Listi
	// ostali detalji implementacije su proizvoljni
	// ...
};

//defaultni/trivialni konstrukor čvorova, meće sve vrijednosti u null
Node::Node(){
	value = 0;
	_next = NULL;
	_prev = NULL;
}

//'onaj drugi' konstruktor čvorova, radi to što konstruktori rade
Node::Node(int value, Node* _prev, Node* _next){
	this -> value = value;
	this -> _prev = _prev;
	this -> _next = _next;
}

//defaultni konstrukto liste, meće vrijednost head i tail u null, jer.
List::List(){
	_head = NULL;
	_tail = NULL;
}

//print funkcija liste printa listu
void  List::print(){
	Node * temp = _head;		//stvorimo čvor temp i damo mu vrijednost prvog čvora
	while(temp){				//sve dok čvor ima nekaku vrijednost 
		cout << "<-" << temp -> value << "->";	//piši listu kao u prvom zadatku
        temp = temp -> _next;	//vrijednost temp dobije vrijednost sljedećeg
        //kad dođe do kraja temp dobije vrijednost NULL, while se prekida
	}
	cout << endl;	//ispiši novi red poslje liste, da bude fino lijepo i uredno
}

void List::push_front(Node *node){	//push front metoda stavlja čvor na prvo mjesto
	Node * newNode = new Node();	//stvaramo novi čvor imena newNode i dinamiči alociramo njegovu memoriju nadedbom new, Node() je defaultni konstruktor klase Node
	newNode -> value = node -> value;	//vrijednost value prosljeđenog čvora 'node' kopiramo u vrijednos novog čvora

	//kako stavljamo novi čvor na početak liste, taj čvor će biti prvi
	newNode -> _next = _head;	//stoga njegov sljedbenik je trenutni prvi odnosno _head

	//ako stavljamo čvor u listu koja nije prazna, tj. postoji li već čvor koji je _head
	if( _head  ) _head -> _prev = newNode;	//tog čvora _head prethodnik je newNode jer je newNode sada prvi
	else _tail = newNode;	//stavljamo li pak newNode u praznu listu, newNode je u tom slučaju prvi i zadnji čvor liste 
	//stoga _tail je i newNode
	
	_head = newNode;	//i naravno prvi čvor postaje noviČvor
}

void List::push_back(Node *node){	//push back metoda stavlja čvor na zadnje mjesto
	Node * newNode = new Node();	//stvaramo novi čvor imena newNode i dinamiči alociramo njegovu memoriju nadedbom new, Node() je defaultni konstruktor klase Node
	newNode -> value = node -> value;	//vrijednost value prosljeđenog čvora 'node' kopiramo u vrijednos novog čvora

	//kako stavljamo novi čvor na kraj liste, taj čvor će biti zadnji
	newNode -> _prev = _tail;	//stoga njegov prethodnik je trenutni zadnji odnosno _tail

	//ako stavljamo čvor u listu koja nije prazna, tj. postoji li već čvor koji je _tail
	if( _tail  ) _tail -> _next = newNode;	//tog čvora _tail sljedbenik je newNode jer je newNode sada zadnji
	else _head = newNode;	//stavljamo li pak newNode u praznu listu, newNode je u tom slučaju prvi i zadnji čvor liste 
	//stoga _head je i newNode
	
	_tail = newNode;	//i naravno zadnji čvor postaje noviČvor
}

Node* List::pop_front(){		//pop front metoda skida prvi čvor s liste i radi return njegove vrijednosti
	if( _head -> _next ){		//ako postoji više od jednog čvora u listi
		Node *temp = _head;		//stvorimo novi čvor i dodjelimo mu vrijednost prvog čvora
	
		_head = _head -> _next;	//sljedeći čvor poslje prvoga sada postalje prvi
		_head -> _prev = NULL;	//čvor koji je do sada bio prvi sada je prethodnik prvom, i njega brišemo
		
		return temp;			//vraćamo vrijednost nekadašnjeg prvog
	}

	else if ( _head ){			//ako postoji samo jedan čvor u listi
		Node *temp = _head;		//stvorimo novi čvor i dodjelimo mu vrijednost prvog čvora
	
		_head = NULL;			//vrijednost prvog elementa stavimo u null
		
		return temp;			//vratimo vrijednost nekadašnjeg elementa
	}

//	else						//ako nema čvorova neradimo ništa
}

Node* List::pop_back(){			//pop back metoda skida zadnj čvor s liste i radi return njegove vrijednosti
	if( _tail -> _prev ){		//ako postoji više od jednog čvora u listi
		Node *temp = _tail;		//stvorimo novi čvor i dodjelimo mu vrijednost zadnjeg čvora
	
		_tail = _tail -> _prev;	//prethodni čvor poslje zadnjeg sada postalje zadnji
		_tail -> _next = NULL;	//čvor koji je do sada bio zadnji sada je sljedeći zadnjem, i njega brišemo
	
		return temp;			//vraćamo vrijednost nekadašnjeg zadnjeg
	}

	else if ( _tail ){			//ako postoji samo jedan čvor u listi
		Node *temp = _tail;		//stvorimo novi čvor i dodjelimo mu vrijednost zadnjeg čvora

		_tail = NULL;			//vrijednost prvog elementa stavimo u null

		return temp;			//vratimo vrijednost nekadašnjeg elementa
	}

//	else						//ako nema čvorova neradimo ništa
}

//metoda inster dodaje čvor newNode iza čvora node
void List::insert(Node* node, Node* newNode){
	newNode -> _prev = node;					//kako dodajemo novi čvor poslje čvora node, prethodnik novog čvora je čvor node
	newNode -> _next = node -> _next;			//sljedeći čvor novog čvora postaje čvor koji je sljedeći čvoru node
	if(node -> _next == NULL) _tail = newNode;	//u slsučaju da dodajemo novi čvor na kraj liste, novi čvor postaje zadnji 
	else node -> _next -> _prev = newNode;		//a ako ne dodajemo čvor na kraj liste prethodni čvor sljedećeg čvora poslje node, postaje novi čvor
	node -> _next = newNode;					//sljedeći čvor čvora node postaje newNode jer ga stavljamo iza
}

//metoda erase briše čvor node sa liste
void List::erase(Node* node){
	if(node -> _prev == NULL)	//ukoliko brišemo čvor ipred kojeg nema ništa, odnosno prvi čvor sa liste
		_head = node -> _next;	//prvi čvor postaje sljedeči čvor poslje čvora kojeg brišemo

	else	//uspurotnom šljedeći čvor prethodnika node postalje sljedbenik čvora node
		node -> _prev -> _next = node -> _next;
	
	if(node -> _next == NULL)	//ukoliko brišemo čvor iza kojeg nema ništa, odnosno zadnji čvor sa liste
		_tail = node -> _prev;	//zadnji čvor postaje prethodni čvor prije čvora kojeg brišemo

	else	//usuprotnom prethodni čvor sljedbenika node postaje postaje prethodnik čvora node
		node -> _next -> _prev = node -> _prev;

	delete node;	//dilitaj node
}

//metoda clear briše sve čvorove iz liste
void List::clear(){
	while( _head ) pop_front(); 	//sve dok postoji čvor na početku liste, skidaj s početka
}

//metoda sort sortira čvorove po vrijednosti value
void List::sort(){
	//možemo sortirati listu ako postoje barem dva čvora u listi
	if(_head -> _next){
		bool swap = 1;	//jeli potrebno sortirati, pretpostavimo da je
		while (swap){	//počnemo sortirati sve dok je potrebno sortirati
			swap = 0;	//pretpostavimo da više nije potrebno sortirati
			Node* tmp = _head;	//svorimo čvor tmp s kojim šibamo kroz listu
			while (tmp -> _next){	//sve dok sljedeči od tmp nije null listaj jer idemo do predzadnjeg
				//ukoliko vrijednost ovo elementa je veća od vrijednosti sljedećeg
				if ((tmp -> value) > (tmp -> _next -> value)){
					swap = 1;	//znači da nismo sortirali do kraja
					Node* temp = new Node();	//stvorimo novi čvor temp pomoću kojega vršimo zamjenu
					temp -> value = tmp -> value;	//vrijednost trenutnog čvora stavljamo u temp
					tmp -> value = tmp -> _next -> value;	//vrijednost sljedećeg čvora stavljamo u vrijednost trenutnog
					tmp -> _next -> value = temp -> value;	//vrijednost temp čvora stavljamo u vrijednost sljedećeg
				}
				tmp = tmp -> _next;	//temp postaje sljedeći
			}
		}
	}
}

//moetoda reverse okreće čvorove...
void List::reverse(){
	//nemožemo okretati listu koja nema barem dva elementa
	//neda mi se razmišljati više tu je link...
	//http://www.codeproject.com/Articles/27742/How-To-Reverse-a-Linked-List-Different-Ways
	if( _head == NULL || _head -> _next == NULL) return;

	Node *parent = _head;
	Node *me = _head -> _next;
	Node *child = me -> _next;

	_head -> _next = NULL;
	me -> _next = _head;

	while( child != NULL){
		me -> _next = parent;
		parent = me;
		me = child;
		child = child -> _next;
	}

	_head = me;
	_head -> _next = parent;
}

int main(){
	List L;
	for(int i=0;i<10;i++)
	{
		int val = rand()%10;
		Node *x = new Node(rand()%10,NULL,NULL);
		Node *y = new Node(rand()%10,NULL,NULL);
		L.push_back(x);
		L.push_front(y);
	}
	L.print();
	L.erase(L.head()->next()->next());
	L.print();
	L.pop_front();
	cout << L.head()->key() << endl;
	L.sort();
	L.print();
	L.reverse();
	L.print();
	L.clear();
	L.print();

	return 0;
}
