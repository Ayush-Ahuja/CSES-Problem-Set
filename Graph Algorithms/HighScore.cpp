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
ll mod = 998244353;
ll N = 3e5+7;

vector<vector<pair<ll, ll>>> adj;
vector<ll> d;
vector<ll> cnt;

bool bellman_ford(ll s){
  d[s] = 0;
  vector<bool> inqueue(adj.size());
  queue<ll> q;
  q.push(s);
  inqueue[s] = true;
  cnt[s] += 1;
  while(!q.empty()){
    ll u = q.front();
    q.pop();
    inqueue[u] = false;
    for(auto p : adj[u]){
      ll v = p.first;
      if (d[v] > d[u] + p.second){
        d[v] = d[u] + p.second;
        if(!inqueue[v]){
          q.push(v);
          inqueue[v] = true;
          cnt[v] += 1;
          if (cnt[v] > (adj.size()-1)){
            return false;
          }
        }
      }
    }
  }
  return true;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, m;
  cin >> n >> m;
  adj.resize(n+1);
  cnt.resize(n+1, 0);
  d.resize(n+1, LLONG_MAX);
  LOOP(0, m){
    ll a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b, -1*c});
  }
  bool ans = true;
  vector<ll> parent(n+1, -1);
  d[1] = 0;
  LOOP_(0, 2*n, j){
    LOOP(1, n+1){
      if (d[i] == LLONG_MAX){
        continue;
      }
      for (auto p : adj[i]){
        if (d[p.first] > (d[i] + p.second)){
          d[p.first] = d[i] + p.second;
          parent[p.first] = i;
        }
      }
    }
  }
  set<ll> p;
  for(int v = n; v != -1; v = parent[v]){
    if(p.count(v)){
      ans = false;
      break;
    }
    else{
      p.insert(v);
    }
  }
  if (ans){
    cout << -1*d[n] << "\n";
  }
  else{
    cout << "-1\n";
  }
  return 0;
}