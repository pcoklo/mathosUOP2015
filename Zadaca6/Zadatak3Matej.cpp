#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cmath>
using namespace std;

template<class T>
class vector
{
public:
	size_t duljina, kapacitet; 
	T *P;
 public:
	vector();
	vector(size_t size);
	vector(const vector&);
	~vector(){delete [] P;};
	size_t size() const; //size_t = unsigned int
	size_t capacity() const;
	// dodavanje i brisanje elemenata s kraja
	void push_back(T x);
	T pop_back();
	void resize_to_fit();
	void clear();
	// operatori pridruzivanja
	vector& operator = (const vector&); // pridruzivanje
	vector& operator += (const vector&); // zbrajanje + pridruzivanje
	vector& operator -= (const vector&); // oduzimanje + pridruzivanje
	vector& operator *= (T lambda); // mnozenje sa skalarom + pridruzivanje
	// aritemticki operatori
	vector operator + (const vector&); // zbrajanje vektora
	vector operator - (const vector&); // oduzimanje vektora
	vector operator * (T lamba); // oduzimanje vektora
	// usporedba
	vector operator == (const vector&); // == u smislu relacije ekvivalencije
	vector operator != (const vector&);
	// operator pristupa
	T& operator[](int i) // pristup i-tom elementu vektora
	{
		return P[i];
	}

	friend ostream& operator<<(ostream& buffer, const vector<T> &V)
	{
		buffer << "(";
		for(int i=0; i<V.duljina-1; i++)
			buffer << V.P[i] << ", ";
		buffer << V.P[V.duljina-1] << ")";
		return buffer;
	}
};

template<class T> 
vector<T>::vector(){
	duljina=0;
	kapacitet=2; 
	P=new T [kapacitet];   
}

template<class T> 
vector<T>::vector(size_t size){
	duljina=0;
	kapacitet=size; 
	P=new T [kapacitet];   
}

template<class T> 
vector<T>::vector(const vector<T> &V)
{
	duljina = V.duljina;
	kapacitet = V.kapacitet;
	P = new T[kapacitet];
		
	for(int i=0; i<duljina; i++)
	{
		P[i] = V.P[i];
	}
}

template<class T> 
size_t vector<T>::size() const{ return duljina; }

template<class T> 
size_t vector<T>::capacity() const{	return kapacitet; }

template<class T>  
void vector<T>::push_back(T x){
	if(duljina==kapacitet)
	{ 
		T *novo=new T [kapacitet];         
		for(int i=0; i<duljina; i++)
		{
			novo[i]=P[i]; 
		}
		delete [] P;
		
		kapacitet=kapacitet*2;
		
		P = new T [kapacitet]; 
		for(int i=0; i<duljina; i++)
		{
			P[i]=novo[i];
		}
		delete [] novo;
	}    
	P[duljina] = x;
	duljina ++;
}

template<class T> 
T vector<T>::pop_back()
{  
	if(duljina>0)
	{  
		duljina--;      
		T zadnji_elem=P[duljina];
		
		if(duljina==kapacitet/2)
		{
			T *novo=new T [kapacitet];
			for(int i=0; i<duljina; i++)
			{
				novo[i]=P[i]; 
			}
			delete [] P;
			
			kapacitet=kapacitet/2;
			
			P = new T [kapacitet];
			for(int i=0; i<duljina; i++)
			{
				P[i]=novo[i];
			}
			delete [] novo;
		}
	return zadnji_elem;
	}
	else return 0;  
}

template<class T> 
void vector<T>::resize_to_fit(){

	kapacitet=duljina;

	T *novo=new T [kapacitet];    
	for(int i=0; i<duljina; i++)
	{
		novo[i]=P[i]; 
	}
	delete [] P;

	P=new T [kapacitet];

	for(int i=0; i<duljina; i++)
	{
		P[i]=novo[i];
	}
	delete [] novo;
}
template<class T> 
void vector<T>::clear(){

	duljina=0; 
	delete []P; 
	P=new T [kapacitet];      
}
template<class T> 
vector<T>& vector<T>::operator=(const vector<T>&V){

	if(V.duljina){
		if(P) {delete [] P;}
		duljina = V.duljina;
		kapacitet = V.kapacitet;
		P = new T[kapacitet];
		for(int i=0; i<duljina; i++)
		{
			P[i] = V.P[i];
		}
	}

}
template<class T> 
vector<T>& vector<T>::operator+=(const vector<T>&V){
	if(duljina==V.duljina)
	{
		for(int i=0; i<duljina; i++)
		{
			P[i] += V.P[i];
		}
	}
	else
	{
		cout<< "Vektori nisu jednake duljine!" <<endl;
	}
}

