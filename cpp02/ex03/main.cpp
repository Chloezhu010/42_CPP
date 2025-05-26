#include "Fixed.hpp"
#include "Point.hpp"

int main()
{
    // define a triangle
    Point   a(0.0f, 0.0f);
    Point   b(4.0f, 0.0f);
    Point   c(2.0f, 3.0f);

    // test points
    Point   inside(2.0f, 1.0f);
    Point   outside(2.0f, 5.0f);
    Point   onedge(2.0f, 0.0f);
    Point   vertex(0.0f, 0.0f);

    std::cout << "Testing BSP\n";
    std::cout << "Point inside (2,1): " << (bsp(a, b, c, inside) ? "Yes" : "No") << std::endl;
    std::cout << "Point outside (2,5): " << (bsp(a, b, c, outside) ? "Yes" : "No") << std::endl;
    std::cout << "Point onedge (2,0): " << (bsp(a, b, c, onedge) ? "Yes" : "No") << std::endl;
    std::cout << "Point vertex (0,0): " << (bsp(a, b, c, vertex) ? "Yes" : "No") << std::endl;
}