#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

//functions
#include "add_word.cpp"
#include "didnt_hang"
#include "dint_right.cpp"
#include "kick_word.cpp"
#include "letter_exists.cpp"
#include "print_erros.cpp"
#include "print_header.cpp"
#include "print_word.cpp"
#include "raffle_word.cpp"
#include "read_file.cpp"
#include "save_archive.cpp"

using namespace std;

string SECRET_WORD; 
map<char, bool> kicked;
vector<char> wrong_kicks;

int main () {
    print_header();

    read_file();
    raffle_word();

    while(didnt_right() && didnt_hang()){
        print_errors();

        print_word();

        kick_word();
    }

    cout << "End of the game!" << endl;
    cout << "The secret word was: " << SECRET_WORD << endl;
    if(didnt_right()){
        cout << "You lost! Try again!" << endl;
    }
    else{
        cout << "Congratulations! You got the secret word right!" << endl;

        cout << "Do you want to add a new word to the bank? (Y/N) ";
        char response;
        cin >> response;
        if(response == 'Y'){
            add_word();
        }
    }
    
    cin.get();
}