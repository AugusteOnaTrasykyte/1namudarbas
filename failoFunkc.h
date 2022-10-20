#pragma once
#include "mylib.h"
#include "skaiciavimai.h"
bool rusiav(const duom& d1, const duom& d2);
void isvedimas_i_faila(vector<duom> v, int pazsk);
void nuskaitymas(vector<duom>& v, int* pazsk, string pavadinimas);
void naujasFailas(int studsk);
void skirstymas(vector<duom> v, vector<duom>& k, vector<duom>& m);
void isvedimas_i_2_failus(vector<duom> v, vector<duom> m);