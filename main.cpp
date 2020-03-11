#include <iostream>
#include "classes.h"
#include <vector>
#include <fstream>
#include <time.h>
#include <string>
#include <cstdlib>

using namespace std;
void load_card_types(vector<string> &card_types);
void menu(vector<Card> &cards, int &amountofcards, vector<string> &card_types);
void addcard(vector<Card> &cards, int &amountofcards);
void print_card_types(vector<string> card_types);
int main();

int displayMenu()
{
    int choice;
    system("clear");
    cout << "------------------------------------------------" << endl;
    cout << "Program jest uruchomiony poraz pierwszy." << endl;
    cout << "Czy chcesz dodać nowe obsługiwane rodzaje kart?." << endl;
    cout << "\n2.Wyświetl aktualnie obsługiwane rodzaje kart" << endl;
    cout << "1.Tak" << endl;
    cout << "0.Nie" << endl;
    cout << "------------------------------------------------" << endl;

    cin >> choice;
    return choice;
}

void add_card_types(vector<Card> &cards, int &amountofcards, vector<string> &card_types)
{
    ofstream cardtypes("types.txt");
    for (;;)
    {
        string card_type;
        switch (displayMenu())
        {
        case 1:

            cout << "Podaj nazwę rodzaju ktory chcesz dodać: ";
            cin >> card_type;
            cardtypes << card_type << endl;
            cardtypes.close();
            load_card_types(card_types);
            break;
        case 2:
            print_card_types(card_types);
            break;
        case 0:
            main();

        default:
            break;
        }
    }
}

/**
 *  Funkcja po uruchominiu zapisuje do pliku tekst by moc sprawdzic 
 *  czy program był juz uruchamiany
 */
void firstrun()
{
    ofstream checkifused("wasrun.txt");
    checkifused << "true";
    checkifused.close();
}

/**
 *  Sprawdza czy program był juz uruchomiony na podstawie
 */
bool wasused()
{
    ifstream checkifused("wasrun.txt");
    string line;
    if (checkifused.good() == true)
    {
        while (!checkifused.eof())
        {
            getline(checkifused, line);
            if (line == "true")
            {
                return true;
            }
        }
    }
    return false;
}
/**
 *  Funkcja dodaje rodzaje kart z pliku txt
 */
void load_card_types(vector<string> &card_types)
{
    ifstream cardtypes;
    cardtypes.open("types.txt", ios::in);
    string line;
    if (cardtypes.good() == true)
    {
        while (!cardtypes.eof())
        {
            getline(cardtypes, line);
            card_types.push_back(line);
        }
    }
    cardtypes.close();
}
/**
 *  Printuje obsługiwane rodzaje kart
 */
