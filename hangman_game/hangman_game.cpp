#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

string SECRET_WORD; 
map<char, bool> kicked;
vector<char> wrong_kicks;

bool letter_exists(char kick){
    for(char letter : SECRET_WORD){
        if(kick == letter){
            return true;
        }
    }
    return false;
}

bool didnt_right(){
    for(char letter : SECRET_WORD){
        if(!kicked[letter]){
            return true;
        }
    }
    return false;
}

bool didnt_hang(){
    return wrong_kicks.size() < 5;
}

void print_header(){
    cout << "*********************" << endl;
    cout << "*** Hangman game ****" << endl;
    cout << "*********************" << endl;
    cout << endl;
}

void print_errors(){
    cout << "Wrong kicks: ";
    for(char letter: wrong_kicks){
        cout << letter << " ";
    }
    cout << endl;
}

void print_word(){
    for(char letter : SECRET_WORD){
        if(kicked[letter]){
            cout << letter << " ";
        }
        else{
            cout << "_ ";
        }
    }
    cout << endl;
}

void kick_word(){
    cout << "Your kick: ";
    char kick;
    cin >> kick;

    kicked[kick] = true;

    if(letter_exists(kick)){
        cout << "You're right! your kick is in the word." << endl;
    }
    else{
        cout << "You missed! Your kick is not in the word." << endl;
        wrong_kicks.push_back(kick);
    }
    cout << endl;
}

vector<string> read_file(){
    ifstream archive;
    archive.open("words.txt");

    if(archive.is_open()){
        int quantity_words;
        archive >> quantity_words;


        vector<string> file_words;

        for(int i=0;i<quantity_words;i++){
            string read_word;
            archive >> read_word;
            file_words.push_back(read_word);
        }

        archive.close();
        return file_words;
    }
    else{
        cout << "Unable to access the word bank." << endl;
        exit(0);
    }
}

void raffle_word(){
    vector<string> words = read_file();

    srand(time(NULL));
    int indice_sorteado = rand() % words.size();

    SECRET_WORD = words[indice_sorteado];
}

void save_archive(vector<string> new_list){
    ofstream archive;
    archive.open("words.txt");
    if(archive.is_open()){
        archive << new_list.size() << endl;

        for(string word : new_list){
            archive << word << endl;
        }
        archive.close();
    }
    else{
        cout << "Unable to access word bank." << endl;
        exit(0);
    }
}

void add_word(){
    cout << "Type the new word, using capital letters." << endl;
    string new_word;
    cin >> new_word;

    vector<string> list_words = read_file();
    list_words.push_back(new_word);

    save_archive(list_words);
}

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