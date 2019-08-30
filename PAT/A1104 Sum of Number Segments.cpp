#include "bits/stdc++.h"
using namespace std;
vector<double>nums;
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        double a;
        cin>>a;
        nums.push_back(a);
    }
    int t = 0;
    double sum = 0;
    for(int i=0; i<nums.size(); i++)
    {
        t = i;
        while(t<nums.size())
        {
            for(int j=0; j<t; j++)
            {
                cout<<nums[j]<<" ";
            }
            t++;
        }
        cout<<endl;
    }
    printf("%.1f\n",sum);
    return 0;
}
