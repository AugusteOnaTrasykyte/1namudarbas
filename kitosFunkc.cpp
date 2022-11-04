#include "skaiciavimai.h"
#include "kitosFunkc.h"

void ivedimas(vector<duom>& v, int n) {
    int nd;

    for (int i = 0; i < n; ++i) {
        v.resize(v.size() + 1);
        cout << "Iveskite studento varda: "; cin >> v[i].var;
        cout << "Iveskite studento pavarde: "; cin >> v[i].pav;
        string rinktis;
        cout << "Jei norite balus irasyti ranka, iveskite 'r', jei norite, kad sugeneruotu kompiuteris bet koki kita simboli" << endl;
        cin >> rinktis;
        if (rinktis == "r") {
            cout << "Iveskite, kiek studentas gavo is egzamino: "; cin >> v[i].egz;
            while (true) {
                cout << "Iveskite pazymi, jei daugiau pazymiu nera iveskite 0: " << endl;
                cin >> nd;
                if (nd >= 1 && nd <= 10) {
                    v[i].paz.push_back(nd);
                }
                else break;
            }
        }
        else {
            v[i].egz = random(1,10);
            for (int b = 0; b < 10; b++) {
                v[i].paz.push_back(random(1,10));
            }
        }

    }
}
bool rusiavimas(const duom& d1, const duom& d2){
       return d1.var < d2.var;
   }

void isvedimas(vector<duom> v, int n) {

    cout << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(40) << left << "Galutinis (Med.)/Galutinis (Vid.)" << endl;
    cout << string(80, '-') << endl;
    sort(v.begin(), v.end(), rusiavimas);
    for (int i = 0; i < n; i++) {
        cout << setw(20) << left << v[i].var << setw(20) << left << v[i].pav;
        cout << fixed << setprecision(2) << setw(20) << left <<galutinis(mediana(v[i].paz),v[i].egz) << galutinis(vidurkis(v[i].paz), v[i].egz) << endl;
    }
}