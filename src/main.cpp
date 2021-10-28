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

    public:
        RightAngleTriangle(int c1, int c2, int hypotenuza, char *color)
        {
            this -> c1 = c1;
            this -> c2 = c2;
            this -> hypotenuza = hypotenuza;
            this -> color = new char[strlen(color) + 1];
            strcpy(this -> color, color);
        }

        //CopyConstructor
        RightAngleTriangle(const RightAngleTriangle& t)
        {
            c1 = t.c1;
            c2 = t.c2;
            hypotenuza = t.hypotenuza;
            color = new char[strlen(t.color) + 1];
            strcpy(color, t.color);
        }

        void displayTriangle() {
            std::cout << "Triangle (" << c1 << "," << c2 << "," << hypotenuza << ") is " << color << ".\n";
        }

};

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

    return 0;
}
