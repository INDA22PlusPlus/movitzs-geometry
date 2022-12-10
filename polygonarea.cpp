#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> 

using namespace std;

// här tror jag att problemet är att jag inte kan hantera self intersecting polygons


int main() {

    int n = 0;

    while (cin >> n && n != 0) {
        vector<pair<int, int>> l;

        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x;
            cin >> y;

            l.push_back({x,y});
        }
        l.push_back(l[0]);
        
        float area = 0.0;
        for (int i = 0; i < l.size(); i++) {
            area += (l[i+1].first*l[i].second - l[i].first * l[i+1].second);
        }

        if (area < 0) {
            cout << "CCW ";
        } else {
            cout << "CW ";
        }

        printf("%.1f\n", abs(area)/2.0);
    }   
}
