class Solution {
public:
    // Greedy fails Thus Try out all possible combination 
    /*
        Recursion => try out all possible ways

            int f(int ind1,int ind2,string text1,string text2){
                if(ind1 == text1.length() || ind2 == text2.length())
                    return 0;
                int res = 0;
                if(text1[ind1] == text2[ind2]) res =  1+f(ind1+1,ind2+1,text1,text2);
                else res =  max(f(ind1+1,ind2,text1,text2),f(ind1,ind2+1,text1,text2));
                return res;
            }   
            int longestCommonSubsequence(string text1, string text2) {
                return f(0,0,text1,text2);
            }

        TC : TC : O(2^n + 2^m)
        SC : O(min(n,m))
    */
    /*
        Memorization

            int f(int ind1,int ind2,vector<vector<int>>& dp,string text1,string text2){
                if(ind1 == text1.length() || ind2 == text2.length()) return 0;
                if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
                int res = 0;
                if(text1[ind1] == text2[ind2]) res =  1+f(ind1+1,ind2+1,dp,text1,text2);
                else res =  max(f(ind1+1,ind2,dp,text1,text2),f(ind1,ind2+1,dp,text1,text2));
                return dp[ind1][ind2] = res;
            }
            int longestCommonSubsequence(string text1, string text2) {
                int size1 = text1.size(), size2 = text2.size();
                vector<vector<int>> dp(size1,vector<int>(size2,-1));
                return f(0,0,dp,text1,text2);
            }
        
        TC : O(N X M)
        SC : O(N X M) + O(N + M) // dp + ASS
    */
    /*
        Tabulation

            int longestCommonSubsequence(string text1, string text2) {
                int size1 = text1.length(), size2 = text2.length();
                vector<vector<int>> dp(size1+1,vector<int>(size2+1,0));
                
                for(int ind1=1;ind1<=size1;ind1++){
                    for(int ind2=1;ind2<=size2;ind2++){
                        if(text1[ind1-1] == text2[ind2-1]) 
                            dp[ind1][ind2] =  1+dp[ind1-1][ind2-1];
                        else
                            dp[ind1][ind2] =  max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
                    }
                }
                return dp[size1][size2];
            }

        TC : O(N X M)
        SC : O(N X M)
    */
    /*
        Space Optimized

        TC : O(N X M)
        SC : O( min(N,M))
    */
    int longestCommonSubsequence(string text1, string text2) {
        int size1 = text1.length(), size2 = text2.length();
        vector<int> prev(size2+1,0);
        
        for(int ind1=1;ind1<=size1;ind1++){
            vector<int> curr(size2+1,0);
            for(int ind2=1;ind2<=size2;ind2++){
                if(text1[ind1-1] == text2[ind2-1]) 
                    curr[ind2] =  1+prev[ind2-1];
                else
                    curr[ind2] =  max(prev[ind2],curr[ind2-1]);
            }
            prev = curr;
        }
        return prev[size2];
    }
    
    
};