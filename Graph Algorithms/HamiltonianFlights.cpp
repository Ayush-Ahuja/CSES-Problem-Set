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

ll n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    vector<vector<int>> in_adj(n);
    LOOP(0, m){
        ll a, b;
        cin >> a >> b;
        a--; b--;
        in_adj[b].push_back(a);
    }
    
    vector<vector<int>> dp(1 << n, vector<int>(n, 0));
    dp[1][0] = 1; // Base case: starting at vertex 0 with only vertex 0 visited
    
    for (int mask = 2; mask < (1 << n); mask++) {
        // Any valid path must start at vertex 0 (Syrjälä)
        if ((mask & 1) == 0) continue; 
        
        // We can only reach vertex n-1 (Lehmäla) if we have visited all vertices
        if ((mask & (1 << (n - 1))) && mask != (1 << n) - 1) continue;
        
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                int prev_mask = mask ^ (1 << i);
                for (int u : in_adj[i]) {
                    if (prev_mask & (1 << u)) {
                        dp[mask][i] = (dp[mask][i] + dp[prev_mask][u]) % mod2;
                    }
                }
            }
        }
    }
    
    cout << dp[(1 << n) - 1][n - 1] << "\n";
    return 0;
}