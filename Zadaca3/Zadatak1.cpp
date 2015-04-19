#include <iostream>
using namespace std;

class Cvor{
public:
	int n;
	Cvor *next;
	Cvor *prev;

public:
	Cvor(){}
	Cvor(int x, Cvor* prev, Cvor* next){
		n = x;
		this->next = next;
		this->prev = prev;
	}
};

int main()
{
	Cvor x(1,NULL,NULL);
	Cvor y(3,x,NULL);
	Cvor z(5,NULL,x);
	while(x=x->next)
	{
		cout << "<-" << x.n "->"; 
	}
}