#include <bits/stdc++.h>
using namespace std;

vector<int> getPositions(vector<int> &psol, int n)
{
    int chess[n][n];
    int l = psol.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            chess[i][j] = 0;
        }
    }

    vector<int> list;
    if (l == 0)
    {
        for (int i = 0; i < n; i++)
            list.push_back(i);
    }
    else if (l == n - 1)
    {
        cout << "Next column is not present" << endl;
    }
    else
    {
        int row;
        for (int i = 0; i < l; i++)
        {
            row = psol[i]; // i is column
            chess[row][i] = 9;
            // for row restriction
            for (int j = 0; j < n; j++)
            {
                if (chess[row][j] != 9)
                    chess[row][j] = 1;
            }
            // for column restriction
            for (int j = 0; j < n; j++)
            {
                if (chess[j][i] != 9)
                    chess[j][i] = 1;
            }

            // for diagonal restriction
            int r = row, c = i;
            while (r >= 0 && c < n)
            {
                if (chess[r][c] != 9)
                    chess[r][c] = 1;
                r--;
                c++;
            }
            r = row, c = i;
            while (r < n && c < n)
            {
                if (chess[r][c] != 9)
                    chess[r][c] = 1;
                r++;
                c++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (chess[i][l] == 0)
            {
                list.push_back(i);
            }
        }
    }
    return list;
}

int main()
{
    cout << "Enter dimension of chess board" << endl;
    int n;
    cin >> n;
    cout << "Enter no of elements present in partial solution" << endl;
    int l;
    cin >> l;
    cout << "Enter partial solution for N queen problem" << endl;
    vector<int> psol;
    int x;
    for (int i = 0; i < l; i++)
    {
        cin >> x;
        psol.push_back(x);
    }

    vector<int> list;
    list = getPositions(psol, n);
    cout << "TASK A" << endl;
    int len = list.size();
    if (len == 0)
        cout << "Empty list" << endl;
    for (int i = 0; i < len; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;

    cout << "TASK B" << endl;
    char chess[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            chess[i][j] = '0';
        }
    }
    for (int i = 0; i < psol.size(); i++)
    {
        chess[psol[i]][i] = 'Q';
    }
    for (int i = 0; i < len; i++)
    {
        chess[list[i]][psol.size()] = 'X';
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << chess[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
