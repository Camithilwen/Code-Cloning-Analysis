#include <iostream>
#include <cmath>
using namespace std;

struct Point 
{
    double x, y;
    Point(double x=0, double y=0) : x(x), y(y) {}
    
	double distance (const Point &o) const 
	{
        return sqrt((x - o.x) * (x - o.x) + (y - o.y) * (y - o.y));
    }

    Point operator+(const Point &o) const 
	{
        return Point(x+o.x, y+o.y);
    }
 
    Point operator-(const Point &o) const 
	{
        return Point(x-o.x, y-o.y);
    }
 
    Point operator*(const double m) const 
	{
        return Point(x*m, y*m);
    }
 
    Point operator/(const double d) const 
	{
        return Point(x/d, y/d);
    }
 
    double cross(const Point &o) const 
	{
        return x * o.y - y * o.x;
    }
 
    double dot(const Point &o) const 
	{
        return x * o.x + y * o.y;
    }
 
    double atan() const 
	{
        return atan2(y, x);
    }

    double norm() const 
	{
        return dot(*this);
    }

	double area(const Point &a,const Point &b) const
	{
		double t = (a.x - x) * (b.y - y);
		double t2 = (a.y - y) * (b.x - x);
		double areas = abs(t-t2);
		return  areas/2;
	}
};

int main()
{
	Point p1,p2;
	cin >> p1.x >> p1.y >> p2.x >> p2.y;
	cout << fixed;
	cout.precision(6);
	cout << p1.distance(p2) << endl;

	return 0;
}