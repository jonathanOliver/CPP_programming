#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

//functions
#include "add_word.hpp"
#include "didnt_hang.hpp"
#include "dint_right.hpp"
#include "kick_word.hpp"
#include "letter_exists.hpp"
#include "print_erros.hpp"
#include "print_header.hpp"
#include "print_word.hpp"
#include "raffle_word.hpp"
#include "read_file.hpp"
#include "save_archive.hpp"

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