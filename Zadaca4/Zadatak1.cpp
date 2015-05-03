#include <iostream>
using namespace std;

class Vektor {
public:
	int *P;
	int len;
	int curr_len;

public:
	// konstruktori
	Vektor(){P = NULL;}
	Vektor(int s);
	Vektor(const Vektor &V); // konstruktor kopiranja

	// ostale metode (interface klase Vektor)
	bool append(int); // dodaje int na kraj
	bool search(int); // vrati 'true' ako je pronašao traženi int
	void ispisi();// ispisuje Vektor na ekran (standardni output)
	void sort();// sortira elemente Vektora
	
	void Zbroji(const Vektor& V1, const Vektor& V2); // V1 + V2
	void Mnozi(const Vektor& V1); // V1 * V2 skalarno
	
	// operatori
	void operator=(const Vektor&);
	Vektor operator+(const Vektor&) const;
	Vektor operator-(const Vektor&) const;
	int operator*(const Vektor&) const;
	void operator+=(const Vektor&);
	void operator-=(const Vektor&);
	bool operator==(const Vektor&) const;
	int& operator[](int) const;
	// destruktor
	~Vektor(){delete [] P;}
};