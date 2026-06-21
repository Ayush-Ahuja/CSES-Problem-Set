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
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n+1);
    LOOP(0, m){
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    vector<ll> dist(n+1, INT_MAX);
    vector<ll> parent(n+1);
    dist[1] = 0;
    parent[1] = -1;
    ll vertex = -1;
    LOOP(0, n){
        vertex = -1;
        LOOP_(1, n+1, j){
            for (auto &pr : adj[j]){
                ll v = pr.first;
                ll w = pr.second;
                if (dist[v] > dist[j] + w){
                    parent[v] = j;
                    dist[v] = dist[j] + w;
                    vertex = v;
                }
            }
        }
    }
    if (vertex == -1){
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        vector<ll> vertices;
        set<ll> temp;
        for (ll i = vertex; temp.find(i) == temp.end(); i = parent[i], vertex = i){
            temp.insert(i);
        }
        for (ll i = parent[vertex]; i != vertex; i = parent[i]){
            vertices.push_back(i);
        }
        vertices.push_back(vertex);
        vertices.push_back(parent[vertex]);
        reverse(all(vertices));
        for (auto v : vertices){
            cout << v << " ";
        }
        cout << "\n";
    }
    return 0;
}