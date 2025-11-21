#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int n, ans = 0;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    int flag;
    for (int i = 1; i < n; i++)
    {
        flag = 0;
        for (int j = 0; j < n; i++)
        {
            if (arr[j] == i)
            {
                flag=1;
                break;
            }
        }
        cout << i;
    }
    return 0;
}