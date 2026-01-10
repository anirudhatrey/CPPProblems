#include <bits/stdc++.h>
using namespace std;

int leadersInArray(int arr[], int n, int k)
{
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int count = 0;
        for (int j = i; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                count = 1;
                break;
            }
        }
        count == 0 && cout << arr[i] << " ";
    }
    cout << arr[n - 1];
    return -1;
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
    int a = leadersInArray(arr, n, k);
    return 0;
}