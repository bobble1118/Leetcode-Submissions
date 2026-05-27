class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lower(26, -1);
        vector<int> upper(26, -1);

        int count = 0;
        for (int i = 0; i < word.size(); i++){
            int index = (word[i] >= 'a') ? word[i] - 'a' : word[i] - 'A';
            if (word[i] < 'a' && upper[index] == -1){
                upper[index] = i;
            }else if (word[i] >= 'a'){
                lower[index] = i;
            }
        }

        for (int i = 0; i < 26; i++){
            if (lower[i] < upper[i] && lower[i] != -1 && upper[i] != -1) count++;
        }
        return count;
    }
};