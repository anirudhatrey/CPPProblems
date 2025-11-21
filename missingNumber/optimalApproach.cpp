#include <bits/stdc++.h>
using namespace std;
int optimalApproach(int arr[], int n)
{
    int missingNumber = 0;

    int SumOfArr = n*(n+1)/2;
int sum=0;
    for(int i = 0;i<n;i++){
        sum+=arr[i];
    }
missingNumber=SumOfArr-sum;
    return missingNumber;
}

int bestApproach(int arr[], int n)
{
    int xor1 = 0;

    int xor2 = 0;
int sum=0;
    for(int i = 0;i<n;i++){
        xor1^=i;
        xor2^=arr[i];
    }
    xor1^=n;
    int missingNumber=xor1^xor2;
    return missingNumber;
}
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
    
    cout<<"First Approach, Missing Number is"<<optimalApproach(arr,n)<<endl;
    cout<<"Second Approach, Missing Number is"<<bestApproach(arr,n);
    return 0;
}