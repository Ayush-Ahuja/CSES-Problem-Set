#include <bits/stdc++.h>

using namespace std;

#define LOOP(p, q) for(int i = (p); i < (q); i++)
#define LOOP_(p,q,i) for(int i = (p); i < (q); i++)
#define ll long long
#define all(x) x.begin(), x.end()
long long GCD(long long a,long long b){
  if(b==0LL) return a;
  else return GCD(b,a%b);
}
long long LCM(long long a,long long b){
  return (a*b)/GCD(a,b);
}
ll N = 3e5+7;
ll mod = 998244353;
ll mod2 = 1e9 + 7;

vector<vector<ll>> dp;
ll m, n;
vector<ll> a;

ll arrayCount(ll idx, ll prev){
    if (idx >= n) return 1;
    if (dp[idx][prev] != -1) return dp[idx][prev];
    ll ans = 0;
    if (a[idx] == 0){
        LOOP(prev-1, prev+2){
            if (i >= 1 && i <= m){
                ans  = (ans + arrayCount(idx + 1, i))%mod2;
            }
        }
    }
    else{
        if (abs(prev-a[idx]) > 1){
            return 0;
        }
        else {            
            ans  = arrayCount(idx + 1, a[idx])%mod2;           
        }
    }
    return dp[idx][prev] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    a.resize(n);
    dp.resize(n, vector<ll>(m+1, -1));
    LOOP(0, n){
        cin >> a[i];
    } 
    if (a[0] == 0){
        ll ans = 0;
        LOOP(1, m+1){
            ans  = (ans + arrayCount(1, i))%mod2;
        }
        cout << ans << "\n";
    }
    else{
        cout << arrayCount(1, a[0]) << "\n";
    }
    return 0;
}