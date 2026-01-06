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

void constructTable(ll k_max, ll n){
    ll siz = ceil(log2(k_max));
    table.resize(n+1, vector<ll>(siz+1));
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, q;
    cin >> n >> q;
    parent.resize(n+1);
    parent[1] = -1;
    LOOP(2, n+1){
        cin >> parent[i];
    }
    constructTable(n, n);
    while(q--){
        ll x, k;
        cin >> x >> k;
        cout << kthAncestor(x, k) << "\n";
    }
    return 0;
}