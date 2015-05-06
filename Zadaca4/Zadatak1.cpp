#include <iostream>
#include <cstdlib>
using namespace std;

class Vektor {
protected:
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

    void Zbroji(const Vektor& V1, const Vektor& V2); // V1 + V2
    void Mnozi(const Vektor& V); // V1 * V2 skalarno

    // operatori pridruživanja
    void operator=(const Vektor&);
    void operator+=(const Vektor&);
    void operator-=(const Vektor&);

    //aritmetični operatori
    Vektor operator-(const Vektor&) const;
    Vektor operator+(const Vektor&) const;
    int operator*(const Vektor&) const;

    //logički operator
    bool operator==(const Vektor&) const;

    //operator pristupa
    int& operator[](int) const;
    
    // destruktor
    ~Vektor(){delete [] P;}
};

//konstruktor stvara Vektor od velićine
Vektor::Vektor(int s){
    len = s;
    P = new int [len];
    curr_len = 0;
}

//kopy konstruktor
Vektor::Vektor(const Vektor &V){
//  if(V.curr_len > 0){
//  if(V.curr_len != 0){
//  if(V.curr_len >= 1){
    if(V.curr_len){     //ako postoji polje
        //trenutna veličina i ukupna veličina starog objekta = trenutna i ukupna ovog objekta
        this -> curr_len = V.curr_len;
        this -> len = V.len;
        //dinamička alokacija polja P
        this -> P = new int [this -> len];
        //kopiraj svaki element polja iz jednog objekta u drugi
        for (int i = 0; i < this -> curr_len; i++)
            this -> P[i] = V.P[i]; 
    }
}

//dodaje element na prvo slobodno mjesto
bool Vektor::append(int x){
    //ako ima mjesta u polju
    if (curr_len < len){
        P[curr_len] = x;    //stavi element na zadnje mjesto
        curr_len++;         //pomakni to mjesto za jedan
        return true;        //istina
    }

    return false;           //nije istina
}

bool Vektor::search(int x){
//  if(V.curr_len > 0){
//  if(V.curr_len != 0){
//  if(V.curr_len >= 1){
    if(curr_len)    //ako postoji polje
        for(int i=0; i<curr_len; i++)   //prođi kroz sve elemente
            if(P[i] == x) return true;  //ako si naišao na element, return true

    //ako polje nepostoji i nisi našao element
    return false;   //vrati false
}


void Vektor::ispisi(){
//  if(V.curr_len > 0){
//  if(V.curr_len != 0){
//  if(V.curr_len >= 1){
    if (curr_len){  //ako postoji polje
        for(int i=0; i<curr_len; i++)   //prođi kroz sve elemente
            cout << P[i] << "\t";       //i ispiši svaki i dodaj tabulator
        cout << endl;   //dodaj endl na kraju
    }
}

