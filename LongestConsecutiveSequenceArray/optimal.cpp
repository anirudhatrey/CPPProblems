#include <bits/stdc++.h>

using namespace std;

pair<int,int> leadersInAnArray(int arr[], int n, int k){
    int ptr=n-2,max=arr[n-1],temp;
    for(int i = n-2; i >=0 ; i --){
       if(arr[i]>max)
       {
        arr[ptr] = arr[i];
        ptr--;
        max=arr[i];
       }
    }
    for(int i = ptr+1 ; i < n ; i ++){
        cout<<arr[i]<<" ";
    }
return make_pair(-1,-1);
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
   pair<int,int> a = leadersInAnArray(arr,n,k);
   
    return 0;
}