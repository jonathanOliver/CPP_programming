
#include <string>
std::string SECRET_WORD
std::map<char, bool> kicked;

string SECRET_WORD; 

bool didnt_right(){
    for(char letter : SECRET_WORD){
        if(!kicked[letter]){
            return true;
        }
    }
    return false;
}