#include <bits/stdc++.h>
using namespace std;

bool issafe(int row, int col, vector<string> board, int n)
{
    int irow = row;
    int icol = col;
    while (row >= 0 && col >= 0)           // check upper diagonal
    {
        if (board[row][col] == 'Q')
        {
            return false;
        }
        row--;
        col--;
    }
    col = icol;
    row = irow;
    while (col >= 0)                           //check coloumn 
    {
        if (board[row][col] == 'Q')
        {
            return false;
        }
        col--;
    }
    row = irow;
    col = icol;
    while (row < n && col >= 0)                //check row
    {
        if (board[row][col] == 'Q')
        {
            return false;
        }
        row++;
        col--;
    }
    return true;
}

void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (issafe(row, col, board, n))         // check the position of queen it is safe or not ??
        {
            board[row][col] = 'Q';              // if safe then place queen 
            solve(col + 1, board, ans, n);      // recursion call for next column
            board[row][col] = '.';              // bactrack step
        }
    }
}

vector<vector<string>> solveNQueen(int n)
{
    vector<vector<string>> ans;       //to store different boards
    vector<string> board(n);          // current board 
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }
    solve(0, board, ans, n);

    return ans;
}



int main()
{
    int n;
    cin >> n;
    if (n < 4)
    {
        cout << "no solution exists" << endl;
    }
    else
    {
        vector<vector<string>> vec = solveNQueen(n);
        for (int i = 0; i < vec.size(); i++)
        {
            for (int j = 0; j < vec[i].size(); j++)      // print different board
            {
                cout << vec[i][j] << endl;
            }
            cout << endl;
        }

        cout << " count = " << vec.size();
    }
    return 0;
}