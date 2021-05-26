#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <ctime>
#include <random>
#include <algorithm>
#include <vector>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

struct Students 
{
    string name, lastname; // vardas, pavarde
    vector<int> nd; // Namu darbai
    int exam = 0;
};

const char file[] = "kursiokai.txt"; //Duomenu failo pavadinimas
const char outFile[] = "rez.txt"; //Rezultatu failo pavadinimas

void addStudent(vector<Students> &stud);
void read(vector<Students> &stud);
bool _check(Students &a, Students &b)
{
    return a.name < b.lastname;
}
void BubbleSort(vector<Students> &stud)
{
	for (int i = 0; i < stud.size(); i++)
	{
		for (int j = i + 1; j < stud.size(); j++)
		{
			if (stud[i].lastname > stud[j].lastname)
			{
				string a = stud[i].lastname;
				stud[i].lastname = stud[j].lastname;
				stud[j].lastname = a;
                string b = stud[i].name;
				stud[i].name = stud[j].name;
				stud[j].name = b;
                vector<int> c = stud[i].nd;
				stud[i].nd = stud[j].nd;
				stud[j].nd = c;
                int d = stud[i].exam;
				stud[i].exam = stud[j].exam;
				stud[j].exam = d;
			}
		}
	}
}
void print1(vector<Students> &stud) //isvedimas su vidurkiu
{
    std::ofstream out(outFile);
    string  line="-";
    string eil2, v="Vardas", p="Pavarde", g="Galutinis balas(vid)\n";
    for(int i=0; i<60; i++)
    {
        eil2+=line;
    }
    eil2+="\n";
    out<<std::left<<std::setw(20)<<p<<std::setw(20)<<v<<std::setw(10)<<g<<eil2;
    for(int i=0; i<stud.size(); i++)
    {
        double avg=0;
        for (int j = 0; j < stud[i].nd.size(); j++)
        {
            avg += stud[i].nd[j];
        }
	    avg /= stud[i].nd.size();
	    avg = 0.4 * avg + 0.6 * stud[i].exam;

        out<<std::setw(20)<<stud[i].lastname<<std::setw(20)<<stud[i].name<<std::setprecision(3)<<std::setw(15)<<avg<<"\n";
    }
    out.close();
}
void print2(vector<Students> &stud) //isvedimas su mediana
{
    std::ofstream out(outFile);
    string  line="-";
    string eil2, v="Vardas", p="Pavarde", g="Galutinis balas(med)\n";
    for(int i=0; i<60; i++)
    {
        eil2+=line;
    }
    eil2+="\n";
    out<<std::left<<std::setw(20)<<p<<std::setw(20)<<v<<std::setw(10)<<g<<eil2;
    for(int i=0; i<stud.size(); i++)
    {
        double med = 0;
	    if (stud[i].nd.size() % 2 == 1)
	    {
            med = stud[i].nd[stud[i].nd.size() / 2];
        }
	    else 
        {
            med = (stud[i].nd[stud[i].nd.size() / 2] + stud[i].nd[stud[i].nd.size() / 2 - 1]) / 2;
        }

        out<<std::setw(20)<<stud[i].lastname<<std::setw(20)<<stud[i].name<<std::setprecision(3)<<std::setw(15)<<med<<"\n";
    }
    out.close();
}
void checkInput(char& choice) 
{

	while (cin.fail() || tolower(choice) != 't' && tolower(choice) != 'n')
    {
		if (cin.fail())
        {
            cout << "Ivestis netinkama (Ivedete skaiciu)\n";
        }
		else if(tolower(choice) != 't' && tolower(choice) != 'n')
        {
            cout << "Neteisingas pasirinkimas! Galimi pasirinkimai: t (taip) arba n (ne)!\n";
        }
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Pakartokite ivedima (t/n): ";
		cin >> choice;
	}
}
void checkInput(int &input) {

	while (cin.fail() || input < 0 || input > 10)
    {
		if (cin.fail())
        {
            cout << "Ivestis netinkama (Ivedete raide)\n";
        }
		else if(input < 0)
        {
            cout << "Skaicius negali buti mazesnis uz 0!\n";
        }
        else if(input > 10)
        {
            cout << "Skaicius negali buti didesnis uz 10!\n";
        }
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Iveskite skaiciu is naujo: ";
		cin >> input;
	}
}
void random(int n, vector<int> &arr)
{
    srand(time(0));

    for(int i = 0; i < n; i++)
    {
        arr.push_back(rand() % 10 + 1);
    }
}
int main()
{
    char choice;
    vector<Students> stud;

    cout << "Ar norite duomenis irasyti patys (T) ar skaityti is failo (N)?\nJusu atsakymas: "; cin >> choice;
    checkInput(choice);

    if(tolower(choice) == 't')
    {
        cin.ignore();
        while(true)
        {

            addStudent(stud);

            cout << "Ar norite prideti dar 1 studenta? (t/n) \nJusu atsakymas: "; cin >> choice;
            cin.ignore();
            checkInput(choice);

            if(tolower(choice) == 'n')
            {
                break;
            }
            else if(tolower(choice) == 't')
            {
                continue;
            }
        }
    }
    else if(tolower(choice) == 'n')
    {
        read(stud);
    }
    cout << "Duomenu irasymas sekmingas." << '\n' << "Norite matyti vidurki? (t='taip'; n='ne') \nPASTABA: Pasirinkus 'ne' bus rodoma mediana \nJusu atsakymas: "; cin >> choice;
    checkInput(choice);

    BubbleSort(stud);
    if(tolower(choice) == 't')
    {
        print1(stud);    
    }
    else if (tolower(choice) == 'n')
    {
        print2(stud);
    }
    return 0;
}

