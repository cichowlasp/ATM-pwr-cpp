#include <iostream>
#include "zbior.h"
#include <vector>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

extern karta::Cards k1;
extern vector<karta::Cards> card;
extern vector<string> wlasc;
extern int ilosc_kart;

void karta::wczytaj_karty()
{
    fstream plik;
    string linia;
    int nr_lini = 1;
    plik.open("baza.txt", ios::in);
    while(getline(plik, linia))
    {
        if(nr_lini==7)
        {
            nr_lini=1;
            ilosc_kart++;

        }
        switch(nr_lini)
        {
        case 1:
            k1.PIN = atoi(linia.c_str());
            break;
        case 2:
            k1.nr_karty = linia;
            break;
        case 3:
            k1.ilosc_srodkow = atof(linia.c_str());
            break;
        case 4:
            k1.rodzaj_karty = linia;
            break;
        case 5:
            k1.owner.name = linia;
            break;
        case 6:
            k1.owner.surname = linia;
            card.push_back(k1);
            break;
        }
        nr_lini++;
    }
plik.close();
}

void karta::zmiana()
{
string pomoc;
    for(unsigned int i = 0; i<card.size(); i++)
    {
    pomoc = card[i].owner.name + card[i].owner.surname;

    wlasc.push_back(pomoc);
    }

    for(unsigned int j = 0; j<wlasc.size(); j++)
    {
        for(unsigned int i = 0; i<wlasc[j].length(); i++)
    {
        wlasc[j][i] = tolower(wlasc[j][i]);
    }
    }

    cout << wlasc[0];
}

