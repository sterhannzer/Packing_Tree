#include "Tree.h"
#include <iostream>


Tree::Tree(){
	root = nullptr;
}

Tree::Tree(Node* _root){
	root = _root;
}

Tree::~Tree(){
	delete root;
}

void Tree::set_root(Node* _root){
	root = _root;
}

Node* Tree::get_root(){
	return root;
}

map <string, double>& Tree::get_list_node(){
	return list_node_of_tree;
}

void Tree::pharse(string tree_in_str){
	double licz = 1;
	return pharse(tree_in_str, root, licz);
}

void Tree::pharse(string tree_in_str, Node* node, double licz){
	Node* children;
	vector<string> tab_divide_elem = divide_to_elem(tree_in_str);
	
	for(int i=0; i<tab_divide_elem.size(); i++){
		string posterity = tab_divide_elem[i];

		int rand_2nd_apostr = posterity.find("\"", 2); // SEARCH 2ND CHAR "  
		string name_node = posterity.substr(2, rand_2nd_apostr-2); // GET NAME FOR NEW NODE 
		int rand_2nd_comma = posterity.find(",", rand_2nd_apostr + 2); // SEARCH 2ND CHAR ,
		string multiple_node_str = posterity.substr(rand_2nd_apostr + 3, rand_2nd_comma - rand_2nd_apostr - 3);
		int rand_1st_bracket = rand_2nd_comma + 2;
		double multiple_node = atof(multiple_node_str.c_str()); // CONVERT STR TO DOUBLE
		string childrens = get_children_from_str(posterity, rand_1st_bracket);
		
		if(node == nullptr){
			children = new Node(name_node, multiple_node);
			set_root(children);
		}
		else{
			multiple_node = multiple_node*licz;
			children = new Node(name_node, multiple_node);
			node->add_children(children);
		}

		if(childrens != "")
			pharse(childrens, children, multiple_node);
	} // END FOR
}

vector <string> Tree::divide_to_elem(string tree_in_str){
	vector<string> tab_of_elem;

	int tmp = 0;
	int range_of = 0;
	int size_tree_string = tree_in_str.size();

	for(int i = 0; i < size_tree_string; i++){
		
		if(tree_in_str[i] == '[')
			tmp++;
		
		if(tree_in_str[i] == ']')
			tmp--;
		
		if(tmp == 0){
			tab_of_elem.push_back(tree_in_str.substr(range_of, (i+1)-range_of)); // ADD ELEM: EX. "["xx", x, ()]" TO TAB 
			range_of = i+3; // SET TO POSITION ON THE FIRST CHAR TABLE "["
			i += 2; // STEP FROM "]" TO "["
		}
	} // END FOR
	return tab_of_elem;
}

string Tree::get_children_from_str(string tree_in_str, int from){
	int tmp = 0;
	
	for(int i = from; i < tree_in_str.size(); i++){
		
		if(tree_in_str[i] == '(')
			tmp++;

		if(tree_in_str[i] == ')')
			tmp--;

		if(tmp == 0)
			return tree_in_str.substr(from+1, i-from-1);   // MISS () : RETURN TABLES ["xxxxx", xx, ()], ["xxx", xx, ()]
	}
}

void Tree::keyword_of_elem_from_tree(Tree* tree, Node* node){   // CREATE KEYWORDS WITH ALL ELEM FROM TREE WITH SUM OF MULTIPLE
	
	if(tree->list_node_of_tree.count(node->get_name()) == 0)
		tree->list_node_of_tree[node->get_name()] = node->get_multiplier();
	else
		tree->list_node_of_tree[node->get_name()] += (node->get_multiplier());

	for(int i=0; i < node->get_tab_children().size(); i++)
		keyword_of_elem_from_tree(tree, node->get_tab_children()[i]);
}

void Tree::print_list_node_of_tree(){
	map <string, double> mymap = get_list_node();
	for (map<string,double>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		cout << it->first << " => " << it->second << endl;
}

Node* Tree::search_by_name(Node* node, string search_name){
	vector <Node*> tab_of_childrens = node->get_tab_children();
	
	if(node->get_name().compare(search_name) == 0)
		return node;
	else{
		for(int i=0; i<tab_of_childrens.size(); i++)
			search_by_name(tab_of_childrens[i], search_name);
	}

	return nullptr;
}

void Tree::insert(Node* node, string name){
	Node* found_node = search_by_name(root, name);
	
	if(found_node == nullptr)
		cout << "Nie ma wezla " << name << " !" << endl;
	else{
		found_node->add_children(node);
		cout << "Pomyslnie dodano wezel \"" << node->get_name() << "\" do wezla  \"" << name << "\"" << endl;
	}
}

bool Tree::is_valid(string tree_in_str){
	vector <string> tab = divide_to_elem(tree_in_str);

	if(!quotations_is_even(tree_in_str)){ 
		cout << "Nieprawidlowa ilosc cudzyslowia!" << endl; 
		return false;
	}


	if(!square_is_even(tree_in_str)){
		cout << "Nieprawidlowo uzyte kwadratowe nawiasy!" << endl; 
		return false;
	}


	if(!bracket_is_even(tree_in_str)){
		cout << "Nieprawidlowo uzyte nawiasy!" << endl; 
		return false;
	}

	if(!space_next_to_comma(tree_in_str)){ 
		cout << "Brakuje spacji po przecinku!" << endl; 
		return false;
	}

	if(!first_last_is_square(tree_in_str)){
		cout << "Wszystko musi zawierac sie w nawiasach kwadratowych!" << endl; 
		return false;
	}

	if(!bracket_before_square(tree_in_str)){
		cout << "Po nawiasie ) musi byc nawias zamykajacy ]" << endl;
		return false;
	}

	if(tab.size() == 2){
		cout << "Nieprawidlowy format!" << endl; 
		return false;
	}
	return true;
}


bool Tree::quotations_is_even(string tree){
	int  quotations= 0;

	for(int i=0; i<tree.size(); i++){
		if(tree[i] == '"') 
			quotations++;
	}
	return quotations%2==0;
}

bool Tree::square_is_even(string tree){
	int square = 0;

	for(int i=0; i<tree.size(); i++){
		if(tree[i] == '[') 
			square++;
		if(tree[i] == ']')
			square--;
	}
	return square==0;
}


bool Tree::bracket_is_even(string tree){
	int brackets = 0;

	for(int i=0; i<tree.size(); i++){
		if(tree[i] == '(') 
			brackets++;
		if(tree[i] == ')')
			brackets--;
	}
	return brackets==0;
}

bool Tree::bracket_before_square(string tree){
	for(int i=0; i<tree.size(); i++){
		if(tree[i] == ')' && tree[i+1] != ']') 
			return false;
	}
	return true;
}

bool Tree::space_next_to_comma(string tree){
	for(int i=0; i<tree.size(); i++){
		if(tree[i] == ',' && tree[i+1] != ' ') 
			return false;
	}
	return true;
}

bool Tree::first_last_is_square(string tree){
	if(tree[0] == '[' && tree[tree.size()-1] == ']')
		return true;
	return false;
}
