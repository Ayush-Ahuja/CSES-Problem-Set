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
vector<ll> order;
vector<ll> ids;
vector<ll> values;
ll n;
ll idx = 1;

void dfs(ll u, ll par){
    order.push_back(values[u]);
    ids[u] = idx++;
    ll sub = 0;
    for (auto v : adj[u]){
        if (v != par){
            dfs(v, u);
            sub += subtree[v];
        }
    }
    sub++;
    subtree[u] = sub;
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
    LOOP(1, n+1){
        cin >> values[i];
    }
    LOOP(0, n-1){
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, -1);
    FenwickTree ft = FenwickTree(order);
    while(q--){
        ll type;
        cin >> type;
        if (type == 1){
            ll s, x;
            cin >> s >> x;
            ft.add(ids[s], x - values[s]);
            values[s] = x;
        }
        else{
            ll s;
            cin >> s;
            cout << ft.rangeQuery(ids[s], ids[s] + subtree[s] - 1) << "\n";
        }
    }
    return 0;
}