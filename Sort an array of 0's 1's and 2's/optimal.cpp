#include <bits/stdc++.h>
// Improvement - 2025-11-13
using namespace std;
//Given an array nums consisting of only 0, 1, or 2. Sort the array in non-decreasing order. The sorting must be done in-place, without making a copy of the original array.

int sort012(int arr[], int n, int k)
{
    int zeroCount = 0, oneCount = 0, twoCount = 0;
    for (int i = 0; i < n;i++)
    {
        if (arr[i] == 0)
        {
            zeroCount++;
        }
        else if (arr[i] == 1)
        {
            oneCount++;
        }
        else if (arr[i] == 2)
        {
            twoCount++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        arr[i]=i<zeroCount?0:i<zeroCount+oneCount?1:2;
    }

    for (int i = 0; i < n;i++)
    {
        cout<<arr[i];
    }
    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int n, ans = 0, k;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> k;
    int sum = 0;
    sort012(arr, n, k);
    return 0;
}