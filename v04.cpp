#include "funcc.cpp"

int main()
{
    char choice;
    vector<Students> stud;
    cout << "Ar norite duomenis irasyti patys (T) ar skaityti is failo (N)?\nJusu atsakymas: "; 
    cin >> choice;
    checkInput(choice);

    if(tolower(choice) == 't')
    {
        cin.ignore();
        while(true)
        {
            addStudent(stud);

            cout << "Ar norite prideti dar 1 studenta? (t/n) \nJusu atsakymas: "; 
            cin >> choice;
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
        cout << "Ar norite skaityti is jau esamo failo(T) ar norite, kad programa sukurtu nauja studentu faila(N)?\nJusu atsakymas: "; 
        cin >> choice;
        checkInput(choice);
        if(tolower(choice)== 't')
        {
            auto start = std::chrono::steady_clock::now();
            read1(stud);
            auto read=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count();
            average(stud);
            mediana(stud);
            questions1(stud, 1);
        }
        else if(tolower(choice) == 'n')
        {
            int files;
            cout << "Irasykite, kiek failu norite sukurti [nuo 1 iki 5].\nJusu atsakymas: ";
            cin >> files;
            checkNum(files);
            int marks;
            for(int i=0; i<files; i++)
            {
                cout << "Irasykite norima i faila irasyti skaiciu studentu.\nJusu atsakymas: "; 
                cin >> people[i];
                checkFile1(people[i]);
                int pep=people[i];
                cout << "Irasykite, kiek pazymiu (be egzamino) studentai gali gauti [nuo 1 iki 15].\nJusu atsakymas: "; 
                cin >> marks;
                checkFile2(marks);
                cout<<pep<<" DUOMENU APDOROJIMAS:\n";
                auto start = std::chrono::steady_clock::now();
                createFile(pep, marks);
                cout<<"Failo sukurimas truko: "<<std::setprecision(3)
                <<std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count()<<"ms\n";
                
                start = std::chrono::steady_clock::now();
                read2(stud, pep);
                cout<<"Isvedimas i 2 failus truko: "<<std::setprecision(3)
                <<std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-start).count()<<"ms\n";
                average(stud);
                mediana(stud);
                questions2(stud, pep);
            }
            
        }
    }
    return 0;
}