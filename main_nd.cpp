#include "my_lib.h"

int main() {
  studentas Laikinas;
  vector <studentas> grupe;
  for(int j=0;j+2;j++){
    cout<<"Įveskite vardą:";
    cin>>Laikinas.Vardas;
    cout<<"Įveskite pavardę:";
    cin>>Laikinas.Pavarde;
    cout << "Įveskite namų darbų rezultatus (baigti įveskite 0): ";
  int rez;
  while (true) {
    cin >> rez;
    if (rez == 0) break; 
    Laikinas.ND_Pazymis.push_back(rez); 
  }
    cout<<"Įveskite egzamino rezultatą:";
    cin>>Laikinas.Egzaminas;

    char pasirinkimas;
    cout << "Pasirinkite, ką skaičiuoti- vidurkis(v) arba mediana (m):";
    cin>>pasirinkimas;
    if(pasirinkimas =='v'){
    double suma = 0; 
  for (int i = 0; i < Laikinas.ND_Pazymis.size(); i++) {
    suma += Laikinas.ND_Pazymis[i]; 
  }
  double vidurkis = suma / Laikinas.ND_Pazymis.size();
  Laikinas.Galutinis = 0.4 * vidurkis + 0.6 * Laikinas.Egzaminas;
    }
    else if (pasirinkimas=='m'){
      vector<int> pazymiai = Laikinas.ND_Pazymis;
      sort(pazymiai.begin(), pazymiai.end());
      double mediana;
      if (pazymiai.size() % 2 == 0) {
        Laikinas.Galutinis = 0.4 * pazymiai[pazymiai.size() / 2]+ (pazymiai[pazymiai.size()/ 2 - 1]) / 2.0  + 0.6 * Laikinas.Egzaminas;
      } else {
        Laikinas.Galutinis = 0.4 * (pazymiai[pazymiai.size() / 2]) + 0.6 * Laikinas.Egzaminas;
      }
    } else {
      cout << "Neteisingas pasirinkimas!" << endl;
    }

    grupe.push_back(Laikinas);
    Laikinas.ND_Pazymis.clear();
  cout << "Galutinis balas: ("<< (pasirinkimas == 'v' ? "Vid." : "Med.") << "): " << fixed << setprecision(2) << Laikinas.Galutinis << endl;
  }
  for (auto&a: grupe){
    cout<<a.Vardas<<" "<<a.Pavarde<<" Semestras:";
    for (auto&z:a.ND_Pazymis)
      cout<<z<<" ";
    cout<<"Egzaminas.: "<<a.Egzaminas<<endl;
  }
}
