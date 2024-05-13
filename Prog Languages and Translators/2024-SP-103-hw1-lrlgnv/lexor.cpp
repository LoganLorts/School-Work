#include <iostream>
using namespace std;

const string KEYWORDS = "FUNCTIONIFENDFWHILEENDWPRINT";
const string NUMBERS = "0123456789";
const string HEXA = "ABCDEF";
const string LETTERS = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwYyXxZz";

bool isInt(string value){
    int length = value.length();
    if(value.length() < 1){
        return false;
    }
    if (value[0] == '+' || value[0] == '-'){
        value[0] = '1';
    }
    for(int i = 0; i < length; i++){
        if(NUMBERS.find(value[i]) == string::npos){
            return false;
        }
    }
    return true;
}

bool isDec(string value){
    int length = value.length();
    int index = 0;
    bool Decimal = false;
    bool allNums = true;
    if(value.length() < 1){
        return false;
    }
    if (value[0] == '+' || value[0] == '-'){
        value[0] = '1';
    }
    if (value.find('.') != string::npos){
        Decimal = true;
        index = value.find('.');
        //check if there is a number after the decimal
        if (value.back() == '.'){
            return false;
        }
        value[index] = '1';
    }
    for(int i = 0; i < length; i++){
        if(NUMBERS.find(value[i]) == string::npos){
            allNums = false;
        }
    }


    if (Decimal && allNums){
        return true;
    }
    return false;
}

bool isScientific(string value){
    int length = value.length();
    int index = 0;
    bool pass = false;
    bool Decimal = false;
    bool allNums = true;
    bool foundE = false;
    if(value.length() < 1){
        return false;
    }
    if (value[0] == '+' || value[0] == '-'){
        value[0] = '1';
    }
    if(value.find('E') != string::npos){
        foundE = true;
        index = value.find('E');
        value[index] = '1';
        if (value[index+1] == '+' || value[index+1] == '-'){
            value[index+1] = '1';
        }
    }
    if (value.find('.') != string::npos){
        Decimal = true;
        index = value.find('.');
        value[index] = '1';
    }
    for(int i = 0; i < length; i++){
        if(NUMBERS.find(value[i]) == string::npos){
            allNums = false;
        }
    }
    if (Decimal && allNums && foundE){
        return true;
    }
    return false;
}

bool isHex(string value){
    // shortest length would be a digit or number followed by h, Length of 2
    if (value.length() < 2){
        return false;
    }
    for (int i = 0; i < value.length()-1; i++){
        if ((NUMBERS.find(value[i]) == string::npos) && (HEXA.find(value[i]) == string::npos)){
            return false;
        }
    }
    if (value[value.length()-1] != 'H'){
        return false;
    }
    return true;
}

bool isKeyword(string value){
    if (value.length() < 1){
        return false;
    }
    if (KEYWORDS.find(value) != string::npos){
        return true;
    }
    return false;
}

bool isStringLiteral(string value){
    bool validQuotes = false;
    if (value.length() < 3){
        return false;
    }
    if ((value[0] == '"') && (value.back() == '"')){
        validQuotes = true;
    }
    if (value.find(' ') != string::npos){
        return false;
    }
    for (int i = 1; i < value.length()-1; i++){
        if (value[i] == '"'){
            return false;
        }
    }
    if (validQuotes){
        return true;
    }
    return false;
}

bool isCharLiteral(string value){
    if (value.length() != 3){
        return false;
    }
    for (int i = 0; i < value.length()-1; i++){
        if ((HEXA.find(value[i]) != string::npos) && (NUMBERS.find(value[i]) != string::npos)){
            return false;
        }
    }
    if (value.back() != 'X'){
        return false;
    }
    return true;
}

bool isIdentifier(string value){
    if (value.length() < 2){
        return false;
    }
    if (isHex(value) || isKeyword(value) || isCharLiteral(value)){
        return false;
    }
    if (LETTERS.find(value[0]) == string::npos){
        return false;
    }
    for (int i = 1; i < value.length(); i++){
        if (LETTERS.find(value[i]) == string::npos && NUMBERS.find(value[i]) == string::npos && value[i] != '_'){
            return false;
        }
    }
    return true;
}

int main()
{
    int input_length = 0;
    string input;
    cin >> input_length;
    string answer = "";
    for(int i = 0; i < input_length; i++){
        cin >> input;
        cout << i+1 << ": ";
        if (isInt(input)){
            cout << "Integer\n";
        }
        else if (isDec(input)){
            cout << "Decimal\n";
        }
        else if (isScientific(input)){
            cout << "Scientific\n";
        }
        else if (isHex(input)){
            cout << "Hexadecimal\n";
        }
        else if (isKeyword(input)){
            cout << "Keyword\n";
        }
        else if (isStringLiteral(input)){
            cout << "String\n";
        }
        else if (isCharLiteral(input)){
            cout << "Character\n";
        }
        else if (isIdentifier(input)){
            cout << "Identifier\n";
        }
        else{
            cout << "INVALID!\n";
        }
    }
    return 0;
}

