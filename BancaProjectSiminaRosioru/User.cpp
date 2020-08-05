#include "User.h"

User::User(const std::string& user, const std::string& parola) : m_UserName(&user), m_Parola(&parola)
{
}

User::~User()
{
}

bool User::Verificare(std::string& user, std::string& parola)
{
	if (user == *m_UserName && parola == *m_Parola)
	{
		return true;
	}
	else
	{
		std::cout << "false information" << std::endl;

		std::cout << "press any key to exit" << std::endl;

		_getch();
		return false;
	}
}


