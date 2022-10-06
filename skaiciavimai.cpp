#include "skaiciavimai.h"
#include "mylib.h"
double mediana(vector<int> v) {
    double m;
    if (v.size() != 0) {
        sort(v.begin(), v.end());
        if (v.size() % 2 != 0) {
            m = v[(v.size() - 1) / 2];
        }
        else {
            m = (v[v.size() / 2] + v[v.size() / 2 - 1]) / 2;
        }
    }
    else m = 0;
    return m;
}

double vidurkis(vector<int> v) {
    double a;
    double suma;
    suma = accumulate(v.begin(), v.end(), 0);
    if (v.size() != 0) {
        a = suma / v.size();
    }
    else a = 0;
    return a;
}

double galutinis(double vid, double egzam) {
    double gal;
    gal = (0.4 * vid) + (0.6 * egzam);
    return gal;
}