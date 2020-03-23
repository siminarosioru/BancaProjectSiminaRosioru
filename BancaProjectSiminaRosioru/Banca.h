#pragma once

#include"ContBancar.h"
#include<iostream>
#include<vector>

#define PRINT(x) std::cout << x << std::endl;

class Banca
{
private:
	std::vector<ContBancar> m_Conturi;
	void print(std::string message);

public:
	Banca();

	void AdaugareCont();

	void PrintConturi();

	bool CautareCont();

	ContBancar CautareCont(std::string& nume, std::string& prenume);

	void ContNou();

	bool ModificareCont();

	void OperatiiSold();

};

