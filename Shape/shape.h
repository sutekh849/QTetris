#ifndef SHAPE_H
#define SHAPE_H
#include "../Block/block.h"
#include <iostream>
#include <QColor>
class Coords
{
public:
	int * X;
	int * Y;
	void x(int * x1);
	void y(int * y1);
	int* x();
	int* y();
};
class Shape
{
public:

		typedef enum {BLOCK,Z,FL,RL,LINE,T} type;
		Shape(type shapeType);
		void rotate();
		bool isActive();
		void deactivate();
		Coords getCoords();
		type getType();
		QColor getFill();
	private: 
		QColor fill;
		int x[4];
		int y[4];
		bool active = true;
		type Type;
		//tetris shapes are always 4 blocks
		
	/*
	idea is to use a co-ordinate system from the bottom left to construct shapes.
	the square shape should have co-ordinates of [0,0],[1,0],[0,1],[1,1]
									x1,y1 x2,y2 x3,y3 x4,y4
	"Block": 					[0,0],[1,0],[0,1],[1,1] (all rotations)
	"Z" upright : 				[0,0],[0,1],[1,1],[1,2]
	"Z" horizontal:			[0,0],[1,0],[1,1],[2,1]
	"L" Vertical : 			[0,0],[1,0],[0,1],[0,2]
	"Reverse L" Vertical: 	[0,0],[1,0],[1,1],[2,1]
	"Line Vertial":			[0,0],[0,1],[0,2],[0,3]
	"Line Horizontal"			[0,0],[1,0],[2,0],[3,0]7
	"T"							[0,1],[1,1],[1,0],[2,1]
	Rotation can be done by flipping each x and y. 
	*/
	
	
};

#endif
