#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
  BRUTE FORCE:
  We explore two choices at each index: 
   (1) Skip the current element
   (2) Include the current element (if valid)
  Then we pick the better (longer) of the two paths.
*/
int LIS_BruteForce(vector<int>& arr, int curr_idx, int prev_idx, vector<int>& res) {
    // Base case
    if (curr_idx == (int)arr.size()) {
        return 0;
    }
    
    // Skip path
    vector<int> skipRes;
    int skipLen = LIS_BruteForce(arr, curr_idx + 1, prev_idx, skipRes);
    
    // Include path
    vector<int> includeRes;
    int includeLen = 0;
    // We can include current element if it's greater than the one at prev_idx
    if (prev_idx == -1 || arr[curr_idx] > arr[prev_idx]) {
        includeLen = 1 + LIS_BruteForce(arr, curr_idx + 1, curr_idx, includeRes);
        // Prepend current element to the included path
        includeRes.insert(includeRes.begin(), arr[curr_idx]);
    }
    
    // Pick whichever is longer
    if (skipLen >= includeLen) {
        res = skipRes;
        return skipLen;
    } else {
        res = includeRes;
        return includeLen;
    }
}

/*
  MEMOIZATION:
  We store lengths in dp[curr_idx][prev_idx+1], and also store paths in a
  companion data structure. Here, to keep it simpler, we do a quick hack:
  we still build local subsequences and compare them, storing only lengths in dp.
  For an actual project, you might use a separate memo for paths.
*/
int LIS_Memoization_Helper(vector<int>& arr, int curr_idx, int prev_idx,
                           vector<vector<int>>& dp,
                           vector<int>& res) {
    // Base case
    if (curr_idx == (int)arr.size()) {
        return 0;
    }
    
    if (dp[curr_idx][prev_idx + 1] != -1) {
        // If we already know the length, we can do a quick fetch. But for
        // storing the path, we still need the actual path. In a real solution,
        // you'd keep a separate data structure. For demo, we rebuild each time.
    }
    
    // Skip path
    vector<int> skipRes;
    int skipLen = LIS_Memoization_Helper(arr, curr_idx + 1, prev_idx, dp, skipRes);
    
    // Include path
    vector<int> includeRes;
    int includeLen = 0;
    if (prev_idx == -1 || arr[curr_idx] > arr[prev_idx]) {
        includeLen = 1 + LIS_Memoization_Helper(arr, curr_idx + 1, curr_idx, dp, includeRes);
        includeRes.insert(includeRes.begin(), arr[curr_idx]);
    }
    
    int bestLen = 0;
    if (skipLen >= includeLen) {
        bestLen = skipLen;
        res = skipRes;
    } else {
        bestLen = includeLen;
        res = includeRes;
    }
    
    dp[curr_idx][prev_idx + 1] = bestLen;
    return bestLen;
}

int LIS_Memoization(vector<int>& arr, int curr_idx, int prev_idx,
                    vector<vector<int>>& dp, vector<int>& res) {
    return LIS_Memoization_Helper(arr, curr_idx, prev_idx, dp, res);
}

/*
  BOTTOM-UP:
  We keep track of the length of LIS ending at each position in dp[].
  Then use a parent[] array to reconstruct the subsequence.
*/
int LIS_BottomUp(vector<int>& arr, vector<int>& res) {
    int n = (int)arr.size();
    if (n == 0) {
        res.clear();
        return 0;
    }
    
    // dp[i] = length of the LIS ending at i
    // parent[i] = index of the previous element in the LIS ending at i
    vector<int> dp(n, 1), parent(n, -1);
    int max_length = 1, max_index = 0;
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }
        if (dp[i] > max_length) {
            max_length = dp[i];
            max_index = i;
        }
    }
    
    // Reconstruct the LIS using parent pointers
    res.clear();
    int idx = max_index;
    while (idx != -1) {
        res.push_back(arr[idx]);
        idx = parent[idx];
    }
    reverse(res.begin(), res.end());
    
    return max_length;
}

int main() {
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60};
    
    // Prepare separate result vectors
    vector<int> resBrute, resMemo, resBottomUp;
    
    // Brute Force
    int bruteLen = LIS_BruteForce(arr, 0, -1, resBrute);
    cout << "Brute Force length: " << bruteLen << endl;
    cout << "Brute Force LIS: ";
    for (auto val : resBrute) cout << val << " ";
    cout << endl;
    
    // Memoization
    int n = (int)arr.size();
    vector<vector<int>> memo(n, vector<int>(n + 1, -1));
    int memoLen = LIS_Memoization(arr, 0, -1, memo, resMemo);
    cout << "Memoization length: " << memoLen << endl;
    cout << "Memoization LIS: ";
    for (auto val : resMemo) cout << val << " ";
    cout << endl;
    
    // Bottom-up
    int bottomUpLen = LIS_BottomUp(arr, resBottomUp);
    cout << "Bottom-up length: " << bottomUpLen << endl;
    cout << "Bottom-up LIS: ";
    for (auto val : resBottomUp) cout << val << " ";
    cout << endl;
    
    return 0;
}