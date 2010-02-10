#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



struct Tnode
{
	char* word;
	int count;
	Tnode* left;
	Tnode* right;
};

vector<const Tnode*> vector_tree;

void print_node(const Tnode* node)
{
	//cout << node << '\n';
	char* s = node->word;
	while (*s != '\0')
		cout << *(s++);
	cout << '\n';
}

Tnode* add(Tnode* parent, const char* child, bool in_left=true)
{
	Tnode* born = new Tnode;
	born->word = new char[50];
	char* s = born->word;
	while((*(s++) = *(child++)) != 0);
	born->count = 0;
	born->left = 0;
	born->right = 0;
	
	if (parent)
	{
		if (in_left)
			parent->left = born;
		else
			parent->right = born;
		parent->count += 1;
	}
	//print_node(born);
	return born;
}


/*
void print_tree(const Tnode* node)
{
	cout << node->word << '\n';
	if (node->left)
		print_tree(node->left);
	if (node->right)
		print_tree(node->right);
}
*/
void print_vector()
{
	for (int i=0; i<vector_tree.size(); i++)
		print_node(vector_tree[i]);
}

void add_to_vector_tree(const Tnode* node)
{
	vector_tree.push_back(node);
	if (node->left)
		add_to_vector_tree(node->left);
	if (node->right)
		add_to_vector_tree(node->right);
}

bool my_compare(const Tnode* a, const Tnode* b)
{
	//cout << "sorting: ";
	//print_node(a);
	//print_node(b);
	char* a1=a->word;
	char* b1=b->word;
	while(*a1 == *b1 && *(a1++) != '\0' && *(b1++) != '\0');
	//cout << i << "=" << *(a1) << ' ' << *(b1) << ' ';
	//cout << "(" << (int)*(a1) << ' ' << (int)*(b1) << ")\n";
	return (int)*(a1) < (int)*(b1);
	//return a->word < b->word;
}


int main()
{
	Tnode* n = add(0, "ilya");
	
	Tnode* lera = add(n, "lera");
	Tnode* oleg = add(n, "oleg", false);
	
	add(oleg, "tanya");
	add(oleg, "serega", false);
	
	add(lera, "ira");
	add( add(lera, "serega_toge", false), "abada");

	add_to_vector_tree(n);
	print_vector();
	cout << "\n-= After sorting =- \n";
	sort(vector_tree.begin(), vector_tree.end(), my_compare);
	print_vector();
}
