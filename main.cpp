#include "mylib.h"
#include "failoFunkc.h"
#include "kitosFunkc.h"


int main() {
    int n, pazsk; //n - stud skaicius , pazsk - pazymiu sk faile
    string m, pavadinimas;
    vector<duom> vect, kiet, mink;

    cout << "Iveskite ('r') , jei balus norite irasyti ranka, \niveskite ('f'), jei norite nuskaityti balus is turimo failo, \niveskite bet kokia kita raide, jei norite sugeneruoti nauja faila: "; cin >> m;
    if (m == "r") {
        cout << "Iveskite, kiek yra studentu: "; cin >> n;
        ivedimas(vect, n);
        isvedimas(vect, n);

    }
    else if (m == "f") {
        cout << "Iveskite failo, kuri norite nuskaityti pavadinima" << endl;
        cin >> pavadinimas;
        nuskaitymas(vect, &pazsk, pavadinimas);
        sort(vect.begin(), vect.end(), rusiav);
        //isvedimas_i_faila(vect, pazsk); (V0.2 uzduoties isvedimas)
        skirstymas(vect, kiet, mink);
        isvedimas_i_2_failus(kiet,mink);
    }
    else {
        cout << "Iveskite, kiek studentu norite sugeneruoti (galimi var.: 1000, 10 000, 100 000, 1 000 000, 10 000 000):  "; cin >> n;
        naujasFailas(n);
        pavadinimas = "studentai" + to_string(n) + ".txt";
        cout << "Sukurto failo pavadinimas: " << pavadinimas << endl;
        nuskaitymas(vect, &pazsk, pavadinimas);
        sort(vect.begin(), vect.end(), rusiav);
        skirstymas(vect, kiet, mink);
        isvedimas_i_2_failus(kiet, mink);
    }return 0;
}

