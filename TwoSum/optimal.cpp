#include <bits/stdc++.h>
// Improvement - 2025-11-10

using namespace std;

pair<int, int> twosum(int arr[], int n, int k)
{
    // Store original indices before sorting
    vector<pair<int, int>> indexedArr;
    for (int i = 0; i < n; i++)
    {
        indexedArr.push_back({arr[i], i});
    }
    sort(indexedArr.begin(), indexedArr.end());

    for (int i = 0, j = n - 1; i < j;)
    {
        if (indexedArr[i].first + indexedArr[j].first == k)
        {
            return make_pair(indexedArr[i].second, indexedArr[j].second);
        }
        else if (indexedArr[i].first + indexedArr[j].first > k)
        {
            j--;
        }
        else
        {
            i++;
        }
    }

    return make_pair(-1, -1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int n, k;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> k;
    pair<int, int> a = twosum(arr, n, k);
    cout << a.first << ", " << a.second;
    return 0;
}