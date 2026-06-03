class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int planA = INT_MAX, planB = INT_MAX;
        int end = INT_MAX;
        // land -> water
        for(int i = 0; i < landStartTime.size(); i++){
            end = min(end, landStartTime[i]+landDuration[i]);
        }

        for(int i = 0; i < waterStartTime.size(); i++){
            planA = min(planA, (max(end, waterStartTime[i])+waterDuration[i]));
        }

        // water->land
        end = INT_MAX;
        for(int i = 0; i < waterStartTime.size(); i++){
            end = min(end, waterStartTime[i]+waterDuration[i]);
        }

        for(int i = 0; i < landStartTime.size(); i++){
            planB = min(planB, (max(end, landStartTime[i])+landDuration[i]));
        }
        return min(planA, planB);
    }
};