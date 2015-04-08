#include <iostream>
using namespace std;

class vector{	//definiramo klasu imena vektor
protected:	//protected zato da se nemože pristupati varijablama van klase
	size_t s;	// s kao size
	size_t c;	// c kao capacity

	float *vektor;	// vektor kao vector, pointer za dinamičku alokaciju memorije

public:
	vector(){	// konstruktor koji se poziva bez parametara
		s = 0;	// stoga stavljamo defaulte veličine. 0 za size jer je veličina na početku nula
		c = 4;	// kapacitet je neki broj. koji vam se najviše svidi.
		vektor = new float [c];	//dinamička alokacija memorije u vektor velečine kapaciteta
	};

	vector(size_t size){	//konstruktor koji se poziva s parametrom size
		s = 0;
		c = size;	//koji stavimo u kapacitet. jer imamo svoj razlog 
		vektor = new float [c];	
	};

	~vector(){ delete[] vektor; };	//destrukror koji dilita alociranu memoriju

	size_t size() const {return s;};	//metoda size vraća veličinu
	size_t capacity() const {return c;};	//metoda capacity vraća kapacitet

	void push_back(float x){	//pročitaj definiciju zadatka i četvri zadatak prošle zadaće.
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

	float pop_back(){	//pročitaj definiciju zadatka i četvri zadatak prošle zadaće.
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

	void resize_to_fit(){	//pročitaj definiciju zadatka i četvri zadatak prošle zadaće.
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

int main(){	//main je za sve ali nemote kopirati svi isti. jer ima vas puno ljenčina koji nežele tipkati
	vector imenaVe(8);
	imenaVe.push_back(0);
	cout << imenaVe.pop_back() << endl;
	imenaVe.resize_to_fit();
	imenaVe.clear();
	
	cout << imenaVe.size() << endl;
	cout << imenaVe.capacity() << endl;
	return 0;
}
