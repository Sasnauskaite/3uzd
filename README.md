# 2UŽDUOTIS

# V0.1 skirta 2021.02.20

Programa klausia studentų vardų ir pavardžių, pažymių už namų darbus ir už egzaminą bei išveda studento vardą, pavardę ir galutinį pažymį (vidurkį arba medianą) į ekraną. Programa leodžia vartotojui įvesti pažymius pačiam arba juos sugeneruoja, ji taip pat veikia kai pažymių už namų darbus skaičius nėra žinomas. (main.cpp yra versija su masyvais, o vector.cpp yra versija su vektoriais.)

# V0.2 skirta 2021.03.06

Tai yra v0.1 papildymas. Nuo šios versijos programa (vartotojui pasirinkus) gali skaityti duomenis iš *(pavadinimas)*.txt failo (jo pavadinimą reikia įrašyti 25 kodo eilutėje). Programa taip pat išrikiuoja studentus pagal jų pavardes.

# Paleidimo instrukcija
Programą geriausia pasileisti terminale (aš naudoju visual studio code) su šiomis komandomis:

pirma sukompiliuoti naudojant komandą: 

`g++ main.cpp -o test` (masyvų versijai) arba `g++ vector.cpp -o test` (vektorių versijai)

po to paleisti su komanda: `./test`

Tada programa pradeda veikti ir jums belieka atsakyti į jos užduodamus klausimus (atsakyti reikia t="taip" arba n="ne).
