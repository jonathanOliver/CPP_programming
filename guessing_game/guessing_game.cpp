#include <iostream>
using namespace std;

int main(){
    
    cout << "************************************************************************************************" << endl;
    cout << "********************************* Welcome to the guessing game *********************************" << endl;
    cout << "************************************************************************************************" << endl;
    
    //const var
    //const int NUMBER_SECRET = 90;
    const int NUMBER_SECRET = rand() % 100 + 1;

    //vars
    int total_attempt = 0;
    bool incorrect = true;

    int dificult;
    cout << "\n\n";
    cout << "-----------------------------------" << endl;
    cout << "|          Choose the level       |" << endl;
    cout << "| 1 - EASY | 2- NORMAL | 3 - HARD |" << endl;
    cout << "-----------------------------------" << endl;
    cout << "Level >> ";
    cin >> dificult;
    cout << "-----------------------------------" << endl;

    switch(dificult){
        case 1: 
             total_attempt = 10;
             break;
        case 2:
             total_attempt = 5;
             break;
        case 3:
             total_attempt = 3;
             break;
        default :
             total_attempt = 10;
             break;
    }

    int attempt = 0;

    while(incorrect){
        attempt++;
        if(attempt > total_attempt){
            cout<< "End of the game!!! (*~*)" << endl;
            cout<< "Total exceeded attempts according to difficulty level >> "<< attempt << endl;
            break;
        }

        cout << "dificult " << dificult << endl;
        cout << "Attempt " << attempt << endl;
        cout<< "What's your kick?" << endl;
        //vars        
        int kick;

        cin >> kick;
    
        //conditionals vars
        bool correct = kick == NUMBER_SECRET;
        bool larger = kick > NUMBER_SECRET;

        if(correct){
            cout<< "Congratulations, Your Kick is Correct (*--*)" << endl;
            cout << "Your kick value is >>> " << kick << endl;
            incorrect = false;
            
        }else if(larger){
            cout<< "Your kick value is larger!!! (*~*)" << endl;
        }else{
            cout<< "Your kick value is smaller!!! (*~*)" << endl;
        }

       
    }

    cout<< "End of the game!!!" << endl;
    cout<< "You got it right in a number of attempts "<< attempt << endl;
    
}


 


