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
vector<ll> depth;
vector<bool> visited;
vector<ll> child;
ll n;

void dfs(ll u){
  visited[u] = true;
  ll ans = depth[u];
  for (auto v : adj[u]){
    if (!visited[v]){
      dfs(v);
    }
    if (ans < depth[v]){
      ans = max(ans, depth[v]);
      child[u] = v;
    }
  }
  if (ans > 0 && u != n){
    depth[u] = 1 + ans;
  }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll m;
    cin >> n >> m;
    adj.resize(n+1);
    depth.resize(n+1);
    visited.resize(n+1, false);
    child.resize(n+1);
    LOOP(0, m){
      ll u, v;
      cin >> u >> v;
      adj[u].push_back(v);
    }
    depth[n] = 1;
    child[n] = -1;
    dfs(1);
    if (depth[1] == 0){
      cout << "IMPOSSIBLE\n";
    }
    else{
      cout << depth[1] << "\n";
      // LOOP(1, n+1){
      //   cout << depth[i] << " ";
      // }
      for (ll v = 1; v != -1; v = child[v]){
        cout << v << " ";
      }
      cout << "\n";
    }   
    adj.clear();
    depth.clear();
    visited.clear();
    child.clear();
    return 0;
}