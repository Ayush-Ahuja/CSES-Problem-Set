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

vector<vector<ll>> adj;
vector<ll> color;
vector<ll> ans;

void solve(ll u, ll par, set<ll>& distCol){
    distCol.insert(color[u]);
    for (auto v : adj[u]){
        if (v != par){
            set<ll> temp;
            solve(v, u, temp);
            if (distCol.size() < temp.size()) swap(distCol, temp);
            for (auto col : temp) distCol.insert(col);
        }
    }
    ans[u] = distCol.size();
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    color.resize(n+1);
    adj.resize(n+1);
    ans.resize(n+1);
    LOOP(1, n+1){
        cin >> color[i];
    }
    LOOP(0, n-1){
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    set<ll> temp;
    solve(1, -1, temp);
    LOOP(1, n+1) cout << ans[i] << " ";
    return 0;
}