class Solution {
public:
    int lengthOfLongestSubstring(string s) {
//         int longestLength = 0;
//         bool findLongest = false;
//         // O(n²) I can improve that
//         for(int i=0; i < s.size(); ++i){
//             unordered_set<char> visitedChars;
//             for(int j=i; j < s.size(); ++j){               
//                 if(visitedChars.count(s[j])){
//                     longestLength = max(longestLength, j - i);
//                     break;
//                 }
                
//                 if(j + 1 == s.size()){
//                     longestLength = max(longestLength, j - i + 1);
//                     findLongest = true;
//                     break;
//                 }
                
//                 visitedChars.insert(s[j]);
//             }
            
//             if(findLongest)
//                 break;
//         }
//         return longestLength;
        
        // --------------- Improving ---------------------- //
        // time O(2*n) || space O(128) || memory 1 * 128 + 4 * 128
//         int longestLength = 0;

//         unordered_map<char, int> visitedChars;
//         int substringStart = 0, i;
//         for(i=0; i < s.size(); ++i){               
//             if(visitedChars.count(s[i])){
//                 debug(longestLength); debug(i - substringStart);
//                 longestLength = max(longestLength, i - substringStart);
//                 int substringFinish = visitedChars[s[i]];
//                 for(int j = substringStart; j <= substringFinish; ++j){
//                     visitedChars.erase(s[j]);
//                 }
//                 substringStart = substringFinish + 1;
//             }
//             visitedChars[s[i]] = i;
//         }
//         debug(longestLength); debug(i - substringStart);
//         longestLength = max(longestLength, i - substringStart);
//         return longestLength;

        // --------------- Improving More ---------------------- //
        // time O(2*n) || space O(n) || memory 128 * 4
        int longestLength = 0;
        vector<int> visitedChars(128, -1);
        int substringStart = 0, i;
        for(i=0; i < s.size(); ++i){               
            if(visitedChars[s[i]] != -1){
                longestLength = max(longestLength, i - substringStart);
                int substringFinish = visitedChars[s[i]];
                for(int j = substringStart; j <= substringFinish; ++j){
                    visitedChars[s[j]] = -1;
                }
                substringStart = substringFinish + 1;
            }
            visitedChars[s[i]] = i;
        }
        longestLength = max(longestLength, i - substringStart);
        return longestLength;
    }
};