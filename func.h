#pragma once

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

//Globalūs kintamieji
const char file[] = "studentai100000.txt"; //Duomenu failo pavadinimas
const char outFile[] = "rez.txt"; //Rezultatu failo pavadinimas

//funkcijos
void BubbleSort(vector<Students> &stud);
void print1(vector<Students> &stud);
void print2(vector<Students> &stud);
void checkInput(char& choice);
void checkInput(int &input);
void random(int n, vector<int>&arr);
void read(vector<Students>&stud);
void addStudent(vector<Students>&stud);