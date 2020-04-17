#ifndef BiSexual_h
#define BiSexual_h

enum sign
{
	LESS, GREATER, EQUAL
};

struct node
{
	int info;
	node* left;
	node* right;
};

class BiSexual
{
public:
	BiSexual();
	~BiSexual();
	bool insertItem(int item);
	sign eval(int one, int compare);

private:
	node* root;
};

#endif // !BiSexual_h
