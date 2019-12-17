
#include <stdio.h>

/* Place your struct definitions for Circle, Triangle, and Rectangle here */

/* Define these 9 functions */
typedef struct
{
	double radius;
	double originX;
	double originY;
} Circle;

typedef struct
{
	double minX;
	double maxX;
	double minY;
	double maxY;

} Rectangle;

typedef struct
{
	double pt1X;
	double pt2X;
	double minY;
	double maxY;

} Triangle;

void InitializeCircle(Circle *circle, double radius, double originX, double originY)
{
	circle->radius = radius;
	circle->originX = originX;
	circle->originY = originY;
};

void InitializeRectangle(Rectangle *rectangle, double minX, double maxX, double minY, double maxY)
{
	rectangle->minX = minX;
	rectangle->maxX = maxX;
	rectangle->minY = minY;
	rectangle->maxY = maxY;
};

void InitializeTriangle(Triangle *triangle, double pt1X, double pt2X, double minY, double maxY)
{
	triangle->pt1X = pt1X;
	triangle->pt2X = pt2X;
	triangle->minY = minY;
	triangle->maxY = maxY;
};


double GetCircleArea(Circle *circle)
{
	double area = 3.14159*circle->radius*circle->radius;
	return area;
};

double GetRectangleArea(Rectangle *rectangle)
{
	double area = (rectangle->maxX-rectangle->minX)*(rectangle->maxY-rectangle->minY);
	return area;
};

double GetTriangleArea(Triangle *triangle)
{
	double area = (triangle->pt2X-triangle->pt1X)*(triangle->maxY-triangle->minY)/2;
	return area;
};

void GetCircleBoundingBox(Circle *circle, double *bbox)
{
	bbox[0] = (circle->originX-circle->radius);
	bbox[1] = (circle->originX+circle->radius);
	bbox[2] = (circle->originY-circle->radius);
	bbox[3] = (circle->originY+circle->radius);
};

void GetRectangleBoundingBox(Rectangle *rectangle, double *bbox)
{
	bbox[0] = rectangle->minX;
	bbox[1] = rectangle->maxX;
	bbox[2] = rectangle->minY;
	bbox[3]	= rectangle->maxY;
};

void GetTriangleBoundingBox(Triangle *triangle, double *bbox)
{
	bbox[0] = triangle->pt1X;
	bbox[1] = triangle->pt2X;
	bbox[2] = triangle->minY;
	bbox[3] = triangle->maxY;
};


/* DO NOT MODIFY AFTER THIS POINT */


void
PrintTriangle(Triangle *t)
{
    double bbox[4];
    double area;
    area = GetTriangleArea(t);
    GetTriangleBoundingBox(t, bbox);
    printf("Triangle has area %f and bounding box [%f->%f], [%f->%f]\n",
           area, bbox[0], bbox[1], bbox[2], bbox[3]);
}

void
PrintRectangle(Rectangle *r)
{
    double bbox[4];
    double area;
    area = GetRectangleArea(r);
    GetRectangleBoundingBox(r, bbox);
    printf("Rectangle has area %f and bounding box [%f->%f], [%f->%f]\n",
           area, bbox[0], bbox[1], bbox[2], bbox[3]);
}

void
PrintCircle(Circle *c)
{
    double bbox[4];
    double area;
    area = GetCircleArea(c);
    GetCircleBoundingBox(c, bbox);
    printf("Circle has area %f and bounding box [%f->%f], [%f->%f]\n",
           area, bbox[0], bbox[1], bbox[2], bbox[3]);
}

int main()
{
    Circle c;
    Triangle t;
    Rectangle r;

    InitializeCircle(&c, 1, 0, 0);
    PrintCircle(&c);
    InitializeCircle(&c, 1.5, 6, 8);
    PrintCircle(&c);
    InitializeCircle(&c, 0.5, -3, 4);
    PrintCircle(&c);

    InitializeRectangle(&r, 0, 1, 0, 1);
    PrintRectangle(&r);
    InitializeRectangle(&r, 1, 1.1, 10, 20);
    PrintRectangle(&r);
    InitializeRectangle(&r, 1.5, 3.5, 10, 12);
    PrintRectangle(&r);

    InitializeTriangle(&t, 0, 1, 0, 1);
    PrintTriangle(&t);
    InitializeTriangle(&t, 0, 1, 0, 0.1);
    PrintTriangle(&t);
    InitializeTriangle(&t, 0, 10, 0, 50);
    PrintTriangle(&t);
}
