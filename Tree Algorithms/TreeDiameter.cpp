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
vector<ll> depth;
vector<bool> visited;
vector<vector<ll>> adj;

void find_depth(ll u, ll dep = 0){
    visited[u] = true;
    depth[u] = dep;
    for(auto v : adj[u]){
        if(!visited[v]){
            find_depth(v, dep+1);
        }
    }
}

ll N = 3e5+7;
ll mod = 998244353;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    adj.resize(n+1);
    visited.resize(n+1, false);
    depth.resize(n+1, 0);
    LOOP(0, n-1){
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    find_depth(1);
    ll max_depth = 0;
    ll max_node = 0;
    LOOP(1, n+1){
        if(depth[i] > max_depth){
            max_depth = depth[i];
            max_node = i;
        }
    }
    visited.assign(n+1, false);
    depth.assign(n+1, 0);
    find_depth(max_node);
    max_depth = 0;
    LOOP(1, n+1){
        max_depth = max(depth[i], max_depth);
    }
    cout << max_depth << "\n";
    visited.clear();
    depth.clear();
    adj.clear(); 
    return 0;
}