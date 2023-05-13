#include <bits/stdc++.h>
using namespace std;

int power_of_two(int n)
{
    int l = (int)log2(n);
    if (l == log2(n))
        return n;
    else
    {
        return pow(2, l + 1);
    }
}

void print_Matrix(vector<vector<int>> &M, int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

vector<vector<int>> matrix_multiplication(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C,int a_row, int a_col, int b_row, int b_col, int c_row, int c_col, int N)
{
    if (N == 1)
    {
        C[c_row][c_col] += A[a_row][a_col] * B[b_row][b_col];
    }
    else
    {
        N = N / 2;
        matrix_multiplication(A, B, C, a_row, a_col, b_row, b_col, c_row, c_col, N);
        matrix_multiplication(A, B, C, a_row, a_col + N, b_row + N, b_col, c_row, c_col, N);
        matrix_multiplication(A, B, C, a_row, a_col, b_row, b_col + N, c_row, c_col + N, N);
        matrix_multiplication(A, B, C, a_row, a_col + N, b_row + N, b_col + N, c_row, c_col + N, N);
        matrix_multiplication(A, B, C, a_row + N, a_col, b_row, b_col, c_row + N, c_col, N);
        matrix_multiplication(A, B, C, a_row + N, a_col + N, b_row + N, b_col, c_row + N, c_col, N);
        matrix_multiplication(A, B, C, a_row + N, a_col, b_row, b_col + N, c_row + N, c_col + N, N);
        matrix_multiplication(A, B, C, a_row + N, a_col + N, b_row + N, b_col + N, c_row + N, c_col + N, N);
    }
    return C;
}

int main()
{
    cout << "Enter size of matrix :" << endl;
    int n;
    cin >> n;

    int N = power_of_two(n);
    int x;
    vector<vector<int>> A;
    cout << "Enter elements of matrix A" << endl;
    for (int i = 0; i < N; i++)
    {
        vector<int> temp;
        for (int j = 0; j < N; j++)
        {
            if (i < n && j < n)
                cin >> x;
            else
                x = 0;
            temp.push_back(x);
        }
        A.push_back(temp);
    }

    vector<vector<int>> B;
    cout << "Enter elements of matrix B" << endl;
    for (int i = 0; i < N; i++)
    {
        vector<int> temp;
        for (int j = 0; j < N; j++)
        {
            if (i < n && j < n)
                cin >> x;
            else
                x = 0;
            temp.push_back(x);
        }
        B.push_back(temp);
    }

    cout << "Matrix A : " << endl;
    print_Matrix(A, n - 1);

    cout << "Matrix B : " << endl;
    print_Matrix(B, n - 1);

    vector<vector<int>> C(N, vector<int>(N, 0));
    C = matrix_multiplication(A, B, C, 0, 0, 0, 0, 0, 0, N); // C is our Result Matrix

    cout << "Matrix C : " << endl;
    print_Matrix(C, n - 1);
}