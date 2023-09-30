#include "my_lib.h"

int main() {
  studentas Laikinas;
  vector <studentas> grupe;
  for(int j=0;j+2;j++){
    cout<<"Įveskite vardą:";
    cin>>Laikinas.Vardas;
    cout<<"Įveskite pavardę:";
    cin>>Laikinas.Pavarde;
    int n = rand() % 10 + 1;
  cout << "Namų darbų skaičius: " << n << "\n";
  cout << "Namų darbų rezultatai: ";
  for (int i = 0; i < n; i++) {
    int rez = rand() % 10 + 1; 
    cout << rez << " ";
    Laikinas.ND_Pazymis.push_back(rez); 
  }
    cout << "\n";
    int egz = rand() % 10 + 1; 
  cout << "Egzamino rezultatas: " << egz << "\n";
  Laikinas.Egzaminas = egz;

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
