#pragma once
#include "bibliotekos.h"

class Studentas {
private:
	string Pavarde;
	vector<int> pazymiai;
	double egzaminas;
	double galutinis_medianas;
public:
	string Vardas;
	Studentas();
	Studentas(string, string, vector<int>, double);
	Studentas(const Studentas& p1);
	~Studentas();
	int Menu();
	void Deletepazymiai();
	void PrintMedianas();
	void PrintFile();
	friend istream& operator >>(istream& input, Studentas& x);
	friend ostream& operator <<(ostream& output, const Studentas& x);
};


int wordnum(string);