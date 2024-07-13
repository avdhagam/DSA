#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>

bool is_safe(vector<string> &board, int row, int col, int n);
void helper(vector<vector<string>> &ans, vector<string> &board, int col, int n);

vector<vector<string>> NQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board;
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
        board.push_back(s);
    }
    helper(ans, board, 0, n);
    return ans;
}

void helper(vector<vector<string>> &ans, vector<string> &board, int col, int n)
{
    // base case
    if (col == n)
    {
        ans.push_back(board);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (is_safe(board, i, col, n))
        {
            board[i][col] = 'Q';
            helper(ans, board, col + 1, n);
            board[i][col] = '.';
        }
    }
}
bool is_safe(vector<string> &board, int row, int col, int n)
{
    int temp_row = row;
    int temp_col = col;
    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }
    while (col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
    }
    while (row < n && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row++;
        col--;
    }
    return true;
}

int main()
{
    vector<vector<string>> ans;
    ans = NQueens(4);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}