class Solution {
public:
    // **  FOR INTERVIEW BIT CHANGE MIN TO MAX  **
    /*
        Greedy Fails 
    */
    /*
        Recursion
            int f(int i,int j,vector<vector<int>> &triangle){
                if(i == triangle.size())
                    return 0;
                return triangle[i][j] + min(f(i+1,j,triangle),f(i+1,j+1,triangle));
            }
            int minimumTotal(vector<vector<int>>& triangle) {
                return f(0,0,triangle);
            }
    */
    /*
        Memorization

            int f(int i,int j,vector<vector<int>> &dp,vector<vector<int>> &triangle){
                if(i == triangle.size())
                    return 0;
                if(dp[i][j] != -1)
                    return dp[i][j];
                return dp[i][j] = triangle[i][j] + min(f(i+1,j,triangle),f(i+1,j+1,triangle));
            }
            int minimumTotal(vector<vector<int>>& triangle) {
                int n = triangle.size();
                vector<vector<int>> dp(n,vector<int>(n,-1));
                return f(0,0,triangle);
            }

        TC :  
        SC :  

    */
    /*
        Tabulation

            int minimumTotal(vector<vector<int>>& triangle) {
                int n = triangle.size();
                vector<vector<int>> dp(n,vector<int>(n,0));
                dp[n-1] = triangle[n-1];
                for(int i=n-2;i>=0;i--){
                    for(int j=0;j<=i;j++){
                        dp[i][j] = triangle[i][j] + min(dp[i+1][j+1],dp[i+1][j]);
                    }
                }
                
                return dp[0][0];
            }
    */

    /*
        Space Optimized
    */
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> prev(n,0);
        prev = triangle[n-1];
        for(int i=n-2;i>=0;i--){
            vector<int> curr(n,0);
            for(int j=0;j<=i;j++){
                curr[j] = triangle[i][j] + min(prev[j+1],prev[j]);
            }
            prev = curr;
        }                
        return prev[0];
    }
};