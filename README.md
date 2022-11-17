# V1.0
* Atliekama dviejų strategijų spartos analizė.
* Anksčiau taikyta strategija: sukurti du naujus konteinerius - "minkšti" ir "kieti" ir juos pildyti duomenimis iš bendro studentų konteinerio.
* Nauja strategija: sukurti viena naują konteinerį - "minkšti". Jį pildyti šalinant elementus iš bendro studentų konteinerio.
* Sukurtos dvi naujos analogiškos funkcijos naujai strategijai panaudojant std::list ir std::vector tipo konteinerius.


![Ekrano nuotrauka 2022-11-17 131711](https://user-images.githubusercontent.com/114149330/202501637-f4b04208-b31f-4b41-b806-3a7b53975596.png)

* Pastebima, kad nauja strategija su std::vector užtrunka ilgai, todėl ji pakeičiama sukuriant naują funkciją, kurioje naudojama remove_if.
* Toliau tęsiama analizė naudojant pastarąją funkciją.

![Ekrano nuotrauka 2022-11-17 135630](https://user-images.githubusercontent.com/114149330/202502592-fc0f0a75-3e4c-4c70-a774-10966143999d.png)
![Ekrano nuotrauka 2022-11-17 174423](https://user-images.githubusercontent.com/114149330/202502604-98e36689-8fae-4f3e-b6f0-b9ac41263e1b.png)
![Ekrano nuotrauka 2022-11-17 174511](https://user-images.githubusercontent.com/114149330/202502615-1a1d524c-53b1-470c-8de0-1d4deae5c2f0.png)
![Ekrano nuotrauka 2022-11-17 145955](https://user-images.githubusercontent.com/114149330/202503237-d223a078-7f2c-4239-9532-d83759b2b60d.png)

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