void print_card_types(vector<string> card_types)
{
    for (;;)
    {
        system("clear");
        cout << "-------------------------------------" << endl;
        cout << "Obsługiwane rodzaje kart: " << endl;
        cout << "\n|";
        for (int i = 0; i < card_types.size(); i++)
        {
            cout << " " << card_types[i] << " |";
        }
        cout << "\n\n-------------------------------------" << endl;
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

/**
 *    Funkcja wczytuje dane z pliku
 */
void loaddata(vector<Card> &cards, int &amountofcards)
{
    vector<string> data;
    ifstream savedata;
    savedata.open("data.txt", ios::in);
    string line;
    if (savedata.good() == true)
    {
        while (!savedata.eof())
        {
            getline(savedata, line);
            data.push_back(line);
        }

        if (savedata.peek() == ifstream::traits_type::eof())
        {
            for (int x = 0; x < data.size() / 6; x++)
            {
                addcard(cards, amountofcards);
            }
            int x = 0;
            for (int i = 0; i < data.size() - 1; i += 6)
            {
                cards[x].name = data[i];
                cards[x].surname = data[i + 1];
                cards[x].PIN = atoi(data[i + 2].c_str());
                cards[x].card_number = atoll(data[i + 3].c_str());
                cards[x].card_type = data[i + 4];
                cards[x].money = atof(data[i + 5].c_str());
                cout << cards[x].name << endl;
                cout << cards[x].surname << endl;
                cout << cards[x].PIN << endl;
                cout << cards[x].card_number << endl;
                cout << cards[x].card_type << endl;
                cout << cards[x].money << endl;
                x++;
            }
        }
    }
    savedata.close();
}
/*
 * funkcja zapisuje dane do pliku
 */
void savedata(int amountofcards, vector<Card> cards)
{
    ofstream savedata("data.txt");
    for (int i = 0; i < amountofcards; i++)
    {
        savedata << cards[i].name << endl;
        savedata << cards[i].surname << endl;
        savedata << cards[i].PIN << endl;
        savedata << cards[i].card_number << endl;
        savedata << cards[i].card_type << endl;
        savedata << cards[i].money << endl;
    }
    savedata.close();
}

/*
 *    Funkcja wyświetla dane karty oraz umozliwia operacje typu wypłacanie i wpłacanie pieniędzy
 */
void registeredcardmenu(int cardindex, vector<Card> &cards, int &amountofcards, vector<string> &card_types)
{
    cout << "Wprowadz PIN do karty: ";
    if (cards[cardindex].pincheck())
    {

        for (;;)
        {
            system("clear");
            cout << "Ilość środkow: " << cards[cardindex].money << endl;
            cout << "-----------------" << endl;
            cout << "1.Informacje o karcie" << endl;
            cout << "2.Wypłać pieniądze" << endl;
            cout << "3.Wpłać pieniądze" << endl;
            cout << "4.Zmień PIN do karty" << endl;
            cout << "0.Powrot do menu głownego" << endl;
            cout << "-----------------" << endl;
            int chose_option;
            cin >> chose_option;
            switch (chose_option)
            {
            case 1:
                cards[cardindex].cardinfo();
                break;
            case 2:
                cards[cardindex].change_money(0);
                break;
            case 3:
                cards[cardindex].change_money(1);
                break;
            case 4:
                cards[cardindex].change_pin();
                break;
            case 0:
                menu(cards, amountofcards, card_types);
                break;
            default:
                break;
            }
        }
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

/*
 *   Zamienia wszystkie literki w stringu na małe
 */
string tolowerletters(string str)
{
    for (int i = 0; i < str.size(); i++)
    {
        str[i] = tolower(str[i]);
    }
    return str;
}

/*
 *   Sprawdza czy karta juz istnieje oraz podaj numer indexu instniejącej karty.
 */
bool checkcard(vector<Card> &cards, int &cardindex)
{
    string name;
    string surname;
    cout << "Podaj imię: ";
    cin >> name;
    cout << "Podaj nazwisko: ";
    cin >> surname;
    for (int i = 0; i < cards.size(); i++)
    {
        if (tolowerletters(name) == tolowerletters(cards[i].name) && tolowerletters(surname) == tolowerletters(cards[i].surname))
        {
            cardindex = i;
            return true;
        }
    }
    return false;
}

/*
 *   Pozwala na konfigurację stworzonej karty
 */
void dataofcard(vector<Card> &cards, int amountofcards, vector<string> &card_types)
{
    cout << "Podaj imię: ";
    cin >> cards[amountofcards - 1].name;
    cout << "Podaj nazwisko: ";
    cin >> cards[amountofcards - 1].surname;
    cout << "Podaj PIN do twojej karty: ";
    cin >> cards[amountofcards - 1].PIN;
    cards[amountofcards - 1].generate_card_number();
    cards[amountofcards - 1].generate_card_type(card_types);
}

/*
 *   Tworzy i dodaje nową kartę do wektora
 */
void addcard(vector<Card> &cards, int &amountofcards)
{

    Card card0;

    cards.push_back(card0);
    amountofcards++;
}
void menu(vector<Card> &cards, int &amountofcards, vector<string> &card_types)
{
    for (;;)
    {
        system("clear");
        data d1; // klasa data
        d1.dataobe();
        cout << "Ilość kart: " << amountofcards << endl;
        cout << "---------------------------" << endl;
        cout << "1.Wczytaj kartę" << endl;
        cout << "2.Dodaj kartę" << endl;
        cout << "3.Obsługiwane rodzaje kart" << endl;
        cout << "0.Wyjście" << endl;
        cout << "---------------------------" << endl;
        int chose_option; //pod wybor menu
        cin >> chose_option;
        bool dalej;
        switch (chose_option)
        {
        case 1:
            int cardindex;
            if (checkcard(cards, cardindex))
            {
                registeredcardmenu(cardindex, cards, amountofcards, card_types);
            }
            else
            {
                for (;;)
                {
                    system("clear");
                    cout << "-------------------------------------" << endl;
                    cout << "Twoja karta nie jest zarejestrowana." << endl;
                    cout << "Proszę ją dodać do systemu." << endl;
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
            break;
        case 2:
            addcard(cards, amountofcards);
            dataofcard(cards, amountofcards, card_types);
            break;
        case 3:
            print_card_types(card_types);
            break;
        case 0:
            savedata(amountofcards, cards);
            exit(0);
        default:
            break;
        }
    }
}

int main()
{
    vector<string> card_types;
    card_types.clear();
    card_types.push_back("VISA");
    card_types.push_back("American Express");
    card_types.push_back("Visa Electron");
    card_types.push_back("Mastercard");
    int amountofcards = 0;
    vector<Card> cards;
    if (wasused())
    {
    }
    else
    {
        firstrun();
        add_card_types(cards, amountofcards, card_types);
    }
    load_card_types(card_types);

    loaddata(cards, amountofcards);
    menu(cards, amountofcards, card_types);
}
