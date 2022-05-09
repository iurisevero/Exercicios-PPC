// 10ms 6.4MB
class Solution {
public:
                        //0, 1,  2,  3,   4,   5,    6
    vector<int> values = {1, 5, 10, 50, 100, 500, 1000};
    vector<char> symbols = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    
    string value_to_symbol(int value, int pos){
        string out;
        if(value < 4){
            out.assign(value, symbols[pos]);
        } else if(value == 4){
            out.push_back(symbols[pos]);
            out.push_back(symbols[pos+1]);
        } else if(value < 9){
            out.push_back(symbols[pos+1]);
            out.append(value - 5, symbols[pos]);
        }else{
            out.push_back(symbols[pos]);
            out.push_back(symbols[pos+2]);
        }
        return out;
    }
    
    string intToRoman(int num) {
        string ans = "";
        int pos = 6; // values.size() - 1;
        while(num && pos >= 0){
            int aux = num / values[pos];
            num %= values[pos];
            ans += value_to_symbol(aux, pos);
            pos -= 2;
        }
        return ans;
    }
};


// 23ms 8.8MB
class Solution {
public:
                        //0, 1, 2, 3,  4,  5,  6,  7,   8,   9,  10,  11,   12
    vector<int> values = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    vector<string> symbols = {"I", "IV",  "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    
    string value_to_symbol(int value, int pos){
        string out = "";
        for(int i=0; i < value; ++i) out += symbols[pos];
        return out;
    }
    
    string intToRoman(int num) {
        string ans = "";
        int pos = 12; // values.size() - 1;
        while(num && pos >= 0){
            ans += value_to_symbol(num / values[pos], pos);
            num %= values[pos];
            pos--;
        }
        return ans;
    }
};
