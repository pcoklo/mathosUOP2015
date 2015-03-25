#include <iostream>
using namespace std;

void *transpose(float *A, int &m, int &n);
void ispis(float *A, int m, int n);
void copyFromLame2Awsome(float M[], float *A, int m, int n);

int main(){
	float *A;		//pointer tipa float zvan A
	int m=5, n=4;		//timenzije

	float M[]={		//matrica iz koje prekopiramo elemente
		-1, 2, 3, 0,	//nije potrebna
		0, 2, 5, 1,	//ali jako
		4, 3, 1, 0,	//olakšava pisanje
		1, 2, -5, 7,
		0, 0, 2, 1
	};
	
	/*** da nema te matrice pisali bi ovako nešto
	A[0]=-1;	A[1]=2;		A[2]=3;		A[3]=0;
        A[4]=0;		A[5]=2;		A[6]=5;		A[7]=1;
        A[8]=4;		A[9]=3;		A[10]=1;	A[11]=0;
        A[12]=1;	A[13]=2;	A[14]=-5	A[15]=7;
        A[16]=0;	A[17]=0;	A[18]=2;	A[19]=1;

	/*** i tako svaki element dobije svoju vrijednost
	 * što nema smisla
	 * */

	A = new float [n*m];		//dinamički alociramo m*n mjesta za matricu

	copyFromLame2Awsome(M,A,m,n);	//kopiramo sve elemente iz M[] matrice u novu *A matricu
	ispis(A,m,n);			//i ispišemo
	A = (float*) transpose(A,m,n);	//"A = transponirano(A)" ovaj (float*) nađite sami
	ispis(A,m,n);			//ispis transponirano A
	
	delete [] A;

	return 0;
}

void copyFromLame2Awsome(float M[], float *A, int m, int n){
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			A[i*n+j] = M[i*n+j];	//kroz dvije for petlje kopiramo elemente iz M[] u *A
	
	// A može i ovako
//	for(int i=0; i<m*n; i++) A[i] = M[i];
}

void ispis(float *A, int m, int n){
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++)		//kroz dvije for petlje ispisujemo elemente
			cout << A[i*n+j] << "\t";
		cout << endl;
	}
	cout << endl;
	// može i ovako
/*	for(int i=0; i<m*n; i++){
		cout << A[i] << "\t";
		if((i+1)%n == 0) cout << endl;
	}
	cout << endl;
/**/
}

void *transpose(float *A, int &m, int &n){
	// &m i &n su reference na variable koje prosljeđujemo
	int y=m;	//pa tako ako ih zamjenimo
	m=n; n=y;	//u ovoj funkciji zamjenjene su svuda

	float *B = new float [m*n];	// B je matrica u koju transponiramo matricu A
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			B[i*n+j]=A[j*m+i];	//magija!

	A=B;	// A = A transponirano
	return A;	//vrati A nazad ... A=(float*)transpose(Am,n);
}
