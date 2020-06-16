long long countWays(int n){
    
    // your code here
    long long  temp1, temp2, temp3;
    
    long long res;
    
    if(n==1) return 1;
    else temp1 = 1;
    
    if(n==2) return 2;
    else temp2 = 2;
    
    if(n==3) return 4;
    else temp3 = 4;
    
    for(int i=4; i<=n; i++){
        res = temp1+temp2+temp3;
        temp1 = temp2;
        temp2 = temp3;
        temp3 = res;
        res %= 1000000007;
        temp3 %= 1000000007;
    }
    
    return res;
}

// TC-  O(N)
// SC - O(1)
