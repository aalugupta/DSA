#include <iostream>
#include <cstring>
#include <string>
using namespace std;

void binary_search(int arr[], int n, int key) // only for sorted arrays
{
    int s = 0;
    int l = n - 1;
    while (s <= l)
    {
        int mid = (s + l) / 2;
        if (key == arr[mid])
        {
            cout << "found at: " << mid;
            return;
        }
        else if (key > arr[mid])
        {
            s = mid + 1;
        }
        else
        {
            l = mid - 1;
        }
    }
    cout << "not found";
}

void all_sub_arrays(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            cout << "(";
            for (int z = i; z <= j; z++)
            {
                cout << arr[z];
            }
            cout << ") , ";
        }
        cout << endl;
    }
}

int max_sum(int arr[], int n) // brute force
{
    int max_sum = INT8_MIN;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int curr_sum = 0;
            cout << "(";
            for (int z = i; z <= j; z++)
            {

                curr_sum += arr[z];
                cout << arr[z];
            }
            cout << ") , {sum : " << curr_sum << "} , ";
            max_sum = max(max_sum, curr_sum);
        }
        cout << endl;
    }
    cout << "{max sum : " << max_sum << "}";
    cout << endl;
    return max_sum;
}

void max_sum2(int arr[], int n) // more optimised
{
    int max_sum = INT8_MIN;
    int curr = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            curr += arr[j];
            max_sum = max(max_sum, curr);
        }
        curr = 0;
    }
    cout << "max_sum is : " << max_sum << endl;
}
void max_sum3(int arr[], int n) // kadane's algo
{
    int max_sum = INT8_MIN;
    int curr_sum = 0;
    for (int i = 0; i < n; i++)
    {
        curr_sum += arr[i];
        max_sum = max(curr_sum, max_sum);
        if (curr_sum < 0)
        {
            curr_sum = 0;
        }
    }
    cout << "max_sum is : " << max_sum;
}
void stock_prediction(int arr[], int n)
{
    int best_buy[n];
    int max_profit = 0;
    best_buy[0] = INT8_MAX;
    for (int i = 1; i < n; i++)
    {
        best_buy[i] = min(best_buy[i - 1], arr[i - 1]);
    }
    for (int i = 1; i < n; i++)
    {
        max_profit += (arr[i] - best_buy[i]);
    }
    cout << max_profit;
}
void trapping_rain_water(int bar[], int l)
{
    int left_highest[l];
    int right_highest[l];
    left_highest[0] = 0;
    right_highest[l - 1] = 0;
    int trapped_water = 0;
    for (int i = 1; i < l - 1; i++)
    {
        left_highest[i] = max(left_highest[i - 1], bar[i - 1]);
    }
    for (int i = l - 2; i >= 0; i--)
    {
        right_highest[i] = max(right_highest[i + 1], bar[i + 1]);
    }
    for (int i = 1; i < l - 1; i++)
    {
        if ((min(left_highest[i], right_highest[i]) - bar[i]) > 0)
        {
            trapped_water += min(left_highest[i], right_highest[i]) - bar[i];
        }
    }
    cout << "trapped_water : " << trapped_water;
}

// to find which subarray is giving max sum
int sub(int arr[], int n, int max_sum)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int curr = 0;
            for (int z = i; z <= j; z++)
            {
                curr += arr[z];
            }
            if (curr == max_sum)
            {
                cout << "(";
                for (int k = i; k <= j; k++)
                {
                    cout << arr[k] << ",";
                }
                cout << ")";
                return 0;
            }
        }
    }
    cout << "not found";
    return 0;
}
// to find which pair is giving maximum product
void max_mul(int arr[], int n)
{
    int max_product = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            cout << "(" << arr[i] << "," << arr[j] << ")";
            cout << "\t";
            cout << (arr[i] * arr[j]) << "\n";
            max_product = max(max_product, (arr[i] * arr[j]));
        }
    }
    cout << max_product;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] * arr[j] == max_product)
            {
                cout << "(" << arr[i] << "||" << arr[j] << ")";
            }
        }
    }
}
// which sub array is giving max product
void max_mul2(float arr[], int n)
{
    float max_product = 0;
    float curr_product = 1;
    float curr = 1;
    for (int i = 0; i < n; i++)
    {
        curr_product *= arr[i];
        max_product = max(max_product, curr_product);
        if (curr_product < 0)
        {
            curr_product = 1;
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int z = i; z <= j; z++)
            {
                curr *= arr[z];
                if (curr == max_product)
                {
                    cout << "max_product=" << curr << "\n";
                    for (int k = i; k <= j; k++)
                    {
                        cout << arr[k] << ",";
                    }
                    return;
                }
            }
            curr = 1;
        }
    }
}

void spiral_matrix(int mat[][4], int n)
{
    int sr = 0, sc = 0;
    int er = n - 1;
    int ec = 3;
    while (sc <= ec && sr <= er)
    {
        for (int j = sc; j <= ec; j++) // top row
        {
            cout << mat[sr][j];
        }
        for (int j = sr + 1; j <= er; j++) // right most column
        {
            if (sc == ec)
            {
                break;
            }
            cout << mat[j][ec];
        }
        for (int j = ec - 1; j >= sc; j--) // bottom row
        {
            if (sr == er)
            {
                break;
            }
            cout << mat[er][j];
        }
        for (int j = er - 1; j >= sr + 1; j--) // left most column
        {
            cout << mat[j][sc];
        }
        sr++;
        sc++;
        er--;
        ec--;
    }
}
void diagonal_sum(int mat[][4], int n)
{
    int curr_sum = 0;
    for (int i = 0; i < n; i++)
    {
        curr_sum += mat[i][i];
        if (n - i - 1 != i)
        {
            curr_sum += mat[i][n - i - 1];
        }
    }
    cout << curr_sum;
}

