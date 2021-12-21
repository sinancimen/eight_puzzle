#include "states.h"
#include <math.h>
#include <ctime>
#include <queue>
#include <functional>


std::vector<Node*> successors(Node* configuration) //The function that returns possible next nodes from a node
{
	std::vector<std::vector<int>> parentConfiguration = configuration->getState(); //retrieving the state of the input node to calculate size of the grid
	std::vector<int> blankPosition= configuration->getBlankPosition(); //function will decide on what moves it can take by using the position of blank tile
	int size = parentConfiguration.size();
	std::vector<Node*> successors_list; //initializing the vector that will be returned
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
			successors_list.push_back(moveDown(configuration));
			successors_list.push_back(moveLeft(configuration));
			//move left and down
		}
		else
		{
			successors_list.push_back(moveDown(configuration));
			successors_list.push_back(moveLeft(configuration));
			successors_list.push_back(moveUp(configuration));
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
			successors_list.push_back(moveDown(configuration));
			successors_list.push_back(moveUp(configuration));
			//move up down right
		}
	}
	else if (blankPosition.at(1) == size - 1)
	{
		successors_list.push_back(moveRight(configuration));
		successors_list.push_back(moveDown(configuration));
		successors_list.push_back(moveLeft(configuration));
		//move left right down
	}
	else
	{
		successors_list.push_back(moveRight(configuration));
		successors_list.push_back(moveDown(configuration));
		successors_list.push_back(moveUp(configuration));
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


Node* generateInitialNode(std::vector<int> initialPosition) //this function will create a node from initial state
{
	int size = sqrt(initialPosition.size());
	std::vector<std::vector<int>> initialConfiguration(size, std::vector<int>(size, 0));
	int blank_x = 0;
	int blank_y = 0; 
	for (int i = 0; i < size; i++) //converting 1-D vector to 2-D
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

	Node* initialNode = new Node(NULL, initialConfiguration, 0); //There will be no parent of initial node
	initialNode->setBlankPosition(blank_x, blank_y); 

	return initialNode;
}

std::vector<std::vector<int>> generateGoalConfig(int size) //size dependent goal configuration generator ex: 123;456;780
{
	std::vector<std::vector<int>> goalConfiguration(size, std::vector<int>(size, 0));
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			goalConfiguration[i][j] = size*i + j + 1;
		}
	}
	goalConfiguration[size - 1][size - 1] = 0;
	return goalConfiguration;
}

