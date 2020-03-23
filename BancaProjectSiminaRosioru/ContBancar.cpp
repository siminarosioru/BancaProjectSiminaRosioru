#include "ContBancar.h"

ContBancar::ContBancar()
{
	m_nume = "NumeNecunoscut";
	m_prenume = "PrenumeNecunoscut";
	m_IBAN = 0;
	m_tipCont = RON;
	m_sold = 0;
}

ContBancar::ContBancar(std::string nume, std::string prenume, int iban, TIPMONEDA tipCont) :
	m_nume(nume), m_prenume(prenume), m_IBAN(iban), m_tipCont(tipCont), m_sold(0)
{

}

bool ContBancar::VerificareNume(const std::string& numeCautat, const std::string& prenumeCautat)
{
	if (numeCautat == m_nume && prenumeCautat == m_prenume)
		return true;
	else
		return false;
}

void ContBancar::AfisareInfo()
{
	std::cout << "Nume: " << m_nume << std::endl;
	std::cout << "Prenume: " << m_prenume << std::endl;
	std::cout << "IBAN: " << m_IBAN << std::endl;
	std::cout << "Tip Cont: " << m_tipCont << std::endl;
}

void ContBancar::DepunereNumerar()
{
	int suma = 0;
	std::cout << "Introduceti suma pe care doriti sa o depuneti " << std::endl;
	std::cin >> suma;

	m_sold += suma;

	std::cout << "Apasati orice tasta pentru a va intoarce" << std::endl;

	_getch();
}

void ContBancar::RetragereNumerar()
{
	int suma = 0;
	std::cout << "Introduceti suma pe care doriti sa o retrageti" << std::endl;
	std::cin >> suma;

	m_sold -= suma;

	std::cout << "Apasati orice tasta pentru a va intoarce" << std::endl;

	_getch();
}

void ContBancar::VizualizareSold()
{
	std::cout << "Sold curent: " << m_sold << std::endl;

	std::cout << "Apasati orice tasta pentru a va intoarce" << std::endl;

	_getch();
}
