#include <iostream>
     
using namespace std;
    
class Cvor{
 public:
    int n;
    Cvor *next;
 public:
    Cvor(int x, Cvor* p){n = x; next = p;}
};
     
class Lista{
 private:
    Cvor *glava;
 public:
    Lista(){glava = NULL;}
    void Insert(int);
    void Display();
    Cvor* Search(int);
    bool Delete(int);
    int velicina();
    ~Lista();
};  
// vraca broj cvorova liste
int Lista::velicina(){
    int br = 0;
    Cvor *tmp = glava;
    while (tmp != NULL){
        br++;
        tmp = tmp->next;
    }
    return br;
} 
//brise cvor koji sadrzi podatak x
bool Lista::Delete(int x){
    Cvor *tmp = glava;
    Cvor *p;
    // ukoliko prvi cvor sadrzi x, preusmjeri glavu na 
    // drugi cvor, a prvi cvor izbrisi
    if (glava->n == x)
    {
        glava = glava->next;
        delete tmp;
        return true;
    }
    // u suprotnom, p pokazuje na prvi, a tmp na drugi cvor
    p = tmp;
    tmp = tmp->next;
    // invarijanta while petlje je da ce p uvijek pokazivati na 
    // prethodni cvor od cvora na koji pokazuje tmp
    while (tmp != NULL)
    {   
        if (tmp->n == x){
            // preusmjeri prethodnik na cvor na koji pokazuje tmp
            // tj. zaobidji (bypass) cvor tmp, a tmp obrisi!
            p->next = tmp->next;
            delete tmp;
            return true;
        }
        // invarijanta petlje
        p = tmp;
        tmp=tmp->next;
    }
    return false;
}
// Vrati pokazivac na cvor koji sadrzi x u sebi. U suprotnom vrati NULL
Cvor* Lista::Search(int x){
    Cvor *tmp = glava;
    while(tmp!=NULL){
        if (tmp->n == x)    
            return tmp;
        tmp=tmp->next;
    }
    return NULL;
}
// dodaj novi cvor na pocetak liste s podatkom x u sebi
void Lista::Insert(int x){
    Cvor *m = new Cvor(x, glava);
    glava = m;
}
// prolazi cvorovima liste i ispisuje podatke u cvorovima na ekran.
void Lista::Display(){
    Cvor *tmp = glava;
    while (tmp != NULL){
        cout << "-->" << tmp->n;
        tmp = tmp->next;  
    }
    cout << "--> NULL" << endl;
} 
// Destruktor brise listu, tj. sve cvorove liste. 
// Primjetite da je destruktor nuzan jer su cvorovi alocirani dinamicki. 
// NAPOMENA: Pazite da ne pobrisete cvor prije nego ste
// pohranili (backupirali) pokazivac na sljedeci. Jer u suprotnom 
// necete vise moci pristupiti sljedecem. 
Lista::~Lista()
{
    Cvor *trenutni = glava;
    while (trenutni!=NULL){
        Cvor *prethodnik = trenutni;
        trenutni = prethodnik->next;
        delete prethodnik;
    }
}
     
int main()
{
    Lista L;
    L.Insert(4);
    L.Insert(7);
    L.Insert(-3);
    L.Insert(2);
        
    L.Display();
    if (L.Search(4)!=NULL) 
        cout << "U listi" << endl;
    else
        cout << "Nije u listi" << endl;
    L.Delete(7);
    L.Display();
    cout << "Lista ima " << L.velicina() << " cvorova " << endl;
    return 0;
}