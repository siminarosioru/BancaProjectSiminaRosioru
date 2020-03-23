#include "Banca.h"

void Banca::print(std::string message)
{
	std::cout << message << std::endl;
}

Banca::Banca()
{
}

void Banca::AdaugareCont()
{
	std::string nume, prenume;
	int iban;
	int tipCont;
	TIPMONEDA tipMoneda;

	print("Introduceti un nume");
	std::cin >> nume;
	std::cin.ignore();

	print("Introduceti un prenume");
	std::cin >> prenume;
	std::cin.ignore();

	print("Introduceti un iban");
	std::cin >> iban;
	std::cin.ignore();

	print("Introduceti un tip cont: 0 = RON ; 1 = EUR");
	std::cin >> tipCont;
	std::cin.ignore();

	if (tipCont == 0)
	{
		tipMoneda = RON;
	}
	else
	{
		tipMoneda = EURO;
	}

	ContBancar cont = ContBancar(nume, prenume, iban, tipMoneda);
	m_Conturi.push_back(cont);
}

void Banca::PrintConturi()
{
	int numarConturi = m_Conturi.size();
	PRINT("Numarul de conturi active este: ");
	PRINT(numarConturi);

	int retrunValue = -1;
	do {
		PRINT("apasati tasta 0 pentru intoarcere la meniul principal ");
		std::cin >> retrunValue;
	} while (retrunValue != 0);

}

bool Banca::CautareCont()
{
	std::string numeCautat;
	std::string prenumeCautat;
	PRINT("Introduceti numele dorit");
	std::cin >> numeCautat;
	PRINT("Introduceti prenumele dorit");
	std::cin >> prenumeCautat;

	for (auto it = m_Conturi.begin(); it != m_Conturi.end(); it++)
	{
		if (it->VerificareNume(numeCautat, prenumeCautat))
		{
			it->AfisareInfo();
			PRINT("Apasati o tasta pt a va intoarce la meniu");
			_getch();
			return true;
		}
	}
	return false;
}

ContBancar Banca::CautareCont(std::string& nume, std::string& prenume)
{
	ContBancar contCautat;

	for (auto it = m_Conturi.begin(); it != m_Conturi.end(); it++)
	{
		if (it->VerificareNume(nume, prenume))
		{
			contCautat = *it;
			break;
		}
	}
	return contCautat;
}

void Banca::ContNou()
{
	char creareCont = '1';
	std::cin >> creareCont;
	if (creareCont == 0)
	{
		AdaugareCont();
	}
	else
	{
		PRINT("Ne intoarcem la meniul principal.");
	}
}

bool Banca::ModificareCont()
{
	PRINT("Introduceti numele contului ce doriti sa il modificati");
	std::string nume;
	std::cin >> nume;

	PRINT("Introduceti prenumele contului ce doriti sa il modificati");
	std::string prenume;
	std::cin >> prenume;

	ContBancar contEditat = CautareCont(nume, prenume);

	if (contEditat.getNume() != "NumeNecunoscut")
	{
		PRINT("Contul a fost gasit: ");
		contEditat.AfisareInfo();

		PRINT("modificati numele");
		std::string numeNou;
		std::cin >> numeNou;
		contEditat.modificareNume(numeNou);

		for (auto it = m_Conturi.begin(); it != m_Conturi.end(); it++)
		{
			if (it->getNume() == nume)
			{
				it->modificareNume(numeNou);
				return true;
			}
		}
	}
	else
	{
		PRINT("contul nu a fost gasit");
		return false;
	}
}

void Banca::OperatiiSold()
{
	std::string nume;
	std::string prenume;
	PRINT("Introduceti numele clientului ");
	std::cin >> nume;
	PRINT("Introduceti prenumele clientului ");
	std::cin >> prenume;

	for (auto it = m_Conturi.begin(); it != m_Conturi.end(); it++)
	{
		if (it->VerificareNume(nume, prenume))
		{
			int optiune;
			PRINT("Operatii Sold Posibile");
			PRINT("Tasta 0: Afisare sold");
			PRINT("Tasta 1: Depunere numerar");
			PRINT("Tasta 2: Retagere numerar");
			std::cin >> optiune;

			switch (optiune)
			{
			case 0:
				it->VizualizareSold();
				break;
			case 1:
				it->DepunereNumerar();
				break;
			case 2:
				it->RetragereNumerar();
				break;
			default:
				break;
			}
		}
	}
}
