#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll ty,ny,iy,cy,my;
    cin>>ty;
    while(ty--)
    {
        cy=0;
        cin>>ny;
        vector<ll>v(ny);
        for(iy=0;iy<ny;iy++)
            cin>>v[iy];
        for(auto x:v)
            cy+=x;
        my=*min_element(v.begin(),v.end());
        cout<<cy-my<<endl;
    }
}
