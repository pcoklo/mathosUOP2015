#include <iostream>
#include <cmath>
using namespace std;

class Tocka
{
public:
	float x;
	float y;
	Tocka(): x(0), y(0) {};
	Tocka(float x, float y): x(x), y(y) {};
	Tocka(const Tocka &T): x(T.x), y(T.y) {};
};

class Pravokutnik
{
public:
	Tocka T1,T2;

	Pravokutnik();
	Pravokutnik(const Tocka& T1, const Tocka& T2);
	Pravokutnik(const Pravokutnik& P);
	// metode za racunanje
	float opseg() const;
	float povrsina() const;
};

class PravilniPoligon
{
public:
	Tocka S, T1;
	int n;
	Tocka *vrhovi;

	PravilniPoligon();
	PravilniPoligon(const Tocka& S, const Tocka& T, int n);
	PravilniPoligon(const PravilniPoligon& P);

	float opseg() const;
	float povrsina() const;
};

Pravokutnik::Pravokutnik(){
	T1.x=0; T1.y=0;
	T2.x=0; T2.y=0;
}

Pravokutnik::Pravokutnik(const Tocka& T1, const Tocka& T2){
	this->T1.x = T1.x; this->T1.y = T1.y;
	this->T2.x = T2.x; this->T2.y = T2.y;
}

Pravokutnik::Pravokutnik(const Pravokutnik& P){
	this->T1.x=P.T1.x; this->T1.y=P.T1.y;
	this->T2.x=P.T2.x; this->T2.y=P.T2.y;
}

float Pravokutnik::opseg() const{
	float a = abs(T1.x-T2.x);
	float b = abs(T1.y-T2.y);
	return 2*a + 2*b;
}

float Pravokutnik::povrsina() const{
	float a = abs(T1.x-T2.x);
	float b = abs(T1.y-T2.y);
	return a*b;
}

int main()
{
	Pravokutnik P(Tocka(1,3), Tocka(2,5));
	cout << "***P: opseg:" << P.opseg() << ", povrsina: " << P.povrsina() << endl;
//	PravilniPoligon P_5(Tocka(1,5), Tocka(3,6), 5);
//	cout << "***P_5: opseg:" << P_5.opseg() << ", povrsina: " << P_5.povrsina() << endl;

}
