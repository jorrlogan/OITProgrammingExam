//
// Created by logan on 10/4/2021.
//

#ifndef OITPROGRAMMINGEXAM_NUMERAL_H
#define OITPROGRAMMINGEXAM_NUMERAL_H

#include <string>
using namespace std;

class Numeral{
public:
    Numeral(int value, string numeralRep){
        this->value = value;
        this->numeralRep = numeralRep;
    }
    int getValue() const {
        return value;
    }

    void setValue(int value) {
        Numeral::value = value;
    }

    const string &getNumeralRep() const {
        return numeralRep;
    }

    void setNumeralRep(const string &numeralRep) {
        Numeral::numeralRep = numeralRep;
    }

private:
    int value;
    string numeralRep;
};

#endif //OITPROGRAMMINGEXAM_NUMERAL_H
