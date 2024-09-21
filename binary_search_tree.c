#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct	s_tree
{
	int		value;
	struct s_tree	*left;
	struct s_tree	*right;
}				t_tree;

void	print_tree(t_tree *tree)
{
	if (tree == NULL)
	{
		printf("tree is empty\n");
		return ;
	}
	printf("%d\n", tree->value);
	printf("left\n");
	print_tree(tree->left);
	printf("right\n");
	print_tree(tree->right);
}

void print_tabs(int tabs)
{
	int i;

	i = 0;
	while (i < tabs)
	{
		printf("\t");
		i++;
	}
}

void print_tree_with_tabs(t_tree *tree, int tabs)
{
	if (tree == NULL)
	{
		print_tabs(tabs);
		printf("---\n");
		return ;
	}
	print_tabs(tabs);
	printf("-%d-\n", tree->value);
	print_tabs(tabs);
	printf("left\n");
	print_tree_with_tabs(tree->left, tabs + 1);
	print_tabs(tabs);
	printf("right\n");
	print_tree_with_tabs(tree->right, tabs + 1);
}

t_tree	*create_node(int value)
{
	t_tree	*new_node;

	new_node = (t_tree *)malloc(sizeof(t_tree));
	if (new_node == NULL)
		return (NULL);
	new_node->value = value;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}

bool insert_number(t_tree **tree, int value)
{
	t_tree *root;
	t_tree *new_node;

	root = *tree;
	new_node = create_node(value);
	if (new_node == NULL)
		return (false);
	if (root == NULL)
	{
		*tree = new_node;
		return (true);
	}
	if (value == root->value)
	{
		free(new_node);
		return (false);
	}
	else if (value < root->value)
	{
		if (root->left == NULL)
			root->left = new_node;
		else
			return (insert_number(&root->left, value));
	}
	else if (value > root->value)
	{
		if (root->right == NULL)
			root->right = new_node;
		else
			return (insert_number(&root->right, value));
	}
}

bool find_number(t_tree *tree, int value)
{
	if (tree == NULL)
		return (false);
	if (tree->value == value)
		return (true);
	else if (tree->value > value)
		return (find_number(tree->left, value));
	else if (tree->value < value)
		return (find_number(tree->right, value));
}

int main()
{
	t_tree *root = NULL;
	insert_number(&root, 15);
	insert_number(&root, 11);
	insert_number(&root, 24);
	insert_number(&root, 5);
	insert_number(&root, 19);
	insert_number(&root, 16);

	print_tree_with_tabs(root, 0);

	printf("find 15: %d\n", find_number(root, 15));
	printf("find 11: %d\n", find_number(root, 11));
	printf("find 24: %d\n", find_number(root, 24));
	printf("find 5: %d\n", find_number(root, 5));
	printf("find 9: %d\n", find_number(root, 9));

	// t_tree *n1 = create_node(1);
	// t_tree *n2 = create_node(2);
	// t_tree *n3 = create_node(3);
	// t_tree *n4 = create_node(4);
	// t_tree *n5 = create_node(5);

	// n1->left = n2;
	// n1->right = n3;
	// n3->left = n4;
	// n3->right = n5;

	// // print_tree(n1);
	// print_tree_with_tabs(n1, 0);
	// printf("\n");

	// free(n1);
	// free(n2);
	// free(n3);
	// free(n4);
	// free(n5);

	return (0);
}


// 	      1
//  	/	
//    2	     3
// 	       /	
//       4		 5	