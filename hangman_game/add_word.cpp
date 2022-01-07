#include <iostream>
#include <vector>
#include <string>

#include "save_archive.cpp"


void add_word(){
    std::cout << "Type the new word, using capital letters." << std::endl;
    std::string new_word;
    std::cin >> new_word;

    std::vector<string> list_words = read_file();
    list_words.push_back(new_word);

    save_archive(list_words);
}