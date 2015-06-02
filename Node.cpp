#include "Node.h"


Node::Node(string _name, double _multiple){
	name = _name;
	multiplier = _multiple;
}

Node::Node(){
}

Node::~Node(){
	for(auto children : tab_of_childrens)
		delete children;
}

void Node::add_children(Node* children){
	tab_of_childrens.push_back(children);
}

string Node::get_name(){
	return name;
}

double Node::get_multiplier(){
	return multiplier;
}

vector <Node*> Node::get_tab_children(){
	return tab_of_childrens;
}