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

vector<ll> parent;
vector<vector<ll>> table;
vector<ll> depth;
vector<vector<ll>> adj;

void calc_depth(ll u, ll dep, ll par){
    depth[u] = dep;
    for (auto v : adj[u]){
        if (v != par){
            calc_depth(v, dep+1, u);
        }
    }
}

void constructTable(ll k_max, ll n){
    ll siz = ceil(log2(k_max));
    table.resize(n+1, vector<ll>(siz+1));
    adj.resize(n+1);
    depth.resize(n+1);
    LOOP(2, n+1){
        adj[i].push_back(parent[i]);
        adj[parent[i]].push_back(i);
    }
    calc_depth(1, 0, -1);
    LOOP(1, n+1){
        table[i][0] = parent[i];
    }
    LOOP(1, siz+1){
        LOOP_(1, n+1, j){
            if (table[j][i-1] == -1){
                table[j][i] = -1;
            }
            else {
                table[j][i] = table[table[j][i-1]][i-1];
            }    
        }
    }
}


ll kthAncestor(ll u, ll k){
    LOOP(0, 31){
        if (k & (1 << i)){
            u = table[u][i];
            if (u == -1) break;
        }
    }
    return u;
}

ll LowestCommonAncestor(ll a, ll b){
    if (depth[a] > depth[b]){
        swap(a, b);
    }
    b = kthAncestor(b, depth[b] - depth[a]);
    if (b == a){
        return a;
    }
    ll low = 1;
    ll high = depth[a];
    while (high != low){
        ll mid = (low + high)/2;
        if (kthAncestor(a, mid) == kthAncestor(b, mid)){
            high = mid;
        }
        else{
            low = mid + 1;
        }
    }
    return kthAncestor(a, high);
}


// -------------------- Approach 2 -----------------------------------
vector<ll> tin, tout;
vector<ll> value;
ll timer = 0;

void dfs(ll u, ll par){
    tin[u] = timer++;
    parent[u] = par;
    for(auto v : adj[u]){
        if (v != par){
            dfs(v, u);
        }
    }
    tout[u] = timer++;
}

void constructTable2(ll k_max, ll n){
    ll siz = ceil(log2(k_max));
    table.resize(n+1, vector<ll>(siz+1));
    depth.resize(n+1);
    tin.resize(n+1);
    tout.resize(n+1);
    parent.resize(n+1);
    value.resize(n+1);
    calc_depth(1, 0, -1);
    dfs(1, -1);
    LOOP(1, n+1){
        table[i][0] = parent[i];
    }
    LOOP(1, siz+1){
        LOOP_(1, n+1, j){
            if (table[j][i-1] == -1){
                table[j][i] = -1;
            }
            else {
                table[j][i] = table[table[j][i-1]][i-1];
            }    
        }
    }
}

bool isAncestor(ll a, ll b){
    if (a == -1 || b == -1) return 1;
    return tin[a] >= tin[b] && tout[a] <= tout[b];
}

ll lca(ll a, ll b){
    if (isAncestor(a, b)){
        return b;
    }
    else if (isAncestor(b, a)){
        return a;
    }
    for (int i = table[1].size()-1; i >= 0; i--){
        if (!isAncestor(b, table[a][i])){
            a = table[a][i];
        }
    }
    return table[a][0];
}

vector<ll> ans;

ll calc_ans(ll u, ll par){
    ll res = 0;
    for (auto v : adj[u]){
        if (v != par){
            res += calc_ans(v, u);
        }
    }
    res += value[u];
    return ans[u] = res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    adj.resize(n+1);
    ans.resize(n+1);
    LOOP(0, n-1){
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    constructTable2(n, n);
    while(m--){
        ll a, b;
        cin >> a >> b;
        value[a] += 1;
        value[b] += 1;
        ll lc = lca(a, b);
        value[lc] -= 1;
        if (lc != 1){
            value[parent[lc]] -= 1;
        }
    }
    calc_ans(1, -1);
    LOOP(1, n+1){
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}