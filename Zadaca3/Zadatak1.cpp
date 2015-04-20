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
	Cvor* x = new Cvor(1,NULL,y);
	Cvor* y = new Cvor(3,x,NULL);
	Cvor* z = new Cvor(5,NULL,x);

	while(x=x->next){
		cout << "<-" << x->n << "->"; 
	}

	return 0;
}