#include <iostream>
#include <string>
#include <map>

std::string SECRET_WORD;
std::map<char, bool> kicked;

void print_word(){
    for(char letter : SECRET_WORD){
        if(kicked[letter]){
            std::cout << letter << " ";
        }
        else{
            std::cout << "_ ";
        }
    }
    std::cout << std::endl;
}