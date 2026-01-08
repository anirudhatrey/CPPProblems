#include <bits/stdc++.h>
using namespace std;

// Helper function to check if two arrays are equal
bool areEqual(int arr1[], int arr2[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr1[i] != arr2[i])
            return false;
    }
    return true;
}

// Brute force approach: Generate all permutations in sorted order,
// find current permutation, return the next one (or first if it's the last)
int stocks(int arr[], int n, int k)
{
    // Create a copy of the original array to preserve it
    int original[n];
    for (int i = 0; i < n; i++)
    {
        original[i] = arr[i];
    }

    // Sort the array to get the first permutation
    sort(arr, arr + n);

    // Store all permutations
    vector<vector<int>> permutations;
    
    // Generate all permutations using next_permutation
    do
    {
        vector<int> perm;
        for (int i = 0; i < n; i++)
        {
            perm.push_back(arr[i]);
        }
        permutations.push_back(perm);
    } while (next_permutation(arr, arr + n));

    // Find the current permutation in the list
    int currentIndex = -1;
    for (int i = 0; i < permutations.size(); i++)
    {
        bool found = true;
        for (int j = 0; j < n; j++)
        {
            if (permutations[i][j] != original[j])
            {
                found = false;
                break;
            }
        }
        if (found)
        {
            currentIndex = i;
            break;
        }
    }

    // Get the next permutation (or first if current is last)
    int nextIndex = (currentIndex + 1) % permutations.size();
    
    // Output the next permutation
    for (int i = 0; i < n; i++)
    {
        cout << permutations[nextIndex][i] << " ";
    }
    
    return currentIndex;
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