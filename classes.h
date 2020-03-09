#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

class Card
{
public:
    string name;
    string surname;
    int PIN;
    long long card_number;
    string card_type;
    double money = 0.0;

    /*
        Losuje numer karty
    */
    void generate_card_number()
    {
        srand(time(0));
        card_number = rand() % (9999999999999999 - 1000000000000000 + 1) + 1000000000000000;
    }

    void generate_card_type()
    {
        string acceptedcards[4] = {"VISA", "American Express", "Visa Electron", "Mastercard"};
        card_type = acceptedcards[rand() % 4 + 1];
    }

    /*
    Sprawdza pin czy wpisany pin zgadza się z pinem karty
*/
    bool pincheck()
    {
        int pin;
        cin >> pin;
        if (PIN == pin)
        {
            return true;
        }
        return false;
    }

    /*
    Funkcja wyświetla podstawowe dane klasy Card
    */
    void cardinfo()
    {
        for (;;)
        {

            system("clear");
            cout << "-----------------------" << endl;
            cout << "Dane właściciela: " << name << " " << surname << endl;
            cout << "Numer karty: " << card_number << endl;
            cout << "Rodzaj karty: " << card_type << endl;
            cout << "-----------------------" << endl;
            cout << "Kliknij 0 aby kontynuować." << endl;
            char enter = 1;
            system("/bin/stty raw");
            enter = getchar();
            system("/bin/stty cooked");
            if (enter == '0')
            {
                break;
            }
        }
    }

    /*
        Funckja dodaje lub odejmuje pieniądze z konta
    */
    void change_money(int option)
    {
        double change;
        if (option == 1)
        {
            cout << "Podaj kwotę do wpłacenia: ";
            cin >> change;
            money += change;
        }
        else
        {
            cout << "Podaj kwotę do wypłacenia: ";
            cin >> change;
            if (money - change < 0)
            {
                for (;;)
                {
                    system("clear");
                    cout << "--------------------------------------------" << endl;
                    cout << "Nie posiadasz wystarczającej ilości środkow." << endl;
                    cout << "Uzupełnij konto i spronuj ponownie." << endl;
                    cout << "--------------------------------------------" << endl;
                    cout << "Kliknij 0 aby kontynuować." << endl;
                    char enter = 1;
                    system("/bin/stty raw");
                    enter = getchar();
                    system("/bin/stty cooked");
                    if (enter == '0')
                    {
                        break;
                    }
                }
            }
            else
            {
                money -= change;
            }
        }
    }

    void change_pin()
    {
        cout << "Wprowadz stary PIN do karty: ";
        if (pincheck())
        {
            cout << "Podaj nowy pin: ";
            cin >> PIN;
        }
        else
        {
            for (;;)
            {
                system("clear");
                cout << "-------------------------------------" << endl;
                cout << "Został wprowadzony zły kod pin." << endl;
                cout << "Proszę sprobować ponownie." << endl;
                cout << "-------------------------------------" << endl;
                cout << "Kliknij 0 aby kontynuować." << endl;
                char enter = 1;
                system("/bin/stty raw");
                enter = getchar();
                system("/bin/stty cooked");
                if (enter == '0')
                {
                    break;
                }
            }
        }
    }
};

class data
{
public:
    void dataobe();
    struct tm *dataob;
    time_t czas;
    string dataobecna;
};
