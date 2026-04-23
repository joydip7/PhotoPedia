#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int open, int close, string curr, vector<string> &ans, int n) {
        // Base case
        if (curr.length() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        // Add '('
        if (open < n) {
            solve(open + 1, close, curr + "(", ans, n);
        }

        // Add ')'
        if (close < open) {
            solve(open, close + 1, curr + ")", ans, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(0, 0, "", ans, n);
        return ans;
    }
};