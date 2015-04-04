#include <iostream>
using namespace std;

class vector{
protected:
	size_t s;	// s kao size
	size_t c;	// c kao capacity

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

	size_t size() const {return s;};
	size_t capacity() const {return c;};

	void push_back(float x){
		if(s==c){
			float *temp = new float [c];
			for(int i=0; i<s; i++)
				temp[i] = vektor[i];
			c=c*2;
			vektor = new float [c];
			for(int i=0; i<s; i++)
				vektor[i] = temp[i];
			delete [] temp;
		}

		vektor[s]=x;
		s++;	
	};

	float pop_back(){
		if(s==0) return 0;
		s--;
		float tmp = vektor[s];
		if(s==c/2){
			float *temp = new float [c];
			for(int i=0; i<s; i++)
				temp[i] = vektor[i];
			c=c/2;
			vektor = new float [c];
			for(int i=0; i<s; i++)
				vektor[i] = temp[i];
			delete [] temp;
		}
		return tmp;	
	};

	void resize_to_fit(){
		c=s;
		float *temp = new float [c];
		for(int i=0; i<s; i++)
			temp[i] = vektor[i];
		vektor = new float [c];
		for(int i=0; i<s; i++)
			vektor[i] = temp[i];
		delete [] temp;
	};
	void clear(){
		s=0;
		vektor = new float [c];
	};
};

int main(){

/**/	return 0;
}