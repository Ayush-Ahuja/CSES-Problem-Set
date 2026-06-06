#include <bits/stdc++.h>
#include <unordered_set>

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    LOOP(0, n) cin >> a[i];
    ll distinct = 0;
    map<ll, ll> mp;
    LOOP(0, n){
        mp[a[i]]++;
        if (mp[a[i]] == 1) distinct++;
        if (i >= k){
            mp[a[i-k]]--;
            if (mp[a[i-k]] == 0) distinct--;
        }
        if (i >= k-1) cout << distinct << " ";
    }
    cout << "\n";
    return 0;
}