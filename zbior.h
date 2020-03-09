#include <iostream>
#include <vector>

using namespace std;

class karta
{
    struct Own
    {
        string name;
        string surname;
    };
    public:
    struct Cards
    {
    int PIN;
    string nr_karty;
    Own owner;
    string rodzaj_karty;
    double ilosc_srodkow;
    };
    int ilosc_kart;
    vector<string> wlasc;
    void zmiana();
    void wczytaj_karty();
};

class ATM : public karta {
    public:
    bool is_cardinserted;
    string acceptedcards[4] = {"VISA", "American Express", "Visa Electron", "Mastercard"};
    bool is_pintrue;
    double amount_to_withdraw;
    karta::Cards inserted_card;
    bool checkcard(karta::Cards inserted_card, string acceptedcards[]){
        for(int i = 0; i < 3;i++){
            if ( inserted_card.rodzaj_karty == acceptedcards[i]){
                return true;
            }
        }
        return false;
    }

    bool is_cardcompatible = checkcard(inserted_card, acceptedcards);

};

class data
{
    public:
    void dataobe();
    struct tm* dataob;
time_t czas;
string dataobecna;
};

