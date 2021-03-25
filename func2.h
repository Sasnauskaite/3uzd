#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <stdio.h> 
#include <chrono>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

struct Studentas
{
	string name;
	string lastname;
	double avg;
	double med;
    int skolaAvg;
    int skolaMed;
};
vector<Studentas> S;
int sk = 0;
int n = 0;
double suma = 0;
double egz = 0;
vector<double> pazymiai;
string yes = "t";
string no = "n";
string ka = "k";
double number;
double number5 = 0;
string v="Vardas", p="Pavarde", vidd="Galutinis (vid)", medd="Galutinis (med)", line="-", nd = "ND", e = "Egz.";
string FileName = "studentai10000.txt"; //Duomenu failo pavadinimas
const char outFile[] = "rez.txt"; //Rezultatu failo pavadinimas


void ReadFromFile();
void PrintBothAvg();
void PrintBothMed();
void PrintRez();
void Separate(int n);
double average();
double mediana();
void KnowND(int n);
void UnknownND(int n);
void KnownStud();
void UnknownStud();
void CreateFile();
void questions();
bool check(double number);
void checkInput1(int choice);
void checkInput2(int choice);
void checkInput3(int choice);
void checkInput4(int choice);
void checkInput(char& choice);
void checkInput(int &in);
void BubbleSort();
