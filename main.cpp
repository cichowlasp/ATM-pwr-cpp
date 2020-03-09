#include <iostream>
#include "zbior.h"
#include <vector>
#include <windows.h>
#include <string>
#include <cstring>

using namespace std;

void switchtosmall(string &napis);
    karta karty;
    karta::Cards k1;
    vector<karta::Cards> card;
    void menu();
    HANDLE hout;
    extern vector<string> wlasc;
    bool sprawdz(const vector<string> &wlasciciel, const string &uzytkownik);
    void SetCP()
{
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
    setlocale(LC_ALL, "1250");
}

int main()
{
    SetCP();
    hout = GetStdHandle(STD_OUTPUT_HANDLE);

    karty.wczytaj_karty();

    menu();

}

void menu()
{
string imie, nazwisko, imna; // imna = imie + nazwisko

for(;;)
{

system("cls");
SetConsoleTextAttribute(hout, FOREGROUND_RED);//zmiana koloru na czerwony
data d1; // klasa data
d1.dataobe();
SetConsoleTextAttribute(hout, 15);//powrot do bialego
SetConsoleTextAttribute(hout, FOREGROUND_BLUE);
cout << "1.Wczytaj kartê\n2.Dodaj kartê\n0.Wyjœcie\n";
SetConsoleTextAttribute(hout, 15);
int m; //pod wybor menu
do{
cin.clear();
cin.sync();
cin >> m;
}while(!cin);
bool dalej;
switch(m)
{
case 1:
    karty.zmiana();
    cout << "Podaj swoje imiê: ";
    cin >> imie;
    system("cls");
    cout << "Podaj swoje nazwisko: ";
    cin >> nazwisko;
    system("cls");
    imna = imie + nazwisko;
    switchtosmall(imna);
dalej = sprawdz(wlasc, imna);
    if(dalej)
    {
        cout << "Jestes";
    }


    getchar();
    getchar();
    break;
case 2:
    break;
case 0:
    exit(0);
default:
    break;
}
}
}

void switchtosmall(string &napis){
    for(int i =0;i < napis.length();i++){
        napis[i] = tolower(napis[i]);
    }

}

bool sprawdz(const vector<string> &wlasciciel, const string &uzytkownik)
{
    for(unsigned int i = 0; i < wlasciciel.size(); i++)
    {
        if(uzytkownik == wlasciciel[i])
        {
            return true;
        }

    }
    return false;
}
