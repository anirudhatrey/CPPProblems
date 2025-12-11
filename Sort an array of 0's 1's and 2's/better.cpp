#include <bits/stdc++.h>
using namespace std;
//Given an array nums consisting of only 0, 1, or 2. Sort the array in non-decreasing order. The sorting must be done in-place, without making a copy of the original array.

int sort012(int arr[], int n, int k)
{
    int low = 0, mid = 0, high = n-1, temp;
    for (int i = 0; mid<high;i++)
    {
        if (arr[mid] == 0)
        {
            temp=arr[low];
            arr[low]=arr[mid];
            arr[mid]=temp;
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else if (arr[mid] == 2)
        {
            temp=arr[high];
            arr[high]=arr[mid];
            arr[mid]=temp;
            high--;
        }
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