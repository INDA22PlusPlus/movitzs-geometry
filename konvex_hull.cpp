#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> 

using namespace std;


bool left(pair<int, int> a, pair<int, int> b, pair<int, int> p) {
    return (b.first - a.first) * (p.second - a.second) - (b.second*a.second) * (p.first * a.first);
}

int distance(pair<int, int> p0, pair<int, int> p) {
    return p0.first * p.second + p0.second *p.first;
}

pair<int, int> p0;

int comparex(pair<int, int> a, pair<int, int> b) {
    int x = left(p0,a,b);

    if (x == 0) {
        return distance(a, b) < 0 ? -1 : 1;
    }
    return x < 0 ? -1 : 1;
}

int main() {

    int n = 0;

    while (cin >> n) {
        p0 = {100000, 100000};
        int p0idx = -1;

        vector<pair<int, int>> l;
        vector<pair<int, int>> res;

        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x;
            cin >> y;

            if (p0.first >= x && p0.second > y) {
                p0 = {x,y};
                p0idx = i;
            }

            l.push_back({x,y});
        }
        if (p0idx != -1) {
            res.push_back(p0);
            l.erase(l.begin() + p0idx);
        }
        sort(l.begin(), l.end(), comparex);


        // cout << "p0: " << p0.first << "/" << p0.second;

        while (!l.empty()) {
            pair<int, int> top = l.back();
            l.pop_back();

            while (res.size() > 1 && left(top, res[res.size()-1], res[res.size()-2]) > 0) {
                res.pop_back();
            }

            res.push_back(top);

            // cout <<  top.first << "/" << top.second << endl;
        }

        cout << res.size() << endl;
        for (auto p : res) {
            cout << p.first << " " << p.second << endl;
        }
        cout << endl;
    }   
}
