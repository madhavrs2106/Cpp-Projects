#include <iostream>
using namespace std;

// --- Creates n whitespaces
string whitespaces(const int n) {
    string blankspaces = "";
    for (int i=0; i<n; i++) blankspaces += " ";
    return blankspaces;
}
// --- Creates n line with character linestyle
string line(const int n, const char linestyle) {
    string linespaces = "";
    for (int i=0; i<n; i++) linespaces += linestyle;
    return linespaces;
}

// --- Creating a class with all Advanced-Patterns
class Patterns {
public:

    // --- List of all Advanced-Patterns
    static void PatternList() {
        cout<<line(50,'=')<<
            "\n-->  Advanced-Patterns List\n\n"<<
            line(17,'-')<<" Solid Patterns "<<line(17,'-')<<endl<<
            whitespaces(10)<<"1. Solid Pyramid.\n"<<
            whitespaces(10)<<"2. Solid Diamond.\n"<<
            whitespaces(10)<<"3. Solid Butterfly.\n\n"<<
            line(17,'-')<<" Hollow Patterns "<<line(16,'-')<<endl<<
            whitespaces(10)<<"4. Hollow Pyramid.\n"<<
            whitespaces(10)<<"5. Hollow Diamond.\n"<<
            whitespaces(10)<<"6. Hollow Butterfly.\n\n"<<
            line(17,'-')<<" Other Patterns "<<line(17,'-')<<endl<<
            whitespaces(10)<<"7. Ice-Cream Cone\n\n"<<
            whitespaces(10)<<"8. Exit...\n"
        <<line(50,'=')<<endl;
    }

    // --- 1. Solid Pyramid
    static void SolidPyramid(const int n) {
        for (int line=1; line<=n; line++) {
            for (int space=1; space<=n-line; space++) cout<<"   ";
            for (int star=1; star<=line; star++) cout<<" * ";
            for (int star=1; star<=line-1; star++) cout<<" * ";
            cout<<endl;
        }
    }

    // --- 2. Solid Diamond
    static void SolidDiamond(const int n) {
        for (int line=1; line<=2*n-1; line++) {
            if (line<=n) {
                for (int spaces=1; spaces<=n-line; spaces++) cout<<"   ";
                for (int star=1; star<=line; star++) cout<<" * ";
                for (int star=1; star<=line-1; star++) cout<<" * ";
            }
            else {
                for (int spaces=1; spaces<=line-n; spaces++) cout<<"   ";
                for (int stars=1; stars<=n-(line-n); stars++) cout<<" * ";
                for (int stars=1; stars<=n-(line-n)-1; stars++) cout<<" * ";
            }
            cout<<endl;
        }
    }

    // --- 3. Solid Butterfly
    static void SolidButterfly(const int n) {
        for (int line=1; line<=2*n-1; line++) {
            if (line<=n) {
                for (int stars=1; stars<=line; stars++) cout<<" *";
                for (int spaces=1; spaces<=(2*n)-(2*line); spaces++) cout<<"  ";
                for (int stars=1; stars<=line; stars++) cout<<" *";
            }
            else {
                for (int stars=1; stars<=n-(line-n); stars++) cout<<" *";
                for (int spaces=1; spaces<=2*(line-n); spaces++) cout<<"  ";
                for (int stars=1; stars<=n-(line-n); stars++) cout<<" *";
            }
            cout<<endl;
        }
    }

    // --- 4. Hollow Pyramid
    static void HollowPyramid(const int n) {
        for (int line=1; line<=n; line++) {
            for (int space=1; space<=n-line; space++) cout<<"   ";
            for (int stars=1; stars<=line; stars++) {
                if (line == n) cout<<" * ";
                else {
                    if (stars == 1) cout<<" * ";
                    else cout<<"   ";
                }
            }
            for (int stars=1; stars<=line-1; stars++) {
                if (line == n) cout<<" * ";
                else {
                    if (stars == line-1) cout<<" * ";
                    else cout<<"   ";
                }
            }
            cout<<endl;
        }
    }

    // --- 5. Hollow Diamond
    static void HollowDiamond(const int n) {
        for (int line=1; line<=2*n-1; line++) {
            if (line<=n) {
                for (int spaces=1; spaces<=n-line; spaces++) cout<<"   ";
                for (int stars=1; stars<=line; stars++) {
                    if (stars == 1) cout<<" * "; else cout<<"   ";
                }
                for (int stars=1; stars<=line-1; stars++) {
                    if (stars == line-1) cout<<" * "; else cout<<"   ";
                }
            }
            else {
                for (int spaces=1; spaces<=line-n; spaces++) cout<<"   ";
                for (int stars=1; stars<=n-(line-n); stars++) {
                    if (stars == 1) cout<<" * "; else cout<<"   ";
                }
                for (int stars=1; stars<=n-(line-n)-1; stars++) {
                    if (stars == n-(line-n)-1) cout<<" * "; else cout<<"   ";
                }
            }
            cout<<endl;
        }
    }

