int wordBreak(string s, vector<string> &wordDict) {
    //code here
    int n = s.size();
        vector<bool>dp(n+1, false);
        dp[0]=true;
        for(int i=1; i<=n; i++){
            for(int j=i-1; j>=0; j--){
                if(dp[j]){
                    string key = s.substr(j, i-j);
                    if(find(wordDict.begin(), wordDict.end(), key)!=wordDict.end()){
                        dp[i]=true;
                        break;
                    }
                }  
            }
        }
        return dp[n];
}

// TC - O(n^2)
// SC - O(n)
