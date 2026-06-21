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

vector<ll> visited;
vector<ll> visited_edge;
void dfs(ll u, vector<vector<pair<ll, ll>>> &adj){
    visited[u] = true;
    for (auto v : adj[u]){
        if (!visited[v.first]) dfs(v.first, adj);
    }
}
vector<ll> ans;
void eulerCircuit(ll u, vector<vector<pair<ll, ll>>> &adj){
    while(!adj[u].empty()){
        auto pr = adj[u].back();
        adj[u].pop_back();
        if (!visited_edge[pr.second]) {
            visited_edge[pr.second] = true;
            eulerCircuit(pr.first, adj);
        }
    }
    ans.push_back(u);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n+1);
    visited_edge.resize(m, false);
    vector<ll> deg(n+1);
    visited.resize(n+1, false);
    LOOP(0, m){
        ll a, b;
        cin >> a >> b;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
        deg[a]++;
        deg[b]++;
    }
    dfs(1, adj);
    bool f = false;
    LOOP(1, n+1){
        if (deg[i]%2 != 0 || (deg[i] > 0 && !visited[i])){
            f = true;
            break;
        }
    }
    if (f) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        eulerCircuit(1, adj);
        LOOP(0, ans.size()){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}