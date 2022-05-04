// 7ms 8.1MB
class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word = "";
        for(size_t i=0; i < s.size(); ++i){
            if(s[i] == ' '){
                if(word.size() > 0){
                    words.push_back(word);
                    word = "";
                }
                continue;
            }
            word.push_back(s[i]);
        }
        
        if(word.size() > 0){
            words.push_back(word);
            word = "";
        }
        reverse(words.begin(), words.end());

        string out;
        for(string w : words){
            out.append(w);
            out.push_back(' ');
        }
        out.pop_back();
        return out;
    }
};


// 9ms 7.2MB
class Solution {
public:
    string reverseWords(string s) {
        string out = "";
        string word = "";
        for(int i=s.size() - 1; i >= 0; --i){
            if(s[i] == ' '){
                if(word.size() > 0){
                    out.append(word.rbegin(), word.rend());
                    out.push_back(' ');
                    word = "";
                }
                continue;
            }
            word.push_back(s[i]);
        }
        
        if(word.size() > 0)
            out.append(word.rbegin(), word.rend());
        else
            out.pop_back();

        return out;
    }
};