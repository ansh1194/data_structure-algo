/*

    Rectangle Intersection

*/
#include "../Lib/common.h"


struct Rect
{
    int x, y, length, width;
};


struct Rect rectangleInt(struct Rect& r1, struct Rect& r2)
{
    int result;

    int lengthNew, widthNew;

    if ( r1.x <= r2.x + r2.width &&
         r1.x + r1.width >= r1.x &&
         r1.y <= r2.y + r2.length &&
         r1.y + r1.length >= r2.length)
    {
        return {std::max(r1.x, r2.x), std::max(r1.y, r2.y),
                std::min(r1.x + r1.width, r2.x + r2.width ) - std::max(r1.x, r2.x), 
                std::max(r1.y + r1.length, r2.y + r2.length) - std::max(r1.y, r2.y)};
    }

    return {0,0,-1,-1};
}

int main()
{
    struct Rect r1 = {3, 4, 5, 2};
    struct Rect r2 = {5,3, 3, 12};

    struct Rect r3 = rectangleInt(r1, r2);

    std::cout << r3.x << " " << r3.y << " " << r3.length << " " << r3.width;

    return 0;
}