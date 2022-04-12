#include<iostream>
#include<stdlib.h>
using namespace std;

bool isWon(char player, char playerboard[][3]);
bool isDraw(char playerboard[][3]);
void displayBoard(char playerboard[][3]);
void makeAMove(char playerboard[][3], char player);

int main() {
    char playerboard[3][3] = { { ' ', ' ', ' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' } };
    displayBoard(playerboard);

    while (true) {
        makeAMove(playerboard, 'X');
        displayBoard(playerboard);
        if (isWon('X', playerboard)) {
            cout << "X player won" << endl;
            exit(0);
        }
        else if (isDraw(playerboard)) {
            cout << "No winner" << endl;
            exit(0);
        }

        makeAMove(playerboard, 'O');
        displayBoard(playerboard);
        if (isWon('O', playerboard)) {
            cout << "O player won" << endl;
            exit(0);
        }
        else if (isDraw(playerboard)) {
            cout << "No winner" << endl;
            exit(0);
        }
    }
    return 0;
}

bool isWon(char player, char playerboard[][3]){

    for (int i = 0; i<3; i++){
        if (playerboard[i][0] == player && playerboard[i][1] == player && playerboard[i][2] == player)
           return true;
        if (playerboard[0][i] == player && playerboard[1][i] == player && playerboard[2][i] == player)
           return true;
    }
    if (playerboard[0][0] == player && playerboard[1][1] == player && playerboard[2][2] == player)
       return true;
    if (playerboard[0][2] == player && playerboard[1][1] == player && playerboard[2][0] == player)
       return true;
    return false;
}

bool isDraw(char playerboard[][3]){

    int count = 0;
    for(int i = 0; i<3; i++){
       for (int j = 0; j<3; j++){
          if (playerboard[i][j] == 'X' || playerboard[i][j] == 'O')
             count++;
       }
    }
    if (count != 9)
       return false;
    if (!isWon('X', playerboard) && !isWon('O', playerboard))
       return true;
}

void displayBoard(char playerboard[][3]){

   cout << "-------------\n";
   for (int i = 0; i<3; i++){
       cout << "|";
       for (int j = 0; j<3; j++){
           cout << playerboard[i][j] << "|";
       }
      
       cout << endl;
       cout << "-------------\n";
      
   }
}


void makeAMove(char playerboard[][3], char player){

   while(true){
       cout << "Enter a row(0,1,2) for player " << player << " :";
       int b;
       cin >> b;
       int c;
       cout << "Enter a column(0,1,2) for player " << player << ":";
       cin >> c;
       if ( b < 0 || b > 2 || c < 0 || c > 2){
          cout << "Invalid Move\n";
       }
       else {
           if (playerboard[b][c] != 'X' && playerboard[b][c] != 'O'){
              playerboard[b][c] = player;
              break;
           }
           else {
               cout << "This cell is already occupied.Try a dufferent cell\n";
           }
       }    
   }
}