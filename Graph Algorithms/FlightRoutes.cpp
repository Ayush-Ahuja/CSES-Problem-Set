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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<ll, ll>>> adj(n+1);
    LOOP(0, m){
        ll a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }
    vector<multiset<ll>> dist(n+1);
    multiset<pair<ll, ll>> ms;
    ms.insert({0, 1});
    dist[1].insert(0);
    while(!ms.empty()){
        auto pr = *ms.begin();
        ms.erase(ms.begin());
        ll dis = pr.first;
        ll u = pr.second;
        for (auto p : adj[u]){
            ll v = p.first;
            ll w = p.second;
            if (dist[v].size() == k){
                ll old_dis = *(--dist[v].end());
                if (old_dis > dis + w){
                    ms.erase(ms.find({old_dis, v}));
                    dist[v].erase(dist[v].find(old_dis));
                    dist[v].insert(dis + w);
                    ms.insert({dis+w, v});
                }
            }
            else {
                dist[v].insert(dis + w);
                ms.insert({dis+w, v});
            }
        }
    }
    for (auto ans : dist[n]){
        cout << ans << " ";
    }
    cout << "\n";
    return 0;
}