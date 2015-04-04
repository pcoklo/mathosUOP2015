#include <iostream>
using namespace std;

class vector
{
protected:
	size_t s;
	size_t c;
	float *vektor;

public:
	vector(){};
	vector(size_t size);
	size_t size() const; //size_t = unsigned int
	size_t capacity() const;
	// dodavanje i brisanje elemenata s kraja
	void push_back(float x);
	float pop_back();
	void resize_to_fit();
	void clear();
};

int main(){

	return 1;
}
