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
string a, b;
ll n, m;
vector<vector<ll>> dp;

ll editDistance(ll idx1, ll idx2){
    if (idx1 >= n && idx2 >= m) return 0;
    if (idx1 >= n) return (m - idx2);
    if (idx2 >= m) return (n - idx1);
    if (dp[idx1][idx2] != -1) return dp[idx1][idx2];
    if (a[idx1] == b[idx2]) return dp[idx1][idx2] = editDistance(idx1 + 1, idx2 + 1);
    return dp[idx1][idx2] = 1 + min(editDistance(idx1 + 1, idx2 + 1), min(editDistance(idx1 + 1, idx2), editDistance(idx1, idx2 + 1)));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    dp.resize(a.size(), vector<ll>(b.size(), -1));
    n = a.size();
    m = b.size();
    cout << editDistance(0, 0) << "\n";
    return 0;
}