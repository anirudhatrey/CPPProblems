#include <bits/stdc++.h>

using namespace std;

int maxLenSubArrWithSumK(int arr[], int n, int k){
    int ans, start = 0, end = 0, sum = 0, maxLen = 0;
    for(int i = 0; i < n || end < n; i++){
        sum += arr[i];
        if(sum == k){
            maxLen = end-start+1;
        }
        if(sum<=k){
            end++;
        }else if(sum > k){
            sum -= arr[start];
            start++;
        }
    }
    return maxLen;
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
    
    // for(int i = 0; i < n ; i ++){
    //     for(int j = i; j < n ; j ++){
    //         sum += arr[j];
    //         if(sum == k){
    //           ans =  ans > j - i + 1 ? ans :  j - i + 1;
    //         }
    //     }
    // }

    ans = maxLenSubArrWithSumK(arr, n, k);
    cout<<ans;
    return 0;
}