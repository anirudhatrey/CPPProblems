#include <bits/stdc++.h>
using namespace std;
//Given an integer array nums of size n, return the majority element of the array.
//The majority element of an array is an element that appears more than n/2 times in the array. The array is guaranteed to have a majority element.

pair<int,int> twosum(int arr[], int n, int k){
    for(int i = 0; i < n ; i ++){
        for(int j = i; j < n ; j ++){
            if(arr[i]+arr[j] == k){
                return   make_pair(i+1,j+1);
            }
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