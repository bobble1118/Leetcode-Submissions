class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int array[5] = {0};
        for (const auto s: text){
            if (s == 'b'){
                array[0]++;
            }else if (s == 'a'){
                array[1]++;
            }else if (s == 'l'){
                array[2]++;
            }else if (s == 'o'){
                array[3]++;
            }else if (s == 'n'){
                array[4]++;
            }
        }

        int once = min({array[0], array[1], array[4]});
        int twice = min(array[2], array[3])/2;
        return min(once, twice);
    }
};