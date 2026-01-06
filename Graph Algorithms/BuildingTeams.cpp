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
vector<ll> d;

void bfs(ll s){
    queue<ll> q;
    q.push(s);
    d[s] = 0;
    visited[s] = true;
    while(!q.empty()){
        ll u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
                d[v] = 1 + d[u];
            }
        }
    }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, m;
  cin >> n >> m;
  adj.resize(n+1);
  LOOP(0, m){
    ll u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  visited.resize(n+1, false);
  d.resize(n+1);
  vector<ll> team(n+1);
  LOOP(1, n+1){
    if (!visited[i]){
        bfs(i);
    }
  }
  LOOP(1, n+1){
    if (d[i]%2 == 0){
        team[i] = 1;
    }
    else{
        team[i] = 2;
    }
  }
  ll f = 0;
  LOOP(1, n+1){
    for (auto u : adj[i]){
        if (team[i] == team[u]){
            f = 1;
        }
    }
  }
  if (f){
    cout << "IMPOSSIBLE\n";
  }
  else{
    LOOP(1, n+1){
        cout << team[i] << " ";
    }
    cout << "\n";
  }
  return 0;  
}