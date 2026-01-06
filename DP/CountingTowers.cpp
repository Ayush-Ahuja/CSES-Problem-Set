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
vector<vector<int>> dp;

ll countTowers(int n, int idx){
    if (dp[n][idx] != -1) return dp[n][idx];
    ll ans = 0;
    if (idx == 0){
        ans = (ans + countTowers(n-1, 1))%mod2;
        ans = (ans + (2LL*countTowers(n-1, 0))%mod2)%mod2;
    }
    else{
        ans = (ans + (4LL*countTowers(n-1, 1))%mod2)%mod2;
        ans = (ans + countTowers(n-1, 0))%mod2;
    }
    return dp[n][idx] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tt;
    cin >> tt;
    dp.resize(1000001, vector<int>(2, -1));
    dp[1][0] = dp[1][1] = 1;
    while(tt--){
        ll n;
        cin >> n;
        cout << (countTowers(n, 0) + countTowers(n, 1))%mod2 << "\n";
    } 
    return 0;
}