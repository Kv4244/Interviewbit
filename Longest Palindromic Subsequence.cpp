class Solution {
public:
    /*
        Basic intution  : if you reverse a string and then find the common subsequence then the answer will be the LCS of both the strings
    */
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        string rev = s;
        reverse(rev.begin(),rev.end());
        vector<int> prev(n+1,0);
        for(int i=1;i<=n;i++){
            vector<int> curr(n+1,0);
            for(int j=1;j<=n;j++){
                if(s[i-1] == rev[j-1])
                    curr[j] = 1 + prev[j-1];
                else
                    curr[j] = max(prev[j],curr[j-1]);
            }
            prev = curr;
        }
        return prev[n];
    }
};