void search(int mat[][4], int n, int key) // brute force
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (key == mat[i][j])
            {
                cout << "found at : " << i << "," << j;
                return;
            }
        }
    }
    cout << "not found";
}
void search2(int mat[][4], int n, int key) // stair case approach
{
    int er = n - 1;
    int ec = 3;
    int i = 0;
    while (i < n || ec >= 0)
    {
        if (key == mat[i][ec])
        {
            cout << "found at : " << i << "*" << ec;
            return;
        }
        else if (key > mat[i][ec])
        {
            i++;
        }
        else
        {
            ec--;
        }
    }
    cout << "not found";
}
void valid_anagram(string str, string str2)
{
    if (str.length() != str2.length())
    {
        cout << "not anagram";
        return;
    }
    int count[26];
    for (int i = 0; i < str.length(); i++)
    {
        count[str[i] - 'a']++;
    }
    for (int i = 0; i < str2.length(); i++)
    {
        if (count[str2[i] - 'a'] == 0)
        {
            cout << "not anagram";
            return;
        }
        count[str2[i] - 'a']--;
    }
    cout << "valid anagram";
}
void pair_sum(int arr[], int n, int sum) // sorted array is required
{
    int str = 0;
    int lst = n - 1;
    while (str < lst)
    {
        if (sum == arr[str] + arr[lst])
        {
            cout << arr[str] << "-" << arr[lst];
            return;
        }
        else if (sum < arr[str] + arr[lst])
        {
            lst--;
        }
        else
        {
            str++;
        }
    }
    cout << "not found";
}
void pair_sum2(int arr[], int n, int sum) // which two pair will give the given sum
{

    for (int i = 0; i < n; i++)
    {
        int curr_sum;
        for (int j = i + 1; j < n; j++)
        {
            curr_sum = arr[i] + arr[j];
            if (curr_sum == sum)
            {
                cout << arr[i] << "-" << arr[j];
                return;
            }
            curr_sum = 0;
        }
    }
    cout << "not found";
}
// strings
// count no of lower case letter in a word
void count(string str)
{
    int count_ = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (96 < (int)str[i] && (int)str[i] < 123)
        {
            count_++;
            cout << str[i] << ",";
        }
    }
    cout << count_;
}
####void string_swap(string str, string str2) // to find can we make same string by just one swap
{
    if (str.length() != str2.length())
    {
        cout << "false";
        return;
    }
    int a, b, count = 0, c = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != str2[i])
        {
            c++;
        }
        if (c > 2)
        {
            cout << "false";
            return;
        }
    }
    for (int i = 0; i < str.length(); i++)
    {
        if (count == 0 && str[i] != str2[i])
        {
            a = i;
            count++;
        }
        else if (count == 1 && str[i] != str2[i])
        {
            cout << a << "," << i;
            return;
        }
    }
    cout << "strings are same";
}
void leaders(int arr[], int n)
{
    int i = n - 1;
    int max=arr[n-1];
    cout << "leaders:" << arr[i] << endl;
    i--;
    while (i >= 0)
    {
        if (arr[i] >= max)
        {   
            max=arr[i];
            cout << max << endl;
        }
        i--;
    }
}
int main()
{
    int arr[] = {1, 2, 5, 6, 8, 9, 45, 52, 5,29 };
    int arr2[] = {1, 5, 6, 8, 9, 56, 67, 226};
    int n = sizeof(arr) / sizeof(int);
    int price[] = {222, 278, 5, 6, 98, 52, 12};
    int m = sizeof(price) / sizeof(int);
    int bar[] = {5, 1, 2, 3, 4, 5};
    int l = sizeof(bar) / sizeof(int);
    float alu[] = {-1, 4, 5, 6, 1, 4, -9, -45, -8, 3, 6, 3.5, 0.45, 100};
    int a = sizeof(alu) / sizeof(int);
    int mat[][4] = {{1, 2, 3, 4}, {2, 3, 4, 5}, {3, 4, 5, 6}, {4, 5, 6, 7}};
    string str = "bank";
    string str2 = "bnak";
    // binary_search(arr2, n, 67);
    all_sub_arrays(arr, 5);
    // max_sum(arr, n);
    // max_sum2(arr, n);
    // max_sum3(arr, n);
    // stock_prediction(price,m);
    // trapping_rain_water(bar, l);
    // int ms = max_sum4(arr,n);
    // sub(arr,n,ms);
    // spiral_matrix(mat, 3);
    // diagonal_sum(mat, 4);
    // search(mat, 4, 6);
    // search2(mat, 4, 8);
    // valid_anagram(str, str2);
    // pair_sum(arr,n,47);
    // pair_sum2(arr,n,47);
    // max_mul2(alu, a);
    // count(str);
    //string_swap(str, str2);
    leaders(arr,n);

    return 0;
}