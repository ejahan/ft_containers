/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 22:33:24 by ejahan            #+#    #+#             */
/*   Updated: 2022/10/14 22:43:02 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

#define RED 1
#define BLACK 0

template<class T>
struct	Node
{
	int		color;
	T		key;
	Node	*leftChild;
	Node	*rightChild;
	Node	*parent;
}




template<class T>
class	red_black_tree
{
	private:

		Node	_root;
		Node	_nil;
	

	public:

		red_black_tree();
		
		void	left_rotate(Node *node_x)
		{
			Node	*node_y = node_x->rightChild;
			node_x->rightChild = node_y->leftChild;
			// If node_y has a left subtree, assign x as the parent of the left subtree of node_y
			if (node_y->leftChild != _nil)
				node_y->leftChild->parent = node_x;
			// If the parent of x is NULL, make node_y as the root of the tree
			// Else if x is the left child of p, make node_y as the left child of p
			// Else assign node_y as the right child of p
			node_y->parent = node_x->parent;
			if (node_x->parent == _nil)
				_root = node_y;
			else if (node_x->parent->leftChild == node_x)
				node_x->parent->leftChild = node_y;
			else
				node_x->parent->rightChild = node_y;
			// Make node_y as the parent of x
			node_y->leftChild = node_x;
			node_x->parent = node_y;
		};

		void	right_rotate(Node *node_x)
		{
			Node	*node_y = node_x->leftChild;
			node_x->leftChild = node_y->rightChild;
			if (node_y->rightChild != _nil)
				node_y->rightChild->parent = node_x;
			node_y->parent = node_x->parent;
			if (node_x->parent == _nil)
				_root = node_y;
			else if (node_x->parent->rightChild == node_x)
				node_x->parent->rightChild = node_y;
			else
				node_x->parent->leftChild = node_y;
			node_y->rightChild = node_x;
			node_x->parent = node_y;
		};

		void	left_right(Node *node)
		{
			left_rotate(node->leftChild);
			right_rotate(node);
		};

		void	right_left(Node *node)
		{
			right_rotate(node->rightChild);
			left_rotate(node);
		};







		// Inserting a node
		void insert(int key) {
			NodePtr node = new Node;
			node->parent = NULL;
			node->data = key;
			node->left = TNULL;
			node->right = TNULL;
			node->color = 1;

			NodePtr y = NULL;
			NodePtr x = this->root;

			while (x != TNULL) {
				y = x;
				if (node->data < x->data) {
					x = x->left;
				} else {
					x = x->right;
				}
			}

			node->parent = y;
			if (y == NULL) {
				root = node;
			} else if (node->data < y->data) {
				y->left = node;
			} else {
				y->right = node;
			}

			if (node->parent == NULL) {
				node->color = 0;
				return;
			}

			if (node->parent->parent == NULL) {
				return;
			}

			insertFix(node);
		}


		void	insert(T key)
		{
			Node *new_n = 
		};










		void	delete_node();
		Node	*search_element(T key);

}

#endif
