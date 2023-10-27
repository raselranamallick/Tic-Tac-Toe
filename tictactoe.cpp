#include<iostream>
#include<vector>
using namespace std;

//
vector<char> board(9,'-');
bool gameRunning = true;
char currentPlayer = 'X';
char winner = '\0';

//print the gameboard
void printBoard(){
    cout<<board[0]<<" | "<<board[1]<<" | "<<board[2]<<endl;
    cout<<"---------"<<endl;
    cout<<board[3]<<" | "<<board[4]<<" | "<<board[5]<<endl;
    cout<<"---------"<<endl;
    cout<<board[6]<<" | "<<board[7]<<" | "<<board[8]<<endl;
}

//take user input
void playerInput(){
    cout<<"Enter a number between 1-9 "<<endl;
    int inp;
    cin >> inp;
    if(inp>=1 && inp<=9 && board[inp-1]=='-')
        board[inp-1] = currentPlayer;
    else
        cout<<"Player is already in that spot!"<<endl;
}

//check for win or tie
bool checkHorizontal(){
    if(board[0]==board[1] && board[0]==board[2] && board[0]!='-'){
        winner = currentPlayer;
        return true;
    }
    else if(board[3]==board[4] && board[3]==board[5]  && board[3]!='-'){
        winner = currentPlayer;
        return true;
    }
    else if(board[6]==board[7] && board[6]==board[8]  && board[6]!='-'){
        winner = currentPlayer;
        return true;
    }
    else
        return false;
}

bool checkVertical(){
    if(board[0]==board[3] && board[0]==board[6] && board[0]!='-'){
        winner = currentPlayer;
        return true;
    }
    else if(board[1]==board[4] && board[1]==board[7] && board[1]!='-'){
        winner = currentPlayer;
        return true;
    }
    else if(board[2]==board[5] && board[2]==board[8] && board[2]!='-'){
        winner = currentPlayer;
        return true;
    }
    else   
        return false;
}

bool checkDiag(){
    if(board[0]==board[4] && board[0]==board[8] && board[0]!='-'){
        winner = currentPlayer;
        return true;
    }
    else if(board[2]==board[4] && board[2]==board[6] && board[2]!='-'){
        winner = currentPlayer;
        return true;
    }
    else    
        return false;
}

void checkTie(){
    for(int i=0;i<9;i++){
        if(board[i]=='-')
            return;
    }
    printBoard();
    cout<<"It is a tie! "<<endl;
    gameRunning = false;
}

void checkWin(){
    if(checkDiag() || checkHorizontal() || checkVertical()){
        printBoard();
        cout<<"The winner is "<<winner<<endl;
        gameRunning = false;
    }
}

//switch player
void switchPlayer(){
    if(currentPlayer == 'X')
        currentPlayer = 'O';
    else
        currentPlayer = 'X'; 
}

//check for win or tie again

int main(){
    while(gameRunning){
        printBoard();
        playerInput();
        checkWin();
        checkTie();
        switchPlayer();
    }    
    return 0;
}