void Vektor::sort(){
//  if(V.curr_len >= 2){
    if(curr_len > 1){   //ako postoji polje i veće je od 1
        bool sorted = false;
        while (!sorted){    //sortiraj bablsortom
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

//množenje vektora je suma umnožaka i-tih elemenata jednog i drugog objekta
void Vektor::Mnozi(const Vektor &V){
    //ako su trenutne duljine vektora jednake
    if (this -> curr_len == V.curr_len){
        int sum=0;  //suma je = 0 jepribrojavamo u nju umnoške elemenata

        for (int i=0; i<V.curr_len; i++)
            sum += this -> P[i] * V.P[i];   //pomnoži i zbrajaj u sumu
        //  sum = sum + this -> P[i] * V.P[i];

        cout << "Skalarni produkt = " << sum << endl;
    //  coit << sum << endl;
    //  cout << "Umnožak vektora = " << sum << endl;
    }
    else cout << "neože se množit" << endl;
}

//ako zovemo funkciju vektora V od vektora V1 i V2 -> V=V1+V2
//npr V.Zbroji(V1,V2); V će biti zbroj ta dva vektora
// this je V
void Vektor::Zbroji(const Vektor &V1, const Vektor &V2){
    //ako su tranutne duljine vektora jednake
    if(V1.curr_len == V2.curr_len){
        this -> len = V1.len;
    //  this -> len = V2.len;

        this -> curr_len = V1.curr_len;
    //  this -> curr_len = V2.curr_len;

        //diniamički alociraj polje vektora veličine ukupne duljine
        this -> P = new int [this -> len];

        for (int i=0; i<V1.curr_len; i++)
            this -> P[i] = V1.P[i] + V2.P[i];
            //zbroji sve element i stavi ih u polje novog objekta
    }
}

//desni kopiramo u lijevi
void Vektor::operator=(const Vektor &V){
//  if(V.curr_len > 0){
//  if(V.curr_len != 0){
//  if(V.curr_len >= 1){
    if(V.curr_len){     //ako postoji vektor
        //obriši staro polje, ako postoji
        if (this -> P) delete [] this -> P;

        //kopiraj vrijednosti
        this -> curr_len = V.curr_len;
        this -> len = V.len;

        //stvori novo polje
        this -> P = new int [this -> len];

        for (int i=0; i < this -> curr_len; i++)
            this -> P[i] = V.P[i];
            //kopiraj elemente iz jednog u drugi
    }
}

//što se događa??
void Vektor::operator+=(const Vektor &V){ *this = *this + V; }
void Vektor::operator-=(const Vektor &V){ *this = *this - V; }

//Z = V1 + V2
//this = V1; V= V2
Vektor Vektor::operator+(const Vektor &V) const{
    if(this -> curr_len == V.curr_len){
        //stvori novi objekt kao kopiju prosljedenog objekta
        Vektor Z(V);
        //Z=V2

        //Z+=V1
        for(int i=0; i<Z.curr_len; i++)
            Z.P[i] += this -> P[i];

        //Z = V1 + V2;
        return Z;
    }
}

Vektor Vektor::operator-(const Vektor &V) const{
    if(this -> curr_len == V.curr_len){
        Vektor Z(V);

        for(int i=0; i<Z.curr_len; i++)
            Z.P[i] -= this -> P[i];

        return Z;
    }
}

int Vektor::operator*(const Vektor &V) const{
    if (this -> curr_len == V.curr_len){
        int sum=0;

        for (int i=0; i<V.curr_len; i++)
            sum += this -> P[i] * V.P[i];

        return sum;     
    }
}

//vrati jednako ako je svaki element jednak svakom elementu
//ako su ukupne i trenutne duljine jednake
//uprotivnom vrati false
bool Vektor::operator==(const Vektor &V) const{
    if(this -> curr_len == V.curr_len && this -> len == V.len){
        for (int i=0; i<V.curr_len; i++)
            if(this -> P[i] != V.P[i]) return false;
            //ako je bilo koji element razlićit return false
        //ako nisi napravio return dosad, znači da su svi elementi jednaki
        return true;
    }
//ako if nije sitina return false
    return false;
}

int & Vektor::operator[](int i) const{
    return this -> P[i];
}


int main(){
    Vektor V1(6), V2(6);
    V1.append(7); V1.append(6); V1.append(11);
    V2.append(16);V2.append(8); V2.append(4);

    if(V1==V2) cout << "V1 == V2" << endl;
    else cout << "V1 != V2" << endl;

    Vektor C(6);

    V1+=V2;

    V1.ispisi();

    C = V1+V2;

    C.ispisi();

    V1.Mnozi(V2);

    V1 = V2;

    if(V1==V2) cout << "V1 == V2" << endl;
    else cout << "V1 != V2" << endl;

    int n=30;
    Vektor V(n);
    Vektor H(n);
    for(int i=0; i<n; i++){
        V.append(rand()%10);
        H.append(rand()%10);
    }
    V.ispisi();
    H.ispisi();
    V.sort(); V.ispisi();
    H.sort(); H.ispisi();
    H+=V;
    H.ispisi();

    cout << H[16] << endl;
    return 0;
}