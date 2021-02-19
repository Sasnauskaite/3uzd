#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <stdio.h> 
#include <iomanip>
#include <vector>

using std::string;
using std::cout;
using std::cin;
using std::vector;

vector<int> nd;
vector<string> name, lastname;
const int maxGrades=15, maxStudents=10;
float vid[maxStudents],  med[maxStudents];
int sk, egz, nr=0, in;
string  line="-";


void student();
void print1() //isvedimas su vidurkiu
{
    string eil2, v="Vardas", p="Pavarde", g="Galutinis balas(vid)\n";
    for(int i=0; i<60; i++)
    {
        eil2+=line;
    }
    eil2+="\n";
    cout<<v<<std::setw(21)<<p<<std::setw(31)<<g<<std::setw(21)<<eil2;
    for(int i=0; i<nr; i++)
    {
        cout << name[i] <<std::setw(21)<< lastname[i] <<std::setw(21)<< std::setprecision(3) << vid[i]<<std::setw(21)<<"\n";
    }
}
void print2() //isvedimas su mediana
{
    string eil2, v="Vardas", p="Pavarde", g="Galutinis balas(med)\n";
    for(int i=0; i<60; i++)
    {
        eil2+=line;
    }
    eil2+="\n";
    cout<<v<<std::setw(21)<<p<<std::setw(31)<<g<<std::setw(21)<<eil2;
    for(int i=0; i<nr; i++)
    {
        cout << name[i] <<std::setw(21)<< lastname[i] <<std::setw(21)<< std::setprecision(3) << med[i]<<std::setw(21)<<"\n";
    }
}
void avg() //pazymio formule : 0.4 * nd vid + 0.6 * egz = galut. pazym.
{
    int num=0;
    for( int i=0; i<sk; i++)
    {
        num = num + nd[i];
    }
    vid[nr-1] = (0.4 * (static_cast<float>(num) / sk)) + (0.6 * egz);
}
void sort() //rikiuoja namu darbu balu masyva
{
    for (int i = 0; i < sk; i++)
    {
        for (int j = i + 1; j < sk; j++)
        {
            if (nd[i] > nd[j])
            {
                int t = nd[j];
                nd[j] = nd[i];
                nd[i] = t;
            }
        }
    }
}
void mediana() //apskaiciuoja galutini bala su mediana
{
    sort();
    int num = 0;
    int number1;

    if (sk % 2 != 0)
    {
        num = (sk / static_cast<float>(2));
        med[nr-1] = (0.4 * nd[num]) + (0.6 * egz);
    }
    else if (sk % 2 == 0)
    {
        num = sk / static_cast<float>(2);
        number1 = num - 1;
        med[nr-1] = ((static_cast<float>(nd[num]) + nd[number1]) / 2);
        med[nr-1] = (med[nr-1] * 0.4);
        med[nr-1] = med[nr-1] + (egz * 0.6);
    }
}
void addStud()//klausiama, ar norime prideti studenta
{
    cout<<"Ar norite prideti dar viena studenta? (t='taip'; n='ne')";
    string answer3;
    cin>>answer3;
    if (answer3 == "t" || answer3 == "T")
    {
        student();
    }
    else if (answer3 == "n" || answer3 == "N")
    {
    }
    else
    {
        cout << "Irasete neteisinga simboli. Pabandykite is naujo\n";
        addStud();
    }
}
void exam() //vartotojas iveda egzamino bala
{
    cout << "Irasykite is egzamino gauta bala: ";
    cin >> egz;
    if (egz < 0 || egz > 10)
    {
        cout << "Irasete netinkama bala, pabandykite is naujo\n";
        exam();
    }
    avg();
    mediana();
    addStud();
}
void examRandom() //sugeneruoja random egzamino bala
{
    srand(time(NULL));
    egz = rand() % 10 + 1;
    cout<<"Egzamino pazymys: " << egz <<"\n";
    avg();
    mediana();
    addStud();
}
void ASKexam()//klausia, ar norime ivesti egzamino rezultata
{
    cout<<"Ar norite ivesti egzamino rezultata? (T='taip'; N='ne')\n PASTABA: pasirinkus 'ne' egzamino rezultatas bus sugeneruotas atsitiktinai. ";
    string answer4;
    cin>>answer4;
    if (answer4 == "T" || answer4 =="t")
    {
        exam();
    } 
    else if (answer4 == "N" || answer4=="n")
    {
       examRandom();
    }
    else
    {
        cout << "Irasete neteisinga simboli. Pabandykite is naujo\n";
        ASKexam();
    }
}
void randomUnknown() //sugeneruoja random namu darbu balus, kai ju kiekis nezinomas
{
    srand(time(NULL));
    int num=1, i=0;
    sk=0;
    while(num!=0)
    {
        sk+=1;
        num = rand() % 10;
        nd.push_back(num);
        cout << num <<"\n";
        i++;
    }
    sk-=1;
    ASKexam();
}
void random() //sugeneruoja random namu darbu balus , kai ju kiekis zinomas
{
    srand(time(NULL));
    int num;
    for (int i = 0; i < sk; i++)
    {
        num = rand() % 10 + 1;
        nd.push_back(num);
        cout << num <<"\n";
    }
    ASKexam();
}
void homeworkUnknown() //vartotojas iveda namu darbu balus, kai ju kiekis nezinomas
{
    int i=0, enter=1;
    sk=0;
    while(enter != 0)
    {
        sk++;
        cout << "Irasykite " << i+1 << " namu darbo pazymi: ";
        cin >> enter;
        nd.push_back(enter);
        if (enter < 0 || enter > 10)
        {
            cout << "Irasete netinkama pazymi, pabandykite is naujo\n";
            homeworkUnknown();
        }
        i++;
    }
    sk-=1;
    ASKexam();
}
void homework() //vartotojas iveda namu darbu balus, kai ju kiekkis zinomas
{
    int a=0;
    while(a<sk)
    {
        cout << "Irasykite " << a+1 << " namu darbo pazymi: ";
        cin >> in;
        nd.push_back(in);
        if (in < 0 || in > 10)
        {
            cout << "Irasete netinkama pazymi, pabandykite is naujo\n";
            homework();
        }
        a++;
    }
    ASKexam();
}
void number() //vartotojas iraso kiek bus namu darbu balu
{
    cout << "Kiek bus pazymiu? (Ju gali buti iki "<< maxGrades<<") ";
    cin >> sk;
    if (sk < 0 || sk > 10)
    {
        cout << "Irasete neteisinga skaiciu, pabandykite is naujo\n";
        number ();
    } 
}
bool isKnown() //klausia, ar zinomas namu darbu pazymiu kiekis
{
    bool status;
    cout << "Ar zinote kiek yra namu darbu pazymiu?(t='taip'; n='ne')\n";
    string answer5;
    cin >> answer5;
    if (answer5 == "T" || answer5 =="t")
    {
        status=true;
    } 
    else if (answer5 == "N" || answer5=="n")
    {
       status=false;
    }
    return status;    
}
void grades() //vartotojas atsako i klausimus
{
    string answer2;
    cout << "Ar norite patys irasyti studento namu darbu pazymius? (t='taip'; n='ne')\nPASTABA: Pasirinkus 'ne' pazymiai bus sugeneruoti automatiskai ";
    cin >> answer2;
    if (answer2 == "t" || answer2 == "T")
    {
        if(isKnown())
        {
            number();
            homework();
        }
        else
        {
            homeworkUnknown();
        }
        
    }
    else if (answer2 == "n" || answer2 == "N")
    {
        if(isKnown())
        {
            number();
            random();
        }
        else
        {
            randomUnknown();
        }
    }
    else
    {
        cout << "Irasete neteisinga simboli. Pabandykite is naujo\n";
        grades();
    }
}
void student() //vartotojas iveda studento varda ir pavarde
{ 
    cout <<"Studento vardas: " ;
    string n, ln;
    cin >> n;
    name.push_back(n);
    cout <<"Studento pavarde: ";
    cin >> ln;
    lastname.push_back(ln);
    nr+=1;
    grades();
}
void question()
{
    cout << "Ar norite suzinoti vidurki?(t='taip'; n='ne')\nPASTABA: Pasirinkus 'ne' bus rodoma mediana ";
    string answer1;
    cin >> answer1;
    if (answer1 == "T" || answer1 =="t")
    {
        print1();
    } 
    else if (answer1 == "N" || answer1=="n")
    {
       print2();
    }
    else
    {
        cout << "Irasete neteisinga simboli. Pabandykite is naujo\n";
        question();
    }
}
int main()
{
    float average;
    
    student();
    question();
       
    return (0);
}