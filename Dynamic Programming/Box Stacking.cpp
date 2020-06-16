bool comp(vector<int>a, vector<int>b){
    return a[1]*a[2] > b[1]*b[2];
} 

int maxHeight(int height[],int width[],int length[],int n)
{
    //Your code here
    vector<vector<int>>boxes(3*n, vector<int>(3));
    int i = 0;
    int j=0;
    
    while(i<3*n){
        boxes[i][0]= height[j];
        boxes[i][1]= max(width[j], length[j]);
        boxes[i][2]= min(width[j], length[j]);
        i++;
        
        boxes[i][0]= width[j];
        boxes[i][1]= max(height[j], length[j]);
        boxes[i][2]= min(height[j], length[j]);
        i++;
        
        boxes[i][0]= length[j];
        boxes[i][1]= max(width[j], height[j]);
        boxes[i][2]= min(width[j], height[j]);
        i++;
        
        j++;
    }
    
    sort(boxes.begin(), boxes.end(), comp);
    
    vector<int>dp(3*n);
    
    int res = 0;
    
    for(int k=0; k<3*n; k++){
        dp[k] = boxes[k][0];
        
        for(int l=0; l<k; l++){
            if(boxes[l][1]>boxes[k][1] && boxes[l][2]>boxes[k][2]) dp[k] = max(dp[k], boxes[k][0] + dp[l]);
        }
        
        res = max(res, dp[k]);
        
    }
    
    return res;
    
}

// TC - O(n^2)
// SC - O(n)
