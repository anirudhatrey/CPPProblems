#include <bits/stdc++.h>
using namespace std;

pair<int,int> twosum(int arr[], int n, int k){
    unordered_map<int,int> mp;
    for(int i = 0; i < n ; i ++){
        if(mp.find(k-arr[i]) != mp.end()){
            return make_pair(mp[(k-arr[i])]+1,i+1);
        }
        else{
            mp[arr[i]]=i;
        }
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
   pair<int,int> a = twosum(arr,n,k);
   cout<< a.first<<", "<<a.second;
    return 0;
}