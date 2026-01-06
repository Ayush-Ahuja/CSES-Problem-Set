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
  ll tt;
  // cin >> tt;
  tt = 1;
  while(tt--){
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll total = 0;
    LOOP(0, n){
        cin >> a[i];
        total += a[i];
    }
    total /= k;
    vector<ll> num;
    num.push_back(0);
    ll curr = 0;
    ll ans = 0;
    LOOP(0, n){
        curr += a[i];
        auto it = upper_bound(all(num), curr - total);
        if (it != num.begin()){
            it--;
            ans = max(ans, curr - *it);
        }
        num.push_back(curr);
    }
    cout << ans << "\n";
  } 
  return 0;
}