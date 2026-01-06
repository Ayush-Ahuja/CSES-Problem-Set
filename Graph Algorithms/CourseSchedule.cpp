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
vector<bool> visited;
vector<ll> color;
bool is_cycle = false;
vector<ll> order;

void dfs(ll u){
  color[u] = 1;
  visited[u] = true;
  for (auto v : adj[u]){
    if (!visited[v]){
      dfs(v);
    }
    else if (color[v] == 1){
      is_cycle = true;
    }
  }
  order.push_back(u);
  color[u] = 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    adj.resize(n+1);
    visited.resize(n+1, false);
    color.resize(n+1);
    LOOP(0, m){
      ll u, v;
      cin >> u >> v;
      adj[u].push_back(v);
    }
    LOOP(1, n+1){
      if (!visited[i]){
        dfs(i);
      }
    }
    if (is_cycle){
      cout << "IMPOSSIBLE\n";
    }
    else{
      reverse(order.begin(), order.end());
      LOOP(0, order.size()){
        cout << order[i] << " ";
      }
      cout << "\n";
    }
    return 0;
}