std::vector<std::vector<std::vector<int>>> find_solution_bfs(std::vector<int> initialPosition) //Breath-First Search
{
	int size = sqrt(initialPosition.size());
	Node* initialNode = generateInitialNode(initialPosition); //Generating initial node
	std::vector<std::vector<int>> goalConfiguration = generateGoalConfig(size); //Generating goal configuration (2-D vector)
	int exploredNodes = 0;
	std::vector<Node*> queue; // the queue which will be used
	queue.push_back(initialNode); // queue will start with the initial node
	Node* result = NULL; //variable to store solution node
	std::vector<std::vector<std::vector<int>>> labeled_states; //vector of labeled configurations which will be used for loop checking
	bool duplicate = false; // dummy variable to be used for loop checking
	System::String^ solving_str = "SOLVING"; // strings that will be shown in the Solver GUI
	System::String^ failed_str = "FAILED";
	System::String^ success_str = "SUCCESS";
	eight_puzzle::MyForm2^ solver_window = gcnew eight_puzzle::MyForm2(); // creating new instance of the Solver GUI
	solver_window->Show(); 
	solver_window->setSolverStatusText(solving_str); // solver status on GUI will start with "Solving"
	clock_t begin = clock(); // beginning of clock to measure time required to solve

	while (true)
	{
		std::vector<Node*> successors_list = successors(queue.at(0)); //at each iteration, first element of the queue will be used
		exploredNodes++; // number of explored nodes is incremented by 1 at each iteration

		std::string str = std::to_string(exploredNodes); // to show the number of explored nodes, int must be converted to System::String^
		System::String^ str2 = gcnew System::String(str.c_str()); // which is a requirement of Windows Forms
		solver_window->setNodesExploreText(str2);
		solver_window->Refresh(); // refreshing the GUI to show the new number

		labeled_states.push_back(queue.at(0)->getState()); // explored nodes are added to labeled_list to be used for loop checking

		if (queue.at(0)->getState() == goalConfiguration) // checking if the last explored node is the goal
		{
			result = queue.at(0);
			solver_window->setSolverStatusText(success_str); //if so, solver status on GUI will be changed to "SUCCESS"
			break;
		}
		queue.erase(queue.begin()); // erasing the explored node from the queue
		
		for (unsigned int i = 0; i < successors_list.size(); i++) // loop checking and adding successors to queue
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

	clock_t end = clock(); // end of clock
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC; //calculation of elapsed time and converting it to System::String^
	std::string str3 = std::to_string(elapsed_secs);
	System::String^ str4 = gcnew System::String(str3.c_str());
	solver_window->setTimePassedText(str4);

	std::vector<std::vector<std::vector<int>>> resultSequence;
	resultSequence.push_back(result->getState());
	Node* parentNode = result->get_parent();
	while (parentNode != NULL) // creating the sequence of moves from the result Node by having its parent at each iteration until parent is NULL
	{
		resultSequence.insert(resultSequence.begin(), parentNode->getState());
		parentNode = parentNode->get_parent();
	}

	return resultSequence;
}

std::vector<std::vector<std::vector<int>>> find_solution_dfs(std::vector<int> initialPosition) //Depth-First Search
{
	int size = sqrt(initialPosition.size());
	Node* initialNode = generateInitialNode(initialPosition);
	std::vector<std::vector<int>> goalConfiguration = generateGoalConfig(size);
	int exploredNodes = 0;
	std::vector<Node*> queue;
	queue.push_back(initialNode);
	Node* result = NULL;
	std::vector<std::vector<std::vector<int>>> labeled_states;
	bool duplicate = false;
	System::String^ solving_str = "SOLVING";
	System::String^ failed_str = "FAILED";
	System::String^ success_str = "SUCCESS";
	eight_puzzle::MyForm2^ solver_window = gcnew eight_puzzle::MyForm2();
	solver_window->Show();
	solver_window->setSolverStatusText(solving_str);
	clock_t begin = clock();
	bool success = false;

	while (true)
	{
		if (queue.size() == 0)
		{
			result = initialNode;
			solver_window->setSolverStatusText(failed_str);
			break;
		}
		else
		{
			std::vector<Node*> successors_list = successors(queue.at(queue.size() - 1)); // Instead of first element of the queue, DFS will take the last element
			exploredNodes++;

			std::string str = std::to_string(exploredNodes);
			System::String^ str2 = gcnew System::String(str.c_str());
			solver_window->setNodesExploreText(str2);
			solver_window->Refresh();

			labeled_states.push_back(queue.at(queue.size() - 1)->getState());
			queue.pop_back(); 

			for (unsigned int i = 0; i < successors_list.size(); i++)
			{
				duplicate = false;
				if (successors_list.at(i)->getState() == goalConfiguration)
				{
					success = true;
					result = successors_list.at(i);
					break;
				}
				for (unsigned int j = 0; j < labeled_states.size(); j++)
				{
					if (labeled_states.at(j) == successors_list.at(i)->getState())
					{
						duplicate = true;
					}
				}
				if (!duplicate)
				{
					if (successors_list.at(i)->getStepsTaken() < 20) // Depth limit is 20
						queue.push_back(successors_list.at(i));
				}
					
			}
			if (success)
			{
				solver_window->setSolverStatusText(success_str);
				break;
			}

		}
	}

	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	std::string str3 = std::to_string(elapsed_secs);
	System::String^ str4 = gcnew System::String(str3.c_str());
	solver_window->setTimePassedText(str4);

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

std::vector<std::vector<std::vector<int>>> find_solution_id(std::vector<int> initialPosition) //Iterative Deepening Search
{
	int size = sqrt(initialPosition.size());
	Node* initialNode = generateInitialNode(initialPosition);
	std::vector<std::vector<int>> goalConfiguration = generateGoalConfig(size);
	int exploredNodes = 0;
	std::vector<Node*> queue;
	queue.push_back(initialNode);
	Node* result = NULL;
	bool duplicate = false;
	System::String^ solving_str = "SOLVING";
	System::String^ failed_str = "FAILED";
	System::String^ success_str = "SUCCESS";
	eight_puzzle::MyForm2^ solver_window = gcnew eight_puzzle::MyForm2();
	solver_window->Show();
	solver_window->setSolverStatusText(solving_str);
	clock_t begin = clock();
	std::vector<Node*> successors_list;
	std::vector<Node*> depth_list;
	bool success = false;

	while (true)
	{
		for (unsigned int j = 0; j < queue.size(); j++) // At each loop, successors of the current queue will be the next queue
		{
			successors_list = successors(queue.at(j));
			exploredNodes++;
			for (unsigned int n = 0; n < successors_list.size(); n++)
			{
				depth_list.push_back(successors_list.at(n));
				if (successors_list.at(n)->getState() == goalConfiguration)
				{
					result = successors_list.at(n);
					solver_window->setSolverStatusText(success_str);
					success = true;
					break;
				}
			}
			if (success)
			{
				break;
			}
			std::string str = std::to_string(exploredNodes);
			System::String^ str2 = gcnew System::String(str.c_str());
			solver_window->setNodesExploreText(str2);
			solver_window->Refresh();
		}
		queue.clear();
		queue = depth_list;
		depth_list.clear();
		if (success)
		{
			break;
		}
	}

	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	std::string str3 = std::to_string(elapsed_secs);
	System::String^ str4 = gcnew System::String(str3.c_str());
	solver_window->setTimePassedText(str4);

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

void calculateManhattanDistance(Node* node) //Calculate manhattan distance heuristic and write it to the property of the node
{
	std::vector<std::vector<int>> state = node->getState();
	int size = state.size();
	int manhattan_distance = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			int number_on_state = state.at(i).at(j);
			if (number_on_state == 0)
				number_on_state = size*size; // the blank tile is normally denoted as 0; however, to calculate the manhattan distance properly, it is size^2 for now
			manhattan_distance += abs((int)(number_on_state / size) - (int)((size * i + j + 1) / size)) + abs((int)(number_on_state % size) - (int)((size * i + j + 1) % size));
		}
	}
	manhattan_distance += node->getStepsTaken(); // the number of steps taken to reach that node is added to the heuristic (cost)
	node->setManhattanDistance(manhattan_distance); // set to property of the class
}

void calculateMisplacedTiles(Node* node) //Calculate misplaced tiles heuristic and write it to the property of the node
{
	std::vector<std::vector<int>> state = node->getState();
	int size = state.size();
	int misplaced_tiles = 0;
	for (int i = 0; i < size; i++) //size*i+j+1 corresponds to the desired number on the tile at i,j (i and j start from 0)
	{
		for (int j = 0; j < size; j++)
		{
			if (state.at(i).at(j) != size * i + j + 1)
				misplaced_tiles++; // for each tile with wrong number on it, heuristic is incremented by one
		}
	}
	misplaced_tiles += node->getStepsTaken(); // the number of steps taken to reach that node is added to the heuristic (cost)
	node->setMisplacedTiles(misplaced_tiles); // set to property of the class
}

struct CompareManhattanDistance { // comparison struct used for std::priority_queue (a default function type to arrange priority queue)
	bool operator()(Node* const& n1, Node* const& n2)
	{
		return n1->getManhattanDistance() > n2->getManhattanDistance();
	}
};

struct CompareMisplacedTiles { // comparison struct used for std::priority_queue (a default function type to arrange priority queue)
	bool operator()(Node* const& n1, Node* const& n2)
	{
		return n1->getMisplacedTiles() > n2->getMisplacedTiles();
	}
};

std::vector<std::vector<std::vector<int>>> find_solution_astar_manhattan(std::vector<int> initialPosition) // A* with Manhattan distance
{
	int size = sqrt(initialPosition.size());
	Node* initialNode = generateInitialNode(initialPosition);
	std::vector<std::vector<int>> goalConfiguration = generateGoalConfig(size);
	int exploredNodes = 0;
	std::priority_queue<int, std::vector<Node*>, CompareManhattanDistance> queue; // instead of simply using std::vector, std::priority queue is used
	// the order of the priority queue will be determined by CompareManhattanDistance struct.
	calculateManhattanDistance(initialNode);
	queue.push(initialNode);
	Node* result = NULL;
	std::vector<std::vector<std::vector<int>>> labeled_states;
	bool duplicate = false;
	System::String^ solving_str = "SOLVING";
	System::String^ failed_str = "FAILED";
	System::String^ success_str = "SUCCESS";
	eight_puzzle::MyForm2^ solver_window = gcnew eight_puzzle::MyForm2();
	solver_window->Show();
	solver_window->setSolverStatusText(solving_str);
	clock_t begin = clock();

	while (true)
	{
		std::vector<Node*> successors_list = successors(queue.top()); // will use the element with lowest heuristic value at each iteration
		exploredNodes++;

		std::string str = std::to_string(exploredNodes);
		System::String^ str2 = gcnew System::String(str.c_str());
		solver_window->setNodesExploreText(str2);
		solver_window->Refresh();

		Node* node_temp = queue.top();
		labeled_states.push_back(queue.top()->getState());

		if (queue.top()->getState() == goalConfiguration)
		{
			result = queue.top();
			solver_window->setSolverStatusText(success_str);
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

	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	std::string str3 = std::to_string(elapsed_secs);
	System::String^ str4 = gcnew System::String(str3.c_str());
	solver_window->setTimePassedText(str4);

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

std::vector<std::vector<std::vector<int>>> find_solution_astar_misplaced(std::vector<int> initialPosition) // A* with Misplaced Tiles
{
	// same as A* with Manhattan distance with only changing the heuristic
	int size = sqrt(initialPosition.size());
	Node* initialNode = generateInitialNode(initialPosition);
	std::vector<std::vector<int>> goalConfiguration = generateGoalConfig(size);
	int exploredNodes = 0;
	std::priority_queue<int, std::vector<Node*>, CompareMisplacedTiles> queue;
	calculateMisplacedTiles(initialNode);
	queue.push(initialNode);
	Node* result = NULL;
	std::vector<std::vector<std::vector<int>>> labeled_states;
	bool duplicate = false;
	System::String^ solving_str = "SOLVING";
	System::String^ failed_str = "FAILED";
	System::String^ success_str = "SUCCESS";
	eight_puzzle::MyForm2^ solver_window = gcnew eight_puzzle::MyForm2();
	solver_window->Show();
	solver_window->setSolverStatusText(solving_str);
	clock_t begin = clock();

	while (true)
	{
		std::vector<Node*> successors_list = successors(queue.top());
		exploredNodes++;

		std::string str = std::to_string(exploredNodes);
		System::String^ str2 = gcnew System::String(str.c_str());
		solver_window->setNodesExploreText(str2);
		solver_window->Refresh();

		Node* node_temp = queue.top();
		labeled_states.push_back(queue.top()->getState());

		if (queue.top()->getState() == goalConfiguration)
		{
			result = queue.top();
			solver_window->setSolverStatusText(success_str);
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

	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	std::string str3 = std::to_string(elapsed_secs);
	System::String^ str4 = gcnew System::String(str3.c_str());
	solver_window->setTimePassedText(str4);

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

