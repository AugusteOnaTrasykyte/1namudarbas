#include "mylib.h"

struct duom{
  string var;
  string pav;
  double paz[35];
  int egz;
  string rez;
  int ndkiekis;
};

void ivedimas(duom arr[], int n){
    for(int i=0; i<n; i++){
        cout<<"Iveskite studento varda: "; cin>>arr[i].var;
        cout<<"Iveskite studento pavarde: "; cin>>arr[i].pav;
        string rinktis;
        srand(time(0));  //kad kiekviena karta generuotu naujus duomenis
        cout<<"Jeigu norite irasyti egzamino bala, iveskite t, jei norite, kad balas butu atsitiktinis, iveskite n"<<endl;
            cin>>rinktis;
            if(rinktis=="t"){ //vartotojas iveda egz bala
                cout<<"Iveskite, kiek studentas gavo is egzamino: "; cin>>arr[i].egz;
            }else if (rinktis=="n"){ //kompiuteris generuoja egz bala
                arr[i].egz = (rand() % 10) + 1;
                cout<<arr[i].egz<<endl;
            }else{
                cout<<"padarete ivedimo klaida"<<endl;
            }

        string pasirinkti;
        int kiekis;
        arr[i].ndkiekis=0;
        cout << "Jeigu namu darbu pazymius ivedinesite ranka rasykite: t, jei norite, kad pazymius sugeneruotu kompiuteris, rasykite: n" << endl;
            cin >> pasirinkti;
            if(pasirinkti == "t"){ // balus veda vartotojas
                int *p = new int[30];
                if(!p)cout << "allocation of memory failed\n";
                else {
                    for(int a=0;a<30;a++){
                        cout<<"Iveskite "<<a+1<<" pazymi, jei daugiau pazymiu nera iveskite 0: ";
                        cin>>p[a];
                        if(p[a]==0)break;
                        else{
                             arr[i].paz[a]=p[a];
                             arr[i].ndkiekis++;
                        }
                    }
                }
            }else if (pasirinkti == "n"){ //balus generuoja kompiuteris
                srand(time(0));
                for( int i = 0; i < (rand() % 30); ++i ) { //parenkamas random kiekis(iki30) random balu
                    arr[i].paz[i]=((rand() % 10) + 1);
                    arr[i].ndkiekis+=1;
                }
            }
            else{
                cout<<"Padarete ivedimo klaida"<<endl;
            }

        cout<<"jei norite spausdinti vidurki, iveskite v, jei mediana - m, jei abu - bet koki kita simboli"<<endl;
        cin>>arr[i].rez;
    }
}
double mediana(duom arr){
    double m;
    sort(arr.paz,arr.paz+arr.ndkiekis);
    if(arr.ndkiekis%2!=0)m=arr.paz[(arr.ndkiekis-1)/2];
    else m = (arr.paz[arr.ndkiekis/2]+arr.paz[arr.ndkiekis/2-1])/2;
    return m;
}
double vidurkis(duom arr){
    double v;
    int sum = 0;
    for(int a=0;a<arr.ndkiekis;a++) sum += arr.paz[a];
    v = 0.4*sum/arr.ndkiekis+0.6*arr.egz;
    return v;
}
void isvedimas(duom arr[], int n ){

        cout<<setw(20)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde"<<setw(40)<<left<<"Galutinis (Med.)/Galutinis (Vid.)"<<endl;
        cout<<string(80, '-')<<endl;
        for(int i=0; i<n; i++){
            cout<<setw(20)<<left<<arr[i].var<<setw(20)<<left<<arr[i].pav;

            if(arr[i].rez == "m"){ //spausdina mediana
                cout<<fixed<<setprecision(2)<<setw(20)<<left<<mediana(arr[i])<<"-"<<endl;
            }
            else if(arr[i].rez == "v"){ //spausdina vidurki
            cout<<fixed<<setprecision(2)<<setw(20)<<setw(20)<<left<<"-"<<vidurkis(arr[i])<<endl;
            }
            else{ //spausdina ir mediana ir vidurki
            cout<<fixed<<setprecision(2)<<setw(20)<<left<<mediana(arr[i]);
            cout<<fixed<<setprecision(2)<<setw(20)<<left<<vidurkis(arr[i])<<endl;
            }
        }
}

int main()
{
    int n; // n studentu skaicius
    duom A[10];
    cout << "Iveskite studentu kieki: ";
    cin >> n;
    ivedimas(A, n);
    isvedimas(A, n);
    return 0;
}
