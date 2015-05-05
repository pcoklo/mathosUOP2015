#include <iostream>
using namespace std;
class Razlomak {

protected:
	int brojnik, nazivnik;

public:
	Razlomak();
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

};

Razlomak::Razlomak(){
	brojnik = 1;
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
	//	this -> brojnik = this -> brojnik + R.brojnik;

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

Razlomak Razlomak::operator + (const Razlomak& R) const{
	Razlomak S;

	if(this -> nazivnik == R.nazivnik){
		S.brojnik = this -> brojnik + R.brojnik;
		S.nazivnik = R.nazivnik;
	//	S.nazivnik = this -> nazivnik;
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
	//	S.nazivnik = this -> nazivnik;
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
	return (float(this -> brojnik) / this -> nazivnik) == (float(R.brojnik) / R.nazivnik);
}

bool Razlomak::operator <= (const Razlomak& R) const{
	return (float(this -> brojnik) / this -> nazivnik) <= (float(R.brojnik) / R.nazivnik);
}

bool Razlomak::operator >= (const Razlomak& R) const{
	return (float(this -> brojnik) / this -> nazivnik) >= (float(R.brojnik) / R.nazivnik);
}

bool Razlomak::operator < (const Razlomak& R) const{
	return (float(this -> brojnik) / this -> nazivnik) < (float(R.brojnik) / R.nazivnik);
}

bool Razlomak::operator > (const Razlomak& R) const{
	return (float(this -> brojnik) / this -> nazivnik) > (float(R.brojnik) / R.nazivnik);
}

float Razlomak::decimal() const{
	return float(brojnik) / nazivnik;
}

float Razlomak::round() const{
	int vrati = brojnik / nazivnik;
//	cout << "Vrati prije provjere " << vrati << endl;
	//float vrijednost prva decimala
	float prvaDecimala = float(brojnik) / nazivnik;
//	cout << "prvaDecimala prvi put " << prvaDecimala << endl;
	prvaDecimala *= 10;
//	cout << "prvaDecimala drugi put " << prvaDecimala << endl;
	prvaDecimala = int(prvaDecimala) % 10;
//	cout << "prvaDecimala treći put " << prvaDecimala << endl;
	if(int(prvaDecimala) >= 5) vrati++;
//	cout << "Vrati poslje provjere " << vrati << endl;
	return vrati;
}

void Razlomak::ispisi_mjesoviti(){
	this->skrati();
	int cijelo = 0;
	int a = brojnik;

	while (a >= nazivnik){
		a-=nazivnik;
		cijelo++;
	}

	if(a==0) cout << cijelo << endl;
	else cout << cijelo << " " << a << "/" << nazivnik << endl;

}

bool Razlomak::skrati(){
	int a = brojnik;
	int b = nazivnik;
	int c;
	
	while(a != 0){
		c = a;
		a = b%a;
		b = c;
	}

	if(b == 1) return true;

	brojnik /= b;
	nazivnik /= b;
	return false;
}

void Razlomak::ispisi(){
	if (nazivnik == 1) cout << brojnik << endl;
	else
		cout << brojnik << "/" << nazivnik << endl;
}

int main(){
	Razlomak R1(56,24);

	R1.ispisi_mjesoviti();

	cout << R1.decimal() << endl;
	cout << R1.round() << endl;

	R1.ispisi();
	return 0;
}