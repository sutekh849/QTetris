#include "mainwindow.h"
#define HEIGHT 600.0
#define WIDTH	400.0
//defined as doubles due to division for aspect ratio.
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
	setWindowTitle(QString::fromUtf8("DM Tetris"));
	resize(WIDTH, HEIGHT); //set size and prevent resizing for now. 
	setMinimumWidth(WIDTH);
	setMaximumWidth(WIDTH);
	setMaximumHeight(HEIGHT);
	setMinimumHeight(HEIGHT);

	/*
		opengl - define columns, and rows. columns as width/12. 
	*/
	int colWidth = WIDTH/12;
	//we want these to be squares, so colWidth is acually rowHeight too.
	double numRows = HEIGHT/WIDTH;
	for(int y=0;y<(numRows*12);y++)
	{
		std::vector<block> b1;
		for(int x=0; x<12;x++)
		{
			int X = x * colWidth;
			int Y = y * colWidth;
			block h(x,X,y,Y,colWidth);
			b1.push_back(h); 
		}
		blocks.push_back(b1);
	}

}
MainWindow::~MainWindow()
{

}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
	if(event->key() == Qt::Key_Left)
	{
		if(g!=nullptr)
		{
			g->left();
		}
	}
	else if(event->key() == Qt::Key_Right)
	{
		if(g!=nullptr)
		{
			g->right();
		}
	}
	else if(event->key() == Qt::Key_Up)
	{
		if(g!=nullptr)
		{
			g->down();
		}
	}
	else if(event ->key()==Qt::Key_Space)
	{
		g = new Game(&blocks, this);
	}
}

void MainWindow::paintEvent(QPaintEvent * event)
{
	QPainter painter(this);
	QPen pen1(Qt::black);
	pen1.setWidth(1);
	painter.setPen(pen1);
	/*Shape s(Shape::T);
	s.rotate();
	s.rotate();
	Coords c= s.getCoords();
	int * sX = c.x();
	int * sY = c.y();
	for(int x =0; x<4; x++)
	{
		//std::cout << sX[x] << "  " << sY[x] << "\n";
		blocks.at(2+sX[x]).at(5+sY[x]).setFill(Qt::green);
	}
		//blocks.at(2).at(5).setFill(Qt::green);
   */
	for(int i = 0; i<blocks.size();i++)
	{
		for(int y = 0; y<blocks.at(i).size();y++)
		{
			painter.setBrush(blocks.at(i).at(y).getFill());
			painter.drawRect(blocks.at(i).at(y).getQRect());
		}
	}

	painter.end();
}
