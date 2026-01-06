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
vector<bool> isInvolved;

ll maxPairs(ll u, ll par){
    ll child = 0;
    ll total_pairs = 0;
    for (auto v : adj[u]){
        if (v != par){
            total_pairs += maxPairs(v, u);
            if (!isInvolved[v]){
                child = v;
            }
        }
    }
    if (child){
        isInvolved[u] = true;
        isInvolved[child] = true;
        total_pairs++;
    }
    return total_pairs;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    adj.resize(n+1);
    isInvolved.resize(n+1);
    LOOP(0, n-1){
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << maxPairs(1, -1) << "\n";
    return 0;
}