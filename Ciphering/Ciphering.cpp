#include <iostream>
#include <string>
#include <vector>
#include <cctype>

std::vector<char> WordtoList(std::string Input) {
    std::vector<char> CharList = {};
    for( char c : Input) {
        CharList.push_back(std::tolower(c));
    } 
    return CharList;
}

std::string ListtoWord(std::vector<char> OutputList, int ifBacon) {
    std::string Output = "";

    for (char c : OutputList) {
        Output += c;
    }
    if (ifBacon == 2) {
    for (int in = 5; in < Output.size(); in += 6 )
        Output.insert(in, " ");
    }

return Output;
}

int main() {

std::string Input = "";
std::cout << "Input a word you would like to cipher.\n";
std::cin >> Input;
std::cout << "Choose 1-2 which Cipher you would like to use.\n";
int NumberedInput;
std::cout << "1. Caesar Cipher\n";
std::cout << "2. Bacon Cipher\n";
std::cin >> NumberedInput;

std::vector<char> AlphaList = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
std::vector<std::string> BaconMap = { "AAAAA", "AAAAB", "AAABA", "AAABB", "AABAA", "AABAB", "AABBA", "AABBB", "ABAAA", "ABAAB","ABABA", "ABABB", "ABBAA", "ABBAB", "ABBBA"
    , "ABBBB", "BAAAA", "BAAAB", "BAABA", "BAABB","BABAA", "BABAB", "BABBA", "BABBB", "BBAAA", "BBAAB"};
std::vector<char> InputList = WordtoList(Input);
std::vector<char> OutputList = {};

if (NumberedInput == 1) { // Caesar Cipher
    int Shift;
    std::cout << "Input a Number Shift (Can ONLY be a integer):\n";
    std::cin >> Shift;
     int index2 = 0;
     while (index2 < InputList.size()) {
        char currentChar = InputList[index2];
        bool found = false;
        for (int f = 0; f < AlphaList.size(); f++) {
            if (currentChar == AlphaList[f]) {
                int Shifted = (f + Shift) % AlphaList.size();
                OutputList.push_back(AlphaList[Shifted]);
                found = true;
                break;
            }
        }
        if (!found) {
            OutputList.push_back(currentChar);
         }
         index2++;
     }
     std::cout << "Ciphered Text: " << ListtoWord(OutputList, NumberedInput) << std::endl;
}      

if (NumberedInput == 2) { // Bacon Cipher
    char letter1;
    char letter2;
    std::cout << "Input what represents A\n";
    std::cin >> letter1;
    std::cout << "Input what represents B\n";
    std::cin >> letter2;

    for (char c: InputList) {
        c = tolower(c);
        if (c >= 'a' && c <= 'z') {
            int locat = c - 'a';
            std::string code = BaconMap[locat];
            for (char letter : code) {
                if (letter == 'A') {
                    OutputList.push_back(letter1);
                } else {
                    OutputList.push_back(letter2);
                }
            }
        }
    }
    std::cout << "Bacon Ciphered Text: " << ListtoWord(OutputList, NumberedInput) << std::endl;
    }

}
