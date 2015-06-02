#ifndef _TREE_H
#define _TREE_H

#include "Node.h";
#include <vector>
#include <map>

using namespace std;
class Tree{
	public:
		Tree();
		Tree(Node* _root);
		~Tree();
		Node* get_root();
		map <string, double>& get_list_node();
		void print_list_node_of_tree();
		void set_root(Node* _top);
		void Tree::insert(Node* node, string name);
		Node* Tree::search_by_name(Node* root, string serach_name);
		

		void pharse(string tree_in_str);
		void pharse(string tree, Node* node, double licz);
		bool is_valid(string tree);
		vector <string> Tree::divide_to_elem(string tree_in_str);
		string get_children_from_str(string tree_in_str, int from);
		void keyword_of_elem_from_tree(Tree* tree, Node* node);
		void reset_keyword(){list_node_of_tree.clear();}
		
		// FUNCTION HELPFUL IN VALIDATION
		bool quotations_is_even(string tree);
		bool square_is_even(string tree);
		bool bracket_is_even(string tree);
		bool space_next_to_comma(string tree);
		bool first_last_is_square(string tree);
		bool bracket_before_square(string tree);

	private:
		Node* root;
		map <string, double> list_node_of_tree;

};

#endif