#include "shape.h"

void Shape::rotate()
{ //nice,small and efficient. 
	int buffer;
	for(int p =0; p<4;p++)
	{
		buffer = y[p];
		y[p] = x[p];
		x[p] = -buffer;
	}
}
Shape::type Shape::getType()
{
	return Type;
}
Shape::Shape(type shapeType)
{
	Type = shapeType;
	for(int p=0;p<4;p++)
	{	//initialize!
		x[p] = 0;
		y[p] = 0;
	}
	switch (shapeType)
	{
	/*create the right blocks. these numbers will be offsets.
	  fortunately all tetris shapes are comprised of 4 blocks. 
	*/
	case BLOCK:
		fill = Qt::red;
		x[1]++;
		y[2]++;
		x[3]++;
		y[3]++;
	break;
	case Z:
		fill =Qt::cyan;
		y[1]++;
		x[2]++;
		y[2]++;
		x[3]++;
		y[3]=2;
	break;
	case FL:
		x[1]++;
		y[2]++;
		y[3]=2;
	break;
	case RL:
		fill = Qt::green;
		x[1]++;
		x[2]++;
		y[2]++;
		x[3]++;
		y[3]=2;
	break;
	case LINE:
		fill = Qt::magenta;
		x[1]++;
		x[2]=2;
		x[3]=3;
	break;
	case T:
		fill = Qt::yellow;
		y[0]++;
		x[1]++;
		y[1]++;
		x[2]++;
		x[3]=2;
		y[3]++;
	break;
	}
}
void Shape::deactivate()
{
	active = false;
}
Coords Shape::getCoords()
{
	Coords p;
	p.x(x);
	p.y(y);
	return p;
}
void Coords::x(int x1[])
{
	X=x1;
}
void Coords::y(int y1[])
{
	Y=y1;
}
int * Coords::x()
{
	return X;
}
int * Coords::y()
{
	return Y;
}
QColor Shape::getFill()
{
	return fill;
}
