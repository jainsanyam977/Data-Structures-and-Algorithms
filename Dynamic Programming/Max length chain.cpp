bool comp(vector<int>a, vector<int>b){
    return a[0]<b[0];
}

int maxChainLen(struct val p[],int n)
{
    //Your code here
    vector<vector<int>>chains(n);
    
    for(int i=0; i<n; i++){
        chains[i].push_back(p[i].first);
        chains[i].push_back(p[i].second);
    }
    
    sort(chains.begin(), chains.end(), comp);
    
    vector<int>dp(n,1);
    
    int res = 1;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(chains[i][0] > chains[j][1]) dp[i] = max(dp[i], dp[j]+1);
        }
        res = max(res, dp[i]);
    }
    
    return res;
}

// TC - O(n^2)
// SC - O(n)
