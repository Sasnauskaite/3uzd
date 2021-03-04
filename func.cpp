#include "func.h"

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
    try
    {
        std::ofstream out(outFile);

        if(!out){
            throw 1;
        }

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
    catch(std::exception e){
        cout << "Failu sistemos klaida\n";
    }  
}
void print2(vector<Students> &stud) //isvedimas su mediana
{
    try
    { 
        std::ofstream out(outFile);

        if(!out){
            throw 1;
        }

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
    catch(const std::exception& e)
    {
        cout << "Failu sistemos klaida\n";
    }
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

void read(vector<Students> &stud)
{
    try
    {
        std::ifstream in(file);

        if(!in)
        {
            throw 1;
        }

        if(in.eof())
        {
            throw 4;
        }

        Students student;

        string line;
        int val;
        vector<int> grades;

        in.ignore(255, '\n');

        while(true)
        {
            in >> student.name >> student.lastname;
            getline(in, line);
            std::istringstream str(line);

            if(!str)
            {
                throw 2;
            }

            int val;
            while(str >> val)
            {
                if(val < 1 || val > 10)
                {
                    throw 3;
                }
                grades.push_back(val);
            }

            grades.pop_back();
            student.exam = val;
            student.nd = grades;

            stud.push_back(student);
            grades.clear();

            if(in.eof())
            {
                break;
            }
        }
        in.close();
    }
    catch(int e) 
    {
        switch (e)
        {
        case 1:
            cout << "Nepavyko atidaryti failo" << endl;
            break;
        case 2:
            cout << "Neteisingas failo formatas" << endl;
            break;
        case 3:
            cout << "Pazymys nepriklauso intervalui [1, 10]" << endl;
            break;
        case 4:
            cout << "Failas tuscias" << endl;
            break;
        
        default:
            cout << "Programos klaida" << endl;
            break;
        }

        cout << "Programa baigia darba ";
        exit(1);

    }
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