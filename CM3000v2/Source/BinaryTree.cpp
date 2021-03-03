#include "BinaryTree.h"
#include "Button.h"

template<class T>
void BinaryTree<T>::PreOrderTraverse(BinaryNode<T>* node, std::function<void(BinaryNode<T>*)> function)
{
	function(node);

	if (node->right != nullptr)
		PreOrderTraverse(node->right, function);

	if (node->left != nullptr)
		PreOrderTraverse(node->left, function);
}

template<class T>
void BinaryTree<T>::PostOrderTraverse(BinaryNode<T>* node, std::function<void(BinaryNode<T>*)> function)
{
	if (node->right != nullptr)
		PostOrderTraverse(node->right, function);

	if (node->left != nullptr)
		PostOrderTraverse(node->left, function);

	function(node);
}

template struct BinaryTree<Button*>;