#include <iostream>
#include <vector>
#include <ctime>
#include <string>

#include "read_file.hpp"

extern std::string SECRET_WORD; 

void raffle_word(){
    std::vector<std::string> words = read_file();

    srand(time(NULL));
    int raffled_index = rand() % words.size();

    SECRET_WORD = words[raffled_index];
}