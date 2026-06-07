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
ll ans = 0;
ll n, k;

void solve(ll u, ll par, ll depth, unordered_map<ll, ll>& depths){
    depths[depth]++;
    for (auto v : adj[u]){
        if (v != par){
            unordered_map<ll, ll> temp;
            solve(v, u, depth+1, temp);
            if (depths.size() < temp.size()) swap(depths, temp);
            for (auto pr : temp){
                if (depths.find(k + 2*depth - pr.first) != depths.end()) {
                    ans += pr.second * depths[k + 2*depth - pr.first];
                    // cout << "u: " << u << "\n";
                }
            }
            for (auto pr : temp){
                depths[pr.first] += pr.second;
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    adj.resize(n+1);
    LOOP(0, n-1){
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<ll, ll> temp;
    solve(1, -1, 0, temp);
    cout << ans << "\n";
    return 0;
}