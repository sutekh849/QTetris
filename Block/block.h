#ifndef BLOCK_H
#define BLOCK_H
#include <QRect>
#include <QBrush>
#include <QColor>
class block
{
/*
	Block represents a square that may be filled or not filled.
	the class contains co-ordinates of the lower left hand corner.
	todo: setcolour, isFilled, Fill, Empty. 
*/
private:
	int X;
	int Y;
	int posx;
	int posy;
	QRect square;
	QBrush brush; 
	QColor colour = Qt::white; 
public:
	block(int x, int posX, int y, int posY,int size);
	QRect getQRect();
	void setFill(const QColor &Colour);
	QColor getFill();
};
#endif
