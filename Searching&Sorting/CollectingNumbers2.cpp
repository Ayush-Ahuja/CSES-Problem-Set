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
const long long MOD = 1e9 + 7;

long long modpow(long long a, long long b) {
  long long res = 1;
  a %= MOD;
  while (b > 0) {
    if (b & 1) res = (res * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}

long long modinv(long long q) {
  return modpow(q, MOD - 2);
}

ll q_update(ll num, unordered_map<ll, ll>& mp, ll n){
    ll ans = 0;
    bool fprev = true;
    if (1 <= num-1 && num+1 <= n){
        if (mp[num-1] < mp[num+1]){
            if (mp[num] > mp[num-1] && mp[num+1] > mp[num]){
                return 0;
            }
            else return 1;
        }
        else {
            if (mp[num] > mp[num-1] && mp[num+1] > mp[num]){
                return 2;
            }
            else return 0;
        }
    }
    else if (1 <= num-1){
        if (mp[num-1] > mp[num]) return 1;
    }
    else if (num+1 <= n){
        if (mp[num+1] < mp[num]) return 1;
    }
    return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  // cin >> t;
  t = 1;
  while(t--){
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n+2);
    vector<ll> b(n+1);
    a[0] = LLONG_MAX;
    a[n+1] = LLONG_MAX;
    LOOP(1, n+1){
        ll x;
        cin >> x;
        b[i] = x;
        a[x] = i;
    }
    ll ans = 0;
    LOOP(1, n+1){
        if (a[i] < a[i-1]) ans++;
    }
    while(m--){
        ll u, v;
        cin >> u >> v;
        if (u == v){
            cout << ans << "\n";
            continue;
        }
        ll num1 = b[u], num2 = b[v];
        ll minn = min(num1, num2);
        ll maxx = max(num1, num2);
        ll diff = maxx - minn;
        if (a[minn] < a[minn - 1]) ans--;
        if (diff != 1 && a[minn + 1] < a[minn]) ans--;
        if (a[maxx] < a[maxx - 1]) ans--;
        if (a[maxx + 1] < a[maxx]) ans--;
        a[num1] = v;
        a[num2] = u;
        swap(b[u], b[v]);
        if (a[minn] < a[minn - 1]) ans++;
        if (diff != 1 && a[minn + 1] < a[minn]) ans++;
        if (a[maxx] < a[maxx - 1]) ans++;
        if (a[maxx + 1] < a[maxx]) ans++;
        cout << ans << "\n";
    }
  }    
  return 0;
}