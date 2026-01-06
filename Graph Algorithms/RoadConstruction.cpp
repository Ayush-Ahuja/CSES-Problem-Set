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

vector<ll> siz;
vector<ll> parent;
ll max_siz;

void make(ll u){
    parent[u] = u;
    siz[u] = 1;
}

ll find(ll u){
    if (parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

void Union(ll u, ll v){
    ll u_par = find(u);
    ll v_par = find(v);
    if (siz[u_par] > siz[v_par]){
        swap(u_par, v_par);
    }
    parent[u_par] = v_par;
    siz[v_par] += siz[u_par];
    max_siz = max(siz[v_par], max_siz);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> edges;
    siz.resize(n+1);
    parent.resize(n+1);
    LOOP(0, m){
        ll u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    LOOP(1, n+1){
        make(i);
    }
    ll comp = n;
    max_siz = 1;
    for (auto e : edges){
        if (find(e[0]) != find(e[1])){
            Union(e[0], e[1]);
            comp--;
        }
        cout << comp << " " << max_siz << "\n";
    }
    siz.clear();
    parent.clear();
    return 0;
}