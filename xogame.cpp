#include<iostream>
#include<cmath>
using namespace std;
void setEmptyBoard(int board[3][3]){
    for (int i = 0 ; i < 3 ; i++){
        for(int j = 0;j<3;j++){
            board[i][j] = -10;
        }

     }
}
void displayBoard(int board[3][3]){
     for (int i = 0 ; i < 3 ; i++){
        for(int j = 0;j<3;j++){
                            char playerSign;

            switch(board[i][j]){
          case -10:
                playerSign = '*';
                break;
          case 1:
            playerSign = 'X';
            break;
          case 2:
            playerSign = 'O';
            break;
            }
            cout<< '|' << playerSign << '|';
        }
       cout << endl;
     }

}
bool hasEmptyCellsInBoard(int board[3][3]){
   for (int i = 0 ; i < 3 ; i++){
        for(int j = 0;j<3;j++){
            if(board[i][j] == 0)
                return true;
        }

     }

     return false;
}
bool hasEmptyCellsInRow(int board[3][3],short rowIndex){
   for (int i = 0 ; i < 3 ; i++){
            if(board[rowIndex][i] == 0)
                return true;
     }
     return false;
}
short checkWinner(int board[3][3]){
    short diognal=0;
    short column = 0;
    short row = 0;

    for (int i = 0 ; i < 3 ; i++){
        for(int j = 0;j<3;j++){
              if(i == j){
                 diognal += board[i][j];
              }
              column += board[j][i];
              row += board[i][j];

        }
              if(column == 6)
                 return 2;
              if(column == 3)
                 return 1;
              if(row == 6)
                 return 2;
              if(row == 3)
                 return 1;
              column = 0;
              row = 0;

     }
     if(diognal == 3)
        return 1;
     if(diognal == 6)
        return 2;
     return 0;
}
int main(){
   int board[3][3];
   setEmptyBoard(board);
    int currentTurn = 1;

   theGame:
    displayBoard(board);
    int position;
    cout << "Enter Your Play Position:";
    cin >> position;
    int r  = (position-1)/3;
    int c = floor((position-1)%3);
    if(board[r][c] > -10){
        cout << "This position is already chosen , please choose another" << endl;
        currentTurn = board[r][c] == 1 ? 2 : 1;
        goto theGame;
    }
    board[r][c] = currentTurn;
    currentTurn = board[r][c] == 1 ? 2 : 1;
    cout << "Current Turn:" << currentTurn << endl;
  short winner = checkWinner(board);
    if(winner > 0){
                cout << "Player " << winner << " is won!" << endl;
                displayBoard(board);
                 return 0;
    }
        else goto theGame;
}
