int knapSack(int W, int wt[], int val[], int n) 
{ 
   // Your code here
   vector<vector<int>>dp(n+1, vector<int>(W+1, 0));
   
   for(int i=1; i<=n; i++){
       for(int j=1; j<=W; j++){
           if(wt[i-1]<=j){
               dp[i][j] = max(dp[i-1][j], dp[i-1][j-wt[i-1]] + val[i-1]);
           }
           else dp[i][j]=dp[i-1][j];
       }
   }
   
   return dp[n][W];
}

// TC - O(n*W)
// SC - O(n*W)
