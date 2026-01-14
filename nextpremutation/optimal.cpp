#include <bits/stdc++.h>
// Improvement - 2025-11-09
using namespace std;
int nextPermutation(int arr[], int n)
{
    int breakpoint = -1, temp, closest = -1;
    
    // Find the rightmost breakpoint where arr[i] < arr[i+1]
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] < arr[i + 1])
        {
            breakpoint = i;
        }
    }

    if (breakpoint == -1)
    {
        // Array is in descending order, return sorted (first permutation)
        sort(arr, arr + n);
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }
    else
    {
        // Find the smallest element in [breakpoint+1, n) that is greater than arr[breakpoint]
        for (int i = breakpoint + 1; i < n; i++)
        {
            if (arr[i] > arr[breakpoint])
            {
                if (closest == -1 || arr[i] < arr[closest])
                {
                    closest = i;
                }
            }
        }

        // Swap breakpoint with closest
        temp = arr[closest];
        arr[closest] = arr[breakpoint];
        arr[breakpoint] = temp;

        // Sort the suffix to get the lexicographically next permutation
        sort(arr + breakpoint + 1, arr + n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
    }
    return breakpoint;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    nextPermutation(arr, n);
    return 0;
}