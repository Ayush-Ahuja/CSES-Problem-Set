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

ll n;
vector<vector<ll>> adj;
vector<ll> order;
vector<ll> subtree;
vector<ll> diff;

void dfs(ll u, ll par = -1){
    ll sub = 0;
    order.push_back(u);
    for (auto v : adj[u]){
        if (v != par){
            dfs(v, u);
            sub += subtree[v];
        }
    }
    subtree[u] = sub + 1;
}

void path_sum(ll u, ll idx, ll par = -1){
    ll curr = idx + 1;
    for (auto v : adj[u]){
        if (v != par){
            diff[curr] += (n-subtree[v]);
            diff[curr + subtree[v]] -= (n-subtree[v]);
            diff[1] += subtree[v];
            diff[curr] -= subtree[v];
            diff[curr + subtree[v]] += subtree[v];
            path_sum(v, curr, u);
            curr += subtree[v];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    adj.resize(n+1);
    subtree.resize(n+1);
    diff.resize(n+2);
    LOOP(0, n-1){
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    order.push_back(0);
    dfs(1);
    order.push_back(0);
    path_sum(1, 1);
    vector<pair<ll, ll>> ans;
    ll temp = 0;
    LOOP(1, n+1){
        temp += diff[i];
        ans.push_back({order[i], temp});
    }
    sort(ans.begin(), ans.end());
    LOOP(0, n){
        cout << ans[i].second << " ";
    }
    cout << "\n";
    return 0;
}