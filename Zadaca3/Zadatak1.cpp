#include <iostream>
using namespace std;
class Cvor{
public:
	int n;
	Cvor next;
	Cvor prev;

public:
	Cvor(){}
	Cvor(int x, Cvor* prev, Cvor* next){n = x; next = next; prev = prev;}

};

int main()
{
	Cvor x(1,NULL,y);
	Cvor y(3,x,NULL);
	Cvor z(5,NULL,x);
	while(x=x->next)
	{
		cout << "<-" << x.n "->"; 
	}
}