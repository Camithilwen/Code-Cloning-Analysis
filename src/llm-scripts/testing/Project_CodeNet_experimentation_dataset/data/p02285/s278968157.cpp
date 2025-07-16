#include <iostream>
#include <string>

using namespace std;

#define nullptr  NULL

struct node
{
	int val;
	node* right;
	node* left;
	node(const int& v = 0) : val(v), right(nullptr), left(nullptr)
	{}
};

struct Tree
{
	node* root;
};

node* insert(node* root, int v)
{
	if (!root)
	{
		root = new node(v);
		return root;
	}
	node* temp = root;
	while (1)
	{
		if (root->val > v)
		{
			if (!root->left)
			{
				root->left = new node(v);
				break;
			}
			root = root->left;
		}
		else
		{
			if (!root->right)
			{
				root->right = new node(v);
				break;
			}
			root = root->right;
		}
	}
	return temp;
}

node* remove(node* root, int v)
{
	if (!root)
		return nullptr;
	if (root->val > v)
		root->left = remove(root->left, v);
	else if (root->val < v)
		root->right = remove(root->right, v);
	else
	{
		if (!root->left || !root->right)
		{
			root = (root->left) ? root->left : root->right;
		}
		else
		{
			node* temp = root->right;
			while (temp->left)
				temp = temp->left;
			root->val = temp->val;
			root->right = remove(root->right, temp->val);
		}
	}
	return root;
}

node* find(node* root, int v)
{
	if (!root)
		return nullptr;
	while (root != nullptr && v != root->val)
	{
		if (v < root->val)
			root = root->left;
		else
			root = root->right;
	}
	return root;
}

void preorder(node* root)
{
	if (!root)
		return;
	cout << " " << root->val;
	preorder(root->left);
	preorder(root->right);
}

void inorder(node* root)
{
	if (!root)
		return;
	inorder(root->left);
	cout << " " << root->val;
	inorder(root->right);
}

int main()
{
	int m;
	node* root = nullptr;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int k;
		string s;
		cin >> s;
		if (s == "insert")
		{
			cin >> k;
			root = insert(root, k);
		}
		else if (s == "delete")
		{
			cin >> k;
			root = remove(root, k);
		}
		else if (s == "find")
		{
			cin >> k;
			if (find(root, k) != nullptr)
				cout << "yes" << endl;
			else
				cout << "no" << endl;
		}
		else if (s == "print")
		{
			inorder(root);
			cout << endl;
			preorder(root);
			cout << endl;
		}
	}

	return 0;
}

