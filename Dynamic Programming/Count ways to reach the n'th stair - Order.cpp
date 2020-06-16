long long countWays(int m){
    // your code here
    long long temp1, temp2;
    
    if(m==1) return 1;
    else temp1 = 1;
    
    if(m==2) return 2;
    else temp2 = 2;
    
    long long res;
    
    for(int i=3; i<=m; i++){
        res = temp1+temp2;
        temp1 = temp2;
        temp2 = res;
        res   %= 1000000007;
        temp2 %= 1000000007;
    }
    
    return res;
}

// TC - O(m)
// SC - O(1)
