#pragma once

#include <functional>

template<class T>
struct BinaryNode
{
	T data;
	BinaryNode<T>* right = nullptr;
	BinaryNode<T>* left = nullptr;
};

template<class T>
struct BinaryTree
{
	BinaryNode<T>* head = nullptr;

	static void PreOrderTraverse(BinaryNode<T>* node, std::function<void(BinaryNode<T>*)> function);
	static void PostOrderTraverse(BinaryNode<T>* node, std::function<void(BinaryNode<T>*)> function);
};

