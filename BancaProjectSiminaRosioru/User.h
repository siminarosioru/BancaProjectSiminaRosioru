#pragma once

#include <string>
#include <iostream>
#include <conio.h>

class User
{
private:
	const std::string* m_UserName;
	const std::string* m_Parola;

public:
	User(const std::string& user, const std::string& parola);

	~User();

	bool Verificare(std::string& user, std::string& parola);
};
