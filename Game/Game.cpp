#include "Game.h"


Shape::type Game::randomShape()
{
	srand(time(NULL));
	int shapeRef = rand() % 6;
	switch (shapeRef)
	{
		case 0:
		return Shape::BLOCK;
		break;
		case 1:
		return Shape::Z;
		break;
		case 2:
		return Shape::FL;
		break;
		case 3:
		return Shape::RL;
		break;
		case 4:
		return Shape::LINE;
		break; 
		case 5:
		return Shape::T;
		break;
	}
	return Shape::T;
}
Game::Game(std::vector<std::vector<block>> * Blocks, QMainWindow * parent):QObject(parent)
{
	blocks = Blocks;
	currentRow = 2;
	std::thread t([this] {
		gameThread();
	});
	t.detach(); 
}
void Game::gameThread()
{

	while(!lost)
	{
		if(currentShape == nullptr)
		{
			currentShape = new Shape(randomShape());
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(ms));
		if(ms<1)
		{
			ms--;
		}
		currentRow++;
		mtx.lock();
		if(currentRow!=blocks->size() && blockHandler())
		{
			QMainWindow * p =(QMainWindow*)parent();
			p->repaint();
		}
		else
		{
			lineChecker();
			if(currentRow<=3)
			{
				lost == true;
			}
			else
			{
				currentRow =2 ;
				currentColumn = 5;
				delete currentShape;
				currentShape = nullptr;
			}
		}
		mtx.unlock();
		

	}
}
void Game::left()
{
	mtx.lock();
	Coords c = currentShape->getCoords();
	int* sX= c.x();
	int* sY =c.y();
	for(int x=0; x<4;x++)
	{
		if(currentColumn + sY[x] -1 < 0)
		{
			mtx.unlock();
			return;
		}
	}
	for(int x=0; x<4; x++)
	{
		if(blocks->at(currentRow+sX[x]).at(currentColumn-1+sY[x]).getFill() != Qt::white)
		{
			bool n = true;
			for(int j =0; j<4;j++)
			{
				if(sX[x] == sX[j] && sY[x]==sY[j]-1)
				{
					n=false;
					break;
				}
			}
		}
	}
	deleteCurrentShape();
	currentColumn--;
	for(int x=0;x<4;x++)
	{
		blocks->at(/*todo!!*/currentRow+sX[x]).at(currentColumn+sY[x]).setFill(currentShape->getFill());
	}
	mtx.unlock();
}
void Game::right()
{
	mtx.lock();
	Coords c = currentShape->getCoords();
	int* sX= c.x();
	int* sY =c.y();
	for(int x=0; x<4;x++)
	{
		if(currentColumn + sY[x] +1  >= blocks->at(0).size())
		{
			mtx.unlock();
			return;
		}
	}
	for(int x=0;x<4;x++)
	{
		if(blocks->at(currentRow+sX[x]).at(currentColumn+1+sY[x]).getFill() != Qt::white)
		{
			bool n = true;
			for(int j =0; j<4;j++)
			{
				if(sX[x] == sX[j] && sY[x]==sY[j]+1)
				{
					n=false;
					break;
				}
			}
		}
	}
	deleteCurrentShape();
	currentColumn++;
	for(int x=0;x<4;x++)
	{
		blocks->at(/*todo!!*/currentRow+sX[x]).at(currentColumn+sY[x]).setFill(currentShape->getFill());
	}
	mtx.unlock();
}
void Game::down()
{
	mtx.lock();
	deleteCurrentShape();
	currentShape->rotate();
	Coords c= currentShape->getCoords();
	int * sX = c.x();
	int * sY = c.y();
	for(int x=0;x<4;x++)
	{
		blocks->at(/*todo!!*/currentRow+sX[x]).at(currentColumn+sY[x]).setFill(currentShape->getFill());
	}
	mtx.unlock();
}
void Game::deleteCurrentShape()
{
	Coords c= currentShape->getCoords();
	int * sX = c.x();
	int * sY = c.y();
	for(int x=0;x<4;x++)
	{
		blocks->at(currentRow+sX[x]).at(currentColumn+sY[x]).setFill(Qt::white);
	}
}
bool Game::blockHandler()
{
	Coords c = currentShape->getCoords();
	int * sX = c.x();
	int * sY = c.y();
	for(int x=0; x<4; x++)
	{
		
		if(currentRow+sX[x] == blocks->size())
		{
			return false;
		}
		if(blocks->at(currentRow+sX[x]).at(currentColumn+sY[x]).getFill()!=Qt::white)
		{
			bool n = true;
			for(int j =0; j<4;j++)
			{
				if(sX[x] == sX[j]-1 && sY[x]==sY[j])
				{
					n=false;
					break;
				}
			}
			if(n)
			{
				return false;
			}
		}
	}
	for(int x=0; x<4; x++)
	{
		blocks->at(currentRow-1+sX[x]).at(currentColumn+sY[x]).setFill(Qt::white);
	}
	for(int x=0;x<4;x++)
	{
		blocks->at(/*todo!!*/currentRow+sX[x]).at(currentColumn+sY[x]).setFill(currentShape->getFill());
	}


	return true;
}
void Game::lineChecker()
{
	for(int x=1;x<blocks->size();x++)
	{
		int c = 0;
		for(int y=0; y<blocks->at(x).size();y++)
		{
			if(blocks->at(x).at(y).getFill() != Qt::white)
			{
				c++;//whey!
			}
		}
		if(c==blocks->at(0).size())
		{
			//hooooo boy. 
			//delete current row. 
			for(int z = x;z>1;z--)
			{
				for(int y =0;y<blocks->at(0).size();y++)
				{
					blocks->at(z).at(y).setFill(blocks->at(z-1).at(y).getFill());
				}
			}

		}
	}
}

