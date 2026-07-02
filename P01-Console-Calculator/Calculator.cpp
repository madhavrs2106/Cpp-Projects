#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

/*===================================
  Function to get Valid Input
===================================*/
double getNumber(string message) {

    double number;
    while (true) {
        cout<<message; cin>>number;

        if (cin.fail()) {
            cout<<"\nInvalid input! Please enter a valid number.\n\n";

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else return number;
    }
}

/*=========================
  Addition
=========================*/
void addition() {
    double num1 = getNumber("Enter First Number  : ");
    double num2 = getNumber("Enter Second Number : ");

    cout<<"\nResult\n";
    cout<<num1<<" + "<<num2<<" = "<< num1+num2<<endl;
}

/*=========================
  Subtraction
=========================*/
void subtraction() {
    double num1 = getNumber("Enter First Number  : ");
    double num2 = getNumber("Enter Second Number : ");

    cout<<"\nResult\n";
    cout<<num1<<" - "<<num2<<" = "<<num1-num2<<endl;
}

/*=========================
  Multiplication
=========================*/
void multiplication() {
    double num1 = getNumber("Enter First Number  : ");
    double num2 = getNumber("Enter Second Number : ");

    cout<<"\nResult\n";
    cout<<num1<<" * "<<num2<<" = "<<num1*num2<<endl;
}

/*=========================
  Division
=========================*/
void division() {

    double numerator = getNumber("Enter Numerator   : ");
    double denominator;

    while (true) {
        denominator = getNumber("Enter Denominator : ");

        if (denominator == 0) {
            cout << "\nError! Division by zero is not allowed.\n\n";
        } else break;
    }

    cout<<"\nResult\n";
    cout<<numerator<<" / "<<denominator<<" = "<<numerator/denominator<<endl;
}

/*=========================
  Power
=========================*/
void power() {
    double base = getNumber("Enter Base     : ");
    double exponent = getNumber("Enter Exponent : ");

    cout<<"\nResult\n";
    cout<<base << " ^ "<<exponent<<" = "<<pow(base, exponent)<<endl;
}

/*=========================
  Main Program
=========================*/
int main() {
    char choice;
    char again;

    cout << "=====================================\n";
    cout << "       SIMPLE CALCULATOR (C++)\n";
    cout << "=====================================\n\n";

    do {
        cout << "Choose an Operation\n";
        cout << "----------------------------\n";
        cout << "+ : Addition\n";
        cout << "- : Subtraction\n";
        cout << "* : Multiplication\n";
        cout << "/ : Division\n";
        cout << "^ : Power\n";
        cout << "Q : Quit\n";

        cout<<"\nEnter Choice : "; cin>>choice;

        switch (choice) {
            case '+':
                addition();
                break;

            case '-':
                subtraction();
                break;

            case '*':
                multiplication();
                break;

            case '/':
                division();
                break;

            case '^':
                power();
                break;

            case 'Q':
            case 'q':
                cout << "\nThank you for using the calculator!\nMade by Madhav Shukla\n";
                return 0;

            default:
                cout << "\nInvalid Operation!\n";
        }

        cout << "\n------------------------------------\n";
        cout << "Do another calculation? (Y/N): ";
        cin >> again;

    } while (again == 'Y' || again == 'y');

    cout << "\nThank you for using the Calculator!\nMade by Madhav Shukla\n";

    return 0;
}