class Solution {
public:
    bool binarySearch(string s, vector<string> wordDict){      
        int left = 0, right = wordDict.size(), mid;
        while(left < right){
            mid = left + (right - left)/2;
            if(wordDict[mid] == s) return true;
            if(wordDict[mid] < s)
                left = mid + 1;
            else
                right = mid;
        }
        return false;
    }
    
    map<string, bool> memo;
    bool wordBreakRec(string s, vector<string>& wordDict){
        if(memo.count(s)) return memo[s];
        for(int i=1; i <= s.size(); ++i){
            string first_word = s.substr(0, i);
            if(binarySearch(first_word, wordDict)){
                string second_word = s.substr(i);                
                if(second_word == "" || binarySearch(second_word, wordDict) || wordBreakRec(second_word, wordDict)){
                    memo[s] = true;
                    return true;
                }
                
            }
        }
        memo[s] = false;
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<string> wordDictCopy = wordDict;
        sort(wordDictCopy.begin(), wordDictCopy.end());
        return wordBreakRec(s, wordDictCopy);
    }
};