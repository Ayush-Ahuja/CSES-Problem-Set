#include <bits/stdc++.h>

using namespace std;

#define LOOP(p, q) for(int i = (p); i < (q); i++)
#define LOOP_(p,q,i) for(int i = (p); i < (q); i++)
#define ll long long
long long GCD(long long a,long long b){
  if(b==0LL) return a;
  else return GCD(b,a%b);
}
long long LCM(long long a,long long b){
  return (a*b)/GCD(a,b);
}

vector<vector<pair<ll, ll>>> adj;
vector<ll> d;
vector<ll> par;

void dijkstra(ll s){
  d[s] = 0;
  set<pair<ll, ll>> ss;
  ss.insert({d[s], s});
  while(!ss.empty()){
    ll v = (*ss.begin()).second;
    ll d_v = (*ss.begin()).first;
    ss.erase(ss.begin());
    for (auto p : adj[v]){
      ll u = p.first;
      ll d_u = d[u];
      if (d_u > (d_v + p.second)){
        ss.erase({d_u, u});
        par[u] = v;
        d[u] = d_v + p.second;
        ss.insert({d[u], u});
      }
    }
  }
}

ll N = 3e5+7;
ll mod = 998244353;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, m;
  cin >> n >> m;
  adj.resize(n+1);
  d.resize(n+1, LLONG_MAX);
  par.resize(n+1, -1);
  LOOP(0, m){
    ll u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
  }
  dijkstra(1);
  LOOP(1, n+1){
    cout << d[i] << " ";
  }
  cout << "\n";
  return 0;
}