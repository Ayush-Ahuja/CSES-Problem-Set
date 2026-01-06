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
ll inf = 1e9 + 7;
ll N = 3e5+7;
ll dp[1000007];
ll mod = 1e9 + 7;

ll solve(ll n, vector<ll>& coins){
    if(n<0) return inf;
    if(n==0) return 0;
    if(dp[n] != -1) return dp[n];
    ll sum = inf;
    LOOP(0, coins.size()){
        sum = min(sum, (1 + solve((n-coins[i]), coins)));
    }
    // cout << sum << "\n";
    dp[n] = sum;
    return dp[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    LOOP(0,n){
        cin >> a[i];
    }
    fill(dp, dp+1000007, inf);
    dp[0] = 0;
    LOOP(0, n){
        LOOP_(0, x, j){
            if (j+a[i] > x) break;
            dp[j+a[i]] = min(dp[j+a[i]], 1 + dp[j]);
        }
    }
    if (dp[x] == inf) cout << "-1\n";
    else cout << dp[x];
}