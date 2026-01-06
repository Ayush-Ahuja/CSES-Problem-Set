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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  // cin >> t;
  t = 1;
  while(t--){
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> num(n+1);
    ll total = 0;
    LOOP(1, n+1){
        ll x;
        cin >> x;
        total += x;
        num[i] = total;
    }
    multiset<ll> ms;
    ll ans = num[a];
    LOOP(0, n+1){
        if (i - a >= 0) ms.insert(num[i-a]);
        if (i - b - 1 >= 0) ms.erase(ms.find(num[i - b - 1]));
        if (ms.size() > 0) ans = max(ans, num[i] - *ms.begin());
    }
    cout << ans << "\n";
  }    
  return 0;
}