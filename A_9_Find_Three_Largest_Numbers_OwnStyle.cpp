#include <bits/stdc++.h>
using namespace std;

int *findThreeLargestNumbers(int arr[], int sizeOfArray)
{
    int *threeLargestNumbers[3] = {0, 5, 0};
    for (int j = 0; j < 3; j++)
    {
        cout << threeLargestNumbers[j] << endl;
    }
    return 0;
}

void fastIO()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main()
{
    fastIO();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int sizeOfArray;
    cin >> sizeOfArray;
    int arr[sizeOfArray];
    for (int i = 0; i < sizeOfArray; i++)
    {
        cin >> arr[i];
    }

    int *threeLargestNumbers = findThreeLargestNumbers(arr, sizeOfArray);

    // for (int j = 0; j < 3; j++)
    // {
    //     cout << threeLargestNumbers[j] << endl;
    // }
    return 0;
}