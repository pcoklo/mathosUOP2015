#include <iostream>
#include <cmath>

using namespace std;

class Trokut {
protected:
	float a,b,c;

public:
	Trokut(float,float,float);
	Trokut(const Trokut&);

	// opseg i povrsina
	float opseg() const;
	float povrsina() const;
};

class JKTrokut: public Trokut {
public:
	JKTrokut(float,float);
};

class JSTrokut: public JKTrokut {
public:
	JSTrokut(float);
};

Trokut::Trokut(float a, float b, float c){
	this-> a = a;
	this-> b = b;
	this-> c = c;
}

JKTrokut::JKTrokut(float a, float b):Trokut(a,b,b){}

JSTrokut::JSTrokut(float a):JKTrokut(a,a){}

float Trokut::opseg() const{
	return a+b+c;
}
float Trokut::povrsina() const{
	float s = (a+b+c)/2;
	return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main() {
	Trokut T1(3,4,5);
	JKTrokut T2(3,4);
	JSTrokut T3(3);

	cout << "opseg i povrsina: " << T1.opseg() << ", " << T1.povrsina() << endl;
	cout << "opseg i povrsina: " << T2.opseg() << ", " << T2.povrsina() << endl;
	cout << "opseg i povrsina: " << T3.opseg() << ", " << T3.povrsina() << endl;
}