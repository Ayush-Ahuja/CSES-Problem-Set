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
    ll n;
    cin >> n;
    vector<pair<ll, ll>> a;
    vector<ll> ans(n+1);
    LOOP(0, n){
        ll x;
        cin >> x;
        a.push_back({x, i+1});
    }
    sort(all(a));
    a.push_back({LLONG_MAX, -1});
    set<ll> s;
    ll i = 0;
    while(i < n){
        vector<ll> idxs;
        while (a[i].first == a[i+1].first){
            idxs.push_back(a[i].second);
            if (!s.empty() && s.upper_bound(a[i].second) != s.begin()){
                auto it = s.upper_bound(a[i].second);
                it--;
                ans[a[i].second] = *it;
            }
            i++;
        }
        idxs.push_back(a[i].second);
        if (s.upper_bound(a[i].second) != s.begin()){
            auto it = s.upper_bound(a[i].second);
            it--;
            ans[a[i].second] = *it;
        }
        i++;
        for (auto idx : idxs) s.insert(idx);
    }
    LOOP(1, n+1){
        cout << ans[i] << " ";
    }
    return 0;
}