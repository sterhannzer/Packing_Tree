#include <cstdlib>
#include <iostream>

#include "Node.h";
#include "Tree.h";
#include "testowanie.h";

using namespace std;
 
void testowanie(){
	Tree drzewo;
	cout << drzewo.is_valid("[\"paleta\", 10, ([\"karton A\", 10, ([\"detal A\", 20, ()], [\"detal B\", 10, ()])], [\"karton B\", 4, ([\"karton D\", 5, ([\"Detal D\", 6, ()])])])]");
	cout << endl;
	/*cout << "nawiasy (: 1 " << drzewo.bracket_is_even("((((");
	cout << endl;
	cout << "nawiasy (: 0 " << drzewo.bracket_is_even("(((");
	cout << endl;
	cout << "przecinek : 1 " << drzewo.comma_is_even(",,,,");
	cout << endl;
	cout << "przecinek : 0 " << drzewo.comma_is_even(",,,");
	cout << "\n";
	cout << "cudzys³ow : 1 " << drzewo.quotations_is_even("\"\"\"\"");
	cout << endl;
	cout << "cudzys³ow : 0 " << drzewo.quotations_is_even("\"\"\"");
	cout << endl;
	cout << "nawias ] : 1 " << drzewo.square_is_even("] ] ] ]");
	cout << endl;
	cout << "nawias ] : 0 " << drzewo.square_is_even("] ] ]");
	cout << endl;
	cout << "space po przecinku  : 1 " << drzewo.space_next_to_comma(", , , ");
	cout << endl;
	cout << "space po przecinku  : 0 " << drzewo.space_next_to_comma(",8 , , ");
	cout << endl;
	cout << "nawiasy na pocz i koncu  : 1 " << drzewo.first_last_is_square("[, , , ]");
	cout << endl;
	cout << "nawiasy na pocz i koncu  : 0 " << drzewo.first_last_is_square("[, , , ])");
	cout << endl;
	*/
}