class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());

        long long current_mass = mass;

        for (int asteroid : asteroids) {
            if (current_mass < asteroid) {
                return false;
            }
            current_mass += asteroid;
        }

        return true;
    }
};