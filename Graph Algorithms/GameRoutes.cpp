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
vector<ll> ways;
vector<bool> visited;
ll n;

void dfs(ll u){
  visited[u] = true;
  for (auto v : adj[u]){
    if (!visited[v]){
      dfs(v);
    }
    ways[u] = (ways[u] + ways[v])%mod2;
  }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll m;
    cin >> n >> m;
    adj.resize(n+1);
    visited.resize(n+1, false);
    ways.resize(n+1);
    LOOP(0, m){
      ll u, v;
      cin >> u >> v;
      adj[u].push_back(v);
    }
    ways[n] = 1;
    dfs(1);
    cout << ways[1] << "\n";
    adj.clear();
    visited.clear();
    ways.clear();
    return 0;
}