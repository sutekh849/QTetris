#ifndef GAME_H
#define GAME_H
#include <QObject>
#include "../Shape/shape.h"
#include "../Block/block.h"
#include <QMainWindow>
#include <chrono>
#include <thread>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <mutex>
class Game : public QObject
{
	Q_OBJECT

	private:
	std::mutex mtx;
	bool lost = false;
	int ms = 500; //miliseconds between the drops
	int currentRow = 0;
	int currentColumn =5;
	Shape * currentShape = nullptr;
	std::vector<std::vector<block>> *blocks;
	bool blockHandler(); 
	
	protected:

	public:
	Game(std::vector<std::vector<block>>* Blocks, QMainWindow* parent);
	Shape::type randomShape();
	//todo: see if slots will make these work. 
	void right();
	void left();
	void down();
	void gameThread();
	void deleteCurrentShape();
	void lineChecker();
};
#endif
