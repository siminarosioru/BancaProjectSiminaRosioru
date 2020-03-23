#pragma once

#include<string>
#include<iostream>
#include <conio.h>

enum TIPMONEDA
{
	RON,
	EURO
};


class ContBancar
{
private:
	std::string m_nume, m_prenume;
	TIPMONEDA m_tipCont;
	int m_IBAN;
	int m_sold;

public:
	ContBancar();

	ContBancar(std::string nume, std::string prenume, int iban, TIPMONEDA tipCont);

	bool VerificareNume(const std::string& numeCautat, const std::string& prenumeCautat);

	void AfisareInfo();

	std::string getNume()
	{
		return m_nume;
	}

	void modificareNume(std::string& nume)
	{
		m_nume = nume;
	}

	void DepunereNumerar();

	void RetragereNumerar();

	void VizualizareSold();

};

