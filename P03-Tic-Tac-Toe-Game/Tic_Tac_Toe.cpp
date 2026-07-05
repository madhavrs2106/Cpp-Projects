#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer = 'X';

/*===================================
    blankspaces & lines function
===================================*/
string blankspaces(const int s) {
    string spaces = "";
    for (int i=0; i<s; i++) { spaces += " "; }
    return spaces;
}
string lines(const int l, char ch, const bool nextLine) {
    string line = "";
    for (int i=0; i<l; i++) { line += ch; }
    if (nextLine) { line +="\n"; }
    return line;
}

/*===================================
        Initialize board
===================================*/
void initializeBoard() {
    char position = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) { board[i][j] = position++; }
    }
}

/*===================================
           Display board
===================================*/
void displayBoard() {
    cout << "\n";
    int row = 0;
    int col = 0;

    for (int l=1; l<=11; l++) {

        if (l==1 || l==3 || l==5 || l==7 || l==9 || l==11) {
            for (int t=1; t<=3; t++) {
                if (t==1) {
                    cout<<blankspaces(12)<<"|";
                } else if (t==2) {
                    cout<<blankspaces(7)<<"|";
                } else if (t==3) {
                    cout<<endl;
                }
            }
        }

        else if (l==4 || l==8) {
            for (int t=1; t<=3; t++) {
                if (t==1) {
                    cout<<blankspaces(5)<<lines(7,'-',false)<<"|";
                } else if (t==2) {
                    cout<<lines(7,'-',false)<<"|";
                } else if (t==3) {
                    cout<<lines(7,'-',true);
                }
            }
        }

        else if (l==2 || l==6 || l==10) {
            for (int t=1; t<=3; t++) {
                char value = board[row][col];
                if (value != 'X' && value != 'O') {
                    value = ' ';
                }

                if (t==1) {
                    cout<<blankspaces(8)<<value<<blankspaces(3)<<"|";
                } else if (t==2) {
                    cout<<blankspaces(3)<<value<<blankspaces(3)<<"|";
                } else if (t==3) {
                    cout<<blankspaces(3)<<value<<blankspaces(3)<<endl;
                }
                col++;
            }
        }

    }

    cout << "\n";
}

/*===================================
             Place move
===================================*/
bool makeMove(int choice) {
    if (choice < 1 || choice > 9)
        return false;

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (board[row][col] == 'X' || board[row][col] == 'O')
        return false;

    board[row][col] = currentPlayer;

    return true;
}

/*===================================
           Check winner
===================================*/
bool checkWinner() {
    // Rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
            return true;
    }

    // Columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i])
            return true;
    }

    // Main diagonal
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return true;

    // Secondary diagonal
    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return true;

    return false;
}

/*===================================
            Check draw
===================================*/
bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') { return false; }
        }
    }

    return true;
}

/*===================================
           Change player
===================================*/
void switchPlayer() {
    if (currentPlayer == 'X') {
        currentPlayer = 'O';
    }
    else {
        currentPlayer = 'X';
    }
}

int main() {
    string player1, player2, currentPlayerName;
    cout<<"  >>  Player-1 Name :- "; cin>>player1;
    cout<<"  >>  Player-2 Name :- "; cin>>player2;

    initializeBoard();

    while (true) {
        cout<<lines(40,'=',true);
        displayBoard();
        int choice;

        // ========== Updating Player Name
        if (currentPlayer=='X') {
            currentPlayerName = player1;
        } else {
            currentPlayerName = player2;
        }

        cout<<"--->> "<<currentPlayerName<<" : "; cin >> choice;

        // ========== Invalid Move
        if (!makeMove(choice)) {
            cout << "\n--->> Invalid move! Try again.\n";
            continue;
        }

        // ========== Checking Winner
        if (checkWinner()) {
            cout<<lines(40,'=',true);
            displayBoard();
            cout<<
                lines(40,'-',true)<<
                "--->>  "<<currentPlayerName<<" Won !!\n"<<
                lines(40,'=',true)
            <<endl;
            break;
        }

        // ========== Checking Draw
        if (checkDraw()) {
            cout<<lines(40,'=',true);
            displayBoard();
            cout<<
                lines(40,'-',true)<<
                "--->>  Match Draw !!\n"<<
                lines(40,'=',true)
            <<endl;
            break;
        }

        // ========== Switching Player
        switchPlayer();
    }

    return 0;
}