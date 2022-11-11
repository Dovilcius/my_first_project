#include "bibliotekos.h"

int main()
{
	vector<Studentas> list;
	vector<int> fpazymiai = { 0 };
	Studentas sarasas;
	int skaicius = 0;
	int pasirinkimas = 0;
	skaicius = sarasas.Menu();
	while (skaicius != 0 or skaicius <=5) {
			while (skaicius == 1) {
				cin >> sarasas;
				list.push_back(sarasas);
				sarasas.Deletepazymiai();
				system("CLS");
				cout << " Studento duomenys buvo ivesti. Ka norite atlikti toliau? " << endl;
				cout << " 1 = Suvesti kito studento duomenis " << endl;
				cout << " 2 = Sugrizti i meniu " << endl;
				cin >> pasirinkimas;
				if (pasirinkimas == 2) { system("CLS"); skaicius = sarasas.Menu(); };
				system("CLS");
			};
			while (skaicius == 2) {
				cout << " Pavarde " << right << setw(25) << " Vardas " <<  "                      Galutinis(Vid.) " << endl;
				cout << "-----------------------------------------------------------------------------------------" << endl;
				for (int i = 0; i < list.size(); i++) { cout << list[i]; }
				cout << endl << "1 = Sugrizti i meniu " << endl;
				cin >> pasirinkimas;
				if (pasirinkimas == 1) { system("CLS"); skaicius = sarasas.Menu(); };
			};
			while (skaicius == 3) {
				cout << " Pavarde " << right << setw(25) << " Vardas " << "                      Galutinis(Med.) " << endl;
				cout << "----------------------------------------------------------------------------------------" << endl;
				for (int i = 0; i < list.size(); i++) { list[i].PrintMedianas(); }
				cout << endl << "1 = Sugristi i meniu" << endl;
				cin >> pasirinkimas;
				if (pasirinkimas == 1) { system("CLS"); skaicius = sarasas.Menu(); };
			};
			while (skaicius == 4) {
				static int checked = 0;
				if (checked == 0) {
					ifstream datafile;
					datafile.open("data.txt");
					string str = "null", Vardass = "null", Pavardee = "null";
					double fscore = 0;
					string arr[50];
					getline(datafile, str);
					int counter = wordnum(str);
					while (datafile.peek() != EOF) {
						getline(datafile, str);
						stringstream ss(str);
						for (int i = 0; i < counter; i++) {
							ss >> arr[i];
							if (i == 0) { Vardass = arr[i]; }
							else if (i == 1) { Pavardee = arr[i]; }
							else if (i > 1 and i + 1 < counter) { fpazymiai.push_back(stoi(arr[i])); }
							else if (i + 1 == counter) { fscore = stoi(arr[i]); }
						};
						Studentas fscholar(Vardass, Pavardee, fpazymiai, fscore);
						list.push_back(fscholar);
						fpazymiai.clear();
					};
					checked++;
					std::sort(list.begin(), list.end(), [](const Studentas& lhs, const Studentas& rhs) {return lhs.Vardas < rhs.Vardas; });
				};
				cout << " Pavarde " << right << setw(25) << " Vardas " << "                   Galutinis (Vid.) / Galutinis (Med.) " << endl;
				cout << "----------------------------------------------------------------------------------------------" << endl;
				for (int i = 0; i < list.size(); i++) { list[i].PrintFile(); };
				cout << endl << "1 = Sugrizti i meniu" << endl;
				cin >> pasirinkimas;
				if (pasirinkimas == 1) { system("CLS"); skaicius = sarasas.Menu(); };
			}
			while (skaicius >= 5 or skaicius == 0) {
				cout << "Klaida: Toks pasirinkimas neegzistuoja" << endl;
				system("pause");
			    system("CLS");
			    skaicius = sarasas.Menu();
			}
		}
		
	return 0;
};
