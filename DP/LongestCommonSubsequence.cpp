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

vector<ll> ans;
vector<ll> a;
vector<ll> b;
vector<vector<ll>> dp;
vector<vector<pair<ll, ll>>> step;
ll n, m;

ll longest(ll idx1, ll idx2){
    if (idx1 >= n || idx2 >= m) return 0;
    if (dp[idx1][idx2] != -1) return dp[idx1][idx2];
    if (a[idx1] == b[idx2]){
        step[idx1][idx2] = {idx1 + 1, idx2 + 1};
        return dp[idx1][idx2] = 1 + longest(idx1 + 1, idx2 + 1);
    }
    if (longest(idx1 + 1, idx2) > longest(idx1, idx2 + 1)){
        step[idx1][idx2] = {idx1 + 1, idx2};
        return dp[idx1][idx2] = longest(idx1 + 1, idx2);
    }
    step[idx1][idx2] = {idx1, idx2 + 1};
    return dp[idx1][idx2] = longest(idx1, idx2 + 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  a.resize(n);
  b.resize(m);
  dp.resize(n , vector<ll>(m, -1));
  step.resize(n , vector<pair<ll, ll>>(m));
  LOOP(0, n){
    cin >> a[i];
  } 
  LOOP(0, m){
    cin >> b[i];
  } 
  cout << longest(0, 0) << "\n";
  vector<ll> ans;
  for (pair<ll, ll> i = {0, 0}; ; i = step[i.first][i.second]){
    if (i.first >= n || i.second >= m) break;
    if (a[i.first] == b[i.second]){
        ans.push_back(a[i.first]);
    }
  }
  LOOP(0, ans.size()){
    cout << ans[i] << " ";
  }
  cout << "\n";
  return 0;
}