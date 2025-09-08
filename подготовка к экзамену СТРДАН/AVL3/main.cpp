#include <iostream>
using namespace std;

class AVLTree
{
	struct Node 
	{
		int data;
		Node* left, * right;
		int height;
		Node() : data(int()), left(nullptr), right(nullptr), height(0) {}
		Node(int i) : data(i), left(nullptr), right(nullptr), height(1) {}
	};

	Node* root;

	int Height(Node* root)
	{
		if (root == nullptr)
			return 0;
		else
			return root->height;
	}

	void fixHeight(Node* root)
	{
		if (!root) return;
		if (Height(root->left) > Height(root->right))
			root->height = Height(root->left) + 1;
		else
			root->height = Height(root->right) + 1;
	}

	int balanceFactor(Node* root)
	{
		return Height(root->right) - Height(root->left);
	}


	void RightRotation(Node*& node)
	{
		if (!node) return;
		Node* q = node->left;
		node->left = q->right;
		q->right = node;
		fixHeight(q);
		fixHeight(node);
		node = q;
	}

	void LeftRotation(Node*& node)
	{
		if (!node) return;
		Node* q = node->right;
		node->right = q->left;
		q->left = node;
		fixHeight(q);
		fixHeight(node);
		node = q;
	}

	void balance(Node*& root)
	{
		int Balance = balanceFactor(root);
		fixHeight(root);
		if (Balance == 2)
		{
			if (balanceFactor(root->right) < 0)
				RightRotation(root->right);
			LeftRotation(root);
		}
		if (Balance == -2)
		{
			if (balanceFactor(root->left) > 0)
				LeftRotation(root->left);
			RightRotation;
		}
	}

	int rrr(Node*& node)
	{
		if (node->right)
			return rrr(node->right);
		Node* p = node;
		int result = node->data;
		node = node->left;
		delete p;
		p = nullptr;
		return result;
	}


	void remove(Node*& root, int elem)
	{
		if (root)
		{
			if (root->data < elem)
				remove(root->right, elem);
			else if (root->data > elem)
				remove(root->right, elem);
			else {
				if (root->left && root->right)
				{
					int a = rrr(root->left);
					root->data = a;
				}
				else if (root->left && !root->right)
				{
					Node* p = root;
					root = root->left;
					delete p;
					p = nullptr;
				}
				else if (!root->left && root->right)
				{
					Node* p = root;
					root = root->right;
					delete p;
					p = nullptr;
				}
				else if (!root->left && !root->right)
				{
					Node* p = root;
					delete p;
					p = nullptr;
				}
				balance(root);
			}
		}
	}

	void clear(Node*& root)
	{
		if (root == nullptr)
			return;
		clear(root->left);
		clear(root->right);
		delete root;
		root = nullptr;
	}

	void insert(Node*& root, int elem)
	{
		if (root == nullptr)
		{
			root = new Node(elem);
			return;
		}
		if (root->data < elem)
			insert(root->right, elem);
		else if (root->data > elem)
			insert(root->left, elem);
		balance(root);
	}

public:



};