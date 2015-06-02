#include <cstdlib>
#include <iostream>

#include "Node.h";
#include "Tree.h";
#include "interface.h";

using namespace std;

void print_control_panel(){
	cout << "0 - wyswietl instrukcje" << endl; 
	cout << "1 - Dodaj wezel" << endl;
	cout << "2 - Wyswietl liste wprowadzonych obiektow i ich ilosci" << endl;
	cout << "3 - Usun cale drzewo" << endl;
	cout << "4 - Stworz drzewo wprowadzajac odpowiednio sformulowane zdanie" << endl;
	cout << "5 - Pokaz jak wyglada przykladowe drzewo w formie napisu" << endl;
	cout << "6 - Zakoncz program" << endl;
}

void interface(){
	int number;
	double multiply;

	string name;
	string search_node;
	string agree;
	string tree_str;

	Node* node = new Node();
	Tree* tree = new Tree();
	
	print_control_panel();

	while(true){
		cout << "\n" << "\n";
		cout << "Wybierz numer instrukcji: " << "\n";
		cin >> number; 

		switch (number){
			case 0:
				print_control_panel();
				break;

			case 1:
				if(tree->get_root() == nullptr){
					cout << "Drzewo jest puste, podaj nazwe wiercholka: " << "\n";
					cin >> name;

					cout << "Podaj mnoznik wierzcholka jako double: " << "\n";
					cin >> multiply;

					node = new Node(name, multiply);

					tree->set_root(node);
					cout << "Pomyslnie stworzono wierzcholek drzewa" << "\n";
				}
				else{
					cout << "Podaj nazwe nowego wezla: " << "\n";
					cin >> name;

					cout << "Podaj mnoznik jako double nowego wezla: " << "\n";
					cin >> multiply;
					
					node = new Node(name, multiply);

					cout << "Podaj nazwe wezla do ktorego chcesz dodac: " << "\n";
					cin >> search_node;

					tree->insert(node, search_node);
				}
				break;

			case 2:
				if(tree->get_root() == nullptr)
					cout << "Drzewo jest puste!";
				else{
					tree->reset_keyword();
					Node* root = tree->get_root();
					double licz = 1;
					tree->keyword_of_elem_from_tree(tree, root);
					tree->print_list_node_of_tree();
				}
				break;

			case 3:
				cout << "Czy na pewno chcesz usunac cale drzewo ?? T/N : ";
				cin >> agree;
				if(agree == "T" || agree == "t"){
					delete tree;
					tree = new Tree();
					cout << "Drzewo zostalo usuniete!" << "\n";
					break;
				}
				else{
					cout << "Nie wyraziles zgody na usuniecie drzewa!" << "\n";
					break;
				}
				
			case 4:
				cout << "Wprowadz drzewo w odpowiednim formacie: " << "\n";
				cin.ignore();
				getline(cin, tree_str);
				delete tree;
				tree = new Tree();
				if(tree->is_valid(tree_str)){
					tree->pharse(tree_str);
					cout << "Drzewo stworzone pomyslnie!" << "\n";
				}
				else
					cout << "Sprobuj ponownie!" << "\n";
				break;
			
			case 5:
				cout << "[\"Paleta\", 10, ([\"KartonA\", 10, ([\"DetalA\", 20, ()], [\"DetalB\", 10, ()])], [\"KartonB\", 4, ([\"KartonD\", 5, ([\"DetalD\", 6, ()])])])]" << "\n" << "\n";
				cout << "                     Paleta 10" << "\n" << "      KartonA 10               KartonB 4";
				cout << "\n" << "DetalA 20, DetalB 10           KartonD 5" << "\n" << "                               DetalD 6" << "\n" "\n";
				break;

			case 6:
				cout << "Zakonczono program" << "\n";
				return;
				
			default:
				cout << "Wybierz numer z instrukcji!" << "\n" << "\n";
				break;
		}
	}
}