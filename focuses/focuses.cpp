
//Exists Function C++ version 11
//Compile g++ focuses.cpp  -o focuses.out -std=c++11

#include <iostream>
#include <string>
#include <cctype>
#include <map>
using namespace std;

//global string
const string SECRET_WORD = "MELANCIA";

map <char, bool> kicking;

//validate kick exist in SECRET_WORD
bool kick_exists (char kick){
    
    for(char word : SECRET_WORD){
         if(kick == word ){
            return true;
        }
    }

    return false;
}




int main(){

    cout << "************************************************************************************************" << endl;
    cout << "********************************* Welcome to the Focuses game *********************************" << endl;
    cout << "************************************************************************************************" << endl;

    cout << "\n\n--- Type a letter ---\n" << endl;

    //não acertou
    bool didnt_hitt = true;

    //não enforcou
    bool didnt_hang = true;

    while ( didnt_hitt && didnt_hang ){
        for (char word : SECRET_WORD ){
            if(kicking[word]){
                cout << "\n\n";
                cout << "Letter "<< word << " has already been typed >> " << endl;
            }else{
                cout << "_ ";
            }
        }

        char kick;
        cin >> kick;

        kicking[kick] = true;

        if(kick_exists( kick )){
             cout << "congrats Your kick correct >> " << kick << endl;
        }else{
            cout << "Your kick incorrect (*~*) >> " << kick << endl;
        }

    }

}