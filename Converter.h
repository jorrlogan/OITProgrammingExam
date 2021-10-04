//
// Created by logan on 10/4/2021.
//

#ifndef OITPROGRAMMINGEXAM_CONVERTER_H
#define OITPROGRAMMINGEXAM_CONVERTER_H

#include <string>
#include <vector>
#include <iostream>
#include "Numeral.h"

using namespace std;

/* this class is to convert from roman numerals to decimal numbers and vice versa*/

class Converter{
    string numeral = "";
    int number;
public:
    Converter(){}

    const string &getNumeral() const;

    void setNumeral(const string &numeral);

    int getNumber() const;

    void setNumber(int number);

    string decimalToRoman(vector<Numeral> numerals, string input);
    int romanToDecimal(vector<Numeral> numerals, string input);
    int getSymbolQuantities(Numeral numeralPassedIn, int remainder, vector<Numeral> numerals);
};

#endif //OITPROGRAMMINGEXAM_CONVERTER_H
