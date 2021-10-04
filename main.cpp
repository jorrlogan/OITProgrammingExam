#include <iostream>
#include <string>
#include <vector>
#include "Numeral.h"
#include "Converter.h"

using namespace std;

int main(int argc, char* argv[]) {
    // numeral objects to represent each type
    vector<Numeral> numerals;
    Numeral numeralI(1, "I");
    Numeral numeralV(5, "V");
    Numeral numeralX(10, "X");
    Numeral numeralL(50, "L");
    Numeral numeralC(100, "C");
    Numeral numeralD(500, "D");
    Numeral numeralM(1000, "M");
    // pushing all numerals onto vector
    numerals.push_back(numeralM);
    numerals.push_back(numeralD);
    numerals.push_back(numeralC);
    numerals.push_back(numeralL);
    numerals.push_back(numeralX);
    numerals.push_back(numeralV);
    numerals.push_back(numeralI);

    string userInput = argv[1];
    // converter for translating input to each form
    Converter* converter = new Converter();

    //conversions depending on input
    if(isdigit(userInput.at(0))){
        converter->setNumber(stoi(userInput));
        string numeral = converter->decimalToRoman(numerals, userInput);
        cout << "Numeral Representation: " << numeral << endl;
    }
    else{
        converter->setNumeral(userInput);
        int number = converter->romanToDecimal(numerals, userInput);
        cout << "Decimal Representation: " << number << endl;
    }

    return 0;
}
