
#include <string>

std::string SECRET_WORD;

bool letter_exists(char kick){
    for(char letter : SECRET_WORD){
        if(kick == letter){
            return true;
        }
    }
    return false;
}