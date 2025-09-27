class Solution {
public:
    double distance(double x1, double y1, double x2, double y2){
        return sqrt(abs(  (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)    ));
    }
    double heron(double x1, double y1, double x2, double y2, double x3, double y3){
        double a = distance(x1, y1, x2, y2);
        double b = distance(x2, y2, x3, y3);
        double c = distance(x3, y3, x1, y1);
        double s = (a + b + c)/(2.0);

        double area = sqrt(abs(s * (s-a) * (s-b) * (s-c)));
        return area;
    }
    double shoelace(double x1, double y1, double x2, double y2, double x3, double y3){
    //    O(1) TC
        double area = 0.5*(
            x1*(y2 - y3) + 
            x2*(y3 - y1) + 
            x3*(y1-y2)
        );
        return abs(area);
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        // heron's formula
        double ans = 0.0;
        int n = points.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = j + 1; k < n; k++){
                    // O(n^3) TC
                    // O(1) SC
                    double x1 = points[i][0], y1 = points[i][1];
                    double x2 = points[j][0], y2 = points[j][1];
                    double x3 = points[k][0], y3 = points[k][1];
                    ans = max(ans, shoelace(x1, y1, x2, y2, x3, y3));
                }
            }
        }
        return ans;

    }
};