template<class T> 
vector<T>& vector<T>::operator-=(const vector<T>&V){
	if(duljina==V.duljina)
	{
		for(int i=0; i<duljina; i++)
		{
			P[i]-=V.P[i];
		}
	}
	else
	{
		cout<< "Vektori nisu jednake duljine!" <<endl;
	}
}

template<class T>     
vector<T>& vector<T>::operator*= (T lambda){ 
	for(int i=0; i<duljina; i++)
		{
			P[i] = lambda*P[i];
		}
}
template<class T>
vector<T> vector<T>::operator+(const vector<T>&V){
	if(duljina== V.duljina)
	{
		vector novo;
		novo.kapacitet = kapacitet;
		novo.duljina = duljina;

		novo.P = new T [kapacitet];

		for(int i=0; i<duljina; i++)
			novo.P[i] = P[i] + V.P[i];

		return novo;
	}
}
template<class T> 
vector<T> vector<T>::operator-(const vector<T> &V)
{
	if(duljina== V.duljina)
	{
		vector novo;
		novo.kapacitet = kapacitet;
		novo.duljina = duljina;

		novo.P = new T [kapacitet];

		for(int i=0; i<duljina; i++)
			novo.P[i] = P[i] - V.P[i];

		return novo;
	}
}
	
template<class T> 
vector<T> vector<T>::operator*(T lambda)       
{
	if(duljina)
		for(int i=0; i<duljina; i++)
				P[i]*=lambda;
}
template<class T>
vector<T> vector<T>::operator==(const vector<T>&V)
{
	if(duljina==V.duljina && kapacitet==V.kapacitet)
	{
		for(int i=0; i<duljina; i++)
		{
			if(P[i]!=V.P[i]) return false;
			return true;
		}
		return false;
	}
}
	
template<class T>
vector<T> vector<T>::operator!=(const vector<T>&V)
{
	if(duljina==V.duljina && kapacitet==V.kapacitet)
	{
		for(int i=0; i<duljina; i++)
		{
			if(P[i]!=V.P[i]) return true;
		}
		return false;
	}
	return true;
}

int cc=1000000;

class complex
{
protected:
	float x,y;

public:
	//konstruktori
	complex();
	complex(float x);
	complex(float x,float y);

	//specificne metode za c-brojeve
	float module() const;
	complex conjugate();
	float real() const;
	float imag() const;
	
	//operatori pridruživanja
	complex& operator = (const complex& z);
	complex& operator += (const complex& z);
	complex& operator -= (const complex& z);
	complex& operator *= (const complex& z);
	complex& operator /= (const complex& z);
	
	//operatori aritmetike
	complex operator + (const complex& z) const;
	complex operator - (const complex& z) const;
	complex operator * (const complex& z) const;
	complex operator / (const complex& z) const;
	
	//relacijski operatori
	bool operator == (const complex& z) const;
	bool operator != (const complex& z) const;
	
