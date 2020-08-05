// BancaProjectSiminaRosioru.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"Banca.h"
#include "User.h"

int main()
{
    bool running = true;

    Banca* itBank = new Banca();

    std::string userName = "SiminaRosioru";
    std::string parola = "Test123";
    User* user = new User(userName, parola);

    int optiuneUser = 0;

    std::string userIntrodus;
    std::string parolaIntrodusa;
    
    PRINT("the user should be informed how many tries are left");
    PRINT("the program stops if you were entered wrongly the usernameand password three times");
    int number = 3;

    do
    {
        std::cout << "the number of attempts: " << number << std::endl;

        PRINT("Input the username: ");
        std::cin >> userIntrodus;
        PRINT("Input the password: ");
        std::cin >> parolaIntrodusa;

        number--;
    } while (!(user->Verificare(userIntrodus, parolaIntrodusa)) && number > 0);
    if (user->Verificare(userIntrodus, parolaIntrodusa))
    {
        PRINT("true information");
        PRINT("press any key to exit");
        _getch();

        do
        {
            system("cls");
            std::cout << "Informatii" << std::endl;
            std::cout << "MAIN MENU" << std::endl;
            std::cout << "0: Creare Cont Nou" << std::endl;
            std::cout << "1: Numar de Conturi Inregistrate" << std::endl;
            std::cout << "2: Vizualizare Cont" << std::endl;
            std::cout << "3: Modificare Cont" << std::endl;
            std::cout << "4: Operatii Sold" << std::endl;
            std::cout << "9: EXIT" << std::endl;
            std::cout << "Va rugam selectati o Optiune" << std::endl;
            std::cin >> optiuneUser;
            std::cin.ignore();
            system("cls");

            switch (optiuneUser)
            {
            case 0:
                itBank->AdaugareCont();
                break;
            case 1:
                itBank->PrintConturi();
                break;
            case 2:
                if (itBank->CautareCont())
                    std::cout << "Cont gasit" << std::endl;
                else
                {
                    PRINT("Numele cautat nu a fost gasit");
                    PRINT("Pentru creare cont apasati tasta 0");
                    PRINT("Pentru intoarcerea la meniul principal apasati tasta 1");

                    itBank->ContNou();
                    break;
                }
                break;
            case 3:
                itBank->ModificareCont();
                break;
            case 4:
                itBank->OperatiiSold();
                break;
            case 9:
                std::cout << "Multumim pentru vizita \n";
                running = false;
                break;
            default:
                break;
            }
        } while (running);

    }
    else
    {
        PRINT("false information");
        PRINT("You have entered a wrong username and password for three times!");
    }

    delete itBank;
}
