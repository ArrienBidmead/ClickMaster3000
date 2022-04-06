#pragma once

#include <functional>

template<class T>
struct BinaryNode
{
	T data;
	BinaryNode<T>* child = nullptr;
	BinaryNode<T>* sibling = nullptr;
};

template<class T>
struct BinaryTree
{
	BinaryNode<T>* head = nullptr;

	static void PreOrderTraverse(BinaryNode<T>* node, std::function<void(BinaryNode<T>*)> function);
	static void PostOrderTraverse(BinaryNode<T>* node, std::function<void(BinaryNode<T>*)> function);
	static BinaryNode<T>* AddChildNodeTo(BinaryNode<T>* parent, T data);
	static BinaryNode<T>* AddSiblingNodeTo(BinaryNode<T>* sibling, T data);
	BinaryNode<T>* AddHeadNode(T data);
};