	//cout ispisivanje
	friend ostream& operator<<(ostream& buffer, const complex& z);
};
//implementacija klase complex
//implementacija konstruktora
complex::complex() {x=0;y=0;}
complex::complex(float x) {this->x=x; this->y=0;}
complex::complex(float x,float y){this->x=x; this->y=y;}
//metode pristupa
float complex::module() const //nesmije mijenjati elemente klase-const
{
	return sqrt(x*x+y*y);   
}
complex complex::conjugate()
{
	/*complex z=(*this); //kopiranje svih elemenata iz thisa u z
	y=-y;
	*/
	return complex(x,-y);   
}
//operatori pridruživanja
complex& complex::operator = (const complex& z)  //klasa ako ima isto ime pa može pristupiti protectedu
{
	x=z.x;
	y=z.y;
	return (*this);
}
complex& complex::operator+=(const complex& z)
{
	//zbrajanje s pridruživanjem
	x += z.x;
	y += z.y;
	
	return (*this);
}
complex& complex::operator-=(const complex& z)
{
	//zbrajanje s pridruživanjem
	x -= z.x;
	y -= z.y;
	
	return (*this);
}
complex& complex::operator*=(const complex& z)
{
	//množenje s pridruživanjem
	float a = x*z.x - y*z.y;
	float b = x*z.y + y*z.x;
	x=a;
	y=b;
	return (*this);
}
complex& complex::operator/=(const complex& z)
{
	//podijeli i pridruži
	
	float modul_sqr = z.module()*z.module();
	float a = (x*z.x + y*z.y);
	float b = (y*z.x - x*z.y);
	x=a/modul_sqr;
	y=b/modul_sqr;
}
//operatori pridruživanja
complex complex::operator+(const complex& z) const
{
	complex u = (*this);
	u += z;
	return u;
}
complex complex::operator-(const complex& z) const
{
	complex u = (*this);
	u -= z;
	return u;
}
complex complex::operator*(const complex& z) const
{
	complex u = (*this);
	u *= z;
	return u;
}
complex complex::operator/(const complex& z) const
{
	complex u = (*this);
	u /= z;
	return u;
}
//logički operatori
bool complex::operator==(const complex& z) const
{
	return ((x==z.x) && (y==z.y));
}
bool complex::operator!=(const complex& z) const
{
	return !((*this)==z);
}
//opterecivanje operatora ubacivanja
ostream& operator<<(ostream& buffer, const complex& z)
{
	buffer<<z.x<<(z.y<0? "-" : "+")<<fabs(z.y)<<"i";
	return buffer;
}
int main()
{
	cout << "LUDNICA" << endl;

	srand(time(0));
	vector <complex> vCom1, vCom2, vCom3;
	vector <int> vInt1, vInt2, vInt3;
	for(int i=0; i<cc; i++){
		vCom1.push_back(complex(rand()%10, rand()%10));
		vCom2.push_back(complex(rand()%10, rand()%10));
		vInt1.push_back(rand()%100);
		vInt2.push_back(rand()%100);
	}

	cout << "V1=" << vInt1 << endl << "V2=" << vInt2 << endl;
	cout << "V3=V1-V2; "; vInt3 = vInt1 - vInt2;
	cout << "V3=" << vInt3 << endl;

	cout << "V3+=V2; "; vInt3 += vInt2;
	cout << "V3=" << vInt3 << endl;
	cout << "V3[0]= " << vInt3[0] << endl << endl;

	cout << vCom1 << endl << vCom2 << endl;
	vCom3 = vCom1 + vCom2;
	cout << vCom3 << endl;

	cout<<"VEKTOR TIPA DOUBLE"<<endl;
	vector<double>v1(10);
	v1.push_back(1.123456789);
	v1.push_back(2.123456789);
	v1.push_back(3.123456789);
	cout<<"Vektor v1 nakon metode push_back: "<<v1<<endl;
	v1.pop_back();
	cout<<"Vektor v1 nakon metode pop_back: "<<v1<<endl;
	
	vector<double>v2(10);
	v2.push_back(2.15489);
	v2.push_back(2.15489);
	v2.push_back(2.15489);
	cout<<"Vector v2: "<<v2<<endl;
	
	cout<<"---------------------"<<endl;
	
	cout<<"VEKTOR TIPA COMPLEX"<<endl;
	
	vector <complex>v3(15);
	complex z1 (2,3);
	complex z2 (5,4);
	
	v3.push_back(z1);
	v3.push_back(z2);       
	cout<<"Vektor nakon metode push_back: "<<v3<<endl;    
	v3.pop_back();
	cout<<"Vektor nakon metode pop_back: "<<v3<<endl;  
   
	cout<<"Neke metode:"<<endl;  
	cout << "z1+z2: " << z1+z2 << endl;
	cout << "z1-z2: " << z1-z2 << endl;
	cout << "z1*z2: " << z1*z2 << endl;
	cout << "z1/z2: " << z1/z2 << endl;
	  
	cout << "Modul od |" << z1 << "| iznosi:" << z1.module() << endl;
	cout << "Konjugirani z1: " << z1.conjugate() << endl;

	return 0;
}