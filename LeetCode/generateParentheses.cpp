class Solution {
public:
    void generateParenthesis(vector<string>& ans, int n, string s, int open, int close){   
        if(s.size() == 2 * n)
            ans.push_back(s);

        if(open < n){
            generateParenthesis(ans, n, s + "(", open+1, close);
        }
        if(close < open){
            generateParenthesis(ans, n, s + ")", open, close+1);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> generated_parenthesis;
        generateParenthesis(generated_parenthesis, n, "(", 1, 0);
        
        return generated_parenthesis;
    }
};