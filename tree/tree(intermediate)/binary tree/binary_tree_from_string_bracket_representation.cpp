int findIndex(string str, int start, int end)
{
	if (start > end)
		return -1;
	stack<char> s;
	for (int i = start; i <= end; ++i)
	{
		if (str[i] == '(')
			s.push(str[i]);
		else if (str[i] == ')')
		{
			if (s.top() == '(')
			{
				s.pop();
				if (s.empty())
					return i;
			}
		}
	}
	return -1;
}

Node *treeFromString(string str, int start, int end)
{

	if (start > end)
	{
		return NULL;
	}
	Node *root = new Node(str[start] - '0');
	int index = -1;

	if (start + 1 <= end && start + 1 == '(')
	{
		index = findIndex(str, start + 1, end);
	}
	if (index != -1)
	{
		root->left = treeFromString(str, start + 2, index - 1);
		root->right = treeFromString(str, index + 2, end - 1);
	}
	return root;
}