// https://www.codechef.com/START24C/problems/ORANDCON?tab=statement
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a=0;
        int i=0;
        while(a<n)
        {
           a=a+pow(2,i);
           i++;
        }
        a=n+pow(2,i);
        cout<<n<<" "<<0<<" "<<a;
        cout<<endl;
    }
}
