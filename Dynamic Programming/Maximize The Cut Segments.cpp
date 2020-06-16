int maximizeTheCuts(int n, int x, int y, int z)
{
    //Your code here
    vector<int>dp(n+1, INT_MIN);
    
    dp[0] = 0;
    
    for(int i=0; i<=n; i++){
        if(dp[i]!=INT_MIN){
            if(i+x <= n) dp[i+x] = max(dp[i+x], dp[i]+1);
            if(i+y <= n) dp[i+y] = max(dp[i+y], dp[i]+1);
            if(i+z <= n) dp[i+z] = max(dp[i+z], dp[i]+1);
        }
    }
    
    return max(dp[n], 0);
}

// TC - O(N)
// SC - O(N)
