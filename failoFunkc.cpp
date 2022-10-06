#include "duomenys.h"
#include "failoFunkc.h"
#include "skaiciavimai.h"

unsigned int balukiekis(string const& str)//skaiciuoja zodziu sk eiluteje, kur zodis - simboliai be tarpu, atima 3(var,pav,egz) ir lieka balu kiekis
{
    stringstream stream(str);
    return distance(istream_iterator<string>(stream), istream_iterator<string>()) - 3;
}

void nuskaitymas(vector<duom>& v, int* pazsk) { //failo nuskaitymo funkcija
    int studsk = 0; //indkesas vektoriuje v (studentas)
    int laikinas; //balo reiksme
    ifstream skaitymas;
    string buff;

    skaitymas.open("Studentai10000.txt");

    if (skaitymas.is_open()) { //ciklas vyksta jei pavyko atidaryti faila
        getline(skaitymas >> ws, buff);
        *pazsk = balukiekis(buff);

        while (!skaitymas.eof()) { //ciklas vyksta kol pasiekiama failo pabaiga
            v.resize(v.size() + 1);
            skaitymas >> v.at(studsk).var;
            skaitymas >> v.at(studsk).pav;

            for (int i = 0; i < *pazsk; i++) { //nuskaitomi balai ir irasomi i vektoriu paz
                skaitymas >> laikinas;
                v.at(studsk).paz.push_back(laikinas);
            }

            skaitymas >> v.at(studsk).egz;
            studsk++;
        }skaitymas.close();
    }
    else cout << "Failas nerastas" << endl;
}

/*struct rusiavimas
{
    bool operator()(const duom& d1, const duom& d2)
    {
        return d1.var < d2.var;
    }
};*/

void isvedimas_i_faila(vector<duom> v, int pazsk) {
    ofstream output;
    output.open("rezultatai.txt");
    output << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(40) << left << "Galutinis(med.)/Galutinis(vid.)" << endl;
    output << string(80, '-') << endl;
   // sort(v.begin(), v.end(), rusiavimas());
    for (int i = 0; i < v.size(); i++)
    {
        output << setw(20) << left << v[i].var << setw(20) << left << v[i].pav;
        output << fixed << setprecision(2) << setw(20) << left << mediana(v[i].paz) << galutinis(vidurkis(v[i].paz), v[i].egz) << endl;
    }
}
