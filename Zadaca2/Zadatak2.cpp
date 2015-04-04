#include <iostream>
using namespace std;

class vector{
protected:
	size_t s;
	size_t c;

	float *vektor;

public:
	vector(){
		s = 0;
		c = 4;
		vektor = new float [c];
	};

	vector(size_t size){
		s = 0;
		c = size;
		vektor = new float [c];	
	};

	vector(const vector& V){
		c = V.c;
		s = V.s;
		vektor = new float [c];
		for(int i=0; i<s; i++)
			vektor[i]=V.vektor[i];
	};

	~vector(){ delete[] vektor; };

	size_t size() const{}; //size_t = unsigned int
	size_t capacity() const{};

	void push_back(float x){
		vektor[s]=x;
		s++;	
	};

	float pop_back(){
		s--;	
		return vektor[s];	
	};

	void resize_to_fit(){};
	void clear(){};
};

int main(){
	vector S1;
	S1.push_back(21);
	S1.push_back(11);
	cout << S1.pop_back() << endl;
	cout << S1.pop_back() << endl;
	return 0;
}