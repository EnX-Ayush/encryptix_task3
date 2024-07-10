#include <iostream>
#include <vector>
using namespace std;

const int BoardSize = 3;
void PrintBoard(const vector<vector<char>>& board) 
{
    cout<<endl;
    for (int i = 0; i < BoardSize; ++i) 
    {
        for (int j = 0; j < BoardSize; ++j) 
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool rowWin(const vector<vector<char>>& board, char player)
{

    for (int i = 0; i < BoardSize; ++i) 
    {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    return false;

}

bool colWin(const vector<vector<char>>& board, char player)
{
    for (int i = 0; i < BoardSize; ++i) 
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
    }
    return false;
}

bool diagonalWin(const vector<vector<char>>& board, char player)
{
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[2][0] == player && board[1][1] == player && board[0][2] == player)
        return true;

    return false;
    
}

bool checkWin(const vector<vector<char>>& board, char player) 
{
 
    if(rowWin(board,player) or colWin(board,player) or diagonalWin(board,player))
    {
        return true;
    }
    return false;    
}

bool checkDraw(const vector<vector<char>>& board) 
{
    for (int i = 0; i < BoardSize; ++i) 
    {
        for (int j = 0; j < BoardSize; ++j) 
        {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

bool makeMove(vector<vector<char>>& board, int row, int col, char player) 
{
    if (row >= 0 && row < BoardSize && col >= 0 && col < BoardSize && board[row][col] == ' ') 
    {
        board[row][col] = player;
        return true;
    }
    return false;
}

int main() 
{
    vector<vector<char>> board(BoardSize, vector<char>(BoardSize, ' '));
    char CurrentPlayerSymbol = 'x';
    cout << "Tic-Tac-Toe";
    PrintBoard(board);
    while (true) 
    {
        int row, col;
        cout << "Player " << CurrentPlayerSymbol << " Please enter row(0-2) and column(0-2) : ";
        cin >> row >> col;

        if (makeMove(board, row, col, CurrentPlayerSymbol)) 
        {
            PrintBoard(board);

            if (checkWin(board, CurrentPlayerSymbol)) 
            {
                cout << "Player " << CurrentPlayerSymbol << " Wins!" << endl;
                break;
            }

            if (checkDraw(board)) 
            {
                cout << "It is a draw!" << endl;
                break;
            }

            CurrentPlayerSymbol = (CurrentPlayerSymbol == 'x') ? 'o' : 'x';
        } 
        else 
        {
            cout << "Invalid move " << endl;
        }
    }

    return 0;
}
