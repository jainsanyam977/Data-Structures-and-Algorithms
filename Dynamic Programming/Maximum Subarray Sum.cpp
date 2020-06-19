int maxSubArray(vector<int> vec) {
    // code here
    int cur = 0;
    int res = INT_MIN;
    
    for(auto n: vec){
        cur = max(n, cur+n);
        res = max(res, cur);
    }
    
    return res;
}

// TC - O(n)
// SC - O(1)
