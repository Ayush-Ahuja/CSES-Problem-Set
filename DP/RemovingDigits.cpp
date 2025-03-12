#include <bits/stdc++.h>

using namespace std;

#define LOOP(p, q) for(int i = (p); i < (q); i++)
#define LOOP_(p,q,i) for(int i = (p); i < (q); i++)
#define ll long long
long long GCD(long long a,long long b){
  if(b==0LL) return a;
  else return GCD(b,a%b);
}
long long LCM(long long a,long long b){
  return (a*b)/GCD(a,b);
}
ll N = 3e5+7;
ll dp[1000007];
ll mod = 1e9 + 7;

ll solve(ll n){
    if (dp[n] != -1) return dp[n]; 
    ll base = n;
    ll minn = LLONG_MAX;
    LOOP(0, 9){
        ll rem = base%10;
        if (rem != 0){
            minn = min(minn, solve((n-rem)));
        }
        base /= 10;
    }  
    return dp[n] = 1 + minn; 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    ll n;
    cin >> n;
    solve(n);
    cout << dp[n] << "\n";
}