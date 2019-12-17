#include <stdio.h>
#include <stdlib.h>

/* Place your struct definitions for Shape, Circle, Triangle, and Rectangle here */
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

typedef struct
{
	void *self;
	void (*GetBoundingBox)(void *, double *);
	double (*GetArea)(void *);
} Shape;

double GetCircleArea(void *circ)
{
	Circle *circle = (Circle *)circ;
	double area = 3.14159*circle->radius*circle->radius;
	return area;
};

double GetRectangleArea(void *rect)
{
	Rectangle *rectangle = (Rectangle *)rect;
	double area = (rectangle->maxX-rectangle->minX)*(rectangle->maxY-rectangle->minY);
	return area;
};

double GetTriangleArea(void *tri)
{
	Triangle *triangle = (Triangle *)tri;
	double area = (triangle->pt2X-triangle->pt1X)*(triangle->maxY-triangle->minY)/2;
	return area;
};
void GetBoundingBox(Shape *shape, double *bbox)
{
	shape->GetBoundingBox(shape->self, bbox);
};

double GetArea(Shape *shape)
{ 
	return shape->GetArea(shape->self);
};

void GetCircleBoundingBox(void *circ, double *bbox)
{
	Circle *circle = (Circle *)circ;
	bbox[0] = (circle->originX-circle->radius);
	bbox[1] = (circle->originX+circle->radius);
	bbox[2] = (circle->originY-circle->radius);
	bbox[3] = (circle->originY+circle->radius);
};

void GetRectangleBoundingBox(void *rect, double *bbox)
{
	Rectangle *rectangle = (Rectangle *)rect;
	bbox[0] = rectangle->minX;
	bbox[1] = rectangle->maxX;
	bbox[2] = rectangle->minY;
	bbox[3]	= rectangle->maxY;
};

void GetTriangleBoundingBox(void *tri, double *bbox)
{
	Triangle *triangle = (Triangle *)tri;
	bbox[0] = triangle->pt1X;
	bbox[1] = triangle->pt2X;
	bbox[2] = triangle->minY;
	bbox[3] = triangle->maxY;
};

Shape * CreateCircle(double radius, double originX, double originY)
{
	Shape *s = malloc(sizeof(Shape));
	Circle *circle = malloc(sizeof(Circle));
	circle->radius = radius;
	circle->originX = originX;
	circle->originY = originY;
	s->self = circle;
	s->GetArea = &GetCircleArea;
	s->GetBoundingBox = &GetCircleBoundingBox;
	return s;
};

Shape * CreateRectangle(double minX, double maxX, double minY, double maxY)
{
	Shape *s = malloc(sizeof(Shape));
	Rectangle *rectangle = malloc(sizeof(Rectangle));
	rectangle->minX = minX;
	rectangle->maxX = maxX;
	rectangle->minY = minY;
	rectangle->maxY = maxY;
	s->self = rectangle;
	s->GetArea = &GetRectangleArea;
	s->GetBoundingBox = &GetRectangleBoundingBox;
	return s;

};

Shape * CreateTriangle(double pt1X, double pt2X, double minY, double maxY)
{
	Shape *s = malloc(sizeof(Shape));
	Triangle *triangle = malloc(sizeof(Triangle));
	triangle->pt1X = pt1X;
	triangle->pt2X = pt2X;
	triangle->minY = minY;
	triangle->maxY = maxY;
	s->self = triangle; 
	s->GetArea = &GetTriangleArea;
	s->GetBoundingBox = &GetTriangleBoundingBox;
	return s;
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
    Shape *shapes[9];
    int    i;
    shapes[0] = CreateCircle(1, 0, 0);
    shapes[1] = CreateCircle(1.5, 6, 8);
    shapes[2] = CreateCircle(0.5, -3, 4);

    shapes[3] = CreateRectangle(0, 1, 0, 1);
    shapes[4] = CreateRectangle(1, 1.1, 10, 20);
    shapes[5] = CreateRectangle(1.5, 3.5, 10, 12);

    shapes[6] = CreateTriangle(0, 1, 0, 1);
    shapes[7] = CreateTriangle(0, 1, 0, 0.1);
    shapes[8] = CreateTriangle(0, 10, 0, 50);

    for(i = 0 ; i < 9 ; i++)
    {
	    double bbox[4];
	    printf("Shape %d\n", i);
	    printf("\tArea: %f\n", GetArea(shapes[i]));
	    GetBoundingBox(shapes[i], bbox);
	    printf("\tBbox: %f-%f, %f-%f\n", bbox[0], bbox[1], bbox[2], bbox[3]);
    }
}

