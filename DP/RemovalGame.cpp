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
ll n;
vector<vector<ll>> score;
vector<ll> a;
vector<ll> prefix_sum;


// recursive
ll optimalScore(ll idx1, ll idx2){
    if (idx1 == idx2) return a[idx1];
    if (score[idx1][idx2] != -1) return score[idx1][idx2];
    return score[idx1][idx2] = max(a[idx1] + prefix_sum[idx2+1] - prefix_sum[idx1+1] - optimalScore(idx1+1, idx2),
                                        a[idx2] + prefix_sum[idx2] - prefix_sum[idx1] - optimalScore(idx1, idx2-1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    score.resize(n, vector<ll>(n, -1));
    a.resize(n);
    prefix_sum.resize(n+1, 0);
    LOOP(0, n){
        cin >> a[i];
    }
    LOOP(1, n+1){
        prefix_sum[i] = prefix_sum[i-1] + a[i-1];
    }
    // iterative
    LOOP_(0, n, diff){
        LOOP_(0, n, idx1){
            if (diff == 0){
                score[idx1][idx1] = a[idx1];
                continue;
            }
            if ((idx1 + diff) < n){
                ll idx2 = idx1+diff;
                score[idx1][idx2] = max(a[idx1] + prefix_sum[idx2+1] - prefix_sum[idx1+1] - score[idx1+1][idx2],
                                    a[idx2] + prefix_sum[idx2] - prefix_sum[idx1] - score[idx1][idx2-1]);
            }
            else break;
        }
    }
    cout << score[0][n-1] << "\n";
    // cout << optimalScore(0, n-1) << "\n"; causes timeout
    return 0;
}