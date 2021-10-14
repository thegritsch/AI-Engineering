// these methods shall calculate and print the convex hull of a set of points.
#include <iostream>
#include <stack>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

struct Point
{
    int x, y;
};

// A handy global point
Point p_dummy;

// please add your code here ---->

static vector<Point> ret;
static bool mycmp(Point& a, Point& b) {
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

int testSide(Point& a, Point& b, Point& c) {
    // cross product of (AB and AC vectors)
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

double distPointLine(Point& A, Point& B, Point& C) {
    // dist(line: ax+by+c=0, and point(x0, y0)): (a*x0 + b*y0 + c)/sqrt(a^2+b^2)
    // line: (y2-y1)*x - (x2-x1)*y + x2*y1 - y2*x1 = 0
    return abs((C.y - A.y) * (B.x - A.x) -
        (B.y - A.y) * (C.x - A.x));
}

void FindHull(vector<Point>& points, Point& A, Point& B) {
    if (points.empty())
        return;

    unsigned int idx = 0;
    double dist = distPointLine(A, B, points[0]);
    for (unsigned int i = 1; i < points.size(); i++) {
        if (distPointLine(A, B, points[i]) > dist) {
            dist = distPointLine(A, B, points[i]);
            idx = i;
        }
    }





    vector<Point> R, T;
    for (unsigned int i = 0; i < points.size(); i++) {
        if (i != idx) {
            int tmp = testSide(A, points[idx], points[i]);
            if (tmp > 0)
                R.push_back(points[i]);
            else {
                tmp = testSide(points[idx], B, points[i]);
                if (tmp > 0)
                    T.push_back(points[i]);
            }
        }
    }
    FindHull(R, A, points[idx]);
    ret.push_back(points[idx]);
    FindHull(T, points[idx], B);


    return;
}



vector<Point> convexHull(Point* pointsarr, int size) {

    vector<Point> points;
    for (int i = 0; i < size; i++)
        points.push_back(pointsarr[i]);
    // find the convex hull; use QuickHull algorithm
    if (points.size() <= 1)
        return points;

    // find the left most and right most two points
    sort(points.begin(), points.end(), mycmp);
    ret.push_back(points[0]);


    // test whether a point on the left side right side or on the line
    vector<Point> Left, Right, Online;
    for (unsigned int i = 1; i < points.size() - 1; i++) {
        int tmp = testSide(points[0], points.back(), points[i]);
        if (tmp < 0)
            Right.push_back(points[i]);
        else if (tmp > 0)
            Left.push_back(points[i]);
        else
            Online.push_back(points[i]);
    }
    // if Upper or Down is empty, Online should be pushed into ret
    /*if (Left.empty() || Right.empty())
        for (int i = 0; i < Online.size(); i++)
            ret.push_back(Online[i]);*/

    FindHull(Left, points[0], points.back());
    ret.push_back(points.back());
    FindHull(Right, points.back(), points[0]);
    for (unsigned int i = 0; i < ret.size(); i++)
        cout << "(" << ret[i].x << ", " << ret[i].y << ")\n";
    return ret;
}

int main()
{
    Point points[] = { {1, 3}, {1, 7}, {2, 1}, {2, 4},
                      {1, 5}, {7, 3}, {2, 4}, {5, 0},
                      {0, 2}, {8, 5}, {1, 4}, {6, 5},
                      {1, 5}, {7, 2}, {2, 4}, {6, 1},
                      {2, 0}, {1, 0}, {3, 2}, {3, 4} };
    int n = sizeof(points) / sizeof(points[0]);
    convexHull(points, n);
    return 0;
}
