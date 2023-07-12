class Solution {
public:
    long long int MAX_INT = 2147483647;
    long long int MIN_INT = -2147483648;
    
    string normalizeString(string s){
        string new_s = "";
        for(char c : s){
            if(new_s.size() == 0 && c == ' ') continue;
            if((c == '-' || c == '+') && new_s.size() == 0){
                new_s.push_back(c);
                continue;
            }
            if(c < '0' || c > '9') break;
            new_s.push_back(c);
        }
        return new_s;
    }
    
    string remove_leading_zeros_and_signal(string s){
        int i = (s[0] < '0'? 1 : 0);
        while(s[i] == '0') i++;
        if(i > s.size()) return "";
        return s.substr(i, s.size() - i + 1);
    }
    
    int myAtoi(string s) {
        s = normalizeString(s);
        if(!s.size()) return 0;
        
        int signal = (s[0] == '-'? -1 : 1);
        
        s = remove_leading_zeros_and_signal(s);
        if(!s.size()) return 0;
        if(s.size() > 10)
            return (signal == -1? MIN_INT : MAX_INT);
        
        long long int num = 0;
        for(char c : s){
            num += (c - '0');
            num *= 10;
        }
        num /= 10;
        
        num *= signal;
        return (signal == -1? max(MIN_INT, num) : min(num, MAX_INT));
    }
};