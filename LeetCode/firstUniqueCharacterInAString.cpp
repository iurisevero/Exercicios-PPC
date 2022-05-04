class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> letter_pos;
        vector<int> letter_count(26);
        size_t _size = s.size();
        
        for(size_t i=0; i < _size; ++i){
            int aux_pos = s[i] - 97;
            if(letter_count[aux_pos] == 0)
                letter_pos[aux_pos] = i;
            letter_count[aux_pos]++;
        }
        
        int first_appear = _size;
        for(int i=0; i < 26; ++i)
            if(letter_count[i] == 1 && letter_pos[i] < first_appear)
                first_appear = letter_pos[i];
       
        return first_appear != _size? first_appear : -1;
    }
};