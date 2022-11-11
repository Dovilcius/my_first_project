#include "bibliotekos.h"

Studentas::Studentas() {
	Vardas = "Null";
	Pavarde = "Null";
	egzaminas = 1;
};
Studentas::Studentas(string vardas, string pavarde, vector<int>xpazymiai, double vertinimas) {
	Vardas = vardas;
	Pavarde = pavarde;
	pazymiai = xpazymiai;
	egzaminas = vertinimas;
};
Studentas::~Studentas() {
	pazymiai.clear();
}

Studentas::Studentas(const Studentas& p1) {
	Vardas = p1.Vardas;
	Pavarde = p1.Pavarde;
	pazymiai = p1.pazymiai;
	egzaminas = p1.egzaminas;
}
void Studentas::Deletepazymiai() {
	pazymiai.clear();
}
int Studentas::Menu() {
	int parinktis;
	cout << "--------------------MENU--------------------" << endl;
	cout << "1 = Suvesti studento duomenis" << endl;
	cout << "2 = Studentu galutiniai vertinimai pagal vidurki " << endl;
	cout << "3 = Sudentu galutiniai vertinimai pagal mediana" << endl;
	cout << "4 = Perziureti duomenis (vid./med.)" << endl;

	cin >> parinktis;
	system("CLS");
	return parinktis;
};
ostream& operator <<(ostream& output, const Studentas& x) {
	double vidurkis = accumulate(x.pazymiai.begin(), x.pazymiai.end(), 0.0) / x.pazymiai.size();
	double galutinisbalas = (0.4 * vidurkis) + (0.6 * x.egzaminas);
	cout << " " << x.Pavarde << right << setw(23) << x.Vardas << right << setw(32) << setprecision(2) << galutinisbalas << endl;
	return output;
};
void Studentas::PrintMedianas() {
	double vidurkis = accumulate(pazymiai.begin(), pazymiai.end(), 0.0) / pazymiai.size();
	double galutinisbalas = (0.4 * vidurkis) + (0.6 * egzaminas);
	nth_element(pazymiai.begin(), pazymiai.begin() + pazymiai.size() / 2, pazymiai.end());
	double galutinis_medianas = pazymiai[pazymiai.size() / 2];
	cout << " " << Pavarde << right << setw(23) << Vardas << right << setw(32) << setprecision(2) << (galutinis_medianas * 0.4) + (0.6 * egzaminas) << endl;
}
void Studentas::PrintFile() {
	double vidurkis = accumulate(pazymiai.begin(), pazymiai.end(), 0.0) / pazymiai.size();
	double galutinisbalas = (0.4 * vidurkis) + (0.6 * egzaminas);
	nth_element(pazymiai.begin(), pazymiai.begin() + pazymiai.size() / 2, pazymiai.end());
	double galutinis_medianas = pazymiai[pazymiai.size() / 2];
	cout << " " << Pavarde << right << setw(23) << Vardas << right << setw(32) << setprecision(2) << galutinisbalas << "      /     " << setprecision(2) << (galutinis_medianas * 0.4) + (0.6 * egzaminas) << endl;
};
istream& operator >>(istream& input, Studentas& x) {
	int parinktis;
	cout << "------------------------------------Suveskite studento duomenis----------------------------" << endl;
	cout << " Studento Vardas : ";
	cin >> x.Vardas;
	cout << " Studento Pavarde : ";
	cin >> x.Pavarde;
	cout << "Suveskite studento pazymius" << endl;
	cout << "Suveskite 11 ir enter norint ivesti egzamino ivertinima" << endl;
	cin >> parinktis;
	while (parinktis != 11) {
		if (parinktis == 11) {
			for (int i = 0; i < 10; i++) {
				int random = rand() % 10 + 1;
				x.pazymiai.push_back(random);
			}
			int random = rand() % 10 + 1;
			x.egzaminas = random;
			return	input;
		}
		else if (parinktis > 10 or parinktis < 0) {
			cout << "Klaida! Galimi skaiciai nuo 0 iki 10. " << endl;
			cin >> parinktis;
		}
		else
		{
			x.pazymiai.push_back(parinktis);
			cin >> parinktis;
		}
	};
	cout << endl << "Iveskite Egzamino pazymi :";
	cin >> x.egzaminas;
	system("CLS");
	cout << "Studento duomenys issaugoti" << endl;
	return input;
};
int wordnum(string wordnume) {
	int countinger = 0;
	std::string word;
	std::stringstream strm(wordnume);

	while (strm >> word) {
		++countinger;
	};
	return countinger;
};