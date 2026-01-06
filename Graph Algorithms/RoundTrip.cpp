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

vector<vector<ll>> adj;
vector<ll> visited;
vector<ll> parent;
ll cycle_start = -1;
ll cycle_end;

bool dfs(ll s, ll par){
  visited[s] = true;
  parent[s] = par;
  for (ll v : adj[s]){
      if (!visited[v]){
        if (dfs(v, s)){
          return true;
        }
      }
      else if (v == par){
        continue;
      }
      else {
        cycle_start = v;
        cycle_end = s;
        return true;
      }
  }
  return false;
}

vector<ll> find_cycle(){
  vector<ll> cycle;
  cycle.push_back(cycle_start);
  for (int u = cycle_end; u != cycle_start; u = parent[u]){
      cycle.push_back(u);
  }
  cycle.push_back(cycle_start);
  reverse(cycle.begin(), cycle.end());
  return cycle;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, m;
  cin >> n >> m;
  adj.resize(n+1);
  visited.resize(n+1, false);
  parent.resize(n+1);
  LOOP(0, m){
    ll u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  LOOP(1, n+1){
    if (!visited[i] && dfs(i, -1)){
      break;
    }
  }
  if(cycle_start == -1){
    cout << "IMPOSSIBLE\n";
  }
  else{
    vector<ll> cycle = find_cycle();
    cout << cycle.size() << "\n";
    LOOP(0, cycle.size()){
      cout << cycle[i] << " ";
    }
    cout << "\n";
  }
  return 0;  
}