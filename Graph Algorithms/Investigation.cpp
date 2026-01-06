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

vector<vector<pair<ll, ll>>> adj;
vector<ll> ways;
vector<pair<ll, ll>> dist;

void min_flight(ll src){
    set<pair<pair<ll, ll>, ll>> s;
    s.insert({{0, 0}, src});
    ways[src] = 1;
    dist[src] = {0, 0};
    while(!s.empty()){
        ll top = (*s.begin()).second;
        pair<ll, ll> dis = (*s.begin()).first;
        s.erase(s.begin());
        for (auto p : adj[top]){
            ll distance = dist[p.first].first;
            if (dist[p.first] > make_pair(dis.first + p.second, dis.second+1)){
                s.erase({dist[p.first], p.first});
                dist[p.first] = make_pair(dis.first + p.second, dis.second+1);
                s.insert({dist[p.first], p.first});
                if (distance != (dis.first + p.second)){
                    ways[p.first] = ways[top];
                    continue;
                }
            }
            if (dist[p.first].first == (dis.first + p.second)){
                ways[p.first] = (ways[p.first] +  ways[top])%mod2;
            }
        }
    }
}

void max_flight(ll src){
    set<pair<pair<ll, ll>, ll>> s;
    s.insert({{0, 0}, src});
    ways[src] = 1;
    dist[src] = {0, 0};
    while(!s.empty()){
        ll top = (*s.begin()).second;
        pair<ll, ll> dis = (*s.begin()).first;
        s.erase(s.begin());
        for (auto p : adj[top]){
            if (dist[p.first] > make_pair(dis.first + p.second, dis.second-1)){
                s.erase({dist[p.first], p.first});
                dist[p.first] = make_pair(dis.first + p.second, dis.second-1);
                s.insert({dist[p.first], p.first});
            }
            if (dist[p.first].first == (dis.first + p.second)){
                ways[p.first] = (ways[p.first] +  ways[top])%mod2;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    ways.resize(n+1);
    adj.resize(n+1);
    dist.resize(n+1, {LLONG_MAX, LLONG_MAX});
    LOOP(0, m){
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    min_flight(1);
    cout << dist[n].first << " " << ways[n]%mod2 << " " << dist[n].second << " ";
    dist.assign(n+1, {LLONG_MAX, LLONG_MAX});
    ways.assign(n+1, 0);
    max_flight(1);
    cout << -1 * dist[n].second << "\n";
    return 0;
}