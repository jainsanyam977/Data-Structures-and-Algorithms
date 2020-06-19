void solve1(string A, int i, int &res, int &mi, int &mj){
    if(i==A.size()-1) return;
    int x = i, y=i+1;
    
    while(x>=0 && y<A.size() && A[x]==A[y]){
        x--;
        y++;
    }
    
    if(y-x-1 > res){
        res = y-x-1;
        mi = x+1;
        mj = y-1;
    }
    
    return;
}

void solve2(string A, int i, int &res, int &mi, int &mj){
    if(i==0 || i==A.size()-1) return;
    int x = i-1, y=i+1;
    
    while(x>=0 && y<A.size() && A[x]==A[y]){
        x--;
        y++;
    }
    
    if(y-x-1 > res){
        res = y-x-1;
        mi = x+1;
        mj = y-1;
    }
    
    return;
    
}

string longestPalindrome(string A) {
    // code here
    int res = 1;
    int mi=0, mj=0;
    for(int i=0; i<A.size(); i++){
        solve1(A, i, res, mi, mj);
        solve2(A, i, res, mi, mj);
    }
    return A.substr(mi, mj-mi+1);
}

// TC - O(n^2)
// SC - O(1)
