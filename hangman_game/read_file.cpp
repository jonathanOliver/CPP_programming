#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>

#include "read_file.hpp"


std::vector<std::string> read_file(){
    std::ifstream archive;
    archive.open("words.txt");

    if(archive.is_open()){
        int quantity_words;
        archive >> quantity_words;

        std::vector<std::string> file_words;

        for(int i=0;i<quantity_words;i++){
            std::string read_word;
            archive >> read_word;
            file_words.push_back(read_word);
        }

        archive.close();
        return file_words;
    }
    else{
        std::cout << "Unable to access the word bank." << std::endl;
        exit(0);
    }
}
