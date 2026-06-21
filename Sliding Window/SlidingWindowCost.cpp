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

ll first_sum = 0;
ll last_sum = 0;

void insert_elem(multiset<ll>& first, multiset<ll>& second, ll elem){
    if (first.empty()) {
        first.insert(elem);
        first_sum += elem;
    }
    else if (*(--first.end()) < elem) {
        second.insert(elem);
        last_sum += elem;
    }
    else {
        first.insert(elem);
        first_sum += elem;
    }
    if (first.size() < second.size()){
        ll first_elem = *(second.begin());
        first.insert(first_elem);
        second.erase(second.begin());
        first_sum += first_elem;
        last_sum -= first_elem;
    }
    else if (first.size() - second.size() > 1){
        ll last_elem = *(--first.end());
        first.erase(--first.end());
        second.insert(last_elem);
        first_sum -= last_elem;
        last_sum += last_elem;
    }
}

void remove_elem(multiset<ll>& first, multiset<ll>& second, ll elem){
    if (*(--first.end()) < elem) {
        second.erase(second.find(elem));
        last_sum -= elem;
    }
    else {
        first.erase(first.find(elem));
        first_sum -= elem;
    }
    if (first.size() < second.size()){
        ll first_elem = *(second.begin());
        first.insert(first_elem);
        second.erase(second.begin());
        first_sum += first_elem;
        last_sum -= first_elem;
    }
    else if (first.size() - second.size() > 1){
        ll last_elem = *(--first.end());
        first.erase(--first.end());
        second.insert(last_elem);
        first_sum -= last_elem;
        last_sum += last_elem;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    LOOP(0, n){
        cin >> a[i];
    }
    vector<ll> ans;
    multiset<ll> first;
    multiset<ll> second;
    LOOP(0, n){
        insert_elem(first, second, a[i]);
        if (i >= k) remove_elem(first, second, a[i-k]);
        if (i >= k-1){
            ll med = *(--first.end());
            ll cost = med*first.size() - first_sum + last_sum - second.size() * med;
            ans.push_back(cost);
        }
    }
    LOOP(0, ans.size()){
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}