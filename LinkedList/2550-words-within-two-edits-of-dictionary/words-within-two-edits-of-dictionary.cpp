class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n = queries.size();
        int m = queries[0].size();
        int p = dictionary.size();
        vector<string> ans;

        for(int i = 0; i < n; i++){
            for(int k = 0; k < p; k++){
                int count = 0;
                for(int j = 0; j < m; j++){    
                    if (queries[i][j] != dictionary[k][j]) count++;
                    if (count > 2) break;
                }
                if (count <= 2){
                    ans.push_back(queries[i]);
                    break;
                }
            }
        }
        return ans;
    }
};