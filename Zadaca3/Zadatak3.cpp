#include <iostream>
#include <cstdlib>
using namespace std;

enum smjer {U,L,R,D,UL,UR,DL,DR,None};

class pozicija{
public:
	int x,y;
	pozicija()
	pozicija(int x,int y);
	pozicija(const pozicija& p); 
};

class Zgrada{
public:
	Zgrada(int w, int h); 
	int sirina() const {return w;}
	int visina() const {return h;}

	smjer ocitanje(pozicija batman_poz) const;
protected:
	pozicija bomba;
	int h, w;
};

class Batman{
protected:
	Zgrada zgrada;
	pozicija batman_poz;

	pozicija GT, DT;

public:
	Batman();
	Batman(const Zgrada& zgrada);
	void skoci(smjer HeatTrack);
	pozicija trenutna_pozicija() const {return batman_poz;}
};

void BatmanVSJoker(int h,int w, int n){
	Zgrada zgrada(w,h);
	Batman batman(zgrada);
	// broj pokusaja
	int skokovi = 0;
	// implementing search
	while(true){
	/*
	Programski kod koji vi implementirate. 
	*/
	}
}

int main(){

	BatmanVSJoker(8,4,10);
	cout << "-----------------------------------" << endl;
	BatmanVSJoker(33,425,49);
	cout << "-----------------------------------" << endl;
	BatmanVSJoker(9999,9999,14);

	return 0;
}