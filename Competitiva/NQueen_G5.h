#pragma once
#include <iostream>
#include <chrono>
using std::cout;
using std::endl;
using std::chrono::milliseconds;
using std::chrono::steady_clock;



void ChooseColumns(char**& mat, int r, int n, int x, int y, bool& isFinished);
bool IsValid(char**& mat, int r, int c, int n);
double nqueens_G5(const int n, int x, int y);

double nqueens_G5(const int n, int x, int y)
{
    auto start = steady_clock::now();

    char** mat = new char* [n];
    mat[0] = new char[n * n];
    for (int i = 1; i < n; ++i)
        mat[i] = mat[i - 1] + n;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            mat[i][j] = '.';
    mat[x][y] = 'x';
    bool isFinished = 0;

    ChooseColumns(mat, 0, n, x, y, isFinished);
    delete mat[0];
    delete[] mat;

    auto end = steady_clock::now();
    std::chrono::duration<double, std::milli> float_ms = end - start;

    return float_ms.count();

}

void ChooseColumns(char**& mat, int r, int n, int x, int y, bool& isFinished)
{
    if (!isFinished)
    {
        if (r == n && (mat[x][y] == 'x'))
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                    cout << mat[i][j] << "\t";
                cout << endl;
            }
            cout << endl;
            isFinished = 1;
        }
        for (int c = 0; c < n; c++)
        {
            if (IsValid(mat, r, c, n) || (x == r && y == c))
            {
                mat[r][c] = 'x';

                ChooseColumns(mat, r + 1, n, x, y, isFinished);
                if (x != r && y != c)
                {
                    mat[r][c] = '.';
                }
            }
        }
    }

}

bool IsValid(char**& mat, int r, int c, int n)
{

    //columna
    for (int i = 0; i < n; ++i)
        if (mat[i][c] == 'x')
            return false;

    // fila
    for (int i = 0; i < n; ++i)
        if (mat[r][i] == 'x')
            return false;


    // diagonal
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((mat[i][j] == 'x') && ((i + j == r + c) || (i - j == r - c))) {
                return false;
            }
        }
    }
    return true;
}
