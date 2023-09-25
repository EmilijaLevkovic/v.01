#include "my_lib.h"

int main() {
  studentas Laikinas;
  vector <studentas> grupe;
  for(int j=0;j+2;j++){
    cout<<"Įveskite vardą: ";
    cin>>Laikinas.Vardas;
    cout<<"Įveskite pavardę: ";
    cin>>Laikinas.Pavarde;
    cout<<"Kiek ND pažymių turi studentas? ";
    int n;
    cin>>n;
    for (int i=0; i<n;i++) 
    {
      int k;
      cout<<"Įveskite" <<i+1<<" ND pažymį: ";
      cin>>k;
      Laikinas.ND_Pazymis.push_back(k);
    }
    cout<<"Įveskite egzamino rezultatą: ";
    cin>>Laikinas.Egzaminas;
    double suma= 0;
  for (int i=0; i<Laikinas.ND_Pazymis.size(); i++){
    suma += Laikinas.ND_Pazymis[i];
  }
  double vidurkis= suma/ Laikinas.ND_Pazymis.size();
  Laikinas.Galutinis= 0.4* vidurkis+ 0.6* Laikinas.Egzaminas;
    grupe.push_back(Laikinas);
    Laikinas.ND_Pazymis.clear();
  cout<< "Galutinis balas: "<<fixed<<setprecision(2)<<Laikinas.Galutinis<<endl;
  }
  for (auto&a: grupe){
    cout<<a.Vardas<<" "<<a.Pavarde<<" Semestras:";
    for (auto&z:a.ND_Pazymis)
      cout<<z<<" ";
    cout<<" Egzaminas:"a.Egzaminas<<endl;
  }
}
