#include <iostream>
#include <bitset>
#include <vector> // biblioteka dinaminiam masyvui
#include <sstream>// ostringstream 
using namespace std;

class Generatorius {
public:
	void skaiciavimas()
	{
		/// PARAMETRAI
		int a = 65;
		int b = 8921;

		int akoeficientas = 16807;
		int bkoeficientas = 48271;
		int dalyba = 2147483647;
		//PARAMENTRU PABAIGA

			int n = 0;
		cout << "kraunasi..." << endl;
		string sk1;
		for (int i = 0; i < 1000000; i++)
		{
			// skaiciavimai pagal uzduoti
			int arezultatas = (a * akoeficientas) % dalyba;
			int brezultatas = (b * bkoeficientas) % dalyba;
			a = arezultatas;
			b = brezultatas;
			string paskutiniaiskaiciai[1];

			// Toliau prasideda tikrinimas 
			//  kovertuoju i dvejetaini koda. Funkcija grazina paskutinius 8 skaicius
			dvejetainis(arezultatas, paskutiniaiskaiciai);
			sk1 = paskutiniaiskaiciai[0];
			dvejetainis(brezultatas, paskutiniaiskaiciai);
			//tikrinam ar musu isiminta simboliu eilute (parametras A) sutampa  su kita simboliu eilute (parametras B)
			if (sk1 == paskutiniaiskaiciai[0])
				n++;
		}
		cout << n;
	}
	
	//Metodas dvejetainis grazina paskunius 8 skaicius
	void dvejetainis(int arezultatas, string paskutiniaiskaiciai[]) {
		paskutiniaiskaiciai[0].clear();
		vector<int> a; //dinaminis masyvas visam skaiciaus dvejetainiui kodui
		ostringstream os;
		int n = arezultatas, i, j = 0;
		for (i = 0; n > 0; i++)
		{
			a.push_back(n % 2); // su push_back irasau i dinamini masyva
			n = n / 2;
		}
		for (i = i - 1;i >= 0;i--)
		{
			//isrenku paskutinius 8 skaicius
			if (i < 8) {
				os << a[i];
			}
		}
		paskutiniaiskaiciai[0] = os.str();
	}
};

class Ispletimas: public Generatorius {
public:
	void naujasMetodas() {
		// jusu kodas cia
	}
};

int main()
{
	Generatorius objektas;
	objektas.skaiciavimas();

	//  Ispletimo kvietimai (nebutini)
	Ispletimas kitasobjektas;
	kitasobjektas.naujasMetodas();

	system("pause"); // Naudojama tik per Microsoft Visual Studio
	return 0;
}


