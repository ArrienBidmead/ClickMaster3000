//Copyright(C) 2021  Arrien Bidmead - Arrien.co.uk
//See <Source.cpp> file for full copyright notice

#include "BinaryTree.h"

template<class T>
void BinaryTree<T>::PreOrderTraverse(BinaryNode<T>* node, std::function<void(BinaryNode<T>*)> function)
{
	function(node);

	if (node->sibling != nullptr)
		PreOrderTraverse(node->sibling, function);

	if (node->child != nullptr)
		PreOrderTraverse(node->child, function);
}

template<class T>
void BinaryTree<T>::PostOrderTraverse(BinaryNode<T>* node, std::function<void(BinaryNode<T>*)> function)
{
	if (node->sibling != nullptr)
		PostOrderTraverse(node->sibling, function);

	if (node->child != nullptr)
		PostOrderTraverse(node->child, function);

	function(node);
}

template<class T>
BinaryNode<T>* BinaryTree<T>::AddChildNodeTo(BinaryNode<T>* parent, T data)
{
	if (parent->child != nullptr)
		return AddSiblingNodeTo(parent->child, data);
	else
	{
		parent->child = new BinaryNode<T>;
		parent->child->data = data;

		return parent->child;
	}
}

template<class T>
BinaryNode<T>* BinaryTree<T>::AddSiblingNodeTo(BinaryNode<T>* sibling, T data)
{
	if (sibling->sibling != nullptr)
		return AddSiblingNodeTo(sibling->sibling, data);
	else
	{
		sibling->sibling = new BinaryNode<T>;
		sibling->sibling->data = data;

		return sibling->sibling;
	}
}

template<class T>
BinaryNode<T>* BinaryTree<T>::AddHeadNode(T data)
{
	if (head != nullptr)
		return nullptr;
	else
	{
		head = new BinaryNode<T>;
		head->data = data;

		return head;
	}
}

// Explicit instantiation for Button class. Required for .cpp file template definitions.
// Add all classes/structs that use BinaryTree or you will get linker errors.
#include "Button.h"
template struct BinaryTree<Button*>;