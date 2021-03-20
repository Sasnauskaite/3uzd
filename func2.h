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
#include <chrono>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using namespace std::chrono;

struct Students 
{
    string name, lastname; // vardas, pavarde
    vector<int> nd; // Namu darbai
    int exam = 0;
    double avg, med;
};
struct Happy
{
    string name, lastname; // vardas, pavarde
    double avg, med;
};
struct Sad
{
    string name, lastname; // vardas, pavarde
    double avg, med;
};

int people[5];//globalus kintamasis
const string fileInt = "studentai10000.txt";//naudoja tada, kai skaitoma is jau esancio failo

void BubbleSort(vector<Students> &stud);
void average(vector<Students> &stud);
void mediana(vector<Students> &stud);
void print1happy(vector<Students> &stud);
void print1sad(vector<Students> &stud);
void print2happy(vector<Students> &stud);
void print2sad(vector<Students> &stud);
void separateAvg(vector<Students> &stud);
void separateMed(vector<Students> &stud);
void checkInput(char& choice);
void checkInput(int &in);
void checkFile1(int &input);
void checkFile2(int &input);
void checkNum(int &input);
void createFile(int file, int marks);
void random(int n, vector<int> &arr);
void read(vector<Students> &stud);
void addStudent(vector<Students> &stud);