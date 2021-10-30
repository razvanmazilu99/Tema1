#include <iostream>
#include <math.h>
#include <string.h>

class RightAngleTriangle 
{   
    private:
        int c1;
        int c2;
        int hypotenuza;
        char *color;
        int triangleNumber;
        static int nr;
        
    public:
        RightAngleTriangle() : c1(0), c2(0), hypotenuza(0) 
        { 
            this -> color = new char[strlen("none") + 1];
            strcpy(this -> color, "none"); 
            triangleNumber = ++nr;
        }

        RightAngleTriangle(int c1, int c2, int hypotenuza, char *color)
        {
            this -> c1 = c1;
            this -> c2 = c2;
            this -> hypotenuza = hypotenuza;
            this -> color = new char[strlen(color) + 1];
            strcpy(this -> color, color);
            triangleNumber = ++nr;
        }

        //CopyConstructor
        RightAngleTriangle(const RightAngleTriangle &obj)
        {
            c1 = obj.c1;
            c2 = obj.c2;
            hypotenuza = obj.hypotenuza;
            color = new char[strlen(obj.color) + 1];
            strcpy(color, obj.color);
            triangleNumber = ++nr;
        }

        //Deconstructor
        ~RightAngleTriangle() 
        {
            delete color;
        }

        void displayTriangle() {
            std::cout << "Triangle " << triangleNumber << " (" << c1 << "," << c2 << "," << hypotenuza << ") is " << color << ".\n";
        }

        int perimeter() 
        {
            int sum = 0;
            sum = c1 + c2 + hypotenuza;
            return sum;
        }

        double aria()
        {
            return (double)c1*c2/2;
        }

        void write()
        {
            std::cout << "Perimeter: " << perimeter() << '\n';
            std::cout << "Aria: " << aria() << '\n';
        }
};

int RightAngleTriangle::nr;

int main()
{
    int c1, c2, hypotenuza;
    char color[20];

    std::cout << "Give the length of the sides: " << '\n';
    std::cout << "c1 = ";
    std::cin >> c1;
    std::cout << "c2 = ";
    std::cin >> c2;
    std::cout << "hypotenuza = ";
    std::cin >> hypotenuza;
    std::cout << "Color: ";
    std::cin >> color;

    RightAngleTriangle triangle(c1, c2, hypotenuza, color);

    triangle.displayTriangle();
    triangle.write();

    RightAngleTriangle triangle1(triangle);

    triangle1.displayTriangle();

    RightAngleTriangle triangle2;

    triangle2.displayTriangle();

    return 0;
}
