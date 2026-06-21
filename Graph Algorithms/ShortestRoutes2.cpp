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
ll LARGE_VAL = 1e14;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll>> adj(n+1, vector<ll>(n+1, LARGE_VAL));
    LOOP(0, m){
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = min(adj[u][v], w);
        adj[v][u] = min(adj[v][u], w);
    }
    LOOP(1, n+1) adj[i][i] = 0;
    LOOP(1, n+1){
        LOOP_(1, n+1, j){
            LOOP_(j, n+1, k){
                adj[j][k] = min(adj[j][k], adj[min(j, i)][max(j, i)] + adj[min(k, i)][max(k, i)]);
            }
        }
    }
    while(q--){
        ll a, b;
        cin >> a >> b;
        ll u = min(a, b);
        ll v = max(a, b);
        if (adj[u][v] == LARGE_VAL) cout << "-1\n";
        else cout << adj[u][v] << "\n";
    }
    return 0;
}