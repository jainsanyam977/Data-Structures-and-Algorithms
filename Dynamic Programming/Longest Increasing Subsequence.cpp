int longestSubsequence(int n, int a[])
{
   // your code here
   vector<int>dp(n, 1);
   
   int res = 1;
   
   for(int i=1; i<n; i++){
       for(int j=0; j<i; j++){
           if(a[j]<a[i]) dp[i] = max(dp[i], dp[j]+1);
           res = max(res, dp[i]);
       }
   }
   
   return res;
}

// TC - O(n^2)
// SC - O(n)
