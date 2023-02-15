#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;

/* Add the required Helper Function */
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n <= 1) {
        return 0;
    }
    vector<int> leftProfit(n), rightProfit(n);
    int leftMin = prices[0];
    for (int i = 1; i < n; i++) {
        leftMin = min(leftMin, prices[i]);
        leftProfit[i] = max(leftProfit[i-1], prices[i]-leftMin);
    }
    int rightMax = prices[n-1];
    for (int i = n-2; i >= 0; i--) {
        rightMax = max(rightMax, prices[i]);
        rightProfit[i] = max(rightProfit[i+1], rightMax-prices[i]);
    }
    int maxProfit = 0;
    for (int i = 0; i < n; i++) {
        maxProfit = max(maxProfit, leftProfit[i]+rightProfit[i]);
    }
    return maxProfit;
}

int main(){
    vector<int> prices_month1 = {3,3,5,0,0,3,1,4};
    /* Answer : 6 */

    vector<int> prices_month2 = {1,2,3,4,5};
    /* Answer : 4 */

    vector<int> prices_month3 = {7,6,4,3,1};
    /* Answer : 0 */
    cout << maxProfit(prices_month1) << endl; // expected output: 6
    cout << maxProfit(prices_month2) << endl; // expected output: 4
    cout << maxProfit(prices_month3) << endl; // expected output: 0

    return 0;
}
