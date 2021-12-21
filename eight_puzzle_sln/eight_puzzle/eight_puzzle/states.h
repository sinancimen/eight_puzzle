
#include <vector>
#include <iostream>
#include "MyForm2.h"
#include <string>
#include <sstream>


class Node {
	Node* parent; // each node will have a parent
	std::vector< std::vector<int> > state; // a 2-D configuration
	int manhattan_distance; // manhattan_distance heuristic (only calculated when A* with manhattan_distance is used)
	int misplaced_tiles; // misplaced_tiles heuristic (only calculated when A* with misplaced_tiles is used)
	int blank_x; // position of empty tile (starts from 0)
	int blank_y;
	int stepsTaken = 0; // number of steps taken to reach this node from the initial node (automatically generated upon creating the node)

public:
	Node() {
		
	}
	Node(Node* parent, // constructor that will be used
		const std::vector< std::vector<int> >&state,
		int manhattan_distance) {
		this->parent = parent;
		this->state = state;
		this->manhattan_distance = manhattan_distance;
		if (this->parent != NULL)
		{
			this->stepsTaken = this->parent->stepsTaken + 1; // incremented parent's property by one
		}
	}

	Node* get_parent() //returns parent of the node (no need for setter for this property since generated at constructor)
	{
		return this->parent;
	}
	
	std::vector<std::vector<int>> getState() //returns 2-D configuration of the node
	{
		return this->state;
	};
	void setBlankPosition(int x, int y) //setter of blank position
	{
		this->blank_x = x;
		this->blank_y = y;
	}
	std::vector<int> getBlankPosition() //getter of blank position
	{
		std::vector<int> pos = { this->blank_x, this->blank_y };
		return pos;
	}

	void setManhattanDistance(int distance) //sets the manhattan distance
	{
		this->manhattan_distance = distance;
	}

	void setMisplacedTiles(int misplaced) //sets the misplaced tiles
	{
		this->misplaced_tiles = misplaced;
	}

	int getManhattanDistance() //getter for manhattan distance
	{
		return this->manhattan_distance;
	}
	
	int getMisplacedTiles() //getter for misplaced tiles
	{
		return this->misplaced_tiles;
	}

	int getStepsTaken() //getter for number of steps
	{
		return this->stepsTaken;
	}
};

//Definitions of functions that are used in solver.cpp and monte_carlo_functions.cpp
std::vector<std::vector<std::vector<int>>> find_solution_bfs(std::vector<int> initialPosition);
std::vector<std::vector<std::vector<int>>> find_solution_dfs(std::vector<int> initialPosition);
std::vector<std::vector<std::vector<int>>> find_solution_id(std::vector<int> initialPosition);
std::vector<std::vector<std::vector<int>>> find_solution_astar_manhattan(std::vector<int> initialPosition);
std::vector<std::vector<std::vector<int>>> find_solution_astar_misplaced(std::vector<int> initialPosition);
std::vector<int> find_solution_bfs_mc(std::vector<int> initialPosition);
std::vector<int> find_solution_dfs_mc(std::vector<int> initialPosition);
std::vector<int> find_solution_id_mc(std::vector<int> initialPosition);
std::vector<int> find_solution_astar_manhattan_mc(std::vector<int> initialPosition);
std::vector<int> find_solution_astar_misplaced_mc(std::vector<int> initialPosition);
std::vector<std::vector<std::vector<int>>> monte_carlo_generation(int size, int number_of_configurations, int number_of_moves);
void calculateManhattanDistance(Node* node);
void calculateMisplacedTiles(Node* node);
std::vector<std::vector<int>> generateGoalConfig(int size);
Node* generateInitialNode(std::vector<int> initialPosition);
std::vector<Node*> successors(Node* node);
Node* moveLeft(Node* node);
Node* moveRight(Node* node);
Node* moveUp(Node* node);
Node* moveDown(Node* node);

