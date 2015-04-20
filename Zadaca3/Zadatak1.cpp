#include <iostream>
using namespace std;

class Cvor{
public:
	int n;
	Cvor *next;
	Cvor *prev;

public:
	Cvor(){
		n = 0;
		next = NULL;
		prev = NULL;
	}
	Cvor(int x, Cvor* prev, Cvor* next){
		n = x;
		this->next = next;
		this->prev = prev;
	}
};

int main()
{
	Cvor* x = new Cvor(1,NULL,NULL);
	Cvor* y = new Cvor(3,x,NULL);
	Cvor* z = new Cvor(5,NULL,x);

	x -> prev = NULL; x -> next = y;
	y -> prev = x; y -> next = z;
	z -> prev = y; z -> next = NULL;

	do{
		cout << "<-" << x->n << "->"; 
	}
	while(x=x->next);

	return 0;
}