    // --- 6. Hollow Butterfly
    static void HollowButterfly(const int n) {
        for (int line=1; line<=2*n-1; line++) {
            if (line<=n) {
                for (int stars=1; stars<=line; stars++) {
                    if (stars == 1 || stars == line) cout<<" *";
                    else cout<<"  ";
                }
                for (int spaces=1; spaces<=(2*n)-(2*line); spaces++) cout<<"  ";
                for (int stars=1; stars<=line; stars++) {
                    if (stars == 1 || stars == line) cout<<" *";
                    else cout<<"  ";
                }
            }
            else {
                for (int stars=1; stars<=n-(line-n); stars++) {
                    if (stars == 1 || stars == n-(line-n)) cout<<" *";
                    else cout<<"  ";
                }
                for (int spaces=1; spaces<=2*(line-n); spaces++) cout<<"  ";
                for (int stars=1; stars<=n-(line-n); stars++) {
                    if (stars == 1 || stars == n-(line-n)) cout<<" *";
                    else cout<<"  ";
                }
            }
            cout<<endl;
        }
    }

    // --- 7. Ice-Cream Cone
    static void IceCreamCone(const int n) {
        for (int line=1; line<=2*n-1; line++) {
            if (line<=n) {
                for (int spaces=1; spaces<=n-line; spaces++) cout<<"  ";
                for (int stars=1; stars<=line; stars++) {
                    if (line == n) cout<<" *";
                    else {
                        if (stars == 1) cout<<" *"; else cout<<"  ";
                    }
                }
                for (int stars=1; stars<=line-1; stars++) {
                    if (line == n) cout<<" *";
                    else {
                        if (stars == line-1) cout<<" *"; else cout<<"  ";
                    }
                }
            }
            else {
                for (int spaces=1; spaces<=line-n; spaces++) cout<<"  ";
                for (int stars=1; stars<=n-(line-n); stars++) cout<<" *";
                for (int stars=1; stars<=n-(line-n)-1; stars++) cout<<" *";
            }
            cout<<endl;
        }
    }

};

int main() {

    Patterns::PatternList();
    int choice;

    do {
        // --- Inputting Choice
        cout<<" -->  Enter Choice: "; cin>>choice;

        // --- Perform Choice
        switch (choice) {
            int number;

            // --- 1. Solid Pyramid
            case 1:
                cout<<" --> Enter Number: "; cin>>number;
                cout<<endl;
                Patterns::SolidPyramid(number);
                cout<<endl<<line(50,'=')<<endl;
                break;

            // --- 2. Solid Diamond
            case 2:
                cout<<" --> Enter Number: "; cin>>number;
                cout<<endl;
                Patterns::SolidDiamond(number);
                cout<<endl<<line(50,'=')<<endl;
                break;

            // --- 3. Solid Butterfly
            case 3:
                cout<<" --> Enter Number: "; cin>>number;
                cout<<endl;
                Patterns::SolidButterfly(number);
                cout<<endl<<line(50,'=')<<endl;
                break;

            // --- 4. Hollow Pyramid
            case 4:
                cout<<" --> Enter Number: "; cin>>number;
                cout<<endl;
                Patterns::HollowPyramid(number);
                cout<<endl<<line(50,'=')<<endl;
                break;

            // --- 5. Hollow Diamond
            case 5:
                cout<<" --> Enter Number: "; cin>>number;
                cout<<endl;
                Patterns::HollowDiamond(number);
                cout<<endl<<line(50,'=')<<endl;
                break;

            // --- 6. Hollow Butterfly
            case 6:
                cout<<" --> Enter Number: "; cin>>number;
                cout<<endl;
                Patterns::HollowButterfly(number);
                cout<<endl<<line(50,'=')<<endl;
                break;

            // --- 7. Ice-Cream Cone
            case 7:
                cout<<" --> Enter Number: "; cin>>number;
                cout<<endl;
                Patterns::IceCreamCone(number);
                cout<<endl<<line(50,'=')<<endl;

        }

    } while (choice != 8);

    return 0;
}