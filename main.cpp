#include "mylib.h"
#include "failoFunkc.h"
#include "kitosFunkc.h"


int main() {
    int n, pazsk; //n - stud skaicius ivedant ranka, pazsk - pazymiu sk faile
    string m;
    vector<duom> vect;

    cout << "Iveskite r , jei balus norite irasyti ranka, iveskite bet kokia kita raide, jei norite nuskaityti balus is failo: "; cin >> m;
    if (m == "r") {
        cout << "Iveskite, kiek yra studentu: "; cin >> n;
        ivedimas(vect, n);
        isvedimas(vect, n);

    }
    else {
        nuskaitymas(vect, &pazsk);
        isvedimas_i_faila(vect, pazsk);
        system("pause");
    }
    return 0;
}
