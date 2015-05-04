#include <iostream>
using namespace std;

class Razlomak {

protected:
	int brojnik, nazivnik;

public:
	Razlomak();
	Razlomak(int a);
	Razlomak(int a, int b);
	Razlomak(const Razlomak &R);

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

	// ukoliko Razlomak nije maksimalno skracen, skrati ga
	// i vraca false, u protivnom vraca true
	bool skrati();
	
	void ispisi();// ispisi Razlomak na ekran
	void ispisi_mjesoviti();// ispisi Razlomak na ekran kao mješoviti broj

	friend ostream& operator<<(ostream& buffer, const Razlomak &R);
};

Razlomak::Razlomak(){
	brojnik = 1;
	nazivnik = 1;
}

Razlomak::Razlomak(int a){
	brojnik = a;
	nazivnik = 1;
}

Razlomak::Razlomak(int a, int b){
	brojnik = a;
	nazivnik = b;
}

void Razlomak::operator = (const Razlomak& R){
	this -> brojnik = R.brojnik;
	this -> nazivnik = R.nazivnik;
}

void Razlomak::operator += (const Razlomak& R){
	if(this -> nazivnik == R.nazivnik)
		this -> brojnik += R.brojnik;
	else{
		this -> brojnik = (this -> brojnik * R.nazivnik) + (this -> nazivnik * R.brojnik);
		this -> nazivnik *= R.nazivnik;
	}
}

void Razlomak::operator -= (const Razlomak& R){
	if(this -> nazivnik == R.nazivnik)
		this -> brojnik -= R.brojnik;
	else{
		this -> brojnik = (this -> brojnik * R.nazivnik) - (this -> nazivnik * R.brojnik);
		this -> nazivnik *= R.nazivnik;
	}
}

void Razlomak::operator *= (const Razlomak& R){
	this -> brojnik *= R.brojnik;
	this -> nazivnik *= R.nazivnik;
}

void Razlomak::operator /= (const Razlomak& R){
	this -> brojnik *= R.nazivnik;
	this -> nazivnik *= R.brojnik;
}

ostream& operator<<(ostream& buffer, const Razlomak &R){
	return buffer << R.brojnik << "/" << R.nazivnik;
}

Razlomak Razlomak::operator + (const Razlomak& R) const{
	Razlomak S;

	if(this -> nazivnik == R.nazivnik){
		S.brojnik = this -> brojnik + R.brojnik;
		S.nazivnik = R.nazivnik;
	}

	else{
		S.brojnik = (this -> brojnik * R.nazivnik) + (this -> nazivnik * R.brojnik);
		S.nazivnik = this -> nazivnik * R.nazivnik;
	}

	return S;
}

Razlomak Razlomak::operator - (const Razlomak& R) const{
	Razlomak S;

	if(this -> nazivnik == R.nazivnik){
		S.brojnik = this -> brojnik - R.brojnik;
		S.nazivnik = R.nazivnik;
	}

	else{
		S.brojnik = (this -> brojnik * R.nazivnik) - (this -> nazivnik * R.brojnik);
		S.nazivnik = this -> nazivnik * R.nazivnik;
	}

	return S;
}

Razlomak Razlomak::operator * (const Razlomak& R) const{
	Razlomak S;

	S.brojnik = this -> brojnik * R.brojnik;
	S.nazivnik  = this -> nazivnik * R.nazivnik;

	return S;
}

Razlomak Razlomak::operator / (const Razlomak& R) const{
	Razlomak S;

	S.brojnik = this -> brojnik * R.nazivnik;
	S.nazivnik  = this -> nazivnik * R.brojnik;

	return S;
}

bool Razlomak::operator == (const Razlomak& R) const{
	return (this -> brojnik / this -> nazivnik) == (R.brojnik / R.nazivnik);
}

bool Razlomak::operator <= (const Razlomak& R) const{
	return (this -> brojnik / this -> nazivnik) <= (R.brojnik / R.nazivnik);
}

bool Razlomak::operator >= (const Razlomak& R) const{
	return (this -> brojnik / this -> nazivnik) >= (R.brojnik / R.nazivnik);
}

bool Razlomak::operator < (const Razlomak& R) const{
	return (this -> brojnik / this -> nazivnik) < (R.brojnik / R.nazivnik);
}

bool Razlomak::operator > (const Razlomak& R) const{
	return (this -> brojnik / this -> nazivnik) > (R.brojnik / R.nazivnik);
}

float Razlomak::decimal() const{
	return float(brojnik) / nazivnik;
}

float Razlomak::round() const{
	int vrati = brojnik / nazivnik;
	float prvaDecimala = float(brojnik) / nazivnik;
	prvaDecimala *= 10;
	prvaDecimala = int(prvaDecimala) % 10;
	if(int(prvaDecimala) >= 5) vrati++; 
	return vrati;
}

int main(){

	Razlomak A(1,2);
	Razlomak B(3,4);

	Razlomak C = A/B;

	cout << C << endl;

	Razlomak G(14,6);

	cout << G.round() << endl;
	cout << G.decimal() << endl;

	return 0;
}