#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;

void add_element(int **A, int i, int x){
	int m = A[i][0]+1;		//broj elemenata + nulti element(broj elemenata) = dulina retka 
	int pot = 1;			//deklaracija potencije za računanje alocirane memorije

	while(m>pot) pot*=2;	//računanje potencije 2^m

	if(pot==m && pot > 1)	//ako je potencija = duljini retka nema mjesta
		cout << "unable to comply" << endl;
	else{					//ako ima mjesta
		A[i][0]++;			//povećaj nulti element retka za 1
		A[i][A[i][0]] = x;	//stavi x na novo mjesto
	}
}

void dynamic_add(int **A, int i, int x){
	int m = A[i][0]+1;		//broj elemenata + nulti element(broj elemenata) = dulina retka 
	int pot = 1;			//deklaracija potencije za računanje alocirane memorije

	while(m>pot) pot*=2;	//računanje potencije 2^m

	if(pot==m && pot > 1){	//ako je potencija = duljini retka nema mjesta

		int *y = new int [m];	//kreiranje novog polja
		for(int j=0; j<m; j++)	//spremi staro polje u novo privremeno polje y
			y[j] = A[i][j];		//kopiram polje iz A u y

		A[i] = new int [m*2];	//duplo veće polje A[i]
		
		for(int j=0; j<m; j++)
			A[i][j] = y[j];		//kopiramo iz y u A
		delete [] y;			//brišemo y

	//	add_element(A,i,x);		//ne funkcionira jer nezna da ima mjesta
		A[i][0]++;				//pa stoga
		A[i][A[i][0]] = x;		//radimo ovo
	}
	else	//ako potencija != duljine retka ima mjesta
		add_element(A,i,x);
}

void print_db(int** A, int n){
	for(int i=0; i<n; i++){
		cout << "i=" << i << " ";	//za ispis ijeva okomito
		int m = A[i][0]+1;			//m= duljina retka
		for(int j=0; j<m; j++)		//vrti for do m
			cout << A[i][j] << " ";	//ispis jotova vidiravno
		cout << endl;				//kad završi ide u novi red
	}
}

int main(){
	int** A;	//'matrica A'
	int n = 200; //broj 'i' elemenata
	//alocirate ovdje inicijalno stanje strukture A kao sto je
	//opisano u tekstu zadatka.
	/****** ovdje ide vasa implementacija ******/
	A = new int *[n];		//u a smo stavili 20 pointera
	for(int i=0; i<n; i++){
		A[i] = new int [2];	//u svaki pointer smo stavili dva elementa
		A[i][0] = 0;		//prvi element = 0 zbog razloga.
	}
	/****** ovdje zavrsava vasa implementacija ******/
	//print_db(A,n); //ispisi inicijalno stanje na ekran
	//Simulirajte online-algoritam na nacin da generirate
	//'size' slucajnih cijelih brojeva i indeksa redaka 'i' od 'A[i]'.
	//U nastavku vam je dan kod za to.
	srand(time(0));
	int size = 10000;		//broj selemenata koje ćemo ubacivati u strukturu
	for(int k=0; k<size; k++){
		int i = rand()%n;		//generiranje slucajnog broja u {0,1,...,n-1}
		int x = rand()%100;		//generiranje slucajnog broj u {1,2,...,99}
		dynamic_add(A, i, x);	//poziva funkciju od random projeva
	}
	print_db(A,n);	//ispisi stanje nakon 'size' mnogo dodavanja.

	for(int i=0; i<n; i++)
		delete [] A[i];		//brišemo svaki vodoravni pointer
	delete [] A;			//onda okomiti
}