void read(vector<Students> &stud)
{
    std::ifstream input(file);

    if(!input)
    {
        cout << "Nurodytas failas neegzistuoja!\n";
        exit(1);
    }

    Students student;

    string line;
    int val;
    vector<int> grades;

    input.ignore(255, '\n');

    while(true)
    {
        input >> student.name >> student.lastname;
        getline(input, line);
        std::istringstream str(line);

        int val;
        while(str >> val)
        {
            grades.push_back(val);
        }

        grades.pop_back();
        student.exam = val;
        student.nd = grades;

        stud.push_back(student);
        grades.clear();

        if(input.eof())
        {
            break;
        }
    }

    input.close();

}

void addStudent(vector<Students> &stud) 
{

    srand(time(0));

    Students student;
    int gr;
    int n = 0; // n yra kaip iterator toje dalyje, kai yra nezinomas pazymiu kiekis
    vector<int> hw;
    char choice;

    cout << "Iveskite studento varda: ";
    getline(cin, student.name);
    
    cout << "Iveskite studento pavarde: ";
    getline(cin, student.lastname);

    cout << "Ar yra zinomas namu darbu pazymiu skaicius? (t/n) \nJusu atsakymas: ";
    cin >> choice;
    checkInput(choice);

    if(tolower(choice) == 't')
    {
        cout << "Iveskite namu darbu pazymiu kieki: "; cin >> n;
        checkInput(n);

        cout << "Ar norite patys ivesti pazymius uz namu darbus? (t/n) \nJusu atsakymas: "; cin >> choice; cout << '\n';
        checkInput(choice);

        if(tolower(choice) == 't')
        {
            for(int i = 0; i < n; i++)
            {
                cout << "Iveskite " << i + 1 << "-a pazymi: ";
                cin >> gr;
                checkInput(gr);
                hw.push_back(gr);
            }
        }
        else if(tolower(choice) == 'n')
        {
            random(n, hw);
        }

    }
    else if(tolower(choice) == 'n')
    {
        cout << "Ar norite patys ivesti pazymius uz namu darbus? (t/n) \nJusu atsakymas: "; cin >> choice; cout << '\n';

        if(tolower(choice) == 't')
        {
            cout << "Noredami baigti pazymiu ivedima, iveskite 0\n";
            while(true)
            {
                cout << "Iveskite " << n + 1 << "-a pazymi: "; cin >> gr;
                checkInput(gr);

                if(gr == 0)
                {
                    break;
                }
                else 
                {
                    n++;
                    hw.push_back(gr);
                }
            }
        }
        else if(tolower(choice) == 'n')
        {
            n = rand() % 11;
            if(n != 0) 
            {
                random(n, hw);
            }
        }
    }

    cout << "Ar norite patys ivesti egzamino vertinima? (t/n) \nJusu atsakymas: "; cin >> choice; cout<< '\n';
    checkInput(choice);

    if(tolower(choice) == 't')
    {
        cout << "Irasykite egzamino vertinima: \nJusu irasytas balas: "; cin >> student.exam;
        checkInput(student.exam);
    }
    else if(tolower(choice) == 'n')
    {
        student.exam = rand() % 10 + 1;
        cout << "Sugeneruotas egzamino vertinimas: " << student.exam << '\n';
    }

    student.nd = hw;

    stud.push_back(student);
}