#include <iostream>
using namespace std;

template<class T>
class vector {
public:
	vector(){}
	vector(size_t size);

	size_t size() const; //size_t = unsigned int
	size_t capacity() const;

	// dodavanje i brisanje elemenata s kraja
	void push_back(T x);
	T pop_back();
	void resize_to_fit();
	void clear();

	// u ovom dijelu potrebno je napraviti izmjene u potpisu metodu kako bi radilo kao metode predloska
	// operatori pridruzivanja

	vector& operator= (const vector<T>&);
	vector& operator+= (const vector<T>&);
	vector& operator-= (const vector<T>&);
	vector& operator*= (T lambda);

	// aritemticki operatori
	vector operator + (const vector<T>&); // zbrajanje vektora
	vector operator - (const vector<T>&); // oduzimanje vektora
	vector operator * (T lamba); // oduzimanje vektora

	// usporedba
	vector operator == (const vector<T>&); // == u smislu relacije
	vector operator != (const vector<T>&); // ekvivalencije
	// kraj izmjena
};

int main() {
	vector<double> L1;
	vector<Complex> L2; // Pair je tip definiran u prvom zadatku

	// ...
	return 0;
}