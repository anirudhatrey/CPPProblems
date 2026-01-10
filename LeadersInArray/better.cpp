#include <bits/stdc++.h>
using namespace std;

int leadersInArray(int arr[], int n, int k)
{
    int max = arr[n-1];
    int count = 1;
    int arr2[n];
    arr2[0] = arr[n - 1];
    for (int i = n - 2, j = 1; i >= 0; i--)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            arr2[j] = arr[i];
            j++;
            count++;
        }
    }

    for(int i=count-1; i>=0;i--)
    {
        cout<<arr2[i]<<" ";
    }
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