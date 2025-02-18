

// Problem 1..
#include <iostream>
#include <vector>
using namespace std;

vector<int> beautifulArray(int n)
{
    vector<int> result = {1};
    while (result.size() < n)
    {
        vector<int> temp;
        for (int num : result)
        {
            if (2 * num - 1 <= n)
                temp.push_back(2 * num - 1);
        }
        for (int num : result)

        {
            if (2 * num <= n)
                temp.push_back(2 * num);
        }
        result = temp;
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<int> res = beautifulArray(n);
    for (int num : res)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

// Problem 2....

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
{
    vector<pair<int, int>> events;
    for (auto &b : buildings)
    {
        events.emplace_back(b[0], -b[2]); // Start of building
        events.emplace_back(b[1], b[2]);  // End of building
    }

    sort(events.begin(), events.end());
    multiset<int> heights = {0};
    vector<vector<int>> result;
    int prevHeight = 0;

    for (auto &e : events)
    {
        int x = e.first, h = e.second;
        if (h < 0)
        {
            heights.insert(-h);
        }
        else
        {
            heights.erase(heights.find(h));
        }

        int maxHeight = *heights.rbegin();
        if (maxHeight != prevHeight)
        {
            result.push_back({x, maxHeight});
            prevHeight = maxHeight;
        }
    }
    return result;
}

int main()
{
    vector<vector<int>> buildings = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
    vector<vector<int>> skyline = getSkyline(buildings);

    for (auto &point : skyline)
    {
        cout << "[" << point[0] << ", " << point[1] << "] ";
    }
    cout << endl;

    return 0;
}
