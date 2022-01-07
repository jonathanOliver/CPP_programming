
#include <string>
#include <map>

std::string SECRET_WORD;
std::map<char, bool> kicked;

bool didnt_right(){
    for(char letter : SECRET_WORD){
        if(!kicked[letter]){
            return true;
        }
    }
    return false;
}