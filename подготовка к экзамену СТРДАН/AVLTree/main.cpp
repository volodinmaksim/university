#include <iostream>
using namespace std;

class AVLTree
{
	struct Node
	{
		int data;
		int height;
		Node* left;
		Node* right;

		Node() : data(int()), height(0), left(nullptr), right(nullptr) {}
		Node(int data) : data(data), height(1), left(nullptr), right(nullptr) {}
	};

	Node* root;


public: 

	AVLTree() : root(nullptr) {}
	AVLTree(int data) : root(new Node(data)) {}

	int Height(Node* root)
	{
		if (root)
			return root->height;
		else
			return 0;
	}

	int BalanceFactor(Node* node)
	{
		return Height(node->right) - Height(node->left);
	}

	void commitHeight(Node* node)
	{
		if (node)
		{
			int left = Height(node->left);
			int right = Height(node->right);
			node->height = (left > right ? left : right) + 1;
		}
	}

	
	void rightRotation(Node*& node)
	{
		Node* q = node->left;
		node->left = q->right;
		q->right = node;
		commitHeight(q);
		commitHeight(node);
		node = q;	
	}

	void leftRotation(Node*& node)
	{
		Node* q = node->right;
		node->right = q->left;
		q->left = node;
		commitHeight(q);
		commitHeight(node);
		node = q;
	}

	void balance(Node*& node)
	{
		commitHeight(node);
		int bfactor = BalanceFactor(node);
		if (bfactor == 2)
		{
			if (BalanceFactor(node->right) < 0)
				rightRotation(node->right);
			leftRotation(node);
		}
		if (bfactor == -2)
		{
			if (BalanceFactor(node->left) > 0)
				leftRotation(node->left);
			rightRotation(node);
		}
	}

	void balance(Node*& node) 
	{
		commitHeight(node);
		int bfactor = BalanceFactor(node);
		if (bfactor == 2)
		{
			if (BalanceFactor(node->right) < 0)
				rightRotation(node->right);
			leftRotation(node);
		}
		if (bfactor == -2)
		{
			if (BalanceFactor(node->left) > 0)
				leftRotation(node->left);
			rightRotation(node);
		}
	}

	void insert(Node*& root, int elem)
	{
		if (root == nullptr)
		{
			root = new Node(elem);
		}
		else if (root->data < elem)
		{
			insert(root->right, elem);
		}
		else
			insert(root->left, elem);
		balance(root);
	}


	int succesor(Node*& node)
	{
		if (node->right)
			succesor(node->right);
		else
		{
			Node* tmp = node;
			int p = node->data;
			node = node->left;
			delete tmp;
			tmp = nullptr;
			return p;
		}
	}

	void remove(Node*& node, int elem)
	{
		if (node)
		{
			if (node->right && node->left)
			{
				int p = succesor(node->left);
				node->data = p;
			}
			else if (node->right && !node->left)
			{
				Node* tmp = node;
				node = node->right;
				delete tmp;
				tmp = nullptr;
			}
			else if (!node->right && node->left)
			{
				Node* tmp = node;
				node = node->left;
				delete tmp;
				tmp = nullptr;
			}
			else if (!node->right && !node->left)
			{
				Node* tmp = node;
				delete tmp;
				tmp = nullptr;
				return;
			}
			balance(node);
		}
	}


};


int main()
{
}