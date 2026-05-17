class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        q.push(start);

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            if (arr[curr] == 0) return true;
            
            if (arr[curr] < 0) continue;

            int val = arr[curr];
            arr[curr] =-arr[curr];

            int left = curr - val;
            if (left >= 0 && arr[left] >= 0) q.push(left);
            int right = curr + val;
            if (right < n && arr[right] >= 0) q.push(right);
        }
        return false;

    }
};