#include <iostream>
using namespace std;

void *transpose(float *A, int &m, int &n);
void ispis(float *A, int m, int n);
void copyFromLame2Awsome(float M[], float *A, int m, int n);

int main(){
	float *A;
	int m=5, n=4;

	float M[]={
		-1, 2, 3, 0,
		0, 2, 5, 1,
		4, 3, 1, 0,
		1, 2, -5, 7,
		0, 0, 2, 1
	};

	A = new float [n*m];

	copyFromLame2Awsome(M,A,m,n);
	ispis(A,m,n);
	A = (float*) transpose(A,m,n);
	ispis(A,m,n);

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

void *transpose(float *A, int &m, int &n){
	int temp=m;
	m=n; n=temp;

	float *tmp = new float [m*n];
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			tmp[i*n+j]=A[j*m+i];

	A=tmp;
	return A;
}