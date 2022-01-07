#include<iostream>
#include<map>
#include<vector>

#include "letter_exists.hpp"
 
extern std::map<char, bool> kicked;
extern std::vector<char> wrong_kicks;

void kick_word(){
    std::cout << "Your kick: ";
    char kick;
    std::cin >> kick;

    kicked[kick] = true;

    if(letter_exists(kick)){
        std::cout << "You're right! your kick is in the word." << std::endl;
    }
    else{
        std::cout << "You missed! Your kick is not in the word." << std::endl;
        wrong_kicks.push_back(kick);
    }
    std::cout << std::endl;
}
