#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    
    cout << "************************************************************************************************" << endl;
    cout << "********************************* Welcome to the guessing game *********************************" << endl;
    cout << "************************************************************************************************" << endl;

    srand(time(NULL));
    const int NUMBER_SECRET = rand() % 100;

    //vars
    double point = 1000.0;
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
            cout<< "End of the game, Restart game! chosen difficulty does not exist!!!!! (*~*)" << endl;
            break;
    }

    int attempt = 0;

    while(incorrect){
        attempt++;
        if(attempt > total_attempt){
            cout<< "End of the game,!!! (*~*)" << endl;
            cout<< "Total exceeded attempts according to difficulty level >> "<< attempt << endl;
            point = 0.00;
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
            point = point - ( abs(kick - NUMBER_SECRET) /2.0);
        }else{
            cout<< "Your kick value is smaller!!! (*~*)" << endl;
            point = point - ( abs(kick - NUMBER_SECRET) /2.0);
        }

       
    }

    cout<< "End of the game!!!" << endl;
    cout<< "You got it right in a number of attempts "<< attempt << endl;
    cout<< "Your Points >>  "<< point << endl;
    
}


 


