#include <iostream>
using namespace std;

class Vektor {
public:
    int *P;
    int len;
    int curr_len;

public:
    // konstruktori
    Vektor(){P = NULL;}
    Vektor(int s);
    Vektor(const Vektor &V); // konstruktor kopiranja

    // ostale metode (interface klase Vektor)
    bool append(int); // dodaje int na kraj
    bool search(int); // vrati 'true' ako je pronašao traženi int
    void ispisi();// ispisuje Vektor na ekran (standardni output)
    void sort();// sortira elemente Vektora

    friend ostream& operator<<(ostream& buffer, const Vektor &V);
    
    void Zbroji(const Vektor& V1, const Vektor& V2); // V1 + V2
    void Mnozi(const Vektor& V); // V1 * V2 skalarno
    
    // operatori
    void operator=(const Vektor&);
    Vektor operator+(const Vektor&) const;
    Vektor operator-(const Vektor&) const;
    int operator*(const Vektor&) const;
    void operator+=(const Vektor&);
    void operator-=(const Vektor&);
    bool operator==(const Vektor&) const;
    int& operator[](int) const;
    // destruktor
    ~Vektor(){delete [] P;}
};

Vektor::Vektor(int s){
    len = s;
    P = new int [len];
    curr_len = 0;
}

Vektor::Vektor(const Vektor &V){
    if (V.curr_len){
        this -> curr_len = V.curr_len;
        this -> len = V.len;

        this -> P = new int [this -> len];

        for (int i = 0; i < this -> curr_len; i++)
            this -> P[i] = V.P[i]; 
    }
}

bool Vektor::append(int x){
    if (curr_len < len){
        P[curr_len] = x;
        curr_len++;
        return true;
    }

    return false;
}

bool Vektor::search(int x){
    if(curr_len){
        for(int i=0; i<curr_len; i++)
            if(P[i] == x) return true;
        return false;
    }
}

void Vektor::ispisi(){
    if (curr_len){
        for (int i=0; i < curr_len; i++)
            cout << P[i] << "\t";
        cout << endl;
    }
}

void Vektor::sort(){
    if(curr_len){
        bool sorted = false;
        while (!sorted){
            sorted = true;
            for(int i=0; i<curr_len - 1; i++){
                if(P[i]>P[i+1]){
                    sorted = false;
                    int tmp = P[i];
                    P[i] = P[i+1];
                    P[i+1] = tmp;
                }
            }
        }
    }
}

void Vektor::Mnozi(const Vektor& V){
    if (this -> curr_len == V.curr_len){
        int sum=0;
        for (int i=0; i<V.curr_len; i++)
            sum += this -> P[i] * V.P[i];
        cout << "Skalarni produkt = " << sum << endl;           
    }
}

void Vektor::Zbroji(const Vektor& V1, const Vektor& V2){
    if(V1.curr_len == V2.curr_len){
        this -> len = V1.len;
        this -> curr_len = V1.curr_len;
        this -> P = new int [this -> len];

        for (int i=0; i<V1.curr_len; i++)
            this -> P[i] = V1.P[i] + V2.P[i];
    }
}

void Vektor::operator=(const Vektor &V){
    if(V.curr_len){
        if (this -> P) delete [] this -> P;

        this -> curr_len = V.curr_len;
        this -> len = V.len;

        this -> P = new int [this -> len];

        for (int i=0; i < this -> curr_len; i++)
            this -> P[i] = V.P[i];
    }
}

Vektor Vektor::operator+(const Vektor&V) const{
    if(this -> len == V.len){
        Vektor Z(V);

        for(int i=0; i<Z.curr_len; i++)
            Z.P[i] += this -> P[i];

        return Z;
    }
}

Vektor Vektor::operator-(const Vektor&V) const{
    if(this -> len == V.len){
        Vektor Z(V);

        for(int i=0; i<Z.curr_len; i++)
            Z.P[i] -= this -> P[i];

        return Z;
    }
}

int Vektor::operator*(const Vektor&V) const{
    if (this -> curr_len == V.curr_len){
        int sum=0;

        for (int i=0; i<V.curr_len; i++)
            sum += this -> P[i] * V.P[i];

        return sum;     
    }
}

void Vektor::operator+=(const Vektor&V){
    if(this -> curr_len == V.curr_len){
        for (int i=0; i<V.curr_len; i++)
            this -> P[i] += V.P[i];
    }
}

void Vektor::operator-=(const Vektor&V){
    if(this -> curr_len == V.curr_len){
        for (int i=0; i<V.curr_len; i++)
            this -> P[i] -= V.P[i];
    }
}

bool Vektor::operator==(const Vektor&V) const{
    if(this -> curr_len == V.curr_len && this -> len == V.len){
        for (int i=0; i<V.curr_len; i++)
            if(this -> P[i] != V.P[i]) return false;
        return true;
    }
    return false;
}

ostream& operator<<(ostream& buffer, const Vektor &V){
    for(int i = 0; i<V.curr_len; i++)
        buffer << V.P[i] << "\t";
    buffer << endl;
    return buffer;
}

int & Vektor::operator[](int i) const{
    return this -> P[i];
}

int main(){
    Vektor V(6);
    V.append(7); V.append(6); V.append(11);

    cout << V << endl;
    
    return 0;
}
