bool findPartition(int a[], int n) {
    // code here
    
    int sum = 0;
    
    for(int i=0; i<n; i++) sum += a[i];
    
    if(sum%2 ==1) return false;
    
    sum /= 2;
    
    vector<int>prev(sum+1, 0);
    vector<int>cur(sum+1);
    
    prev[0]=1;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            cur[j] = prev[j];
            if(a[i-1]<=j) cur[j] = max(cur[j], prev[j-a[i-1]]);
        }
        prev = cur;
    }
    
    return cur[sum];
}

// TC - O(sum*n)
// SC - O(sum)
