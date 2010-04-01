#include <iostream>

class Char_queue
{
private:
  struct Node
	{
		char c;
		Node* next;
		Node* prev;
	} *head, *end;
public:
  Char_queue();
  ~Char_queue();
  Char_queue& add(char);
  char get();
};

Char_queue::Char_queue()
{
	head = 0;
	end = 0;
}

Char_queue::~Char_queue()
{
	while (get());
}

Char_queue& Char_queue::add(char c)
{
	Node* n = new Node;
	n->c = c;
	n->next = n->prev = 0;
	
	if (head == 0)
		head = end = n;
	else
	{
		n->prev = end;
		end->next = n;
		end = n;
	}
	return *(this);
}

char Char_queue::get()
{
	if (end != 0){
		char ret = end->c;
		if (end == head)
		{
			delete end;
			head = 0;
			end = 0;
		}
		else
		{
			Node* prev = end->prev;
			delete end;
			prev->next = 0;
			end = prev;
			//end->next = 0;
		}
		return ret;
	} 
	else
		return 0;
}

int main()
{
	std::cout << "aaa\n";
	Char_queue q;
	q.add('a');
	q.add('b');
	q.add('c');
	std::cout << "aaa\n";
	std::cout << q.get() << std::endl;
	std::cout << q.get() << std::endl;
	std::cout << q.get() << std::endl;
}