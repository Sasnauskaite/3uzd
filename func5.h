#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <stdio.h> 
#include <chrono>
#include <vector>
#include <deque>
#include <list>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::deque;
using std::list;

struct Studentas
{
	string name;
	string lastname;
	double avg;
	double med;
    int skolaAvg;
    int skolaMed;
};
struct Galvocius
{
	string name;
	string lastname;
	double avg;
	double med;
};
struct Vargselis
{
	string name;
	string lastname;
	double avg;
	double med;
};
int studs = 1000000, mrks = 5; //Tyrimo studentu skaicius ir pazymiu skaicius
double d = 5.00000;
string FileName = "studentai10000.txt"; //Duomenu failo pavadinimas
const char outFile[] = "rez.txt"; //Rezultatu failo pavadinimas
int sk = 0;
int n = 0;
double suma = 0;
double egz = 0;
vector<double> pazymiai;
double number;
string yes = "t";
string no = "n";
double number5 = 0;
string v="Vardas", p="Pavarde", vidd="Galutinis (vid)", medd="Galutinis (med)", line="-", nd = "ND", e = "Egz.";

template <class T>
void ReadFromFile(T& S);
template <class T>
void PrintBothAvg(T& S);
template <class T>
void PrintBothMed(T& S);
//--------------vector
template <class T>
void PrintVectorAvg(T& S);
template <class T>
void PrintVectorMed(T& S);
template <class G, class B>
void PrintVectorAvg1(G& Good, B& Bad);
template <class G, class B>
void PrintVectorMed1(G& Good, B& Bad);
template <class T, class B>
void PrintVectorAvg2(T& S, B& Bad);
template <class T, class B>
void PrintVectorMed2(T& S, B& Bad);
//------------Deque
template <class T>
void PrintDequeAvg(T& S);
template <class T>
void PrintDequeMed(T& S);
template <class G, class B>
void PrintDequeAvg1(G& Good, B& Bad);
template <class G, class B>
void PrintDequeMed1(G& Good, B& Bad);
template <class T, class B>
void PrintDequeAvg2(T& S, B& Bad);
template <class T, class B>
void PrintDequeMed2(T& S, B& Bad);
//---------------List
template <class T, class B>
void PrintListAvg1(T& Good, B& Bad);
template <class T, class B>
void PrintListMed1(T& Good, B& Bad);
template <class T, class B>
void PrintListAvg2(T& S, B& Bad);
template <class T, class B>
void PrintListMed2(T& S, B& Bad);
template <class T, class G, class B>
void SeparateList1(T& S, G& Good, B& Bad, char choice);
template <class T, class B>
void SeparateList2(T& S, B& Bad, char choice);
//---------------
template <class T>
void PrintRez(T& S);
template <class T>
void Separate(T& S);
double average();
double mediana();
template <class T>
void KnowND(T& S, int n);
template <class T>
void UnknownND(T& S, int n);
template <class T>
void KnownStud(T& S);
template <class T>
void UnknownStud(T& S);
void CreateFile();
template <class T>
void questions(T& S);
bool check(double number);
void checkInput1(int choice);
void checkInput2(int choice);
void checkInput3(int choice);
void checkInput4(int choice);
void checkInput5(int choice);
void checkInput(char& choice);
void checkInput(int &in);
template <class T>
void BubbleSort(T& S);
template <class T, class G, class B>
void Separate1(T& S, G& Good, B& Bad, char choice);
template <class T, class B>
void Separate2(T& S, B& Bad, char choice);
template <class T>
void ReadToList(T& S);
template <class T>
void SeparateList(T& S);
template <class T>
void PrintListAvg(T& S);
template <class T>
void PrintListMed(T& S);
void tyrimas1();
void tyrimas2();