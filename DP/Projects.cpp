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

vector<vector<ll>> project;
vector<ll> starting;
vector<ll> maxReward;

ll findMaxReward(ll idx){
    if (idx >= project.size()) return 0;
    if (maxReward[idx] != -1) return maxReward[idx];
    auto it = upper_bound(starting.begin(), starting.end(), project[idx][1]);
    ll indx = it - starting.begin();
    return maxReward[idx] = max(project[idx][2] + findMaxReward(indx), findMaxReward(idx+1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    project.resize(n, vector<ll>(3));
    starting.resize(n);
    maxReward.resize(n, -1);
    LOOP(0, n){
        LOOP_(0, 3, j){
            cin >> project[i][j];
        }
    }
    sort(project.begin(), project.end());
    LOOP(0, n){
        starting[i] = project[i][0];
    }
    cout << findMaxReward(0) << "\n";
    return 0;
}