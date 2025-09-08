#include <iostream>
#include <istream>
using namespace std;

class Tree
{
	struct Node 
	{
		char ch;
		Node* left, * right;

		Node(char ch = ' ') : ch(ch), left(nullptr), right(nullptr) {}
	};
	Node* root;
public:
	Node* create(istream& in)
	{
		char p = in.get();
		Node* temp;
		if (p >= 0 && p <= 9)
			temp = new Node(p);
		else
		{
			temp->left = create(in);
			temp->ch = in.get();
			temp->right = create(in);
			p = in.get();
		}
	}

	string toString(Node* node)
	{
		char ch = node->ch;
		if (ch >= 0 && ch <= 9)
			return string(1, ch);
		else
			return "(" + toString(node->left) + ch + toString(node->right) + ")";
	}

	int culc(Node* node)
	{
		char ch = node->ch;
		if (ch <= 9 && ch >= 0)
			return ch - '0';
		else
		{
			switch (ch)
			{
			case '+':
			{
				return culc(node->left) + culc(node->right);
				break;
			}
			case '-':
			{
				return culc(node->left) -  culc(node->right);
				break;
			}
			case '*':
			{
				return culc(node->left) * culc(node->right);
				break;
			}
			default:
				break;
			}
		}
	}
};