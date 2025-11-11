#include <bits/stdc++.h>
// Improvement - 2025-11-11
using namespace std;

int stocks(int arr[], int n, int k)
{
    int zeroCount = 0, oneCount = 0, twoCount = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (zeroCount < arr[j] - arr[i])
            {
                zeroCount = arr[j] - arr[i];
            }
        }
    }

    
   cout<<zeroCount;
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
    stocks(arr, n, k);
    return 0;
}