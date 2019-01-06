#include <stdio.h>
#include <stdlib.h>


typedef struct t
{
	struct node *right;
	struct node *left;

	int number;
}node;

node *createNode(int number)
{
	node *new = (node *)malloc(sizeof(node));

	new->right = NULL;
	new->left = NULL;
	new->number = number;

	return new;
}

void addNode(node *n, int number)
{
	if (number < n->number)
	{
		if (n->left == NULL)
		{
			node *new = createNode(number);
			n->left = new;
		}
		else
		{
			addNode(n->left, number);
		}
	}

	else
	{
		
		if (n->right == NULL)
		{
			node *new = createNode(number);
			n->right = new;
		}
		
		else
		{
			addNode(n->right, number);
		}
	}
}
void show(node *n)
{
	node *left = n->left;
	node *right = n->right;
	printf("%d %d %d\n", n->number, n->left == NULL ? 0 : left->number, n->right == NULL ? 0 : right->number);
}


void printTree(node *n)
{
	if (n != NULL)
	{
		printTree(n->left);
		show(n);
		printTree(n->right);
	}
}


int main(int argc, char *argv[])
{
	char str[7];
	node *top = NULL;

	int i = 0;
	while (fgets(str, sizeof(str), stdin))
	{
		int number = atoi(str);
		if (top == NULL)
		{
			top = createNode(number);
		}
		else
		{
			addNode(top, number);
		}
	}

	printTree(top);

	return 0;
}
