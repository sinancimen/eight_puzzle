
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
	Node* get_parent();
	void print_node();
	
	std::vector<std::vector<int>> getState(Node* node)
	{
		return node->state;
	};
	void setBlankPosition(Node* node, int x, int y)
	{
		node->blank_x = x;
		node->blank_y = y;
	}
	std::vector<int> getBlankPosition(Node* node)
	{
		std::vector<int> pos = { blank_x, blank_y };
		return pos;
	}
};

void find_solution_bfs(std::vector<int> initialPosition);
std::vector<Node*> successors(Node* node);
Node* moveLeft(Node* node);
Node* moveRight(Node* node);
Node* moveUp(Node* node);
Node* moveDown(Node* node);