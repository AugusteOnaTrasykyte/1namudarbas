# V0.4
* Sukuriamos analogiškos funkcijos naudojant konteinerį std::list.
* Atliekama spartos analizė lyginant programos veikimą su std::vector ir std::list.
* Vartotojas gali rinktis ar naudoti anksčiau sukurtus failus, ar generuoti naujus.

Testavimo sistemos parametrai:
CPU: AMD Ryzen 7 4700U with Radeon Graphics 2.00 GHz,
RAM: 8GB,
SSD: 475GB


Programos testavimas panaudojant anksčiau sukurtus studentai----.txt failus:
![Ekrano nuotrauka 2022-11-04 091810](https://user-images.githubusercontent.com/114149330/199920274-0e12866b-e8f0-42e0-8d45-c1018bd6876a.png)
![Ekrano nuotrauka 2022-11-03 153453](https://user-images.githubusercontent.com/114149330/199736459-6bf2b4b5-a52d-4f01-8d45-5d9ecf78b484.png)

# V0.3
* Vartotojas gali rinktis įvesti duomenis ranka, nuskaityti iš turimo failo arba sugeneruoti naują failą.
* Spartos analizei atlikti sugeneruoti 5 failai su studentų kiekiu: 1 000, ..., 10 000 000.
* Studentai dalinami į dvi kategorijas: "minkšti", "kieti", pagal jų galutinius balus (t.y. > ar < už penkis).
* Rezultatai išvedami į du surušiuotus failus.
* Atliekama programos spartos analizė.

1000:
Failo sukūrimas užtruko:  0.039134s;
Failo nuskaitymas užtruko:  0.0410825s;
Skirstymas į "kietus" ir "minkštus" užtruko:  0.0086524s;
Išvedimas į du failus užtruko:  0.0220889s;

10 000:
Failo sukūrimas užtruko: 0.041964s;
Failo nuskaitymas užtruko: 0.399317s;
Skirstymas į "kietus" ir "minkštus" užtruko: 0.0963973s;
Išvedimas į du failus užtruko: 0.199172s;

100 000:
Failo sukūrimas užtruko: 3.9284s;
Failo nuskaitymas užtruko: 4.05601s;
Skirstymas į "kietus" ir "minkštus" užtruko: 0.903951s;
Išvedimas į du failus užtruko: 1.96094s;

1 000 000:
Failo sukūrimas užtruko: 38.0462s;
Failo nuskaitymas užtruko: 39.7492s;
Skirstymas į "kietus" ir "minkštus" užtruko: 10.0476s;
Išvedimas į du failus užtruko: 19.6593s;


10 000 000:
Failo sukūrimas užtruko: 384.926s (~6min);
Failo nuskaitymas užtruko: 450.898s (~8min);
Skirstymas į "kietus" ir "minkštus" užtruko: 146.749s (~2min);
Išvedimas į du failus užtruko: 204.127s (~3min);
# V0.2
* Vartotojas gali pasirinkti duomenis įvesti ranka arba nuskaityti iš failo.
* Išvedamas rezultatas surušiuojamas pagal vardą.
* Rezultatas išvedamas į naują failą.
# V0.1
* Vartotojas parašo, kiek studentų duomenų norės įvesti.
* Vartotojas įveda vardą, pavardę, namų darbų balus ir egzamino balą (n. d. kiekis pasirenkamas iš anksto arba ne).
* Ekrane išvedami studentų galutiniai pažymiai pagal vidurkį arba mediana pasirinktinai.
