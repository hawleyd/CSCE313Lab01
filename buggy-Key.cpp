using namespace std;
#include <iostream>
#include <stdio.h>
#include <string.h>

struct Point {
    int x, y;

    Point () : x(), y() {}
    Point (int _x, int _y) : x(_x), y(_y) {}
};

class Shape {
    int vertices;
    Point** points;

    public:
        Shape (int _vertices) {
            vertices = _vertices;
            points = new Point*[vertices+1];
            //allocate points in array
            for(int i = 0; i<vertices; i++)
            {
                points[i] = new Point();
            }
        }

    ~Shape () {
        //remove array
        for (int i = 0; i < vertices; i++)
        {
            delete points[i];
        }
        delete[] points;
    }

    void addPoints (Point pts[]) {
        for (int i = 0; i < vertices; i++) {
            memcpy(points[i], &pts[i%vertices], sizeof(Point));
        }
    }

    double area () {

        if (vertices ==3)
        {
            //we have a triangle
            return abs(((points[0]->x*(points[1]->y - points[2]->y)) + 
            (points[1]->x*(points[2]->y - points[0]->y))+
            (points[2]->x*(points[0]->y - points[1]->y)))) /2.0;
        }
        else if (vertices ==4)
        {
            return abs((points[0]->x*points[1]->y + 
            points[1]->x*points[2]->y + 
            points[2]->x*points[3]->y + 
            points[3]->x*points[0]->y) - 
            (points[1]->x*points[0]->y + 
            points[2]->x*points[1]->y + 
            points[3]->x*points[2]->y + 
            points[0]->x*points[3]->y)) /2.0;

        }
        else
        {
            return -1;
        }
    }
};

int main () {
    // FIXME: create the following points using the three different methods
    //        of defining structs:
    //          tri1 = (0, 0)
    //          tri2 = (1, 2)
    //          tri3 = (2, 0)
    Point tri1(0,0);
    Point tri2(1,2);
    Point tri3(2,0);

    // adding points to tri
    Point triPts[3] = {tri1, tri2, tri3};
    Shape* tri = new Shape(3);
    tri->addPoints(triPts);

    // FIXME: create the following points using your preferred struct
    //        definition:
    //          quad1 = (0, 0)
    //          quad2 = (0, 2)
    //          quad3 = (2, 2)
    //          quad4 = (2, 0)

    Point quad1(0,0);
    Point quad2(5,0);
    Point quad3(5,5);
    Point quad4(0,5);

    // adding points to quad
    Point quadPts[4] = {quad1, quad2, quad3, quad4};
    Shape* quad = new Shape(4);
    quad->addPoints(quadPts);

    // FIXME: print out area of tri and area of quad

    //double areaOfTri = tri->area();
    cout << "Area of tri: " << tri->area() << endl;
    cout << "Area of quad: " << quad->area() << endl;

    delete tri;
    delete quad;

}