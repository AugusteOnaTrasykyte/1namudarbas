#include "mylib.h"
struct duom{
  string var;
  string pav;
  double paz[35];
  int egz;
  string rez;
};

duom ivedimas(int &n);
void isvedimas(duom ats, int n);

int main(){
  duom asmuo, mas[30];
  int n, m;
  cout<<"Iveskite, kiek yra studentu: "; cin>>n;
  for (int i=0;i<n;i++){
       mas[i]=ivedimas(m);
       isvedimas (mas[i], m);
    }
}

duom ivedimas(int &n){
    duom stud;
    cout<<"Iveskite studento varda: "; cin>>stud.var;
    cout<<"Iveskite studento pavarde: "; cin>>stud.pav;
    string rinktis;
    srand(time(0));  //kad kiekviena karta generuotu naujus duomenis
    cout<<"Jeigu norite irasyti egzamino bala, iveskite t, jei norite, kad balas butu atsitiktinis, iveskite n"<<endl;
        cin>>rinktis;
        if(rinktis=="t"){ //vartotojas iveda egz bala
            cout<<"Iveskite, kiek studentas gavo is egzamino: "; cin>>stud.egz;
        }else if (rinktis=="n"){ //kompiuteris generuoja egz bala
            stud.egz = (rand() % 10) + 1;
            cout<<stud.egz<<endl;
        }else{
            cout<<"padarete ivedimo klaida"<<endl;
        }

    vector<int> vek; //sukuriamas vektorius
    vek.reserve(30);
    n=0;
    string pasirinkti;
    int kiekis;
    cout << "Jeigu namu darbu pazymius ivedinesite ranka rasykite: t, jei norite, kad pazymius sugeneruotu kompiuteris, rasykite: n" << endl;
        cin >> pasirinkti;
        if(pasirinkti == "t"){ // balus veda vartotojas
            cout<<"iveskite balu kieki (iki 30), jei jo nezinote, iveskite 100"<<endl; //nes vektoriuje rezervuota 30 vietu
            cin>>kiekis;
            if(kiekis==100){ //ciklas kai ivedami pazymiai nezinant ju kiekio
                for(int a=0;a<30;a++){
                    cout<<"Iveskite pazymi, jei daugiau pazymiu nera iveskite 0: ";
                    cin>>vek[a];
                    if(vek[a]==0)break;
                    else if(vek[a]>=1 && vek[a]<=10){ //tikrinama ar ivestas tinkamas pazymys
                        stud.paz[a] = vek[a];
                    }
                    else{
                        cout<<"Padarete ivedimo klaida"<<endl;
                        break;
                    }
                    n++;
                    vek.push_back(a); //i vektoriu iraso elementa
                }
            }else if(kiekis>=1 && kiekis<=30){ //tikrinama ar balai tilps i vektoriu
                for(int a=0; a<kiekis;a++){
                    cout<<"iveskite "<<a+1<<" pazymi: ";cin>>vek[a];
                    if(vek[a]>=1 && vek[a]<=10){
                        stud.paz[a] = vek[a];
                        n++;
                    }
                    else{
                        cout<<"Padarete ivedimo klaida"<<endl;
                        break;
                    }vek.push_back(a);

                }
            }else{
                cout<<"per didelis pazymiu skaicius"<<endl;}

        }else if (pasirinkti == "n"){ //balus generuoja kompiuteris
            srand(time(0));
            for( int i = 0; i < (rand() % 30); ++i ) { //parenkamas random kiekis(iki30) random balu
                vek.push_back((rand() % 10) + 1);
                stud.paz[i]=vek[i];
                n++;
            }
        }
        else{
            cout<<"Padarete ivedimo klaida"<<endl;
        }

    vek.shrink_to_fit(); // sumazina vek capacity iki size
    cout<<"jei norite spausdinti vidurki, iveskite v, jei mediana - m, jei abu - bet koki kita simboli"<<endl;
    cin>>stud.rez;
    return stud;
}
double mediana(duom md,int n){
    double m;
    sort(md.paz,md.paz+n);
    if(n%2!=0)m=md.paz[(n-1)/2];
    else m = (md.paz[n/2]+md.paz[n/2-1])/2;
    return m;
}
double vidurkis(duom vd, int n){
    double v;
    int sum = 0;
    for(int a=0;a<n;a++) sum += vd.paz[a];
    v = 0.4*sum/n+0.6*vd.egz;
    return v;
}
void isvedimas(duom ats, int n){

        cout<<setw(20)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde"<<setw(40)<<left<<"Galutinis (Med.)/Galutinis (Vid.)"<<endl;
        cout<<string(80, '-')<<endl;
        cout<<setw(20)<<left<<ats.var<<setw(20)<<left<<ats.pav;

        if(ats.rez == "m"){ //spausdina mediana
            cout<<fixed<<setprecision(2)<<setw(20)<<left<<mediana(ats, n)<<"-"<<endl;
        }
        else if(ats.rez == "v"){ //spausdina vidurki
        cout<<fixed<<setprecision(2)<<setw(20)<<setw(20)<<left<<"-"<<vidurkis(ats,n)<<endl;
        }
        else{ //spausdina ir mediana ir vidurki
        cout<<fixed<<setprecision(2)<<setw(20)<<left<<mediana(ats,n);
        cout<<fixed<<setprecision(2)<<setw(20)<<left<<vidurkis(ats,n)<<endl;
        }
}
