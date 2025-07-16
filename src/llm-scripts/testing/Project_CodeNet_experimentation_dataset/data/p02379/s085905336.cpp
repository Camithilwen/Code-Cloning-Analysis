#include <iostream>
#include <iomanip> //setprecision
#include <cstdlib>
#include <cmath>

double abs(double coodinate1, double coodinate2); 

int main(void) {
    double x1;
    double y1;
    double x2;
    double y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    double dif_x = abs(x1, x2);
    double dif_y = abs(y1, y2);
    double target = dif_x * dif_x + dif_y * dif_y;

    std::cout << std::setprecision(12);
    std::cout << sqrt(target) << std::endl;

    return EXIT_SUCCESS;
}

double abs(double coodinate1, double coodinate2) {
    double dif = coodinate1 - coodinate2;
    if (dif < 0) {
        dif *= (-1.0);
    }
    return dif;
}