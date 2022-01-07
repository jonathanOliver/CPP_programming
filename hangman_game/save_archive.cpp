#include <iostream>
#include <vector>
#include <ofstream>
#include <string>

void save_archive(vector<string> new_list){
    std::ofstream archive;
    archive.open("words.txt");
    if(archive.is_open()){
        std::archive << new_list.size() << std::endl;

        for(std::string word : new_list){
            std::archive << word << std::endl;
        }
        std::archive.close();
    }
    else{
        std::cout << "Unable to access word bank." << std::endl;
        exit(0);
    }
}