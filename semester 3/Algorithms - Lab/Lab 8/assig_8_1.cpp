#include <bits/stdc++.h>
using namespace std;

bool issafe(vector<vector<int>> &board, int n,int row, int col)
{
    int irow = row;
    int icol = col;
    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 1)
        {
            return false;
        }
        row--;
        col--;
    }
    col = icol;
    row = irow;
    while (col >= 0)
    {
        if (board[row][col] == 1)
        {
            return false;
        }
        col--;
    }
    row = irow;
    col = icol;
    while (row < n && col >= 0)
    {
        if (board[row][col] == 1)
        {
            return false;
        }
        row++;
        col--;
    }
    return true;
}

bool solve(vector<vector<int>>&board,int n,int x)
{
    if(x>=n)
    {
        return true;
    }
    for (int row = 0; row < n; row++)
    {
        if(issafe(board,n,row,x))
        {
            board[row][x]=1;
            if(solve(board,n,x+1))
                return true;
            board[row][x]=0;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    if (n < 4)
    {
        cout << "no solution" << endl;
    }
    else
    {
        vector<vector<int>> board(n, vector<int>(n, 0));
        solve(board,n,0);
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
}