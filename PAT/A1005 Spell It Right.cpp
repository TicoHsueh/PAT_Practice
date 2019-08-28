#include "bits/stdc++.h"
using namespace std;

char num[103];
char english[10][20] = {"zero","one","two","three","four",
                        "five","six","seven","eight","nine",
                       };
int sum = 0;
void spell(int n);
void cacuSum()
{
    sum = 0;
    for(int i=0;i<strlen(num);i++){
       sum += num[i]-'0';
    }
    spell(sum);
}

void spell(int n)
{
    if(n/10==0){
        printf("%s",english[n]);
        return ;
    }
    spell(n/10);
    printf(" %s",english[n%10]);
}

int main()
{
    scanf("%s",num);
    cacuSum();
    return 0;
}
