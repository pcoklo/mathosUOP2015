#include <iostream>
#include <cmath>

const float PI = 3.14159;

using namespace std;

class Krug {
protected:
	float r;

public:
	Krug(){r=1;};
	Krug(float);
	Krug(const Krug&);
	float opseg() const;
	float povrsina() const;

	float radius() const{return r;};
};

class Stozac: public Krug{
protected:
	float h;

public:
	Stozac();
	Stozac(Krug &K, float h);
	Stozac(float r, float h);
	float oplosje() const;
	float volumen() const;
};

class Kugla: public Krug{

public:
	Kugla();
	Kugla(Krug& K);
	Kugla(float r);
	float oplosje() const;
	float volumen() const;
};

Krug::Krug(float r){
	this -> r = r;
}

Krug::Krug(const Krug &K){
	this -> r = K.r;
}

float Krug::povrsina() const{
	return r*r*PI;
}

float Krug::opseg() const{
	return 2*r*PI;
}

Kugla::Kugla(float r){
	this -> r = r;
}

Kugla::Kugla(Krug& K){
	this -> r = K.radius();
}

float Kugla::oplosje() const{
	return 4*r*r*PI;
}

float Kugla::volumen() const{
	return 4/3*r*r*r*PI;
}

Stozac::Stozac(float r, float h){
	this -> r = r;
	this -> h = h;
}

Stozac::Stozac(Krug &K, float h){
	this -> r = K.radius();
	this -> h = h;
}

float Stozac::oplosje() const{
	return r;
}

float Stozac::volumen() const{
	return 2*r;
}

int main(){
	Krug K1(12);
	Kugla ku1(K1);
	Stozac S1(K1,12);

	cout << "Opseg i povrsina kruga: " << K1.opseg() << ", " << K1.povrsina() << endl;
	cout << "Oplosje i volumen kugle: " << ku1.oplosje() << ", " << ku1.volumen() << endl;
	cout << "Oplosje i volumen stosca: " << S1.oplosje() << ", " << S1.volumen() << endl;

	return 0;
}
