#include <stdio.h>
#include <stdlib.h>


typedef struct t
{
	struct node *right;
	struct node *left;

	int number;
}node;

//新規ノード追加
node *createNode(int number)
{
	node *new = (node *)malloc(sizeof(node));

	new->right = NULL;
	new->left = NULL;
	new->number = number;

	return new;
}

//追加
void addNode(node *n, int number)
{
	//numberが、渡されたnodeの番号よりも小さいとき
	if (number < n->number)
	{
		//左側に追加すべきなので、左側にnodeがないときつっこめる
		if (n->left == NULL)
		{
			node *new = createNode(number);
			n->left = new;
		}
		//左に既にノードがある場合、次のノードへもちこみ
		else
		{
			addNode(n->left, number);
		}
	}

	//numberが、渡されたnodeの番号より大きいとき
	else
	{
		//右側に追加すべきなので、右側にnodeがないときつっこめる
		if (n->right == NULL)
		{
			node *new = createNode(number);
			n->right = new;
		}
		//右に既にノードがある場合、次のノードへもちこみ
		else
		{
			addNode(n->right, number);
		}
	}
}

//表示
void show(node *n)
{
	node *left = n->left;
	node *right = n->right;
	printf("%d %d %d\n", n->number, n->left == NULL ? 0 : left->number, n->right == NULL ? 0 : right->number);
}

//再帰による二分木出力
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
