#include <bits/stdc++.h>
using namespace std;

// A point structure
struct Point {
  int x, y;
  Point(int _x, int _y) : x(_x), y(_y) {}
};

// Function to find the orientation of the triplet (p, q, r) ==> cross
// 0 -> p, q, r are collinear
// 1 -> Clockwise
// 2 -> Counterclockwise
int orientation(Point p, Point q, Point r) {
  int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
  if (val == 0) return 0; // collinear
  return (val > 0) ? 1 : 2; // clockwise or counterclockwise
}

// Function to find the convex hull of a set of points
vector<Point> convexHull(vector<Point>& points) {
  int n = points.size();
  if (n < 3) return {}; // Convex hull is not possible with less than 3 points

  // Sort points lexicographically (by x, then by y)
  sort(points.begin(), points.end(), [](const Point& p1, const Point& p2) {
    if (p1.x == p2.x)
      return p1.y < p2.y;
    return p1.x < p2.x;
  });

  // Build the lower hull
  vector<Point> lower;
  for (int i = 0; i < n; i++) {
    while (lower.size() >= 2 && orientation(lower[lower.size() - 2], lower[lower.size() - 1], points[i]) != 2) {
      lower.pop_back();
    }
    lower.push_back(points[i]);
  }

  // Build the upper hull
  vector<Point> upper;
  for (int i = n - 1; i >= 0; i--) {
    while (upper.size() >= 2 && orientation(upper[upper.size() - 2], upper[upper.size() - 1], points[i]) != 2) {
      upper.pop_back();
    }
    upper.push_back(points[i]);
  }

  // Remove the last point of each half because it is repeated at the beginning of the other half
  lower.pop_back();
  upper.pop_back();

  // Concatenate lower and upper hull to get the complete hull
  lower.insert(lower.end(), upper.begin(), upper.end());
  return lower;
}

int32_t main() {
  // Input points
  vector<Point> points = {
    Point(0, 3),
    Point(2, 2),
    Point(1, 1),
    Point(2, 1),
    Point(3, 0),
    Point(0, 0),
    Point(3, 3)
  };

  vector<Point> hull = convexHull(points);

  // Output the points of the convex hull
  cout << "Points in the Convex Hull are:" << endl;
  for (const Point& p : hull) {
    cout << "(" << p.x << ", " << p.y << ")" << endl;
  }

  return 0;
}
