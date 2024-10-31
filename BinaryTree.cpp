#include "BinaryTree.h"
#include <stdexcept>

#include <iostream>
#include "BlackScholesPricer.h"
#include "AsianCallOPtion.h"
#include "AsianPutOption.h"
#include "MT.h"


template <typename T>
BinaryTree<T>::BinaryTree(int depth)
{
	this->_depth = depth;
	this->_tree = std::vector<std::vector<T>>(_depth);
	for (int i = 0; i < _depth; i++)
	{
		_tree[i] = std::vector<T>(i+1);
	}
}



template <typename T>
void BinaryTree<T>::setDepth(int depth)
{
	this->_depth = depth;
	this->_tree = std::vector<std::vector<T>>(_depth);
	for (int i = 0; i < _depth; i++)
	{
		_tree[i] = std::vector<T>(i + 1);
	}
}

template <typename T>
void BinaryTree<T>::setNode(int i, int j, T valeur)
{
	if (j <= i)
	{
		_tree[i][j] = valeur;
	}
	else
	{
		throw std::invalid_argument("position incorrecte");
	}
}


template <typename T>
T BinaryTree<T>::getNode(int i, int j)
{
	if (j <= i)
	{
		return _tree[i][j];
	}
	else
	{
		throw std::invalid_argument("position incorrecte");
	}

}

/*template <typename T>
void BinaryTree<T>::display()
{
	for (int i = 0; i < _depth; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			std::cout << _tree[i][j] << " ";
		}
		std::cout << " \n";
	}
}*/

template <typename T>
void BinaryTree<T>::display()
{
	for (int i = 0; i < _depth; ++i)
	{
		for (int j = 0; j < (i + 1); j++)
		{
			std::cout << getNode(i, j) << " ";
		}
		std::cout << std::endl;;
	}
	std::cout << std::endl;;

	for (int i = 0; i < _depth; ++i)
	{
		for (int j = 0; j < _depth - i; j++)
		{
			std::cout << "  ";
		}
		for (int k = 0; k < i + 1; k++)
		{
			std::cout << getNode(i, k) << "   ";
		}
		std::cout << std::endl;;
		for (int l = 0; l < 2 * (_depth - i) - 1; l++)
		{
			std::cout << " ";
		}
		for (int m = 0; m < i + 1; m++)
		{
			if (i != _depth - 1)
			{
				std::cout << "/ \\ ";
			}
		}
		std::cout << std::endl;;
	}
}





