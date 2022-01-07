#include <iostream>
#include <vector>
#include <ofstream>
#include <string>

void save_archive(vector<string> new_list){
    std::ofstream archive;
    archive.open("words.txt");
    if(archive.is_open()){
        archive << new_list.size() << std::endl;

        for(std::string word : new_list){
            archive << word << std::endl;
        }
        archive.close();
    }
    else{
        std::cout << "Unable to access word bank." << std::endl;
        exit(0);
    }
}