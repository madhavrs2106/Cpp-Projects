#include <iostream>
#include <random>

using namespace std;

/*===============================
    create Single line
===============================*/
void singleLine() {
    for (int i=1; i<=50; i++) { cout<<"-"; }
    cout<<endl;
}

/*===============================
    creates Double line
===============================*/
void doubleLine() {
    for (int i=1; i<=50; i++) { cout<<"="; }
    cout<<endl;
}

/*===============================
    Quiting Text
===============================*/
void quitGame() {
    singleLine();
    cout<<" >>   Quiting Game...\n"<<endl;
    doubleLine();
}

int main() {

    // ===== Heading
    cout<<"==================================================\n";
    cout<<"            Number Guessing Game (C++)\n";
    cout<<"==================================================\n\n";
    char start;
    cout<<"Start Guessing (Y,N) : "; cin>>start;

    // ===== Starts Game
    if (start=='Y' || start=='y') {

        // ===== Generating Random number
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dist(1,100);
        int generatedNumber = dist(gen);

        // ===== Guess Number
        int guessedNumber;
        int attempts=1;
        singleLine();

        do {
            cout<<" Guess Number : "; cin>>guessedNumber;

            // ===== for Guessed Number is Greater
            if (guessedNumber>generatedNumber) {
                cout<<"  --> Too High...\n"<<endl;
            }

            // ===== for Guessed Number is Lower
            else if (guessedNumber<generatedNumber) {
                cout <<"  --> Too Low...\n"<<endl;
            }

            // ===== for Guessed Number is Generated Number
            else if (guessedNumber==generatedNumber) {
                cout<<"\t --> You Got it..."<<endl;
                cout<<"\t --> Attempts  :  "<<attempts<<"\n"<<endl;
                quitGame();
                break;
            }

            // ===== Updating attempts
            attempts++;
            singleLine();

        } while (guessedNumber!=generatedNumber);
    }

    // ===== Quits Game
    else if (start=='N' || start=='n') { quitGame(); }

    else {
        cout<<" >>  Warning:  Choose from (Y for yes and N for no)"<<endl;
        cout<<" >>  Restart to Play...\n"<<endl;
        doubleLine();
    }

    cout << "\nThank you for Playing!\nMade by Madhav Shukla\n";

    return 0;
}