#include "mylib.h"
#include "failoFunkc.h"
#include "kitosFunkc.h"


int main() {
    int n, pazsk, stud; //n - stud skaicius , pazsk - pazymiu sk faile
    string m, pavadinimas;
    vector<duom> vect, kiet, mink;
    list<duom> lst, kieti, minksti;

    // V0.1 VERSIJA
 /*
     cout << "Iveskite, kiek yra studentu: "; cin >> n;
     ivedimas(vect, n);
     isvedimas(vect, n);

 }*/
    cout << "iveskite ('f'), jei norite nuskaityti turimus failus, \niveskite bet kokia kita raide, jei norite sugeneruoti naujus failus: "; cin >> m;

    if (m == "f") {
        while (true) {
            cout << "Iveskite failo, kuri norite nuskaityti pavadinima, arba ('0'), jei baigete darba " << endl;
            cin >> pavadinimas;
            if (pavadinimas == "0")break;
            else {
                //       VECTOR:
                nuskaitymas(vect, &pazsk, stud, pavadinimas);
                sort(vect.begin(), vect.end(), rusiav);
                //isvedimas_i_faila(vect, pazsk); (V0.2 UZDUOTIES ISVEDIMAS I VIENA FAILA)
                
                skirstymas(vect, kiet, mink);
                //isvedimas_i_2_failus(kiet,mink, stud); //(V0.3 UZDUOTIES ISVEDIMAS) 

                //naujas_skirstymas(vect, mink);
                //isvedimas_i_2_failus(vect, mink, stud);

                remove_if_skirstymas(vect, mink);
                //isvedimas_i_2_failus(vect, mink, stud);

                //       LIST:
                nuskaitymas_list(lst, &pazsk, stud, pavadinimas);
                lst.sort(rusiav);

                skirstymas_list(lst, kieti, minksti);
                //isvedimas_i_2_failus_list(stud, kieti, minksti);

                naujas_skirstymas_list(lst, minksti);
                //isvedimas_i_2_failus_list(stud, lst, minksti);

            }
        }
    }
    else {
        while (true) {
            cout << "Iveskite, kiek studentu norite sugeneruoti, jei baigete darba, iveskite ('0'):  "; cin >> n;
            if (n == 0) break;
            else {
                try {
                    if (n < 0) throw 0;
                    naujasFailas(n);
                    pavadinimas = "studentai" + to_string(n) + ".txt";
                    cout << "Sukurto failo pavadinimas: " << pavadinimas << endl;

                    //       VECTOR:
                    nuskaitymas(vect, &pazsk, stud, pavadinimas);
                    sort(vect.begin(), vect.end(), rusiav);
                    //isvedimas_i_faila(vect, pazsk); (V0.2 UZDUOTIES ISVEDIMAS I VIENA FAILA)

                    //skirstymas(vect, kiet, mink);
                    //isvedimas_i_2_failus(kiet,mink, stud); //(V0.3 UZDUOTIES ISVEDIMAS) 

                    remove_if_skirstymas(vect, mink);
                    //isvedimas_i_2_failus(vect, mink, stud);

                    naujas_skirstymas(vect, mink);
                    //isvedimas_i_2_failus(vect, mink, stud);


                    //       LIST:
                    nuskaitymas_list(lst, &pazsk, stud, pavadinimas);
                    lst.sort(rusiav);

                    skirstymas_list(lst, kieti, minksti);
                    //isvedimas_i_2_failus_list(stud, kieti, minksti);

                    naujas_skirstymas_list(lst, minksti);
                    //isvedimas_i_2_failus_list(stud, lst, minksti);
                }
                catch (int e) { cout << "Per mazas studentu kiekis \n"; }
            }
        }
    }
}

