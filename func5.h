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
int studs = 100000, mrks = 5; //Tyrimo studentu skaicius ir pazymiu skaicius
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
template <class T>
void PrintRez(T& S);
template <class T>
void Separate(T& S, int n);
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

template <class T>
void ReadToList(T& S);
template <class T>
void SeparateList(T& S, int n);
template <class T>
void PrintListAvg(T& S);
template <class T>
void PrintListMed(T& S);
