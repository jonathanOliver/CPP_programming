
#include <string>
#include <map>

extern std::string SECRET_WORD;
extern  std::map<char, bool> kicked;

bool didnt_right(){
    for(char letter : SECRET_WORD){
        if(!kicked[letter]){
            return true;
        }
    }
    return false;
}