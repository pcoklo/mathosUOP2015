#include <iostream>
using namespace std;

class Tocka
{
public:
	float x;
	float y;
	Tocka(): x(0), y(0) {};
	Tocka(float x, float y): x(x), y(y) {};
	Tocka(const Tocka &T): x(T.x), y(T.y) {};
};

int main(){
	Tocka A(0,2);
	cout << A.x << endl << A.y << endl;
	return 1;
}
