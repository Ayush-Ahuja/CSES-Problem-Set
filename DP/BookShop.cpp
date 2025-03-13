#include <bits/stdc++.h>

using namespace std;

#define LOOP(p, q) for(int i = (p); i < (q); i++)
#define LOOP_(p,q,i) for(int i = (p); i < (q); i++)
#define ll long long
long long GCD(long long a,long long b){
  if(b==0LL) return a;
  else return GCD(b,a%b);
}
long long LCM(long long a,long long b){
  return (a*b)/GCD(a,b);
}


class Solution {
public:
    // Function to return max value that can be put in knapsack of capacity.
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
        
        // Fill the dp table bottom-up
        for (int i = 1; i <= n; i++) {
            for (int w = 0; w <= capacity; w++) {
                // If current item's weight is less than or equal to current capacity
                if (wt[i-1] <= w) {
                    // Choose maximum of including or excluding current item
                    dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]], dp[i-1][w]);
                } else {
                    // Can't include current item, so take previous result
                    dp[i][w] = dp[i-1][w];
                }
            }
        }
        
        return dp[n][capacity];
    }
};

ll N = 3e5+7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    vector<int> val, wt;
    cin >> n >> x;
    LOOP(0, n){
      int s;
      cin >> s;
      wt.push_back(s);
    }
    LOOP(0, n){
        int s;
        cin >> s;
        val.push_back(s);
    }
    Solution ss;
    cout << ss.knapSack(x, val, wt);
}