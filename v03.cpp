#include "func.cpp"

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
