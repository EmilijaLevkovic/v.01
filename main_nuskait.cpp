#include "my_lib.h"

vector<studentas> nuskaityti_faila(const string& failo_vardas) {
    ifstream fin(failo_vardas); 
    if (!fin) { 
        cout << "Nepavyko atidaryti failo " <<failo_vardas << endl;
        return {}; 
    }
    string eilute;
    getline(fin, eilute); 
    stringstream ss(eilute);
    string zodis;
    int nd_kiekis = -2; 
    while (ss >> zodis) { 
        nd_kiekis++; 
    }
    vector<studentas> grupe; 
    while (getline(fin, eilute)) {
        stringstream ss(eilute); 
        studentas Laikinas; 
        ss >> Laikinas.Vardas >> Laikinas.Pavarde;
        for (int i = 0; i < nd_kiekis; i++) { 
            int k;
            ss >> k;
            Laikinas.ND_Pazymis.push_back(k);
        }
        ss >> Laikinas.Egzaminas; 
        grupe.push_back(Laikinas); 
    }
    fin.close();
    return grupe; 
}

void isvesti_rezultatus(const vector<studentas>& grupe) {
    cout << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde" << setw(20) << right << "Galutinis (Vid.)" << setw(20) << right << "Galutinis (Med.)" << endl; 
    cout << setfill('-') << setw(70) << "-" << endl; 
    cout << setfill(' '); 
    for (auto& Laikinas : grupe) { 
    double suma = 0; 
    for (int i = 0; i < Laikinas.ND_Pazymis.size(); i++) {
        suma += Laikinas.ND_Pazymis[i]; 
    }
    double vidurkis = suma / Laikinas.ND_Pazymis.size();
    Laikinas.GalutinisVid = 0.4 * vidurkis + 0.6 * Laikinas.Egzaminas; 

        vector<int> pazymiai = Laikinas.ND_Pazymis;
        sort(pazymiai.begin(), pazymiai.end());
        double mediana;
        if (pazymiai.size() % 2 == 0) {
            mediana = (pazymiai[pazymiai.size() / 2] + pazymiai[pazymiai.size()/ 2 - 1]) / 2.0;
        } else {
            mediana = pazymiai[pazymiai.size() / 2];
        }
        Laikinas.GalutinisMed= 0.4 * mediana + 0.6 * Laikinas.Egzaminas;

        cout << setw(15) << left << Laikinas.Vardas << setw(15) << left << Laikinas.Pavarde << setw(20) << right << fixed << setprecision(2) << Laikinas.GalutinisVid << setw(20) << right << fixed << setprecision(2) << Laikinas.GalutinisMed << endl; 
    }
}

int main() {
  vector<studentas> grupe= nuskaityti_faila("kursiokai.txt");
  isvesti_rezultatus(grupe); 
  return 0;
}
