#include <iostream>
#include "classes.h"
#include <vector>
#include <fstream>
#include <time.h>
#include <string>

using namespace std;

extern string dataobecna;
extern struct tm* dataob;
extern time_t czas;
void data::dataobe(){ //zapis obecnej daty w string
    time(&czas);
    dataob = localtime(&czas);
    cout << "DATA: ";
    if(dataob->tm_mday<10){
                    dataobecna = "0" + to_string(dataob->tm_mday) + "-";
        if(dataob->tm_mon+1<10){
            dataobecna += "0" + to_string(dataob->tm_mon+1) + "-" + to_string(dataob->tm_year+1900);
        } else {
            dataobecna += to_string(dataob->tm_mon+1) + "-" + to_string(dataob->tm_year+1900);
            }
    } else {
        dataobecna = to_string(dataob->tm_mday) + "-";
        if(dataob->tm_mon<10) {
            dataobecna += "0" + to_string(dataob->tm_mon+1) + "-" + to_string(dataob->tm_year+1900);
        } else {
            dataobecna += to_string(dataob->tm_mon+1) + "-" + to_string(dataob->tm_year+1900);
            }
        }
    cout << dataobecna << "|\n";
    cout << "----------------|\n";
}

