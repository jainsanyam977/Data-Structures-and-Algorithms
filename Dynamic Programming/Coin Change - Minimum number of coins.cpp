long long minimumNumberOfCoins(int coins[],int numberOfCoins,int value)
{
    long long minimumNumberOfCoinsRequired[value+1]={0};
    //The above array holds the minimum number of coins for every amount from 0 to value
    
    
    minimumNumberOfCoinsRequired[0]=0;
    //
    
    for(int i=1;i<value+1;i++)
    {
        minimumNumberOfCoinsRequired[i]=INT_MAX;
        //We fill all array with inifinty as intially we need infinite coins to make the value
    }
    
    vector<int> coinsSet;
    
    for(int i=0;i<numberOfCoins;i++)
    {
        coinsSet.push_back(coins[i]);
    }
    
    
    for(auto coin:coinsSet) //Iterating over each coin
    {
        for(int i=1;i<value+1;i++)
        {
            if(i>=coin) //No use in checking for values that are smaller than the current coin
            {
                if(minimumNumberOfCoinsRequired[i-coin] != INT_MAX) minimumNumberOfCoinsRequired[i] = 
                    min(minimumNumberOfCoinsRequired[i], minimumNumberOfCoinsRequired[i-coin]+1);
              
            }
        }
    }
    
    return minimumNumberOfCoinsRequired[value];
}
