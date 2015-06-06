#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

template<class T>
class Vektor {
protected:	//protected zato da se nemože pristupati varijablama van klase
	size_t s;	// s kao size
	size_t c;	// c kao capacity

	T *vektor;	// vektor kao Vektor, pointer za dinamičku alokaciju memorije
public:
	Vektor(){	// konstruktor koji se poziva bez parametara
		s = 0;	// stoga stavljamo defaulte veličine. 0 za size jer je veličina na početku nula
		c = 4;	// kapacitet je neki broj. koji vam se najviše svidi.
		vektor = new T[c];	//dinamička alokacija memorije u vektor velečine kapaciteta
	};

	Vektor(size_t capacity){	//konstruktor koji se poziva s parametrom capacity
		s = 0;
		c = capacity;	//koji stavimo u kapacitet. jer imamo svoj razlog 
		vektor = new T[c];	
	};

	Vektor(const Vektor &V){
		if(V.c){
			this->c = V.c;
			this->s = V.s;

			this->vektor = new T[this->c];

			for(int i=0; i<this->s; i++)
				this->vektor[i] = V.vektor[i];
		}
	};

	~Vektor(){ delete[] vektor; };	//destrukror koji dilita alociranu memoriju

	size_t size() const {return s;};	//metoda size vraća veličinu
	size_t capacity() const {return c;};	//metoda capacity vraća kapacitet

	// dodavanje i brisanje elemenata s kraja
	void push_back(T x){
		if(s==c){
			T *temp = new T[c];
			for(int i=0; i<s; i++)
				temp[i] = vektor[i];
			c=c*2;
			vektor = new T[c];
			for(int i=0; i<s; i++)
				vektor[i] = temp[i];
			delete [] temp;
		}
		vektor[s]=x;
		s++;	
	};

	T pop_back(){	//pročitaj definiciju zadatka i četvri zadatak prošle zadaće.
		if(s==0) return 0;
		s--;
		T tmp = vektor[s];
		if(s==c/2){
			T *temp = new T [c];
			for(int i=0; i<s; i++)
				temp[i] = vektor[i];
			c=c/2;
			vektor = new T [c];
			for(int i=0; i<s; i++)
				vektor[i] = temp[i];
			delete [] temp;
		}
		return tmp;	
	};

	void resize_to_fit(){	//pročitaj definiciju zadatka i četvri zadatak prošle zadaće.
		c=s;
		T *temp = new T [c];
		for(int i=0; i<s; i++)
			temp[i] = vektor[i];
		vektor = new T [c];
		for(int i=0; i<s; i++)
			vektor[i] = temp[i];
		delete [] temp;
	};

	void clear(){
		s=0;
		vektor = new T [c];
	};

	// u ovom dijelu potrebno je napraviti izmjene u potpisu metodu kako bi radilo kao metode predloska
	// operatori pridruzivanja

	Vektor& operator= (const Vektor<T>&V){
		if(V.s){
			if(this->vektor) delete [] this->vektor;

			this->s = V.s;
			this->c = V.c;

			this->vektor = new T[this->c];

			for(int i=0; i<this->s; i++)
				this->vektor[i] = V.vektor[i];
		}
	};

	Vektor& operator+= (const Vektor<T>&V){ *this = *this + V; };
	Vektor& operator-= (const Vektor<T>&V){ *this = *this - V; };
	Vektor& operator*= (T lambda){ *this = *this * lambda; };

	// aritemticki operatori
	Vektor operator + (const Vektor<T>&V){ // zbrajanje vektora
		if(this->s == V.s){
			Vektor Z(V);

			for(int i=0; i<Z.s; i++)
				Z.vektor[i] += this->vektor[i];
			return Z;
		}
	};

	Vektor operator - (const Vektor<T>&V){ // oduzimanje vektora
		if(this->s == V.s){
			Vektor Z(V);

			for(int i=0; i<Z.s; i++)
				Z.vektor[i] -= this->vektor[i];

			return Z;
		}
	};

	Vektor operator * (T lambda){
		if(this->s)
			for(int i=0; i<this.s; i++)
				this->vektor[i]*=lambda;
	};

	// usporedba
	Vektor operator == (const Vektor<T>&V){ // == u smislu relacije
		if(this->s == V.s && this->c == V.c){
			for(int i=0; i<this->s; i++)
				if(this->vektor[i] != V.vektor[i]) return false;
			return true;
		}
		return false;
	};

	Vektor operator != (const Vektor<T>&V){ // ekvivalencije
		if(this->s == V.s && this->c == V.c){
			for(int i=0; i<this->s; i++)
				if(this->vektor[i] != V.vektor[i]) return true;
			return false;
		}
		return true;
	};

	friend ostream& operator<<(ostream& buffer, const Vektor<T> &V){
		buffer << "(";
		for(int i=0; i<V.s-1; i++)
			buffer << V.vektor[i] << ", ";
		buffer << V.vektor[V.s-1] << ")";
		return buffer;
	};
	// kraj izmjena
};

class Pair
{
	float x, y;
public:
	Pair();
	Pair(float x,float y);
	Pair(const Pair &T);

	bool operator<(const Pair &) const;
	bool operator>(const Pair &) const;

	friend ostream& operator<<(ostream& buffer, const Pair& T);
};

Pair::Pair(): x(0), y(0) {};
Pair::Pair(float x, float y): x(x), y(y) {};
Pair::Pair(const Pair &T): x(T.x), y(T.y) {};

bool Pair::operator<(const Pair &T) const{ return this->x < T.x; }
bool Pair::operator>(const Pair &T) const{ return this->x > T.x; }

ostream& operator<<(ostream& buffer, const Pair& T){
	return buffer << "(" << T.x << "," << T.y << ")";
};

int main() {
	srand(time(0));

	Vektor<double> L1, L2, L3;
	int n=10;
	for(int i=0; i<n; i++){
		L1.push_back((rand()%100) + (double(rand()%100000)/100000));
		L2.push_back((rand()%100) + (double(rand()%100000)/100000));
	}

	cout << L1 << endl;
	cout << L2 << endl;
	L3 = L1 + L2;

	cout << L3 << endl;

	Vektor<Pair> L4; // Pair je tip definiran u prvom zadatku
	for(int i = 0; i<n; i++){
		L4.push_back(Pair(rand()%100, rand()%100));
	}

	cout << L4 << endl;

	// ...
	return 0;
}