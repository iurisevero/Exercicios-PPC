class Solution {
public:       
    int change(int amount, vector<int>& coins) {
        vector<int> memo(amount + 1);
        memo[0] = 1;
        
        for(int coin : coins)
            for(int i = coin; i <= amount; ++i)
                memo[i] += memo[i - coin];
        
        cout << "Memo:";
        for(int i=0; i<=amount; ++i) cout << " " << memo[i];
        cout << endl;
        
        return memo[amount];
    }
};