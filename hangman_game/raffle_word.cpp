#include <iostream>
#include <vector>
#include <ctime>
#include <string>

std::string SECRET_WORD; 

void raffle_word(){
    std::vector<string> words = read_file();

    srand(time(NULL));
    int raffled_index = rand() % words.size();

    std::SECRET_WORD = words[raffled_index];
}