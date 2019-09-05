#include "bits/stdc++.h"
using namespace std;

int main()
{
    int n;
    cin>>n;
    int m = sqrt(n);
    int start = 0;
    int cnt = 0;
    int maxCnt = 0;
    int resSt = 0;
    for(int i=2;i<=m;i++){
        start = i;
        int temp = n;
        cnt = 0;
        while(temp%start==0){
            cnt++;
            temp /= start;
            start++;
        }
        if(cnt>maxCnt){
            maxCnt = cnt;
            resSt = i;
        }
    }
    if(maxCnt==0){
        cout<<1<<endl;
        cout<<n<<endl;
    }else{
        cout<<maxCnt<<endl;
        for(int i=resSt;i<resSt+maxCnt;i++){
            cout<<i;
            i==resSt+maxCnt-1?printf("\n"):printf("*");
        }
    }
    return 0;
}
