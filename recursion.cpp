#include <iostream>
#include <string>
#include <vector>
using namespace std;

void decreasing(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n;
    decreasing(n - 1);
}
int sum_natural(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n + sum_natural(n - 1);
}
int nth_fibonaci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    int nth = nth_fibonaci(n - 1) + nth_fibonaci(n - 2);

    return nth;
}
bool is_sorted(int ptr[], int n, int i)
{
    if (i == n - 1)
    {
        return true;
    }

    if (ptr[i] > ptr[i + 1])
    {
        return false;
    }
    i++;
    return is_sorted(ptr, n, i); // retun is important because only original function which is called in main function can return any value to the main function and without return original function is not gettin any return value
}
int first_occurence(int arr[], int n, int tar, int i)
{
    if (i == n)
    {
        return -1;
    }
    if (arr[i] == tar)
    {
        return i;
    }
    return first_occurence(arr, n, tar, i + 1);
}
int last_occurence(int arr[], int n, int tar, int i)
{
    if (i == n)
    {
        return -1;
    }
    int idx = last_occurence(arr, n, tar, i + 1);
    if (idx == -1 && arr[i] == tar)
    {
        return i;
    }
    return idx;
}
int power(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    return x * power(x, n - 1);
}
int tiling_problem(int n)
{
    int ans1 = 0, ans2 = 0;
    if (n == 1 || n == 0)
    {
        return 1;
    }
    ans1 = tiling_problem(n - 1);
    ans2 = tiling_problem(n - 2);
    return ans1 + ans2;
}
string remove_duplicates(string str, int i, string ans, bool arr[26])
{
    if (i == str.length())
    {
        return ans;
    }

    if (arr[str[i] - 'a'] == true)
    {
        return remove_duplicates(str, i + 1, ans, arr);
    }
    else
    {
        arr[str[i] - 'a'] = true;
        return remove_duplicates(str, i + 1, ans + str[i], arr);
    }
};
int friends_pair(int n)
{
    if (n == 1 || n == 2)
    {
        return n;
    }
    return friends_pair(n - 1) + (friends_pair(n - 2)) * (n - 1);
}
void binary_string(string str, int last, int n)
{
    if (n == 0)
    {
        cout << str << "\n";
        return;
    }
    if (last != 1)
    {
        binary_string(str + '0', 0, n - 1);
        binary_string(str + '1', 1, n - 1);
    }
    else
    {
        binary_string(str + '0', 0, n - 1);
    }
}
void print_board(vector<vector<char>> board)
{
    int n = board.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }
}
vector<vector<char>> create_board(int n)
{
    vector<vector<char>> board;

    for (int i = 0; i < n; i++)
    {
        vector<char> newrow;
        for (int j = 0; j < n; j++)
        {
            newrow.push_back('.');
        }
        board.push_back(newrow);
    }
    return board;
}

vector<vector<int>> create_sudoku()
{
    vector<vector<int>> sudoku(9, vector<int>(9, 0));
    return sudoku;
}

void print_sudoku(vector<vector<int>> sudoku)
{
    int count = 0, counti = 0;
    for (int i = 0; i < sudoku.size(); i++)
    {
        counti++;

        for (int j = 0; j < sudoku.size(); j++)
        {
            cout << sudoku[i][j];
            count++;
            if (count % 3 == 0)
            {
                cout << "|";
            }
        }
        if (counti % 3 == 0)
        {
            cout << endl
                 << "------------";
        }
        cout << endl;
    }
}

bool issafe(vector<vector<char>> board, int row, int col)
{
    int n = board.size();
    for (int i = 0; i < n; i++)
    { // horizontal line
        if (board[row][i] == 'Q')
        {
            return false;
        }
    }
    for (int i = 0; i <= row; i++)
    { // vertical line
        if (board[i][col] == 'Q')
        {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    { // prime diagonal
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    { // other diagonal
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }
    return true;
}
int n_queen(vector<vector<char>> board, int row)
{
    int n = board.size();
    int count = 0;
    if (row == n)
    {
        print_board(board);
        cout << "----------------------------------------------------------------------" << endl;
        return 1;
    }
    for (int j = 0; j < n; j++)
    {
        if (issafe(board, row, j))
        {
            board[row][j] = 'Q';
            count += n_queen(board, row + 1);
            board[row][j] = '.';
        }
    }
    return count;
}
int grid_search(int n, int m, int row, int col)
{
    int count1 = 0, count2 = 0;
    if (row == n - 1 && col == m - 1)
    {
        return 1;
    }
    if (row >= n || col >= m)
    {
        return 0;
    }
    count1 += grid_search(n, m, row + 1, col); // row move
    count2 += grid_search(n, m, row, col + 1); // col move
    return count1 + count2;
}
void sudoku_solver(vector<vector<int>> sudoku, int row, int column)
{
    for (int dig = 0; dig < 10; dig++)
    {
        sudoku[row][column] = dig;
        sudoku_solver(sudoku, row + 1, column);
        sudoku[row][column] = 0;
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    string str = "aasdfggghjfdsl";
    string ans = "";
    // decreasing(6);
    // cout << endl;
    // cout << sum_natural(5);
    // cout << endl;
    // cout << nth_fibonaci(5);
    // cout << endl;
    // cout << is_sorted(arr, 6, 0);
    // cout << endl;
    // cout << first_occurence(arr, 6, 7, 0);
    // cout << endl;
    // cout << power(2, 5);
    // bool ar[26];
    // cout << tiling_problem(3);
    // cout << remove_duplicates(str, 0, "", ar);
    // cout<<friends_pair(5);
    // binary_string(ans, 0, 3);
    // print_board(create_board(4));
    // cout << n_queen(create_board(4), 0);
    // cout << grid_search(3, 3, 0, 0);
    print_sudoku(create_sudoku());
    return 0;
}