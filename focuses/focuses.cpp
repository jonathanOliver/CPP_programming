
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

//global string
const string SECRET_WORD = "MELANCIA";

bool kick_exists (char kick){

    int i = 0;
    for(i; i < SECRET_WORD.size(); i++){
        if(kick == SECRET_WORD[i] ){
            return true;
        }
    }
    
    return false;
}


int main(){

    //não acertou
    bool didnt_hitt = true;

    //não enforcou
    bool didnt_hang = true;

    while ( didnt_hitt && didnt_hang ){
        char kick;
        cin >> kick;

        if(kick_exists( kick )){
             cout << "congrats Your kick correct >> " << kick << endl;
        }else{
            cout << "Your kick incorrect (*~*) >> " << kick << endl;
        }

    }

}