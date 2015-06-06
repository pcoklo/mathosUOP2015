#include <iostream>
using namespace std;

template<class T>
void sort(T *x, int N);

class Pair
{
public:
	Pair();
	Pair(float x,float y);
	Pair(const Pair &T);

	bool operator<(const Pair &) const;
	bool operator>(const Pair &) const;
};

int main(){

	return 0;
}