#include <iostream>
using namespace std;

class Razlomak {

public:
	int brojnik, nazivnik;

public:
	Razlomak();
	Razlomak(int a, int b);
	Razlomak(const Razlomak q);

	// operatori pridruzivanja
	void operator = (const Razlomak&);
	void operator += (const Razlomak&);
	void operator -= (const Razlomak&);
	void operator *= (const Razlomak&);
	void operator /= (const Razlomak&);

	// aritmeticki operatori
	Razlomak operator + (const Razlomak&) const;
	Razlomak operator - (const Razlomak&) const;
	Razlomak operator * (const Razlomak&) const;
	Razlomak operator / (const Razlomak&) const;

	// logicki operatori
	bool operator == (const Razlomak&) const;
	bool operator <= (const Razlomak&) const;
	bool operator >= (const Razlomak&) const;
	bool operator < (const Razlomak&) const;
	bool operator > (const Razlomak&) const;

	// pretvaranje razlomka u odgovarajuci float
	float decimal() const; // Razlomak u float
	float round() const; // Najbliže cijelo

	// ukoliko razlomak nije maksimalno skracen, skrati ga
	// i vraca false, u protivnom vraca true
	bool skrati();
	
	void ispisi();// ispisi razlomak na ekran
	void ispisi_mjesoviti();// ispisi razlomak na ekran kao mješoviti broj
};