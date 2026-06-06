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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    LOOP(0, n) cin >> a[i];
    set<pair<ll, ll>> st;
    map<ll, ll> mp;
    LOOP(0, n){
        st.erase({mp[a[i]], a[i]});
        mp[a[i]]++;
        st.insert({mp[a[i]], a[i]});
        if (i >= k){
            st.erase({mp[a[i-k]], a[i-k]});
            mp[a[i-k]]--;
            st.insert({mp[a[i-k]], a[i-k]});
        }
        auto pr = *(--st.end());
        if (i >= k-1) cout << (*st.upper_bound({pr.first-1, LLONG_MAX})).second << " ";
    }
    cout << "\n";
    return 0;
}