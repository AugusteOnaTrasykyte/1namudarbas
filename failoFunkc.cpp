#include "mylib.h"
#include "failoFunkc.h"
#include "skaiciavimai.h"

unsigned int balukiekis(string const& str)//skaiciuoja zodziu sk eiluteje, atima 3(var,pav,egz) ir lieka balu kiekis
{
    stringstream stream(str);
    return distance(istream_iterator<string>(stream), istream_iterator<string>()) - 3;
}

bool rusiav(const duom& d1, const duom& d2)
{
    return d1.var < d2.var;
}
void nuskaitymas(vector<duom>& v, int* pazsk, string pavadinimas) { 
    auto start = std::chrono::high_resolution_clock::now();
    int studsk = 0; //indkesas vektoriuje v (studentas)
    int laikinas; //balo reiksme
    ifstream skaitymas;
    string buff;
    try{
        skaitymas.open(pavadinimas);

        if (!skaitymas.is_open()) throw 0;

        getline(skaitymas >> ws, buff);
        *pazsk = balukiekis(buff);

        while (true) {
            v.resize(v.size() + 1);
            skaitymas >> v.at(studsk).var;
            if (skaitymas.eof()) {
                v.pop_back(); break;
            }
            skaitymas >> v.at(studsk).pav;
            for (int i = 0; i < *pazsk; i++) { //nuskaitomi balai ir irasomi i vektoriu paz
                skaitymas >> laikinas;
                v.at(studsk).paz.push_back(laikinas);
            }

            skaitymas >> v.at(studsk).egz;
            studsk++;
        }skaitymas.close();
    }
    catch (int e) {
        cout << "Failas nerastas"<< endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration < double>diff = end - start;
    cout << "Failo nuskaitymas uztruko: " << diff.count() << "s\n";
}


void isvedimas_i_faila(vector<duom> v, int pazsk) {
    ofstream output;
    output.open("rezultatai.txt");
    output << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(40) << left << "Galutinis(med.)/Galutinis(vid.)" << endl;
    output << string(80, '-') << endl;

    for (int i = 0; i < v.size(); i++)
    {
        output << setw(20) << left << v[i].var << setw(20) << left << v[i].pav;
        output << fixed << setprecision(2) << setw(20) << left << galutinis(mediana(v[i].paz), v[i].egz) << galutinis(vidurkis(v[i].paz), v[i].egz) << endl;
    }
}

void naujasFailas(int studsk) {

    auto start = std::chrono::high_resolution_clock::now();
    string file;
    file = "studentai" + to_string(studsk) + ".txt";

    ofstream generuoti;
    generuoti.open(file);

    generuoti << left << setw(20) << "Vardas" << setw(20) << "Pavarde";
    for (int i = 0; i < 10; i++) {
        generuoti << setw(7) << "ND" + to_string(i + 1);
    };
    generuoti << setw(7) << "Egz.";
    generuoti << endl;//sukurta virsutine eilute su stulpeliu pavadinimais
    for (int i = 0; i < studsk; i++) { //failas uzpildomas duomenimis
        generuoti << left << setw(20) << "Vardas" + to_string(i + 1) << setw(20) << "Pavarde" + to_string(i + 1);

        for (int j = 0; j < 11; j++) {
            generuoti << setw(7) << random(1,10);
        }
        if (i != studsk - 1) generuoti << endl;
    }

    generuoti.close();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration < double>diff = end - start;
    cout << "Failo sukurimas uztruko: " << diff.count() << "s\n";
}

void skirstymas(vector<duom> v, vector<duom>& k, vector<duom>& m) {
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < v.size(); i++) {
        if (galutinis(mediana(v[i].paz), v[i].egz) && galutinis(vidurkis(v[i].paz), v[i].egz) < 5 ){
            m.push_back(v[i]);
        }
        else k.push_back(v[i]);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration < double>diff = end - start;
    cout << "Skirstymas i kietus ir minkstus uztruko: " << diff.count() << "s\n"; 
    v.clear();
}

void isvedimas_i_2_failus(vector<duom> k, vector<duom> m) {
    auto start = std::chrono::high_resolution_clock::now();
    ofstream output1,output2;
    output1.open("kieti.txt");
    output1 << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(40) << left << "Galutinis(med.)/Galutinis(vid.)" << endl;
    output1 << string(80, '-') << endl;

    for (int i = 0; i < k.size(); i++)
    {
        output1 << setw(20) << left << k[i].var << setw(20) << left << k[i].pav;
        output1 << fixed << setprecision(2) << setw(20) << left << galutinis(mediana(k[i].paz), k[i].egz) << galutinis(vidurkis(k[i].paz), k[i].egz) << endl;
    }
    output2.open("minksti.txt");
    output2 << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(40) << left << "Galutinis(med.)/Galutinis(vid.)" << endl;
    output2 << string(80, '-') << endl;

    for (int i = 0; i < m.size(); i++)
    {
        output2 << setw(20) << left << m[i].var << setw(20) << left << m[i].pav;
        output2 << fixed << setprecision(2) << setw(20) << left << galutinis(mediana(m[i].paz), m[i].egz) << galutinis(vidurkis(m[i].paz), m[i].egz) << endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration < double>diff = end - start;
    cout << "Isvedimas i du failus uztruko: " << diff.count() << "s\n";
}