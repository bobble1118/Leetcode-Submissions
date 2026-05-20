class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n, 0);
        vector<int> hash(51, 0);

        int prev = 0;
        for(int i = 0; i < n; i++){
            ans[i] = prev;

            hash[A[i]] += 1;
            if (hash[A[i]] > 1){
                ans[i] = prev + 1;
                prev = ans[i];
            } 
            hash[B[i]] += 1;
            if (hash[B[i]] > 1){
                ans[i] = prev + 1;
                prev = ans[i];
            } 
        }
        return ans;
    }
};