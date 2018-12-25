#include <stdio.h>
#include <stdlib.h>


typedef struct t
{
	struct node *right;
	struct node *left;

	int number;
}node;

//�V�K�m�[�h�ǉ�
node *createNode(int number)
{
	node *new = (node *)malloc(sizeof(node));

	new->right = NULL;
	new->left = NULL;
	new->number = number;

	return new;
}

//�ǉ�
void addNode(node *n, int number)
{
	//number���A�n���ꂽnode�̔ԍ������������Ƃ�
	if (number < n->number)
	{
		//�����ɒǉ����ׂ��Ȃ̂ŁA������node���Ȃ��Ƃ������߂�
		if (n->left == NULL)
		{
			node *new = createNode(number);
			n->left = new;
		}
		//���Ɋ��Ƀm�[�h������ꍇ�A���̃m�[�h�ւ�������
		else
		{
			addNode(n->left, number);
		}
	}

	//number���A�n���ꂽnode�̔ԍ����傫���Ƃ�
	else
	{
		//�E���ɒǉ����ׂ��Ȃ̂ŁA�E����node���Ȃ��Ƃ������߂�
		if (n->right == NULL)
		{
			node *new = createNode(number);
			n->right = new;
		}
		//�E�Ɋ��Ƀm�[�h������ꍇ�A���̃m�[�h�ւ�������
		else
		{
			addNode(n->right, number);
		}
	}
}

//�\��
void show(node *n)
{
	node *left = n->left;
	node *right = n->right;
	printf("%d %d %d\n", n->number, n->left == NULL ? 0 : left->number, n->right == NULL ? 0 : right->number);
}

//�ċA�ɂ��񕪖؏o��
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
