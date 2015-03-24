#include <iostream>
using namespace std;

void ispis(float *A, int m, int n);
void copyFromLame2Awsome(float M[], float *A, int m, int n);
void matrix_multiply(float *A, float *B, float *C, int m, int k, int n);

int main(){
	
	return 0;
}

void copyFromLame2Awsome(float M[], float *A, int m, int n){
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			A[i*n+j] = M[i*n+j];
}

void ispis(float *A, int m, int n){
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++)
			cout << A[i*n+j] << "\t";
	}
	cout << endl;
}

void matrix_multiply(float *A, float *B, float *C, int m, int k, int n){
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++){
			C[i*n+j]=0;
			for(int l=0; l<k; l++)
				C[i*n+j]=C[i*n+j]+(A[i*k+l]*B[l*n+j]);
		}
}