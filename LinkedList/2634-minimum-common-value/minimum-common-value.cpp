class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hash;

        int MinRes = 2;
        for (const auto& num: nums1){
            hash[num] += 1;
        }

        for (const auto& num: nums2){
            if (hash[num] > 0) return num;
        }

        return -1;
    }
};