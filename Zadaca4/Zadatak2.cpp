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

//defaultni konstruktor stavlja vrijednosti 1
Razlomak::Razlomak(){
	brojnik = 1;
	nazivnik = 1;
}

//ovaj drugi konstruktor stavlja vrijednosti a i b u brojnik i nazivnik
Razlomak::Razlomak(int a, int b){
	brojnik = a;
	nazivnik = b;
}

//konstruktor kopiranja kopira vrijednosti R razlomka i stavlja ih u novi objekt
Razlomak::Razlomak(const Razlomak &R){
	this -> brojnik = R.brojnik;
	this -> nazivnik = R.nazivnik;
}

//this objekt je lijevo od operatora, a R desno.
//operator = radi tako da desnu stranu prebaci u lijevu
//stoga slijedi:
void Razlomak::operator = (const Razlomak& R){
	this -> brojnik = R.brojnik;
	this -> nazivnik = R.nazivnik;
}

//operator += zbraja desnu stranu u lijevu
void Razlomak::operator += (const Razlomak& R){
	//ako su nazivnici jednaki, samo zbrojimo brojnike
	if(this -> nazivnik == R.nazivnik)
		this -> brojnik += R.brojnik;
	//	this -> brojnik = this -> brojnik + R.brojnik;

	//ako su nazivnici različiti...
	else{
		this -> brojnik = (this -> brojnik * R.nazivnik) + (this -> nazivnik * R.brojnik);
		this -> nazivnik *= R.nazivnik;
	}
}

//isto kao i += samo oduzima
void Razlomak::operator -= (const Razlomak& R){
	if(this -> nazivnik == R.nazivnik)
		this -> brojnik -= R.brojnik;
	//	this -> brojnik = this -> brojnik + R.brojnik;
	else{
		this -> brojnik = (this -> brojnik * R.nazivnik) - (this -> nazivnik * R.brojnik);
		this -> nazivnik *= R.nazivnik;
	}
}

//množi
void Razlomak::operator *= (const Razlomak& R){
	this -> brojnik *= R.brojnik;
	this -> nazivnik *= R.nazivnik;
//	this -> brojnik = this -> brojnik * R.brojnik;
//	this -> nazivnik = this -> nazivnik * R.brojnik;
}

void Razlomak::operator /= (const Razlomak& R){
	this -> brojnik *= R.nazivnik;
	this -> nazivnik *= R.brojnik;
//	this -> brojnik = this -> brojnik * R.nazivnik;
//	this -> nazivnik = this -> nazivnik * R.brojnik;
}

//isto kao i += samo spremi zbroj u vrati i onda napravi return
Razlomak Razlomak::operator + (const Razlomak& R) const{
	Razlomak vrati;

	if(this -> nazivnik == R.nazivnik){
		vrati.brojnik = this -> brojnik + R.brojnik;
		vrati.nazivnik = R.nazivnik;
	//	vrati.nazivnik = this -> nazivnik;
	}

	else{
		vrati.brojnik = (this -> brojnik * R.nazivnik) + (this -> nazivnik * R.brojnik);
		vrati.nazivnik = this -> nazivnik * R.nazivnik;
	}

	return vrati;
}

//isto kao i u + samo oduzima
Razlomak Razlomak::operator - (const Razlomak& R) const{
	Razlomak vrati;

	if(this -> nazivnik == R.nazivnik){
		vrati.brojnik = this -> brojnik - R.brojnik;
		vrati.nazivnik = R.nazivnik;
	//	vrati.nazivnik = this -> nazivnik;
	}

	else{
		vrati.brojnik = (this -> brojnik * R.nazivnik) - (this -> nazivnik * R.brojnik);
		vrati.nazivnik = this -> nazivnik * R.nazivnik;
	}

	return vrati;
}

//isto kao i u *= samo meći u vrati i napravi return
Razlomak Razlomak::operator * (const Razlomak& R) const{
	Razlomak vrati;

	vrati.brojnik = this -> brojnik * R.brojnik;
	vrati.nazivnik  = this -> nazivnik * R.nazivnik;

	return vrati;
}

//recipročno množi
Razlomak Razlomak::operator / (const Razlomak& R) const{
	Razlomak vrati;

	vrati.brojnik = this -> brojnik * R.nazivnik;
	vrati.nazivnik  = this -> nazivnik * R.brojnik;

	return vrati;
}

//uspoređujemo lijevi(brojnik/nazivnik) sa desnim(brojnik/nazivnik)
//pošto int/int = int moramo staviti jednu vrijednost u float() da bi dobili dobru vrijednost
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

//vrati float vrijednost brojnik / nazivnik
// int / int = int
float Razlomak::decimal() const{
	return float(brojnik) / nazivnik;
}

//zaokružujemo na bliži jer int a = 3.96; a = 3;
float Razlomak::round() const{
//	uzmimo za primjer osam trećina
//	int 8/3 = 2; spremi to u int variablu vrati
	int vrati = brojnik / nazivnik;

//	float 8/3 = 2.667; spremi to u prva decimala
	float prvaDecimala = float(brojnik) / nazivnik;

//	pomnoži prva decimala sa 10 i dobiješ 26.667;
	prvaDecimala *= 10;

//	ostatak pri cjelobrojnom djeljenu od 26 je 6;
	prvaDecimala = int(prvaDecimala) % 10;

//	ako je prva decimala veća ili jednaka 5, povećaj vrati za 1
	if(int(prvaDecimala) >= 5) vrati++;
	return vrati;
}

//možda sutra
void Razlomak::ispisi_mjesoviti(){
	Razlomak A(*this);
	A.skrati();

	int cijelo = 0;
	int a = A.brojnik;

	while (a >= A.nazivnik){
		a -= A.nazivnik;
		cijelo++;
	}

	if(a==0) cout << cijelo << endl;
	else cout << cijelo << "+" << a << "/" << A.nazivnik << endl;

}

//da bi skratili moramo pronaći najveći zajednički djelitelj
// http://bit.ly/1GNwQqe <- ovaj link je zakon (nije pornjava, kunem se)
bool Razlomak::skrati(){
	int a = brojnik;
	int b = nazivnik;
	int c;
	
//pronađi najveći zajednički djelitelj
	while(a != 0){
		c = a;
		a = b%a;
		b = c;
	}

//ako je djelitelj == 1, nemože se kratiti razlomak, lol 
	if(b == 1) return true;

//ako nije 1 onda se može skratit.
	brojnik /= b;
	nazivnik /= b;
	return false;
}

//ispis lol.
void Razlomak::ispisi(){
	if (nazivnik == 1) cout << brojnik << endl;
	else
		cout << brojnik << "/" << nazivnik << endl;
}

int main(){
	Razlomak R1(8,3);

	R1.ispisi_mjesoviti();

	cout << R1.decimal() << endl;
	cout << R1.round() << endl;

	R1.ispisi();
	return 0;
}