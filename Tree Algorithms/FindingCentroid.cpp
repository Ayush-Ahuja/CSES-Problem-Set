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
ll minn = LLONG_MAX;
ll ans = -1;
ll n;

ll solve(ll u, ll par){
    ll maxx = 0;
    ll subtree_size = 1;
    for (auto v : adj[u]){
        if (v != par){
            ll sizee = solve(v, u);
            subtree_size += sizee;
            maxx = max(maxx, sizee);
        }
    }
    maxx = max(maxx, n - subtree_size);
    if (maxx < minn) {
        ans = u;
        minn = maxx;
    }
    return  subtree_size;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    adj.resize(n+1);
    LOOP(0, n-1){
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    solve(1, -1);
    cout << ans << "\n";
    return 0;
}