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
map<vector<ll>, ll> m;
ll x;

ll minRides(vector<ll> weight){
    ll siz = weight.size();
    if (weight.size() == 1) return 1;
    sort(weight.begin(), weight.end());
    if (m.find(weight) != m.end()) return m[weight];
    ll ans = siz;
    LOOP(0, siz){
        LOOP_(0, siz, j){
            if (j == i) continue;
            if ((weight[j] + weight[i]) > x) continue;
            vector<ll> next;
            LOOP_(0, siz, k){
                if (k == i) continue;
                if (k == j){
                    next.push_back(weight[k] + weight[i]);
                }
                else{
                    next.push_back(weight[k]);
                }
            }
            ans = min(ans, minRides(next));
        }
    }
    m[weight] = ans;
    return m[weight];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n >> x;
    vector<ll> weights(n);
    LOOP(0, n){
        cin >> weights[i];
    }
    cout << minRides(weights) << "\n";
    return 0;
}