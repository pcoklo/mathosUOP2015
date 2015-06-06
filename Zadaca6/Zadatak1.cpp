#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

template<class T>
void print(T *x, int N){
	for(int i=0; i<N; i++){
		cout << x[i] << "\t";
	}
	cout << endl;
}

template<class T>
void sort(T *x, int N){
    for (int i=0;i<N;i++)
        for (int j=1;j<N;j++)
            if (x[j]<x[j-1])
            {
                T t = x[j-1];
                x[j-1] = x[j];
                x[j] = t;
            }
}

class Pair
{
	float x, y;
public:
	Pair();
	Pair(float x,float y);
	Pair(const Pair &T);

	bool operator<(const Pair &) const;
	bool operator>(const Pair &) const;

	friend ostream& operator<<(ostream& buffer, const Pair& T);
};

Pair::Pair(): x(0), y(0) {};
Pair::Pair(float x, float y): x(x), y(y) {};
Pair::Pair(const Pair &T): x(T.x), y(T.y) {};

bool Pair::operator<(const Pair &T) const{ return this->x < T.x; }
bool Pair::operator>(const Pair &T) const{ return this->x > T.x; }

ostream& operator<<(ostream& buffer, const Pair& T){
	return buffer << "(" << T.x << "," << T.y << ")";
};

int main(){
	srand(time(0));

	int n = 10;
	
	int *intList = new int [n];
	float *floatList = new float [n];
	Pair *pairList = new Pair [n];

	for(int i = 0; i<n; i++){
		intList[i] = rand()%100;
		floatList[i] = (rand()%100) + (float(rand()%100000)/100000);
		pairList[i] = Pair(rand()%100, rand()%100);
	}

	print(intList, n);
	sort(intList, n);
	print(intList, n);

	print(floatList, n);
	sort(floatList, n);
	print(floatList, n);

	print(pairList, n);
	sort(pairList, n);
	print(pairList, n);
	return 0;
}