class Solution {
public:
    int memo[10001];
    
    int coinChangeRec(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        if(amount < 0) return INT_MAX;
        if(memo[amount] != -1) return memo[amount];
        
        int total_coins = INT_MAX;
        for(int coin : coins)
            total_coins = min(total_coins, coinChangeRec(coins, amount - coin));

        return memo[amount] = (total_coins != INT_MAX? total_coins + 1 : INT_MAX);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        memset(memo, -1, sizeof(memo));
        int total_coins = coinChangeRec(coins, amount);
        return (total_coins != INT_MAX? total_coins : -1);
    }
};