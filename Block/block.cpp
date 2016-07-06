#include "block.h"
block::block(int x, int posX, int y, int posY, int size)
{
	X = x;
	posx = posX;
	Y = y;
	posy = posY;
	square = QRect(posX,posY,size,size);
}
QRect block::getQRect()
{
	return square; 
}
void block::setFill(const QColor &Colour)
{
	QColor l(Colour);
	colour = l;
}
QColor block::getFill()
{
	return colour;
}
