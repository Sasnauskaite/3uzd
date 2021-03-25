#include "func2.h"

void questions()
{
	int answer1;
	int kint = 0;
	cout << "Ar norite:\n(1)Duomenis irasyti patys\n(2)Duomenis skaityti is failo\n(3)Sukurti nauja duomenu faila?\nJusu atsakymas: "; 
    cin >> answer1;
    checkInput1(answer1);
	if (answer1 == 1)
	{
		UnknownStud();
		BubbleSort();
		PrintRez();
	}
	else if (answer1 == 2)
	{
		ReadFromFile();
		BubbleSort();
		PrintRez();
	}
	else if (answer1 == 3)
	{
		cout << "Kiek failu norite sugeneruoti? (nuo 1 iki 5): ";
		cin >> kint;
		for (int i = 0; i < kint; i++)
		{
	        cout << "Iveskite kiek bus studentu: ";
	        cin >> n;
			checkInput3(n);
	        cout << "Iveskite kiek bus namu darbu pazymiu[nuo 1 iki 15]: ";
	        cin >> sk;
			checkInput4(sk);
			char ats;
			cout<< "Ar noretumete pamatyti vidurki(t) ar mediana(n)?\nJusu atsakymas: ";
			cin>>ats;
			checkInput(ats);
			cout<<"Apdorojama "<<n<< " duomenu: "<<endl;
	        auto start = std::chrono::steady_clock::now();
			CreateFile();
			cout << "Naujo failo sugeneravimas truko:" << std::setprecision(4)<<
			std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count() << " ms" << endl;
			start = std::chrono::steady_clock::now();
			ReadFromFile();
			cout << "Sugeneruoto failo skaitymas truko:" << std::setprecision(4)<<
			std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count() << " ms" << endl;
			cout<<"Skaiciavimai..."<<endl;
			BubbleSort();
			start = std::chrono::steady_clock::now();
			Separate(n);
			cout << "Studentu isrusiavimas truko:" << std::setprecision(4)<<
			std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count() << " ms" << endl;
			if(tolower(ats)=='t')
			{
				start = std::chrono::steady_clock::now();
			    PrintBothAvg();
			    cout << "Studentu atspausdinimas truko:" << std::setprecision(4)<<
			    std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count() << " ms" << endl;
			}
			else if(tolower(ats)=='n')
			{
				start = std::chrono::steady_clock::now();
			    PrintBothMed();
			    cout << "Studentu atspausdinimas truko:" << std::setprecision(4)<<
			    std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count() << " ms" << endl;
			}
			
		}
	}
}
void Separate(int n)
{
	for(int i=0; i<n; i++)
	{
		if(S[i].avg>=5)
		{
			S[i].skolaAvg = 0;
		}
		else if(S[i].avg<5)
		{
			S[i].skolaAvg = 1;
		}
		if(S[i].med>=5)
		{
			S[i].skolaMed = 0;
		}
		else if(S[i].med<5)
		{
			S[i].skolaMed = 1;
		}
	}
}
void PrintRez()
{
	std::ofstream fr(outFile);
	fr <<std::setw(20) << v << std::setw(20) << p << std::setw(15) << vidd << std::setw(15) <<
	medd << endl;
	for(int i=0; i<70; i++)
	{
		fr << line;
	}
	fr << endl;
	for (int i = 0; i < n; i++)
	{
		fr <<std::setw(20) << S[i].name << std::setw(20) << S[i].lastname << std::setw(20) << std::setprecision(3) << S[i].avg << 
		std::setw(20) << std::setprecision(3) << S[i].med << endl;
	}
	fr.close();
}
void PrintBothAvg()
{
	std::ofstream out1("Galvotukai.txt");
	std::ofstream out2("Vargsiukai.txt");
	out1 << std::left<<std::setw(20) << v << std::setw(20) << p << std::setw(20) << vidd << endl;
	for(int i=0; i<70; i++)
	{
	    out1 << line;
	}
	out1 << endl;
	out2 << std::left<<std::setw(20) << v << std::setw(20) << p << std::setw(20) << vidd << endl;
	for(int i=0; i<70; i++)
	{
	    out2 << line;
	}
	out2 << endl;
	for (int i = 0; i < n; i++)
	{
		if (S[i].skolaAvg == 0)
		{
            out1 <<std::left<<std::setw(20) << S[i].name << std::setw(20) << S[i].lastname << std::setw(20) << std::setprecision(3) <<
			S[i].avg << endl;
		}
		else if (S[i].skolaAvg == 1)
		{
			out2 <<std::left<< std::setw(20) <<S[i].name << std::setw(20) << S[i].lastname << std::setw(20) << std::setprecision(3) << 
			S[i].avg << endl;
		}
	}
	out1.close();
	out2.close();
}
void PrintBothMed()
{
	std::ofstream out1("Galvotukai.txt");
	std::ofstream out2("Vargsiukai.txt");
	out1 <<std::left<< std::setw(20) << v << std::setw(20) << p << std::setw(20) << medd << endl;
	for(int i=0; i<70; i++)
	{
	    out1 << line;
	}
	out1 << endl;
	out2 <<std::left<< std::setw(20) << v << std::setw(20) << p << std::setw(20) << medd << endl;
	for(int i=0; i<70; i++)
	{
	    out2 << line;
	}
	out2 << endl;
	for (int i = 0; i < n; i++)
	{
		if (S[i].skolaMed == 0)
		{
            out1 <<std::left<<std::setw(20) << S[i].name << std::setw(20) << S[i].lastname << std::setw(20) << std::setprecision(3) <<
			S[i].med << endl;
		}
		else if (S[i].skolaMed == 1)
		{
			out2 <<std::left<< std::setw(20) <<S[i].name << std::setw(20) << S[i].lastname << std::setw(20) << std::setprecision(3) << 
			S[i].med << endl;
		}
	}
	out1.close();
	out2.close();
}
void UnknownStud()
{
	string input1, input2, answer3, answer4, answer5, answer6;
	int number3 = 0;
	cout << "iveskite studento varda: ";
	cin >> input1;
	cout << "iveskite studento pavarde: ";
	cin >> input2;
	S.push_back(Studentas());
	S[n].name = input1;
	S[n].lastname = input2;
	cout << "Ar norite patys ivesti namu darbu pazymius? (t/n): ";
	cin >> answer3;
	if (answer3 == yes)
	{
		cout << "Ar zinote kiek bus namu darbu pazymiu? (t/n): ";
		cin >> answer4;
		if (answer4 == yes)
		{
			KnowND(n);
		}
		else if (answer4 == no)
		{
			UnknownND(n);
		}
	}
	else if (answer3 == no)
	{
		cout << "Iveskite kiek bus namu darbu pazymiu: ";
		cin >> sk;
		srand(time(NULL));
		int number6;
		pazymiai.clear();
		suma = 0;
		for (int ii = 0; ii < sk; ii++)
		{
			number6 = rand() % 10 + 1;
			suma = suma + number6;
			pazymiai.push_back(number6);
		}
		cout << "Ar norite patys ivesti egzamino bala? (t/n): ";
		cin >> answer5;
		if (answer5 == yes)
		{
			cout << "Iveskite egzamino bala: ";
			cin >> egz;
			if (check(egz) == false)
			{
				cout << "Ivedete netinkama skaiciu, iveskite studento informacija is naujo" << endl;
				UnknownStud();
			}
		}
		else if (answer5 == no)
		{
			srand(time(NULL));
			number3 = rand() % 10 + 1;
			egz = number3;
		}
		S[n].avg = average();
		S[n].med = mediana();
	}
	n++;
	cout << "Ar norite prideti dar viena studenta? (t/n): ";
	cin >> answer6;
	if (answer6 == yes)
	{
		UnknownStud();
	}
}
void KnowND(int a)
{
	char answer5;
	cout << "Iveskite kiek bus namu darbu pazymiu: ";
	cin >> sk;
	int input3;
	cout << "Iveskite " << sk << " skacius: ";
	pazymiai.clear();
	suma = 0;
	for (int i = 0; i < sk; i++)
	{
		cin >> input3;
		while(check(input3) == false)
		{
			cout << "Ivedete netinkama skaiciu, iveskite studento informacija is naujo" << endl;
			cin>> input3;
		}
		suma += input3;
		pazymiai.push_back(input3);
	}
	cout << "Ar norite patys ivesti egzamino bala? (t/n): ";
	cin >> answer5;
	if (tolower(answer5) == 't')
	{
		cout << "Iveskite egzamino bala: ";
		cin >> egz;
		while(check(egz) == false)
		{
			cout << "Ivedete netinkama skaiciu, iveskite studento informacija is naujo" << endl;
			cin >>egz;
		}
	}
	else if (tolower(answer5) == 'n')
	{
		srand(time(NULL));
		egz = rand() % 10 + 1;
	}
	S[a].avg = average();
	S[a].med = mediana();
}
void UnknownND(int a)
{
	char answer5;
	cout << "Veskite kiek norite namu darbu pazymiu, kai noresite baigti vesti, iveskite '00': ";
	int enter = 1;
	int i = 0;
	pazymiai.clear();
	suma = 0;
	while (enter != 00)
	{
	    cin >> enter;
		while (check(enter) == false)
		{
	    	cout << "Ivedete netinkama skaiciu, iveskite studento informacija is naujo" << endl;
			cin>>enter;
		}
		suma = suma + enter;
		pazymiai.push_back(enter);
		i++;
	}
	cout << "Ar norite patys ivesti egzamino bala? (t/n): ";
	cin >> answer5;
	if (tolower(answer5) == 't')
	{
		cout << "Iveskite egzamino bala: ";
		cin >> egz;
		while(check(egz) == false)
		{
			cout << "Ivedete netinkama skaiciu, iveskite studento informacija is naujo" << endl;
			cin>>egz;
		}
	}
	else if (tolower(answer5) == 'n')
	{
		srand(time(NULL));
		egz = rand() % 10 + 1;
	}
	sk = i - 1;
	S[a].avg = average();
	S[a].med = mediana();
}
void ReadFromFile()
{
	std::ifstream in(FileName);
	string x;
	int y;
	try {
		if (!in)
		{
			throw 1;
		}
		for (int i = 0; i < 100; i++)
		{
			in >> x;
			if (x == "Egz.")
			{
				sk = i - 2;
				break;
			}
		}
		for (int i = 0; !in.eof(); i++)
		{
			suma = 0;
			S.push_back(Studentas());
			in >> S[i].name;
			in >> S[i].lastname;
			pazymiai.clear();
			for (int j = 0; j < sk; j++)
			{
				in >> y;
				suma = suma + y;
				pazymiai.push_back(y);
			}
			in >> egz;
			S[i].avg = average();
			S[i].med = mediana();
			n = i;
		}
		n = n + 1;
		in.close();
	}
	catch (int ex3)
	{
		cout << "Duomenu failas nerastas" << endl;
		exit;
	}
}
bool check(double number)
{
	if (number > 0 && number <= 10)
		return true;
	if (number <= -1 || number > 10)
		return false;
}
double average()
{
	double vid = ((suma / sk) * 0.4) + (egz * 0.6);
	return vid;
}
double mediana()
{
	for (int i = 0; i < sk; i++)
	{
		for (int j = i + 1; j < sk; j++)
		{
			if (pazymiai[i] > pazymiai[j])
			{
				double t = pazymiai[i];
				pazymiai[i] = pazymiai[j];
				pazymiai[j] = t;
			}
		}
	}
	double med = 0;

	if (pazymiai.size() % 2 != 0)
	{
		med = (pazymiai.at(pazymiai.size() / 2) * 0.4) + (egz * 0.6);

	}
	else if (pazymiai.size() % 2 == 0)
	{
		med = (((pazymiai.at(pazymiai.size() / 2) + pazymiai.at((pazymiai.size() / 2) - 1)) / 2) * 0.4) + (egz * 0.6);
	}
	return med;
}
void CreateFile()
{
	string file;
	file = "kursiokai" + std::to_string(n);
	file += ".txt";
	FileName = file;
	std::ofstream out(file);
	out << std::left << std::setw(20) << v << std::setw(20) << p;
	for (int i = 1; i < sk + 1; i++)
	{
		out << std::setw(7) << nd + std::to_string(i);
	}
	out << std::setw(7) << e << endl;
	srand(time(NULL));
	for (int i = 1; i < n + 1; i++)
	{
		out << std::left << std::setw(20) << v + std::to_string(i) << std::setw(20) << p + std::to_string(i);
		for (int j = 0; j < sk; j++)
		{
			out << std::setw(7) << rand() % 10 + 1;
		}
		out << std::setw(7) << rand() % 10 + 1 << endl;
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
void checkInput1(int choice)
{
    while (cin.fail() || choice < 1 || choice > 3)
    {
		if (cin.fail())
        {
            cout << "Ivestis netinkama (Ivedete raide)\n";
            cout <<"Galimi pasirinkimai:\n(1)Irasysiu pats\n(2)skaityti is failo\n(3)Sugeneruoti nauja duomenu faila\nJusu atsakymas: ";
        }
        else if(choice < 1 || choice > 3)
        {
            cout << "Turite pasirinkti is intervalo [1;3]\n";
            cout <<"Galimi pasirinkimai:\n(1)Irasysiu pats\n(2)skaityti is failo\n(3)Sugeneruoti nauja duomenu faila\nJusu atsakymas: ";
        }
		cout << "Iveskite savo pasirinkima: ";
		cin >> choice;
	}
}
void checkInput2(int choice)
{
    while (cin.fail() || choice < 1 || choice > 5)
    {
		if (cin.fail())
        {
            cout << "Ivestis netinkama (Ivedete raide)\n";
        }
        else if(choice < 1)
        {
            cout << "Skaicius negali buti mazesnis uz 1!\nTurite pasirinkti is intervalo [1;5]\n";
        }
        else if(choice > 5)
        {
            cout << "Skaicius negali buti didesnis uz 5!\nTurite pasirinkti is intervalo [1;5]\n";
        }
		cout << "Iveskite savo pasirinkima: ";
		cin >> choice;
	}
}
void checkInput3(int choice)
{
    while (cin.fail())
    {
		if (cin.fail())
        {
            cout << "Ivestis netinkama (Ivedete raide)\n";
        }
        else
        {
            continue;
        }
		cout << "Iveskite savo pasirinkima: ";
		cin >> choice;
	}
}
void checkInput4(int choice)
{
    while (cin.fail() || choice < 1 || choice > 15)
    {
		if (cin.fail())
        {
            cout << "Ivestis netinkama (Ivedete raide)\n";
        }
        else if(choice < 1)
        {
            cout << "Skaicius negali buti mazesnis uz 1!\nTurite pasirinkti is intervalo [1;15]\n";
        }
        else if(choice > 15)
        {
            cout << "Skaicius negali buti didesnis uz 15!\nTurite pasirinkti is intervalo [1;15]\n";
        }
		cout << "Iveskite savo pasirinkima: ";
		cin >> choice;
	}
}
void BubbleSort()
{
	for (int i = 0; i < S.size(); i++)
	{
		for (int j = i + 1; j < S.size(); j++)
		{
			if (S[i].lastname > S[j].lastname)
			{
				string a = S[i].lastname;
				S[i].lastname = S[j].lastname;
				S[j].lastname = a;
                string b = S[i].name;
				S[i].name = S[j].name;
				S[j].name = b;
                double c = S[i].avg;
				S[i].avg = S[j].avg;
				S[j].avg = c;
                double d = S[i].med;
				S[i].med = S[j].med;
				S[j].med = d;
			}
		}
	}
}
