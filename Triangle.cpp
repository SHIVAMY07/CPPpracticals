
#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

class Triangle
{
private:
    double a,b,c;

    double semiPerimeter() const
    {
        return (a+b+c)/2.0;
    }

    void validateSides(double a, double b, double c)
    {
        if(a<=0 || b<=0 || c<=0)
            throw invalid_argument("All sides must be greater than 0");
        if(a+b<=c || b+c<=a || a+c<=b)
            throw invalid_argument("Sum of any two sides must be greater than the third side.");
    }

    double areaHeron() const 
    {
        double s = semiPerimeter();
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

public:
    Triangle(double a, double b, double c)
    {
        validateSides(a, b, c);
        this->a=a;
        this->b=b;
        this->c=c;
    }

    double area(bool rightAngled) const
    {
        if (!rightAngled)
            return areaHeron();

        if (a*a + b*b == c*c)
            return 0.5 * a * b;
        else if (a*a + c*c == b*b)
            return 0.5 * a * c;
        else if (b*b + c*c == a*a)
            return 0.5 * b * c;
        else
            throw logic_error("Triangle is not right-angled.");
    }
    
    double area() const {
        return areaHeron();
    }
};

int main()
{
    try {
        Triangle t1(3, 4, 5);
        cout << "Area of right-angled triangle: " << t1.area(true) << endl;
        cout << "Area using Heron's formula: " << t1.area() << endl;

        Triangle t2(3, 4, 6);
        cout << "Area using Heron's formula: " << t2.area() << endl;
        cout << "Area of right-angled triangle: " << t2.area(true) << endl;
        
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
