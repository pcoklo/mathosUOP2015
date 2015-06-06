#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

template<class T>
void sort(T *x, int N){
	for (int i=0;i<N;i++)
		for (int j=1;j<N;j++)
			if (x[j]<x[j-1]){
				T t = x[j-1];
				x[j-1] = x[j];
				x[j] = t;
			}
}

template<class T, int n>
class Tuple{
	T *podaci;
public:
	Tuple(){ podaci = new T[n]; };
	Tuple(T *input){
		podaci = new T[n];
		for(int i=0; i<n; i++)
			podaci[i]=input[i];
	};
	~Tuple(){ delete [] podaci; };

	bool operator<(const Tuple<T, n> &t) const{
		for(int i=0; i<n; i++)
			if(this->podaci[i]<t.podaci[i]) return 0;
		return 1;
	};
	bool operator>(const Tuple<T, n> &t) const{
		for(int i=0; i<n; i++)
			if(this->podaci[i]>t.podaci[i]) return 0;
		return 1;
	};

	friend ostream& operator<<(ostream& buffer, const Tuple<T, n> &t){
		buffer << "(";
		for(int i=0; i<n-1; i++)
			buffer << t.podaci[i] << ", ";
		buffer << t.podaci[n-1] << ")";
		return buffer;
	};
};


int main(){
	srand(time(0));

	const int n = 5, m = 10;

	Tuple <int, n> *T = new Tuple<int, n>[m];

	for(int j=0; j<m; j++){
		int *podaci = new int[n];
		for(int i=0; i<n; i++)
			podaci[i] = rand()%100;
		sort(podaci,n);
		Tuple <int, n> Tj(podaci);
		delete [] podaci;
		T[j]=Tj;
		cout << T[j] << endl;
	}

	return 0;
}