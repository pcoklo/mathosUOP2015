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
	void Mnozi(const Vektor& V); // V1 * V2 skalarno
	
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

Vektor::Vektor(int s){
	len = s;
	P = new int [len];
	curr_len = 0;
}

Vektor::Vektor(const Vektor &V){
	if (V.curr_len){
		this -> curr_len = V.curr_len;
		this -> len = V.len;

		this -> P = new int [this -> len];

		for (int i = 0; i < this -> curr_len; i++){
			this -> P[i] = V.P[i]; 
		}
	}
}

bool Vektor::append(int x){
	if (curr_len < len){
		P[curr_len] = x;
		curr_len++;
		return true;
	}

	else return false;
}

void Vektor::ispisi(){
	if (curr_len){
		for (int i=0; i < curr_len; i++)
			cout << P[i] << "\t";
		cout << endl;
	}
}

void Vektor::Mnozi(const Vektor& V){
	if (this -> curr_len == V.curr_len){
		int sum=0;
		for (int i=0; i<V.curr_len; i++)
			sum += this -> P[i] * V.P[i];
		cout << "Skalarni produkt = " << sum << endl;			
	}
}

void Vektor::Zbroji(const Vektor& V1, const Vektor& V2){
	if(V1.curr_len == V2.curr_len){
		this -> len = V1.len;
		this -> curr_len = V1.curr_len;
		this -> P = new int [this -> len];

		for (int i=0; i<V1.curr_len; i++)
			this -> P[i] = V1.P[i] + V2.P[i];
	}
}

int main(){
	Vektor V(6), B;

	V.append(0);
	V.append(6);
	V.append(5);

	Vektor A(V);
	A.ispisi();

	A.Mnozi(V);

	B.Zbroji(A,V);
	B.ispisi();

	return 0;
}
