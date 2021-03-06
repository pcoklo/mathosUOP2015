#include <iostream>
using namespace std;

void ispis(float *A, int m, int n);
void copyFromLame2Awsome(float M[], float *A, int m, int n);
void matrix_multiply(float *A, float *B, float *C, int m, int k, int n);

int main(){
	int m=5;
	int k=4;
	int n=3;
	// vidi zadatak1
	float* A=new float[m*k];
	float* B=new float[k*n];
	float* C=new float[m*n];
	// vidi zadatak1
	float Ma[]={
		-1, 2, 3, 0,
		0, 2, 5, 1,
		4, 3, 1, 0,
		1, 2, -5, 7,
		0, 0, 2, 1
	};
	// vidi zadatak1
	float Mb[]={
		-1, 0, 1,
		2, 0, 3,
		1, 3, 0,
		9, -2, 4
	};
	// vidi zadatak1
	copyFromLame2Awsome(Ma, A, m, k);
	copyFromLame2Awsome(Mb, B, k, n);
	// vidi zadatak1
	matrix_multiply(A,B,C,m,k,n);
	ispis(A, m, k);
	ispis(B, k, n);
	ispis(C, m, n);
	// vidi zadatak1
	delete[] A;
	delete[] B;
	delete[] C;
	// vidi zadatak1
	return 0;
}

void copyFromLame2Awsome(float M[], float *A, int m, int n){
	// vidi zadatak1
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			A[i*n+j] = M[i*n+j];
}

void ispis(float *A, int m, int n){
	// vidi zadatak1
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++)
			cout << A[i*n+j] << "\t";
		cout << endl;
	}
	cout << endl;
}

void matrix_multiply(float *A, float *B, float *C, int m, int k, int n){
	// vidi zadatak1
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++){	//magija počinje odavde
			C[i*n+j]=0;	//svaki element prije sumiranja stavljamo u 0
			for(int l=0; l<k; l++)
				C[i*n+j]=C[i*n+j]+(A[i*k+l]*B[l*n+j]);
		//može i ovako	C[i*n+j]+=A[i*k+l]*B[l*n+j];
		}
}
