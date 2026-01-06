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
vector<ll> subtree;
vector<ll> ids;
vector<ll> values;
vector<ll> path_values;
ll n;
ll idx = 1;

void dfs(ll u, ll par, ll pathSum){
    ids[u] = idx++;
    ll sub = 0;
    for (auto v : adj[u]){
        if (v != par){
            dfs(v, u, pathSum + values[u]);
            sub += subtree[v];
        }
    }
    sub++;
    subtree[u] = sub;
    path_values[u] = pathSum + values[u];
}

struct FenwickTree {
    ll siz;
    vector<ll> bit;

    FenwickTree(ll n) {
        this->siz = n;
        bit.assign(n+1, 0);
    }

    FenwickTree(vector<ll> const &a) : FenwickTree(a.size()) {
        for (ll i = 0; i < siz; ++i) {
            add(i + 1, a[i]);
        }
    }
    
    void add(ll idx, ll delta){
        for (int i = idx; i <= siz; i += (i&-i)){
            bit[i] += delta;
        }
    }

    ll getValue(ll idx){
        ll res = 0;
        for (int i = idx; i > 0; i -= (i&-i)){
            res += bit[i];
        }
        return res;
    }

    ll rangeQuery(ll l, ll r){
        return getValue(r) - getValue(l-1);
    }

    void rangeUpdate(ll l, ll r, ll delta){
        add(l, delta);
        add(r+1, -delta);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll q;
    cin >> n >> q;
    values.resize(n+1);
    adj.resize(n+1);
    subtree.resize(n+1);
    ids.resize(n+1);
    path_values.resize(n+1);
    LOOP(1, n+1){
        cin >> values[i];
    }
    LOOP(0, n-1){
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, -1, 0);
    FenwickTree ft = FenwickTree(n);
    while(q--){
        ll type;
        cin >> type;
        if (type == 1){
            ll s, x;
            cin >> s >> x;
            ft.rangeUpdate(ids[s], ids[s] + subtree[s] - 1, x - values[s]);
            values[s] = x;
        }
        else{
            ll s;
            cin >> s;
            cout << path_values[s] + ft.getValue(ids[s]) << "\n";
        }
    }
    return 0;
}