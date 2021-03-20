#include "func2.h"

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
void average(vector<Students> &stud)
{
    Students student;
    for(int i=0; i<stud.size(); i++)
    {
        double av=0;
        for (int j = 0; j < stud[i].nd.size(); j++)
        {
            av += stud[i].nd[j];
        }
	    av /= stud[i].nd.size();
	    av = 0.4 * av + 0.6 * stud[i].exam;
        student.avg = av;
    }
}
void mediana(vector<Students> &stud)
{
    Students student;
    for(int i=0; i<stud.size(); i++)
    {
        double md = 0;
	    if (stud[i].nd.size() % 2 == 1)
	    {
            md = stud[i].nd[stud[i].nd.size() / 2];
        }
	    else 
        {
            md = (stud[i].nd[stud[i].nd.size() / 2] + stud[i].nd[stud[i].nd.size() / 2 - 1]) / 2;
        }
        student.med = md;
    }
}
void print1happy(vector<Students> &stud, int pep) //isvedimas su vidurkiu
{
    string outF;
    if(pep==1)
    {
        outF = "moklinciai.txt";
    }
    else
    {
        outF = "mokslinciai"+std::to_string(pep)+".txt";
    }
    std::ofstream out(outF);
    Happy h;
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
        out<<std::setw(20)<<h.lastname<<std::setw(20)<<h.name<<std::setprecision(3)<<std::setw(15)<<h.avg<<"\n";
    }
    out.close();
}
void print1sad(vector<Students> &stud, int pep) //isvedimas su vidurkiu
{
    string outF;
    if(pep==1)
    {
        outF = "nuskriaustieji.txt";
    }
    else
    {
        outF = "nuskriaustieji"+std::to_string(pep)+".txt";
    }
    std::ofstream out(outF);
    Sad s;
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
        out<<std::setw(20)<<s.lastname<<std::setw(20)<<s.name<<std::setprecision(3)<<std::setw(15)<<s.avg<<"\n";
    }
    out.close();
}
void print2happy(vector<Students> &stud, int pep) //isvedimas su mediana
{
    string outF;
    if(pep==1)
    {
        outF = "moklinciai.txt";
    }
    else
    {
        outF = "mokslinciai"+std::to_string(pep)+".txt";
    }
    std::ofstream out(outF);
    Happy h;
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
        out<<std::setw(20)<<h.lastname<<std::setw(20)<<h.name<<std::setprecision(3)<<std::setw(15)<<h.med<<"\n";
    }
    out.close();
}
void print2sad(vector<Students> &stud, int pep) //isvedimas su mediana
{
    string outF;
    if(pep==1)
    {
        outF = "nuskriaustieji.txt";
    }
    else
    {
        outF = "nuskriaustieji"+std::to_string(pep)+".txt";
    }
    std::ofstream out(outF);
    Sad s;
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
        out<<std::setw(20)<<s.lastname<<std::setw(20)<<s.name<<std::setprecision(3)<<std::setw(15)<<s.med<<"\n";
    }
    out.close();
}
void separateAvg(vector<Students> &stud)
{
    //turi skaiciuot atskyrimo laika
    int j=0, ii=0;
    Happy h;
    Sad s;
    for(int i=0; i<stud.size(); i++)
    {
        if(stud[i].avg >= 5)
        {
            h.name=stud[i].name;
            h.lastname=stud[i].lastname;
            h.avg=stud[i].avg;
            h.med=stud[i].med;
            j++;
        }
        else if(stud[i].avg < 5)
        {
            s.name=stud[i].name;
            s.lastname=stud[i].lastname;
            s.avg=stud[i].avg;
            s.med=stud[i].med;
            ii++;
        }
    }
    cout<<"Viso yra "<<j<<" mokslinciu ir "<<ii<<" nuskriaustuku.\n";
}
void separateMed(vector<Students> &stud)
{
    //turi skaiciuot atskyrimo laika
    int j=0, ii=0;
    Happy h;
    Sad s;
    for(int i=0; i<stud.size(); i++)
    {
        if(stud[i].med >= 5)
        {
            h.name=stud[i].name;
            h.lastname=stud[i].lastname;
            h.avg=stud[i].avg;
            h.med=stud[i].med;
            j++;
        }
        else if(stud[i].med < 5)
        {
            s.name=stud[i].name;
            s.lastname=stud[i].lastname;
            s.avg=stud[i].avg;
            s.med=stud[i].med;
            ii++;
        }
    }
    cout<<"Viso yra "<<j<<" mokslinciu ir "<<ii<<" nuskriaustuku.\n";
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
void checkFile1(int &input)
{
    while (cin.fail() || input < 1)
    {
		if (cin.fail())
        {
            cout << "Ivestis netinkama (Ivedete raide)\n";
        }
		else if(input < 1)
        {
            cout << "Skaicius negali buti mazesnis uz 1!\n";
        }
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Iveskite skaiciu is naujo: ";
		cin >> input;
	}
}
void checkFile2(int &input)
{
    while (cin.fail() || input < 1 || input > 15)
    {
		if (cin.fail())
        {
            cout << "Ivestis netinkama (Ivedete raide)\n";
        }
		else if(input < 1)
        {
            cout << "Skaicius negali buti mazesnis uz 1!\n";
        }
        else if(input > 15)
        {
            cout << "Skaicius negali buti didesnis uz 15!\n";
        }
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Iveskite skaiciu is naujo: ";
		cin >> input;
	}
}
void checkNum(int &input)
{
    while (cin.fail() || input < 1 || input > 5)
    {
		if (cin.fail())
        {
            cout << "Ivestis netinkama (Ivedete raide)\n";
        }
		else if(input < 1)
        {
            cout << "Skaicius negali buti mazesnis uz 1!\n";
        }
        else if(input > 5)
        {
            cout << "Skaicius negali buti didesnis uz 5!\n";
        }
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Iveskite skaiciu is naujo: ";
		cin >> input;
	}
}
void createFile(int f, int marks)
{
    string creation;
    creation = std::to_string(f) + ".txt";
    std::ofstream out(creation);
    string  line="-";
    string eil2, v="Vardas", p="Pavarde", n="ND", e="EGZ.";
    int linesize=45+(5*marks);
    for(int i=0; i<linesize; i++)
    {
        eil2+=line;
    }
    eil2+="\n";
    out<<std::left<<std::setw(20)<<v<<std::setw(20)<<p;
    for(int i=0; i<marks; i++)
    {
        out<<std::setw(5)<<n+std::to_string(i);
    }
    out<<std::setw(5)<<e<<endl;
    out<<std::left<<eil2;
    srand(time(0));
    for(int i=0; i<f; i++)
    {
        out<<std::left<<std::setw(20)<<v+std::to_string(i)<<std::setw(20)<<p+std::to_string(i);
        for(int j=0; j<marks; j++)
        {
            out<<std::setw(5)<<rand() % 10 + 1;
        }
        out<<std::setw(5)<<rand() % 10 + 1<<"\n";
    }
    out.close();
}
void random(int n, vector<int> &arr)
{
    srand(time(0));

    for(int i = 0; i < n; i++)
    {
        arr.push_back(rand() % 10 + 1);
    }
}
void read1(vector<Students> &stud)
{
    try
    {
        std::ifstream in (fileInt);

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
void read2(vector<Students> &stud, int pep)
{
        std::ifstream input;
    string fileName;
    string type=".txt";
    fileName = pep + ".txt";

    Students student;

    string line;
    int val;
    vector<int> grades;
    try
    {
        input.open("/Users/Evelina/Desktop/Studijos 2semestras/Objektinis programavimas/2uzd" + fileName);
        if(!input)
        {
            throw 1;
        }
        if(input.eof())
        {
            throw 2;
        }
	    input.ignore(256, '\n');

        while(!input.eof())
        {
            input >> student.name >> student.lastname;
            getline(input, line);
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
        }
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
void questions1(vector<Students> &stud, int pep)
{
    char choice;
    cout << "Norite matyti vidurki? (t='taip'; n='ne') \nPASTABA: Pasirinkus 'ne' bus rodoma mediana \nJusu atsakymas: "; 
    cin >> choice;
    checkInput(choice);
    
    BubbleSort(stud);
    if(tolower(choice) == 't')
    {
        auto start = std::chrono::steady_clock::now();
        separateAvg(stud); 
        cout<<"Isskirstymas truko: "<<std::setprecision(3)
        <<std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count()<<"ms\n"; 

        start = std::chrono::steady_clock::now();
        print1happy(stud, pep);
        print1sad(stud, pep);
        cout<<"Atsakymu isvedimas truko: "<<std::setprecision(3)
        <<std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count()<<"ms\n";
        
    }
    else if (tolower(choice) == 'n')
    {
        auto start = std::chrono::steady_clock::now();
        separateMed(stud); 
        cout<<"Isskirstymas truko: "<<std::setprecision(3)
        <<std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count()<<"ms\n"; 

        start = std::chrono::steady_clock::now();
        print2happy(stud, pep);
        print2sad(stud, pep);
        cout<<"Atsakymu isvedimas truko: "<<std::setprecision(3)
        <<std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count()<<"ms\n";
    }

}
void questions2(vector<Students> &stud, int pep)
{
    char choice;
    cout << "Norite matyti vidurki? (t='taip'; n='ne') \nPASTABA: Pasirinkus 'ne' bus rodoma mediana \nJusu atsakymas: "; 
    cin >> choice;
    checkInput(choice);
    
    BubbleSort(stud);
    if(tolower(choice) == 't')
    {
        auto start = std::chrono::steady_clock::now();
        separateAvg(stud); 
        cout<<"Isskirstymas truko: "<<std::setprecision(3)
        <<std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count()<<"ms\n";

        start = std::chrono::steady_clock::now();
        print1happy(stud, pep);
        print1sad(stud, pep);
        cout<<"Atsakymu isvedimas truko: "<<std::setprecision(3)
        <<std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count()<<"ms\n";
    }
    else if (tolower(choice) == 'n')
    {
        auto start = std::chrono::steady_clock::now();
        separateMed(stud);
        cout<<"Isskirstymas truko: "<<std::setprecision(3)
        <<std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count()<<"ms\n";
        
        start = std::chrono::steady_clock::now();
        print2happy(stud, pep);
        print2sad(stud, pep);
        cout<<"Atsakymu isvedimas truko: "<<std::setprecision(3)
        <<std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count()<<"ms\n";
    }
}