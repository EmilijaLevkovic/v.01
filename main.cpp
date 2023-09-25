#include "my_lib.h"

int main() {
  studentas Laikinas;
  vector <studentas> grupe;
  for(int j=0;j+2;j++){
    cout<<"Iveskite varda:";
    cin>>Laikinas.Vardas;
    cout<<"Iveskite pavarde:";
    cin>>Laikinas.Pavarde;
    cout<<"Kiek ND pazymiu turi studentas?";
    int n;
    cin>>n;
    for (int i=0; i<n;i++) 
    {
      int k;
      cout<<"Iveskite" <<i+1<<"ND Pazymi:";
      cin>>k;
      Laikinas.ND_Pazymis.push_back(k);
    }
    cout<<"Iveskite egzamino rezultata:";
    cin>>Laikinas.Egzaminas;
    grupe.push_back(Laikinas);
    Laikinas.ND_Pazymis.clear();
  }
  for (auto&a: grupe)
    cout<<a.Vardas<<" "<<a.Pavarde<<" "<<a.Egzaminas<<endl;;
}
