//
// Created by logan on 10/4/2021.
//

#include "Converter.h"

string Converter::decimalToRoman(vector<Numeral> numerals, string input){
    int remainder = this->number;
    for(int i = 0; i < numerals.size(); ++i){
        remainder = getSymbolQuantities(numerals.at(i), remainder, numerals);
    }
    return this->numeral;
}

int Converter::getSymbolQuantities(Numeral numeralPassedIn, int remainder, vector<Numeral> numerals){
    int amountContained = remainder / numeralPassedIn.getValue();
    if(amountContained > 0){
        if(amountContained == 4){
            for(int j = 0; j < numerals.size(); ++j){
                if(numerals.at(j).getValue() == numeralPassedIn.getValue()){
                    string letter = numerals.at(j-1).getNumeralRep();
                    this->numeral.append(numeralPassedIn.getNumeralRep());
                    this->numeral.append(letter);
                }
            }
        }
        else{
            this->numeral.append(numeralPassedIn.getNumeralRep());
        }
    }

    for(int j = 0; j < numerals.size(); ++j){
        for(int i = 0; i < numerals.size(); ++i){
            if((numerals.at(j).getValue() - numerals.at(i).getValue()) == remainder){
                this->numeral.append(numerals.at(i).getNumeralRep());
                this->numeral.append(numerals.at(j).getNumeralRep());
                remainder = remainder - numerals.at(j).getValue() - numerals.at(i).getValue();
                return remainder;
            }
        }
    }
    if(amountContained == 0){
        return remainder;
    }
    remainder = remainder % numeralPassedIn.getValue();
    return remainder;
}

int Converter::romanToDecimal(vector<Numeral> numerals, string input){
    int number = 0;
    if(input.length() == 1){
        for(int j = 0; j < numerals.size(); ++j) {
            if (input.at(0) == numerals.at(j).getNumeralRep().at(0)) {
                this->number = numerals.at(j).getValue();
                return this->number;
            }
        }
    }
    if(input.size() > 1){
        if(input.size() % 2 == 0) {
            for (int i = 0; i < input.size(); i = i + 2) {
                if (i != input.size() - 1) {
                    if (input.at(i) == input.at(i + 1)) {
                        // convert symbol to decimal
                        for(int j = 0; j < numerals.size(); ++j){
                            if(input.at(i) == numerals.at(j).getNumeralRep().at(0)){
                                number += (numerals.at(j).getValue() * 2);
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}


const string &Converter::getNumeral() const {
    return numeral;
}

void Converter::setNumeral(const string &numeral) {
    Converter::numeral = numeral;
}

int Converter::getNumber() const {
    return number;
}

void Converter::setNumber(int number) {
    Converter::number = number;
}
