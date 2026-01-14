#include <bits/stdc++.h>
using namespace std;
//run two loops the inner loops navigates and checks for all numbers shorter and update the length
int leadersInArray(int arr[], int n, int k)
{
    int count = 0,maxLength=1,search=-1;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==search){
        int search = arr[i]+1;
        i=0;
        count++;
        if(count>maxLength){
            maxLength = count;
        }
        }else if(i== n-1 || i==0){
           int search = arr[i]+1;
           i=0;
        }

       
        count != 0 && cout << arr[i] << " ";
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