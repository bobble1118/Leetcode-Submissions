class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int minDistance = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                int directDist = abs(i - startIndex);
                int circularDist = min(directDist, n - directDist);
                
                minDistance = min(minDistance, circularDist);
            }
        }
        return (minDistance == INT_MAX) ? -1 : minDistance;
    }
};