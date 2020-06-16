int wildCard(string pattern,string str)
{
    vector<vector<int>>dp(pattern.size()+1, vector<int>(str.size()+1, 0));
    
    dp[0][0] = 1;
    
    for(int i=1; i<=pattern.size(); i++){
        for(int j=1; j<=str.size(); j++){
            if(pattern[i-1]=='?' || pattern[i-1]==str[j-1]) dp[i][j]=dp[i-1][j-1];
            else if(pattern[i-1]=='*'){
                dp[i][0]=dp[i-1][0];
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
            } 
        }
    }
    
    return dp[pattern.size()][str.size()];
}

// TC - O(pattern.size()*str.size())
// SC - O(pattern.size()*str.size())
