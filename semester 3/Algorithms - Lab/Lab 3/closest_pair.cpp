#include <bits/stdc++.h>
using namespace std;
// vector<pair<pair<double, double>,pair<double, double>>> vec1;
pair<double, double> x1, x2;

bool sort_by_y_coordinate(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second < b.second);
}
bool sort_by_x_coordinate(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.first < b.first);
}
double find_distance(pair<double, double> p1, pair<double, double> p2, pair<double, double> &min1, pair<double, double> &min2)
{
    if (sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second)) < sqrt((min1.first - min2.first) * (min1.first - min2.first) + (min1.second - min2.second) * (min1.second - min2.second)))
    {
        min1 = p1;
        min2 = p2;
    }

    return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}

double find_smallest_distance(vector<pair<double, double>> sorted_x, vector<pair<double, double>> sorted_y, pair<double, double> &min1, pair<double, double> &min2)
{

    int n = sorted_x.size();

    if (n <= 1)
    {
        return DBL_MAX;
    }

    pair<double, double> p1, p2, p3, p4 = {DBL_MAX, DBL_MAX};
    vector<pair<double, double>> left_x;
    vector<pair<double, double>> right_x;

    for (int i = 0; i < n; i++)
    {
        if (i < n / 2)
        {
            left_x.push_back(sorted_x[i]);
        }
        else
        {
            right_x.push_back(sorted_x[i]);
        }
    }

    int middle = left_x.back().first;

    vector<pair<double, double>> left_y, right_y;

    for (auto x : sorted_y)
    {
        if (x.first <= middle)
        {
            left_y.push_back(x);
        }
        else
        {
            right_y.push_back(x);
        }
    }

    double d1 = find_smallest_distance(left_x, left_y, p1, p2);
    double d2 = find_smallest_distance(right_x, right_y, p3, p4);

    if (d1 < d2)
    {
        min1 = p1;
        min2 = p2;
        // vec1.push_back({min1, min2});
    }

    else
    {
        min1 = p3;
        min2 = p4;
        // vec1.push_back({min2, min2});
    }

    double d = min(d1, d2);

    vector<pair<double, double>> band;

    for (auto x : sorted_y)
    {
        if (x.first > middle - d)
            band.push_back(x);
    }

    for (int i = 0; i < band.size(); i++)
    {
        for (int j = i + 1; j < band.size() && band[j].second < band[i].second + d; j++)
        {
            if (find_distance(band[i], band[j], p1, p2) < d)
            {
                min1 = band[i];
                min2 = band[j];
                // vec1.push_back({min1, min2});
                d = find_distance(band[i], band[j], p1, p2);
            }
        }
    }
    x1 = min1;
    x2 = min2;
    return d;
}

int main()
{
    int n, k;
    vector<pair<double, double>> vec;
    vector<pair<double, double>> vec1;
    vector<pair<double, double>> vec2;
    cout << "enter the value of k" << endl;
    cin >> k;
    cout << "How many points are there on the 2D plane ?  " << endl;
    cin >> n;
    if (n <= 1)
    {
        cout << "Invalid Input" << endl;
        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        double x, y;
        cout << "Enter the coordinates of Point " << i << endl;
        cout << "x " << i << " : ";
        cin >> x;
        cout << "y " << i << " : ";
        cin >> y;
        vec.push_back({x, y});
    }
    cout << endl;
    if (k <= 3)
    {
        sort(vec.begin(), vec.end(), sort_by_x_coordinate);
        vector<pair<double, double>> sorted_x = vec;
        sort(vec.begin(), vec.end(), sort_by_y_coordinate);
        vector<pair<double, double>> sorted_y = vec;
        pair<double, double> min1 = {DBL_MAX, DBL_MAX};
        pair<double, double> min2 = {DBL_MAX, DBL_MAX};

        double x = find_smallest_distance(sorted_x, sorted_y, min1, min2);

        cout << "\tClosest points : (" << min1.first << "," << min1.second << ") "
             << "and "
             << "(" << min2.first << "," << min2.second << ") " << endl;
        cout << "\tDistance : " << x << " units" << endl;
    }
    if (k >= 2)
    {
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i] == x1)
            {
                continue;
            }
            else
            {
                vec1.push_back(vec[i]);
            }
        }

        sort(vec1.begin(), vec1.end(), sort_by_x_coordinate);
        vector<pair<double, double>> sorted_x2 = vec1;
        sort(vec1.begin(), vec1.end(), sort_by_y_coordinate);
        vector<pair<double, double>> sorted_y2 = vec1;
        pair<double, double> min3 = {DBL_MAX, DBL_MAX};
        pair<double, double> min4 = {DBL_MAX, DBL_MAX};

        double x1 = find_smallest_distance(sorted_x2, sorted_y2, min3, min4);

        cout << "\tClosest points : (" << min3.first << "," << min3.second << ") "
             << "and "
             << "(" << min4.first << "," << min4.second << ") " << endl;
        cout << "\tDistance : " << x1 << " units" << endl;
    }

    if (k >= 3)
    {
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i] == x2)
            {
                continue;
            }
            else
            {
                vec2.push_back(vec[i]);
            }
        }

        sort(vec2.begin(), vec2.end(), sort_by_x_coordinate);
        vector<pair<double, double>> sorted_x3 = vec2;
        sort(vec2.begin(), vec2.end(), sort_by_y_coordinate);
        vector<pair<double, double>> sorted_y3 = vec2;
        pair<double, double> min5 = {DBL_MAX, DBL_MAX};
        pair<double, double> min6 = {DBL_MAX, DBL_MAX};

        double x2 = find_smallest_distance(sorted_x3, sorted_y3, min5, min6);

        cout << "\tClosest points : (" << min5.first << "," << min5.second << ") "
             << "and "
             << "(" << min6.first << "," << min6.second << ") " << endl;
        cout << "\tDistance : " << x2 << " units" << endl;
    }
}
