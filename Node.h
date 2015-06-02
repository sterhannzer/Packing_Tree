#ifndef _NODE_H
#define _NODE_H

#include <string>
#include <vector>

using namespace std;

class Node{
	public:
		Node();
		Node(string name, double multiple);
		~Node();

		void add_children(Node* _node);
		double get_multiplier();
		vector <Node*> get_tab_children();
		string get_name();
		
	private:
		double multiplier;
		string name;
		vector <Node*> tab_of_childrens;
		
};
#endif