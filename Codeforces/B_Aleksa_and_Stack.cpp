#include <bits/stdc++.h> 
using namespace std;

#define endl "\n"
#define deb(x)      cout << #x << "=" << x << " ";
#define debl(x)     cout << #x << "=" << x << "\n";

#define lp(i,a,n)   for(ll i=a; i<n; i++)
#define lpr(i,n)    for(int i=n-1; i>-1; i--) 

typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;



//    * * * * *   *       *   *   *       *   * * * * *
//    *           *       *   *   * *     *   *        
//    * * * * *   * * * * *   *   *   *   *   * * * * *
//            *   *       *   *   *     * *   *        
//    * * * * *   *       *   *   *       *   * * * * *



vector<ll> prime;
void sieve(ll n){
    bitset<200005> prime;
    for(ll i=2; i*i<=n; i++){
        if(!prime[i]){

            for(ll j=2*i; j<=n; j+=i){
                prime[j] = 1;
            }
        }
    }
    lp(i, 2, n+1)   if(!prime[i])
        ::prime.push_back(i);
}


ll gcd(ll a, ll b){
    return (a%b==0)? b: gcd(b, a%b);
}


ll power(ll a, ll b){
    ll res = 1;
    while(b>0){
        if(b&1)     
            res *= a;
        a *= a;
        b = b >> 1;
    }
    return res;
}


// (a*b) % n == ((a%n) * (b%n)) % n
ll powmod(ll a, ll b){
    ll res = 1;
    while(b>0){
        if(b&1)
            res = (res * (a%mod)) % mod;
        a = ((a%mod) * (a%mod)) % mod;
        b = b >> 1;
    }
    return res;
}


void SHINE(){
    int n;
    cin >> n;

    int a=2;
    for(int i=0; i<n; i++) {
        cout << 2*i+1 << " ";
    }
    cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(NULL), cin.tie(NULL), cout.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        SHINE();
    }
    // cerr << "Time taken: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}

// SHINE BRIGHT LIKE A DIAMOND
/*

*/
