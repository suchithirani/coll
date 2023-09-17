#include <iostream>
using namespace std;
//TacTacToe
void Board(char board[4][4]) {
    cout<<endl<<endl;

    for(int i=0;i<3;i++) {
        for(int j=0; j<3;j++) {
            cout<<board[i][j]
            if (j<2) 
            cout << " | ";
        }
        cout<<endl;
        if (i<2) 
        cout<<"---------"<< endl;
    }
    cout<<endl;
}

bool Win(char board[4][4], char player) {
    
    for(int i = 0; i < 3; ++i) {
        if(board[i][0]==player && board[i][1]==player && board[i][2]==player) 
        return true; 
        if(board[0][i]==player && board[1][i]==player && board[2][i]==player) 
        return true; 
    }
    if(board[0][0]==player && board[1][1]==player && board[2][2]==player) 
        return true;
    if(board[0][2]==player && board[1][1]==player && board[2][0]==player)
        return true;

    return false;
}


bool Tie(char board[4][4]) {
    for (int i =0;i<3;i++) {
        for (int j=0;j<3;j++) {
            if (board[i][j]==' ')
            return false;
        }
    }
    return true;
}

int main() {
    cout<<endl<<"Welcome to the world of TicTacToe!"<<endl<<endl;
    char play;
    do
    {
    
    char board[4][4] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };
    string s1,s2;
    cout<<"Enter your names to play game"<<endl;
    cin>>s1>>s2;
    cout<<endl;

    char currentMove;
    cout<<"With which character you like to start your game(X,O)?: ";
    cin>>currentMove;
    char temp=currentMove;
    int r,c,i=0;
           
    while (true) {
        Board(board);
        if(i%2==0)
        {

            cout<<s1<<" enter your move (row and column): ";
        }
        else
        {
            cout<<s2<<" enter your move (row and column): ";
        }
       
        
        cin >>r>>c;
        cout<<endl;
        i= (i==1)?0:1;

       
        if (r<0 || r>=3 || c<0 || c>=3 || board[r][c]!= ' ') {
            cout << "Invalid move. Try again." << endl;
            i= (i==1)?0:1;
            continue;
        }
   
        board[r][c] = currentMove;

        if (Win(board,currentMove)) {
            Board(board);
            if(currentMove==temp)
            {
                cout<<" Congratulations! "<<s1<<" you won the game."<<endl;
            }
            else{
            cout<<" Congratulations! "<<s2<<" you won the game."<<endl;
            }
            break;
        }

        if (Tie(board)) {
            Board(board);
            cout<<"It's a tie!. Better luck next time."<<endl;
            break;
        }
    
        currentMove=(currentMove=='X')?'O':'X';
    }
    cout<<"want to play another game(y,n):";
    cin>>play;
    }
    while(play=='Y' ||play=='y');
    return 0;
}
