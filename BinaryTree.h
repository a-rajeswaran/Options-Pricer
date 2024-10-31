#pragma once
#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <vector>
template <typename T>
class BinaryTree
{
private:
	
	std::vector<std::vector<T>> _tree;

public:
	BinaryTree(int depth);
	void setDepth(int depth);
	void setNode(int i, int j, T valeur);
	T getNode(int i, int j);
	void display();
	int _depth;



};

#endif

