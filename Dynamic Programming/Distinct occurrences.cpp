int subsequenceCount(string S, string T)
{
    //Your code here
    vector<vector<long long int>>dp(T.size()+1, vector<long long int>(S.size()+1, 0));
    
    for(int i=1; i<=T.size(); i++) dp[i][0]=0;
    
    for(int j=0; j<=S.size(); j++) dp[0][j]=1;
    
    for(int i=1; i<=T.size(); i++){
        for(int j=1; j<=S.size(); j++){
            if(T[i-1]!=S[j-1]) dp[i][j] = dp[i][j-1];
            else dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
            
            dp[i][j] %= 1000000007;
        }
    }
    
    return dp[T.size()][S.size()]%1000000007;
}
 
// TC - O(m*n)
// SC - O(m*n)
