#include <bits/stdc++.h>

using namespace std;

#define LOOP(p, q) for(int i = (p); i < (q); i++)
#define LOOP_(p, q, i) for(int i = (p); i < (q); i++)
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

long long modpow(long long a, long long b, long long mod) {
  long long res = 1;
  a %= mod;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}

long long modinv(long long q, long long mod) {
  return modpow(q, mod - 2, mod);
}

vector<ll> fact, inv_fact;

void precompute_factorials(int n, long long mod) {
  fact.resize(n + 1);
  inv_fact.resize(n + 1);
  fact[0] = 1;
  for (int i = 1; i <= n; i++) {
    fact[i] = (fact[i-1] * i) % mod;
  }
  inv_fact[n] = modinv(fact[n], mod);
  for (int i = n - 1; i >= 0; i--) {
    inv_fact[i] = (inv_fact[i+1] * (i+1)) % mod;
  }
}

long long nCk(int n, int k, long long mod) {
  if (k > n || k < 0) return 0;
  return (fact[n] * inv_fact[k] % mod) * inv_fact[n-k] % mod;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll tt;
  // cin >> tt;
  tt = 1;
  while(tt--){
    ll n;
    cin >> n;
    vector<ll> a(n);
    LOOP(0, n){
        cin >> a[i];
    }
    ll ans = 0;
    LOOP(1, n){
        if (a[i] < a[i-1]){
            ans += a[i-1] - a[i];
            a[i] = a[i-1];
        }
    }
    cout << ans << "\n";
  } 
  return 0;
}