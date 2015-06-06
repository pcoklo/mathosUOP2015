#include <iostream>
using namespace std;

template<class T, int n>
class Tuple
{
public:
	T *podaci;
	Tuple();
	Tuple(T *input);
	~Tuple();

	bool operator<(const Tuple &) const;
	bool operator>(const Tuple &) const;
};

int main(){

	return 0;
}