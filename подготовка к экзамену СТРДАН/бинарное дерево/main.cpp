

inline void printWidth(BinaryTree* root)
{
	if (!isEmpty(root))
	{
		Queue<BinaryTree*> q;
		q.enque(root);
		while (!q.isEmpty())
		{
			BinaryTree* cur = q.peek();
			q.deque();
			cout << cur->data << " ";
			if (!isEmpty(cur->left))
				q.enque(cur->left);
			if (!isEmpty(cur->right))
				q.enque(cur->right);
		}
	}
}


void printDFS(Node* root)
{
	if (root)
	{
		Stack<Node*> s;
		s.add(root);
		while (!s.isEmpty())
		{
			Node* cur = s.peek();
			s.del();
			cout << cur->data << " ";
			if (!isEmpty(cur->right))
				s.add(cur->right)
			if (!isEmpty(cur->left))
				s.add(cur->left)
		}
	}
}