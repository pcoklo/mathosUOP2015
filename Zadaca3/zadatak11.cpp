#include <iostream>
using namespace std;

class Cvor{
public:
	int n;
	Cvor* next;
	Cvor* prev;

public:
	Cvor(){}
	Cvor(int x, Cvor* prev, Cvor* next){
		n = x;
		this -> next = next;
		this -> prev = prev;
	}

};

int main()
{
	Cvor* x = new Cvor(1, NULL, NULL);
	Cvor* y = new Cvor(3, x, NULL);
	Cvor* z = new Cvor(5, y, NULL);

	x -> next = y;
	y -> next = z;
	

	while(x)
	{
		cout << "<-" << x -> n << "->";
        x = x->next;
	}

	return 0;
}