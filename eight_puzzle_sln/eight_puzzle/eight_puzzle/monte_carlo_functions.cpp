#include "states.h"
#include <math.h>
#include <ctime>
#include <queue>
#include <functional>
#include <random>
#include <algorithm>

std::vector<int> find_solution_bfs_mc(std::vector<int> initialPosition)
{
	int size = sqrt(initialPosition.size());
	Node* initialNode = generateInitialNode(initialPosition);
	std::vector<std::vector<int>> goalConfiguration = generateGoalConfig(size);
	int exploredNodes = 0;
	std::vector<Node*> queue;
	queue.push_back(initialNode);
	std::vector<std::vector<std::vector<int>>> labeled_states;
	bool duplicate = false;
	System::String^ solving_str = "SOLVING";
	System::String^ failed_str = "FAILED";
	System::String^ success_str = "SUCCESS";

	while (true)
	{
		std::vector<Node*> successors_list = successors(queue.at(0));
		exploredNodes++;

		labeled_states.push_back(queue.at(0)->getState());

		if (queue.at(0)->getState() == goalConfiguration)
		{
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

	int explored_nodes = labeled_states.size();
	int memory_usage = explored_nodes + queue.size();
	std::vector<int> result;
	result.push_back(explored_nodes);
	result.push_back(memory_usage);
	return result;
}

std::vector<int> find_solution_dfs_mc(std::vector<int> initialPosition)
{
	int size = sqrt(initialPosition.size());
	Node* initialNode = generateInitialNode(initialPosition);
	std::vector<std::vector<int>> goalConfiguration = generateGoalConfig(size);
	int exploredNodes = 0;
	std::vector<Node*> queue;
	queue.push_back(initialNode);
	std::vector<std::vector<std::vector<int>>> labeled_states;
	bool duplicate = false;
	System::String^ solving_str = "SOLVING";
	System::String^ failed_str = "FAILED";
	System::String^ success_str = "SUCCESS";

	while (true)
	{
		if (queue.size() == 0)
		{
			break;
		}
		else
		{
			std::vector<Node*> successors_list = successors(queue.at(queue.size() - 1));
			exploredNodes++;

			labeled_states.push_back(queue.at(queue.size() - 1)->getState());

			if (queue.at(0)->getState() == goalConfiguration)
			{
				break;
			}
			queue.pop_back();

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
	}

	int explored_nodes = labeled_states.size();
	int memory_usage = explored_nodes + queue.size();
	std::vector<int> result;
	result.push_back(explored_nodes);
	result.push_back(memory_usage);

	return result;
}

std::vector<int> find_solution_id_mc(std::vector<int> initialPosition)
{
	int size = sqrt(initialPosition.size());
	Node* initialNode = generateInitialNode(initialPosition);
	std::vector<std::vector<int>> goalConfiguration = generateGoalConfig(size);
	int exploredNodes = 0;
	std::vector<Node*> queue;
	queue.push_back(initialNode);
	bool duplicate = false;
	System::String^ solving_str = "SOLVING";
	System::String^ failed_str = "FAILED";
	System::String^ success_str = "SUCCESS";
	std::vector<Node*> successors_list;
	std::vector<Node*> depth_list;
	bool success = false;
	int depth = 1;

	while (true)
	{
		for (unsigned int i = 0; i < depth; i++)
		{
			for (unsigned int j = 0; j < queue.size(); j++)
			{
				successors_list = successors(queue.at(j));
				for (unsigned int n = 0; n < successors_list.size(); n++)
				{
					depth_list.push_back(successors_list.at(n));
				}
			}
			queue = depth_list;
			depth_list.clear();
		}
		for (unsigned int k = 0; k < queue.size(); k++)
		{
			exploredNodes++;

			if (queue.at(k)->getState() == goalConfiguration)
			{
				success = true;
				break;
			}

		}
		if (success)
		{
			break;
		}
		depth++;
	}

	int explored_nodes = exploredNodes;
	int memory_usage = explored_nodes + queue.size();
	std::vector<int> result;
	result.push_back(explored_nodes);
	result.push_back(memory_usage);

	return result;
}

struct CompareManhattanDistance {
	bool operator()(Node* const& n1, Node* const& n2)
	{
		return n1->getManhattanDistance() > n2->getManhattanDistance();
	}
};

struct CompareMisplacedTiles {
	bool operator()(Node* const& n1, Node* const& n2)
	{
		return n1->getMisplacedTiles() > n2->getMisplacedTiles();
	}
};

std::vector<int> find_solution_astar_manhattan_mc(std::vector<int> initialPosition)
{
	int size = sqrt(initialPosition.size());
	Node* initialNode = generateInitialNode(initialPosition);
	std::vector<std::vector<int>> goalConfiguration = generateGoalConfig(size);
	int exploredNodes = 0;
	std::priority_queue<int, std::vector<Node*>, CompareManhattanDistance> queue;
	calculateManhattanDistance(initialNode);
	queue.push(initialNode);
	std::vector<std::vector<std::vector<int>>> labeled_states;
	bool duplicate = false;
	System::String^ solving_str = "SOLVING";
	System::String^ failed_str = "FAILED";
	System::String^ success_str = "SUCCESS";

	while (true)
	{
		std::vector<Node*> successors_list = successors(queue.top());
		exploredNodes++;

		Node* node_temp = queue.top();
		labeled_states.push_back(queue.top()->getState());

		if (queue.top()->getState() == goalConfiguration)
		{
			break;
		}
		queue.pop();

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
			{
				Node* temp_node = successors_list.at(i);
				calculateManhattanDistance(temp_node);
				queue.push(successors_list.at(i));
			}
		}
	}

	int explored_nodes = exploredNodes;
	int memory_usage = explored_nodes + queue.size();
	std::vector<int> result;
	result.push_back(explored_nodes);
	result.push_back(memory_usage);

	return result;
}

std::vector<int> find_solution_astar_misplaced_mc(std::vector<int> initialPosition)
{
	int size = sqrt(initialPosition.size());
	Node* initialNode = generateInitialNode(initialPosition);
	std::vector<std::vector<int>> goalConfiguration = generateGoalConfig(size);
	int exploredNodes = 0;
	std::priority_queue<int, std::vector<Node*>, CompareMisplacedTiles> queue;
	calculateMisplacedTiles(initialNode);
	queue.push(initialNode);
	std::vector<std::vector<std::vector<int>>> labeled_states;
	bool duplicate = false;
	System::String^ solving_str = "SOLVING";
	System::String^ failed_str = "FAILED";
	System::String^ success_str = "SUCCESS";

	while (true)
	{
		std::vector<Node*> successors_list = successors(queue.top());
		exploredNodes++;

		Node* node_temp = queue.top();
		labeled_states.push_back(queue.top()->getState());

		if (queue.top()->getState() == goalConfiguration)
		{
			break;
		}
		queue.pop();

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
			{
				Node* temp_node = successors_list.at(i);
				calculateMisplacedTiles(temp_node);
				queue.push(successors_list.at(i));
			}
		}
	}

	int explored_nodes = exploredNodes;
	int memory_usage = explored_nodes + queue.size();
	std::vector<int> result;
	result.push_back(explored_nodes);
	result.push_back(memory_usage);

	return result;
}

std::vector<std::vector<std::vector<int>>> monte_carlo_generation(int size, int number_of_configurations, int number_of_moves)
{
	Node* initialNode = new Node(NULL, generateGoalConfig(size), 0);
	initialNode->setBlankPosition(size-1, size-1);
	std::vector<std::vector<std::vector<int>>> config_list;
	for (int k = 0; k < number_of_configurations; k++)
	{
		std::vector<Node*> queue;
		queue.push_back(initialNode);
		std::vector<std::vector<std::vector<int>>> labeled_states;
		bool duplicate = false;
		int move = 0;

		while (move < number_of_moves)
		{
			std::vector<Node*> successors_list = successors(queue.at(queue.size() - 1));
			labeled_states.push_back(queue.at(queue.size() - 1)->getState());

			std::random_shuffle(std::begin(successors_list), std::end(successors_list));
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
				{
					queue.push_back(successors_list.at(i));
					break;
				}
			}
			move++;
		}
		config_list.push_back(queue.at(queue.size()-1)->getState());
		queue.clear();
	}

	return config_list;
}