#include "my_lib.h"

double vidurkis(vector<int> v) {
  double suma = 0;
  for (int x : v) {
    suma += x;
  }
  return suma / v.size();
}

double mediana(vector<int> v) {
  sort(v.begin(), v.end());
  int n = v.size();
  if (n % 2 == 0) { 
    return (v[n/2 - 1] + v[n/2]) / 2.0; 
  } else { 
    return v[n/2];
  }
}

studentas nuskaitytiStudenta(fstream& fin) {
  studentas s; 
  fin >> s.Vardas >> s.Pavarde; 
  int x; 
  while (fin >> x && x != -1) {
    s.ND_Pazymis.push_back(x); 
  }
  s.Egzaminas = x;
  return s;
}

void spausdintiStudentus(vector<studentas> studentai) {
  cout << "Vardas\t\tPavarde\t\tGalutinis (Vid.)\tGalutinis (Med.)\n"; 
  cout << "-------------------------------------------\n";
  for (studentas s : studentai) { 
    s.GalutinisVid = 0.4 * vidurkis(s.ND_Pazymis) + 0.6 * s.Egzaminas;
    s.GalutinisMed = 0.4 * mediana(s.ND_Pazymis) + 0.6 * s.Egzaminas;
    cout << s.Vardas << "\t\t" << s.Pavarde << "\t\t" << fixed << setprecision(2) << s.GalutinisVid << "\t\t" << s.GalutinisMed << "\n";
  }
}

int main() {
  fstream fin("kursiokai.txt");
  vector<studentas> studentai;
  while (!fin.eof()) { 
    studentai.push_back(nuskaitytiStudenta(fin)); 
  }
  fin.close(); 
spausdintiStudentus(studentai); 
  return 0;
}
