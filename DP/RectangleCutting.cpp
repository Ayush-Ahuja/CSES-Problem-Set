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

vector<vector<ll>> dp(501, vector<ll>(501, -1));

ll rectCut(ll a, ll b){
    if (dp[a][b] != -1) return dp[a][b];
    if (a == b){
        return dp[a][b] = 0;
    }
    ll ans = LLONG_MAX;
    LOOP(1, (a/2)+1){
        ans = min(ans, rectCut(a-i, b) + rectCut(i, b));
    }
    LOOP(1, (b/2)+1){
        ans = min(ans, rectCut(a, b-i) + rectCut(a, i));
    }
    ans++;
    return dp[a][b] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a, b;
    cin >> a >> b;
    cout << rectCut(a, b) << "\n";
}