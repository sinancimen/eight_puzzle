#include "states.h"
#include <math.h>

std::vector<Node*> successors(Node* configuration)
{
	std::vector<std::vector<int>> parentConfiguration = configuration->getState();
	std::vector<int> blankPosition= configuration->getBlankPosition();
	int size = parentConfiguration.size();
	std::vector<Node*> successors_list;
	if (blankPosition.at(0) == 0)
	{
		if (blankPosition.at(1) == 0)
		{
			successors_list.push_back(moveUp(configuration));
			successors_list.push_back(moveLeft(configuration));
			//move up and left
		}
		else if (blankPosition.at(1) == size - 1)
		{
			successors_list.push_back(moveLeft(configuration));
			successors_list.push_back(moveDown(configuration));
			//move left and down
		}
		else
		{
			successors_list.push_back(moveLeft(configuration));
			successors_list.push_back(moveUp(configuration));
			successors_list.push_back(moveDown(configuration));
			//move left, up, down
		}
	}
	else if (blankPosition.at(1) == 0)
	{
		if(blankPosition.at(0) == size - 1)
		{
			successors_list.push_back(moveRight(configuration));
			successors_list.push_back(moveUp(configuration));
			//move left and up
		}
		else
		{
			successors_list.push_back(moveRight(configuration));
			successors_list.push_back(moveUp(configuration));
			successors_list.push_back(moveLeft(configuration));
			//move right, left, up
		}
	}
	else if (blankPosition.at(0) == size - 1)
	{
		if (blankPosition.at(1) == size - 1)
		{
			successors_list.push_back(moveRight(configuration));
			successors_list.push_back(moveDown(configuration));
			// move down and right
		}
		else
		{
			successors_list.push_back(moveRight(configuration));
			successors_list.push_back(moveUp(configuration));
			successors_list.push_back(moveDown(configuration));
			//move up down right
		}
	}
	else if (blankPosition.at(1) == size - 1)
	{
		successors_list.push_back(moveRight(configuration));
		successors_list.push_back(moveLeft(configuration));
		successors_list.push_back(moveDown(configuration));
		//move left right down
	}
	else
	{
		successors_list.push_back(moveRight(configuration));
		successors_list.push_back(moveUp(configuration));
		successors_list.push_back(moveDown(configuration));
		successors_list.push_back(moveLeft(configuration));
		//move up down left right
	}
	return successors_list;
}

Node* moveLeft(Node* configuration)
{
	std::vector<int> blankPosition;
	blankPosition = configuration->getBlankPosition();
	std::vector<std::vector<int>> state = configuration->getState();
	state[blankPosition.at(0)][blankPosition.at(1)] = state.at(blankPosition.at(0) + 1).at(blankPosition.at(1));
	state[blankPosition.at(0) + 1][blankPosition.at(1)] = 0;
	Node* resultNode = new Node(configuration, state, 0);
	resultNode->setBlankPosition(blankPosition.at(0) + 1, blankPosition.at(1));
	return resultNode;
}

Node* moveRight(Node* configuration)
{
	std::vector<int> blankPosition;
	blankPosition = configuration->getBlankPosition();
	std::vector<std::vector<int>> state = configuration->getState();
	state[blankPosition.at(0)][blankPosition.at(1)] = state.at(blankPosition.at(0) - 1).at(blankPosition.at(1));
	state[blankPosition.at(0) - 1][blankPosition.at(1)] = 0;
	Node* resultNode = new Node(configuration, state, 0);
	resultNode->setBlankPosition(blankPosition.at(0) - 1, blankPosition.at(1));
	return resultNode;
}

Node* moveUp(Node* configuration)
{
	std::vector<int> blankPosition;
	blankPosition = configuration->getBlankPosition();
	std::vector<std::vector<int>> state = configuration->getState();
	state[blankPosition.at(0)][blankPosition.at(1)] = state.at(blankPosition.at(0)).at(blankPosition.at(1) + 1);
	state[blankPosition.at(0)][blankPosition.at(1) + 1] = 0;
	Node* resultNode = new Node(configuration, state, 0);
	resultNode->setBlankPosition(blankPosition.at(0), blankPosition.at(1) + 1);
	return resultNode;
}

Node* moveDown(Node* configuration)
{
	std::vector<int> blankPosition;
	blankPosition = configuration->getBlankPosition();
	std::vector<std::vector<int>> state = configuration->getState();
	state[blankPosition.at(0)][blankPosition.at(1)] = state.at(blankPosition.at(0)).at(blankPosition.at(1) - 1);
	state[blankPosition.at(0)][blankPosition.at(1) - 1] = 0;
	Node* resultNode = new Node(configuration, state, 0);
	resultNode->setBlankPosition(blankPosition.at(0), blankPosition.at(1) - 1);
	return resultNode;
}


std::vector<std::vector<std::vector<int>>> find_solution_bfs(std::vector<int> initialPosition)
{
	int size = sqrt(initialPosition.size());
	std::vector<std::vector<int>> initialConfiguration(size, std::vector<int>(size, 0));
	int blank_x = 0;
	int blank_y = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			initialConfiguration[i][j] = initialPosition.at(size*i + j);
			if (initialPosition.at(size*i + j) == 0)
			{
				blank_x = i;
				blank_y = j;
			}
		}
	}

	Node* initialNode = new Node(NULL, initialConfiguration, 0);
	initialNode->setBlankPosition(blank_x, blank_y);

	std::vector<std::vector<int>> goalConfiguration(size, std::vector<int>(size, 0));
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			goalConfiguration[i][j] = size*i + j + 1;
		}
	}
	goalConfiguration[size-1][size-1] = 0;

	int exploredNodes = 0;
	std::vector<Node*> queue;
	queue.push_back(initialNode);
	Node* result = NULL;
	std::vector<std::vector<std::vector<int>>> labeled_states;
	bool duplicate = false;

	while (true)
	{
		std::vector<Node*> successors_list = successors(queue.at(0));
		exploredNodes++;

		labeled_states.push_back(queue.at(0)->getState());

		if (queue.at(0)->getState() == goalConfiguration)
		{
			result = queue.at(0);
			break;
		}
		queue.erase(queue.begin());
		
		for (unsigned int i = 0; i < successors_list.size(); i++)
		{
			duplicate = false;
			for (unsigned int j = 0; j < labeled_states.size(); j++)
			{
				if (labeled_states.at(j) == successors_list.at(i)->getState())
				{
					duplicate = true;
				}
			}
			if (!duplicate)
				queue.push_back(successors_list.at(i));
		}
	}

	std::vector<std::vector<std::vector<int>>> resultSequence;
	resultSequence.push_back(result->getState());
	Node* parentNode = result->get_parent();
	while (parentNode != NULL)
	{
		resultSequence.insert(resultSequence.begin(), parentNode->getState());
		parentNode = parentNode->get_parent();
	}

	return resultSequence;
}