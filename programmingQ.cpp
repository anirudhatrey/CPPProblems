#include <iostream>
using namespace std;

struct athlete
{
    int r1;
    int r2;
    int r3;
};


int main(){
struct athlete a1,a2,a3;
int avg1,avg2,avg3,max,flag=0;
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
cin>>a1.r1>>a1.r2>>a1.r3;
cin>>a2.r1>>a2.r2>>a2.r3;
cin>>a3.r1>>a3.r2>>a3.r3;
if(a1.r1<101&&a1.r2<101&&a1.r3<101&&a2.r1<101&&a2.r2<101&&a2.r3<101&&a3.r1<101&&a3.r2<101&&a3.r3<101)
    {
 avg1=(a1.r1+a1.r2+a1.r3)/3;
 avg2=(a2.r1+a2.r2+a2.r3)/3;
 avg3=(a3.r1+a3.r2+a3.r3)/3;
 max=avg2>avg1?(avg2>avg3?avg2:avg3):(avg3>avg1?avg3:avg1);
 if(max<70){
     cout<<"all trainer are unfit";
 }else{
     if(avg1==max && avg1>=70){
         cout<<"trainer 1 is faster";
     }else if(avg2==max && avg2>=70){
         cout<<"trainer 2 is faster";
     }else if(avg3==max && avg3>=70){
         cout<<"trainer 3 is faster";
     }
 }
    }else cout<<"invalid input";
    return 0;
}