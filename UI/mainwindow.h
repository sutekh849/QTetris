#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QStatusBar>
#include <QLabel>
#include <QWidget>
#include <QAction>
#include <QCloseEvent>
#include <QToolBar> 
//#include <QtGUI>
#include <QColor>
#include <iostream>
#include <QKeyEvent>
#include <QLine>
#include <QPainter>
#include "../Block/block.h"
#include "../Shape/shape.h"
#include "../Game/Game.h"
class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();
private:
	std::vector<std::vector<block>> blocks; 
	Game * g = nullptr;
protected:
void paintEvent(QPaintEvent *event);
void keyPressEvent(QKeyEvent *event);
	
};

#endif
