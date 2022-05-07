class Solution {
    double r, x, y;
public:
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        x = x_center;
        y = y_center;
    }
    vector<double> randPoint() {
        double rand1 = sqrt((double)rand() / RAND_MAX);
        double R = rand1 * r;
        double theta = 2 * M_PI * rand() / RAND_MAX;
        return {x + R * cos(theta), y + R * sin(theta)};
    }
};
