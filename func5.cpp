#include "func5.h"
#include "print.cpp"
template <class T>
void questions(T& S)
{
	int answer1;
	int kint = 0;
	int answerr;
	cout << "Ar norite:\n(1)Duomenis irasyti patys\n(2)Duomenis skaityti is failo\n(3)Sukurti nauja duomenu faila?\n"<<
	"(4)Atlikti spartos tyrima (pagal konteinerius)?\n(5)Atlikti spartos tyrima (pagal rusiavimo budus)?\nJusu atsakymas: "; 
    cin >> answer1;
    checkInput1(answer1);
	if (answer1 == 1)//Duomenu irasymas patiems
	{
		UnknownStud(S);
		BubbleSort(S);
	    PrintRez(S);
	}
	else if (answer1 == 2)//Skaitymas is esamo failo
	{
		ReadFromFile(S);
	    BubbleSort(S);
	    PrintRez(S);
	}
	else if (answer1 == 3)//Naujas duomenu failas
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
	    	ReadFromFile(S);
		    cout << "Sugeneruoto failo skaitymas truko:" << std::setprecision(4)<<
		    std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count() << " ms" << endl;
		    cout<<"Skaiciavimai..."<<endl;
		    BubbleSort(S);
		    start = std::chrono::steady_clock::now();
		    Separate(S);
		    cout << "Studentu isrusiavimas truko:" << std::setprecision(4)<<
		    std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count() << " ms" << endl;
		    if(tolower(ats)=='t')
		    {
		    	start = std::chrono::steady_clock::now();
		        PrintBothAvg(S);
		        cout << "Studentu atspausdinimas truko:" << std::setprecision(4)<<
		        std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count() << " ms" << endl;
		    }
		    else if(tolower(ats)=='n')
		    {
		    	start = std::chrono::steady_clock::now();
		        PrintBothMed(S);
		        cout << "Studentu atspausdinimas truko:" << std::setprecision(4)<<
		        std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count() << " ms" << endl;
		    }	
		}
	}
	else if(answer1 == 4)//Tyrimas
	{
		tyrimas1();
	}
	else if(answer1 == 5)//Tyrimas (rusiavimu)
	{
		tyrimas2();
	}
}
void tyrimas1()
{
	cout<<"Norite matyti vidurki(t) ar mediana(n)?\n";
	char choice;
	cin>>choice;
	checkInput(choice);
	checkInput3(studs);
	checkInput4(mrks);
	char ats;
	cout<<"Apdorojama "<<studs<< " duomenu: \n";
	n = studs;
	sk = mrks;
    auto start = std::chrono::steady_clock::now();
	CreateFile();
	cout << "Naujo failo sugeneravimas truko:" << std::setprecision(4)<<
	std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count() << " ms" << endl;
	for(int j=0; j<3; j++)
	{
		if(j==0)
		{
			vector<Studentas> S;
			cout<<"------------------------------\nVECTOR KONTEINERIS\n";
			auto start1 = std::chrono::steady_clock::now();
    	    start = std::chrono::steady_clock::now();
        	ReadFromFile(S);
			cout << "Sugeneruoto failo skaitymas truko:" << std::setprecision(4)<<
        	std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count() << " ms" << endl;
    	
        	start = std::chrono::steady_clock::now();
        	Separate(S);
        	cout << "Studentu isrusiavimas truko:" << std::setprecision(4)<<
        	std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count() << " ms" << endl;
			if(choice=='t')
			{
				PrintVectorAvg(S);
			}
			else if(choice=='n')
			{
				PrintVectorMed(S);
			}
        	cout << "Viso abi uzduotys ir skaiciavimai truko:" << std::setprecision(4)<<
        	std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start1).count() << " ms" << endl;
			S.clear();
		}
		if(j==1)
	    {
	    	deque<Studentas> S;
	        cout<<"------------------------------\nDEQUE KONTEINERIS\n";
        	auto start1 = std::chrono::steady_clock::now();
        	start = std::chrono::steady_clock::now();
        	ReadFromFile(S);
        	cout << "Sugeneruoto failo skaitymas truko:" << std::setprecision(4)<<
        	std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count() << " ms" << endl;
        	
        	start = std::chrono::steady_clock::now();
        	Separate(S);
        	cout << "Studentu isrusiavimas truko:" << std::setprecision(4)<<
        	std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count() << " ms" << endl;
			if(choice=='t')
			{
				PrintDequeAvg(S);
			}
			else if(choice=='n')
			{
				PrintDequeMed(S);
			}
        	cout << "Viso abi uzduotys ir skaiciavimai truko:" << std::setprecision(4)<<
        	std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start1).count() << " ms" << endl;
			S.clear();
	    }
	    if(j==2)
     	{
        	list<Studentas> S;
        	cout<<"------------------------------\nLIST KONTEINERIS\n";
        	auto start1 = std::chrono::steady_clock::now();
           	start = std::chrono::steady_clock::now();
        	ReadToList(S);
        	cout << "Sugeneruoto failo skaitymas truko:" << std::setprecision(4)<<
           	std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count() << " ms" << endl;
   	
        	start = std::chrono::steady_clock::now();
            SeparateList(S);
        	cout << "Studentu isrusiavimas truko:" << std::setprecision(4)<<
        	std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count() << " ms" << endl;
			if(choice=='t')
			{
				PrintListAvg(S);
			}
			else if(choice=='n')
			{
				PrintListMed(S);
			}
        	cout << "Viso abi uzduotys ir skaiciavimai truko:" << std::setprecision(4)<<
        	std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start1).count() << " ms" << endl;
			S.clear();
	    }
    }
}
void tyrimas2()
{
	cout<<"Norite matyti vidurki(t) ar mediana(n)?\n";
	char choice;
	cin>>choice;
	checkInput(choice);
	checkInput3(studs);
	checkInput4(mrks);
	char ats;
	cout<<"Apdorojama "<<studs<< " duomenu: \n";
	n = studs;
	sk = mrks;
    auto start = std::chrono::steady_clock::now();
	CreateFile();
	cout << "Naujo failo sugeneravimas truko:" << std::setprecision(4)<<
	std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count() << " ms" << endl;
	for(int j=0; j<3; j++)
	{
		if(j==0)
		{
			vector<Studentas> S;
			cout<<"-----------------------------------\nVECTOR KONTEINERIS\n";
			auto start1 = std::chrono::steady_clock::now();
        	ReadFromFile(S);
        	start = std::chrono::steady_clock::now();
        	Separate(S);
        	cout << "Studentu vector isrusiavimas mano budu truko:" << std::setprecision(4)<<
        	std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count() << " ms" << endl;
			if(choice=='t')
			{
				PrintVectorAvg(S);
			}
			else if(choice=='n')
			{
				PrintVectorMed(S);
			}
			vector<Galvocius> Good;
			vector<Vargselis> Bad;
			start = std::chrono::steady_clock::now();
        	Separate1(S, Good, Bad, choice);
        	cout << "Studentu vector isrusiavimas 1-uoju budu truko:" << std::setprecision(4)<<
        	std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count() << " ms" << endl;
			if(choice=='t')
			{
				PrintVectorAvg1(Good, Bad);
			}
			else if(choice=='n')
			{
				PrintVectorMed1(Good, Bad);
			}
			Good.clear();
			Bad.clear();
			start = std::chrono::steady_clock::now();
        	Separate2(S, Bad, choice);
        	cout << "Studentu vector isrusiavimas 2-uoju budu truko:" << std::setprecision(4)<<
        	std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count() << " ms" << endl;
			if(choice=='t')
			{
				PrintVectorAvg2(S, Bad);
			}
			else if(choice=='n')
			{
				PrintVectorMed2(S, Bad);
			}
        	cout << "Viso uztruko:" << std::setprecision(4)<<
        	std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start1).count() << " ms" << endl;
			S.clear();
			Bad.clear();
			Good.clear();
		}
		if(j==1)
	    {
	    	deque<Studentas> S;
	        cout<<"-----------------------------------\nDEQUE KONTEINERIS\n";
        	auto start1 = std::chrono::steady_clock::now();
        	ReadFromFile(S);
        	
        	start = std::chrono::steady_clock::now();
        	Separate(S);
        	cout << "Studentu deque isrusiavimas mano budu truko:" << std::setprecision(4)<<
        	std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count() << " ms" << endl;
			if(choice=='t')
			{
				PrintDequeAvg(S);
			}
			else if(choice=='n')
			{
				PrintDequeMed(S);
			}
			deque<Galvocius> Good;
			deque<Vargselis> Bad;
			start = std::chrono::steady_clock::now();
        	Separate1(S, Good, Bad, choice);
        	cout << "Studentu deque isrusiavimas 1-uoju budu truko:" << std::setprecision(4)<<
        	std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count() << " ms" << endl;
			if(choice=='t')
			{
				PrintDequeAvg1(Good, Bad);
			}
			else if(choice=='n')
			{
				PrintDequeMed1(Good, Bad);
			}
			Good.clear();
			Bad.clear();
			start = std::chrono::steady_clock::now();
        	Separate2(S, Bad, choice);
        	cout << "Studentu deque isrusiavimas 2-uoju budu truko:" << std::setprecision(4)<<
        	std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count() << " ms" << endl;
			if(choice=='t')
			{
				PrintDequeAvg2(S, Bad);
			}
			else if(choice=='n')
			{
				PrintDequeMed2(S, Bad);
			}
        	cout << "Viso uztruko:" << std::setprecision(4)<<
        	std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start1).count() << " ms" << endl;
			S.clear();
			Bad.clear();
	    }
	    if(j==2)
     	{
        	list<Studentas> S;
        	cout<<"-----------------------------------\nLIST KONTEINERIS\n";
        	auto start1 = std::chrono::steady_clock::now();
        	ReadToList(S);
    	
        	start = std::chrono::steady_clock::now();
        	SeparateList(S);
        	cout << "Studentu isrusiavimas mano budu truko:" << std::setprecision(4)<<
        	std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count() << " ms" << endl;
			if(choice=='t')
			{
				PrintListAvg(S);
			}
			else if(choice=='n')
			{
				PrintListMed(S);
			}
			list<Galvocius> Good;
			list<Vargselis> Bad;
			start = std::chrono::steady_clock::now();
        	SeparateList1(S, Good, Bad, choice);
        	cout << "Studentu deque isrusiavimas 1-uoju budu truko:" << std::setprecision(4)<<
        	std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count() << " ms" << endl;
			if(choice=='t')
			{
				PrintListAvg1(Good, Bad);
			}
			else if(choice=='n')
			{
				PrintListMed1(Good, Bad);
			}
			Good.clear();
			Bad.clear();
			start = std::chrono::steady_clock::now();
        	SeparateList2(S, Bad, choice);
        	cout << "Studentu deque isrusiavimas 2-uoju budu truko:" << std::setprecision(4)<<
        	std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count() << " ms" << endl;
			if(choice=='t')
			{
				PrintListAvg2(S, Bad);
			}
			else if(choice=='n')
			{
				PrintListMed2(S, Bad);
			}
        	cout << "Viso truko:" << std::setprecision(4)<<
        	std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start1).count() << " ms" << endl;
			S.clear();
			Bad.clear();
	    }
    }
}
template <class T>
void SeparateList(T& S)
{
	for (Studentas x : S)
	{
		if(x.avg>=d)
		{
			x.skolaAvg = 0;
		}
		else if(x.avg<d)
		{
			x.skolaAvg = 1;
		}
		if(x.med>=d)
		{
			x.skolaMed = 0;
		}
		else if(x.med<d)
		{
			x.skolaMed = 1;
		}
	}
}
template <class T, class G, class B>
void SeparateList1(T& S, G& Good, B& Bad, char choice)
{
	if(choice == 't')
	{
		Galvocius student1;
		Vargselis student2;
		for(Studentas z:S)
		{
			if(z.avg>=d)
			{
				student1.name=z.name;
				student1.lastname=z.lastname;
				student1.avg=z.avg;
				student1.med=z.med;
				Good.push_back(student1);
			}
		}		
		for(Studentas z:S)
		{
			if(z.avg<d)
			{
				student2.name=z.name;
			    student2.lastname=z.lastname;
				student2.avg=z.avg;
				student2.med=z.med;
				Bad.push_back(student2);
			}
		}
	}
	else if(choice == 'n')
	{
		Galvocius student1;
		Vargselis student2;
		for(Studentas z:S)
		{
			if(z.med>=d)
			{
				student1.name=z.name;
			    student1.lastname=z.lastname;
				student1.avg=z.avg;
				student1.med=z.med;
				Good.push_back(student1);
			}
		}		
		for(Studentas z:S)
		{
			if(z.med<d)
			{
				student2.name=z.name;
				student2.lastname=z.lastname;
		    	student2.avg=z.avg;
				student2.med=z.med;
				Bad.push_back(student2);
			}
		}
	}
}
template <class T, class B>
void SeparateList2(T& S, B& Bad, char choice)
{
	if(choice == 't')
	{
		Studentas student1;
		Vargselis student2;	
		for(Studentas z:S)
		{
			if(z.avg<d)
			{
				student2.name=z.name;
			    student2.lastname=z.lastname;
				student2.avg=z.avg;
				student2.med=z.med;
				Bad.push_back(student2);/*
				student1.name=z.name;
				student1.lastname=z.lastname;
		    	student1.avg=z.avg;
				student1.med=z.med;
				S.remove(student1);*/
			}
		}
	}
	else if(choice == 'n')
	{
		Studentas student1;
		Vargselis student2;	
		for(Studentas z:S)
		{
			if(z.med<d)
			{
				student2.name=z.name;
				student2.lastname=z.lastname;
		    	student2.avg=z.avg;
				student2.med=z.med;
				Bad.push_back(student2);/*
				student1.name=z.name;
				student1.lastname=z.lastname;
		    	student1.avg=z.avg;
				student1.med=z.med;
				S.remove(student1);*/
			}
		}
	}
}
template <class T>
void Separate(T& S)
{
	for(int i=0; i<studs; i++)
    {
    	if(S[i].avg>=d)
        {
    		S[i].skolaAvg = 0;
    	}
		else if(S[i].avg<d)
       	{
       		S[i].skolaAvg = 1;
    	}
    	if(S[i].med>=d)
    	{
    		S[i].skolaMed = 0;
      	}
       	else if(S[i].med<d)
       	{
    		S[i].skolaMed = 1;
       	}
    }
}
template <class T, class G, class B>
void Separate1(T& S, G& Good, B& Bad, char choice)
{
	Good.clear();
	Bad.clear();
	if(choice == 't')
	{
		int gal = 0, varg = 0;
        int i=0;
		while(i<studs)
		{
			if(S[i].avg>=d)
			{
				Good.push_back(Galvocius());
				Good[gal].name = S[i].name;
				Good[gal].lastname = S[i].lastname;
				Good[gal].avg = S[i].avg;
				Good[gal].med = S[i].med;
				gal+=1;
			}
			else if(S[i].avg<d)
			{
				Bad.push_back(Vargselis());
				Bad[varg].name = S[i].name;
				Bad[varg].lastname = S[i].lastname;
				Bad[varg].avg = S[i].avg;
				Bad[varg].med = S[i].med;
				varg+=1;
			}
			i++;
		}
	}
	else if(choice == 'n')
	{
		int gal = 0, varg = 0;
		int i=0;
		while(i<studs)
		{
			if(S[i].med>=d)
			{
				Good.push_back(Galvocius());
				Good[gal].name = S[i].name;
				Good[gal].lastname = S[i].lastname;
				Good[gal].avg = S[i].avg;
				Good[gal].med = S[i].med;
				gal+=1;
			}
			else
			{
				Bad.push_back(Vargselis());
				Bad[varg].name = S[i].name;
				Bad[varg].lastname = S[i].lastname;
				Bad[varg].avg = S[i].avg;
				Bad[varg].med = S[i].med;
				varg+=1;
			}
			i++;
		}
	}
}
template <class T, class B>
void Separate2(T& S, B& Bad, char choice)
{
	Bad.clear();
    if(choice == 't')
	{	
		int varg=0;
		double x;
        for(int i=0; i<studs; i++)
		{
			if(S[i].avg<5.00)
			{
				Bad.push_back(Vargselis());
				Bad[varg].name = S[i].name;
				Bad[varg].lastname = S[i].lastname;
				Bad[varg].avg = S[i].avg;
				Bad[varg].med = S[i].med;
				//S.erase(S.begin()+(i-1));
				varg+=1;
			}
			else if(S[i].avg>=5.00)
			{
				continue;
			}
		}
	}
	else if(choice == 'n')
	{
		int varg = 0;
		double x;
		for(int i=0; i<studs; i++)
		{
			if(S[i].med<5.00)
			{
				Bad.push_back(Vargselis());
				Bad[varg].name = S[i].name;
				Bad[varg].lastname = S[i].lastname;
				Bad[varg].avg = S[i].avg;
				Bad[varg].med = S[i].med;
				//S.erase(S.begin()+(i-1));
				varg+=1;
			}
			else if(S[i].med>=5.00)
			{
				continue;
			}
		}
	}
}
template <class T>
void UnknownStud(T& S)
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
			KnowND(S, n);
		}
		else if (answer4 == no)
		{
			UnknownND(S, n);
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
				UnknownStud(S);
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
		UnknownStud(S);
	}
}
template <class T>
void KnowND(T& S, int a)
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
template <class T>
void UnknownND(T& S, int a)
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
template <class T>
void ReadFromFile(T& S)
{
	S.clear();
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
template <class T>
void ReadToList(T& S)
{
	Studentas student;
	S.clear();
	std::ifstream in(FileName);
	string x;
	int y;
	try 
	{
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
			in >> student.name;
			in >> student.lastname;
			pazymiai.clear();
			for (int j = 0; j < sk; j++)
			{
				in >> y;
				suma = suma + y;
				pazymiai.push_back(y);
			}
			in >> egz;
			student.avg = average();
			student.med = mediana();
			n = i;
			S.push_back(student);
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
	file = "kurs" + std::to_string(n);
	file += ".txt";
	FileName = file;
	std::ofstream out(file);
	out << std::left << std::setw(20) << v << std::setw(20) << p;
	for (int i = 1; i < sk+1; i++)
	{
		out << std::setw(7) << nd + std::to_string(i);
	}
	out << std::setw(7) << e << endl;
	srand(time(NULL));
	for (int i = 1; i < n+1; i++)
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
    while (cin.fail() || choice < 1 || choice > 5)
    {
		if (cin.fail())
        {
            cout << "Ivestis netinkama (Ivedete raide)\n";
            cout <<"Galimi pasirinkimai:\n(1)Irasysiu pats\n(2)Skaityti is failo\n(3)Sugeneruoti nauja duomenu faila\n"<<
			"(4)Atlikti konteineriu spartos tyrima\n(5)Atlikti rusiavimo spartos tyrima\nJusu atsakymas: ";
        }
        else if(choice < 1 || choice > 5)
        {
            cout << "Turite pasirinkti is intervalo [1;5]\n";
            cout <<"Galimi pasirinkimai:\n(1)Irasysiu pats\n(2)Skaityti is failo\n(3)Sugeneruoti nauja duomenu faila\n"<<
			"(4)Atlikti konteineriu spartos tyrima\n(5)Atlikti rusiavimo spartos tyrima\nJusu atsakymas: ";
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
void checkInput5(int choice)
{
    while (cin.fail() || choice < 1 || choice > 3)
    {
		if (cin.fail())
        {
            cout << "Ivestis netinkama (Ivedete raide)\n";
            cout <<"Galimi pasirinkimai:\n(1)vector\n(2)deque\n(3)list\nJusu atsakymas: ";
        }
        else if(choice < 1 || choice > 3)
        {
            cout << "Turite pasirinkti is intervalo [1;3]\n";
            cout <<"Galimi pasirinkimai:\n(1)vector\n(2)deque\n(3)list\nJusu atsakymas: ";
        }
		cout << "Iveskite savo pasirinkima: ";
		cin >> choice;
	}
}
template <class T>
void BubbleSort(T& S)
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
