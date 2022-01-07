
#include <vector>
#include <iostream>

extern std::vector<char> wrong_kicks;

void print_errors(){
    std::cout << "Wrong kicks: ";
    for(char letter: wrong_kicks){
        std::cout << letter << " ";
    }
    std::cout << std::endl;
}