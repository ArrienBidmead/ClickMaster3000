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

template<class T>
BinaryNode<T>* BinaryTree<T>::AddChildNodeTo(BinaryNode<T>* parent, T data)
{
	if (parent->right != nullptr)
		return AddSiblingNodeTo(parent->right, data);
	else
	{
		parent->right = new BinaryNode<T>;
		parent->right->data = data;

		return parent->right;
	}
}

template<class T>
BinaryNode<T>* BinaryTree<T>::AddSiblingNodeTo(BinaryNode<T>* sibling, T data)
{
	if (sibling->left != nullptr)
		return AddSiblingNodeTo(sibling->left, data);
	else
	{
		sibling->left = new BinaryNode<T>;
		sibling->left->data = data;

		return sibling->left;
	}
}

template<class T>
BinaryNode<T>* BinaryTree<T>::AddHeadNode(T data)
{
	if (head != nullptr)
		return nullptr;
	else
	{
		head = new BinaryNode<Button*>;
		head->data = data;

		return head;
	}
}

template struct BinaryTree<Button*>;