
#include <vector>
#include <iostream>


class Node {
	Node* parent;
	std::vector< std::vector<int> > state;
	int manhattan_distance;
	int blank_x;
	int blank_y;

public:
	Node() {}
	Node(Node* parent,
		const std::vector< std::vector<int> >&state,
		int manhattan_distance) {
		this->parent = parent;
		this->state = state;
		this->manhattan_distance = manhattan_distance;
	}

	int get_manhattan_distance();
	Node* get_parent()
	{
		return this->parent;
	}
	
	std::vector<std::vector<int>> getState()
	{
		return this->state;
	};
	void setBlankPosition(int x, int y)
	{
		this->blank_x = x;
		this->blank_y = y;
	}
	std::vector<int> getBlankPosition()
	{
		std::vector<int> pos = { this->blank_x, this->blank_y };
		return pos;
	}
};

std::vector<std::vector<std::vector<int>>> find_solution_bfs(std::vector<int> initialPosition);
std::vector<Node*> successors(Node* node);
Node* moveLeft(Node* node);
Node* moveRight(Node* node);
Node* moveUp(Node* node);
Node* moveDown(Node* node);