#include <iostream>
#include <cstdlib>
#include <cstdio> 
using namespace std;

typedef struct node{
	int key;
	struct node *parent;
	struct node *left;
	struct node *right;
} Node, Tree;

void insert(Tree **T, int key)
{
	Node *pre = NULL;
	Node *curr = *T;
	Node *newNode = NULL;
	
	newNode = (Node*)malloc(sizeof(Node));
	newNode->key = key;
	newNode->left = NULL;
	newNode->right = NULL;
	
	while (curr != NULL) {
		pre = curr;
		if (key > curr->key) {
			curr = curr->right;
		} else {
			curr = curr->left;
		}
	}
	
	newNode->parent = pre;
	
	//如果根结点存在，则pre一定不为空，反之pre为空 
	if (pre == NULL) {
		*T = newNode;
	} else {
		if (key > pre->key) {
			pre->right = newNode;
		} else {
			pre->left = newNode;
		}
	}
}

void Inorder(Tree *T)
{
	if (T == NULL)
		return;
		
	Inorder(T->left);
	cout << " " << T->key;
	Inorder(T->right);
}

void Preorder(Tree *T)
{
	if (T == NULL)
		return;
		
	cout << " " << T->key;	
	Preorder(T->left);
	Preorder(T->right);
}

bool find(Tree *T, int key)
{
	Node *curr = T;
	if (T == NULL)
		return false;
		
	while (curr != NULL) {
		if (key == curr->key)
			return true;
		else if (key > curr->key) {
			curr = curr->right;
		} else {
			curr = curr->left;
		}
	}
		
	return false;
}

Node *minNode(Node *N)
{
	Node *pre = NULL;
	Node *curr = N;
	
	while (curr != NULL) {
		pre = curr;
		curr = curr->left;
	}
	
	return pre;
}

bool deleteNode(Tree **T, int key)
{
	Node *pre = NULL;
	Node *curr = *T;
	Node *nextNode = NULL;
	Node *p = NULL;
	
	if (key == (*T)->key) {
		p = *T;
		if ((*T)->left == NULL && (*T)->right == NULL) {
			(*T) = NULL;
			free(p);
		} else if ((*T)->left == NULL) {
			(*T) = (*T)->right;
			free(p);
		} else if ((*T)->right == NULL) {
			(*T) = (*T)->left;
			free(p);
		} else {
			p = minNode((*T)->right);
			(*T)->key = p->key;
			if (p->right == NULL) {
				if (p->parent->left == p) {
					p->parent->left = NULL;
				} else {
					p->parent->right = NULL;
				}
			} else {
				(*T)->right = p->right;
				p->right->parent = (*T);
			}
			free(p);
		}
		
		return true;
	} else {
		while (curr != NULL) {
			if (key == curr->key) {
				if (curr->left == NULL && curr->right == NULL) {
					if (curr->parent->left == curr) {
						curr->parent->left = NULL;
					} else {
						curr->parent->right = NULL;
					}
					free(curr);
				} else if (curr->left == NULL) {
					
					if (curr->parent->left == curr) {
						curr->parent->left = curr->right;
					} else {
						curr->parent->right = curr->right;
					}
					curr->right->parent = curr->parent; 
					free(curr);
				} else if (curr->right == NULL) {
					
					if (curr->parent->left == curr) {
						curr->parent->left = curr->left;
					} else {
						curr->parent->right = curr->left;
					}
					curr->left->parent = curr->parent; 
					free(curr);	
				} else {
					p = minNode(curr->right);
					curr->key = p->key;
					if (p->right == NULL) {
						if (p->parent->left == p) {
							p->parent->left = NULL;
						} else {
							p->parent->right = NULL;
						}
					} else {
						if (curr->left == p) {
							curr->left = p->right;
						} else {
							curr->right = p->right;
						}
						p->right->parent = curr;	
					}
					free(p);
				}
				
				return true;	
			} else if (key > curr->key) {
				curr = curr->right;
			} else {
				curr = curr->left;
			}
		}
	}
	
	return false;
}

void print(Tree *T)
{
	Inorder(T);
	cout << '\n';
	Preorder(T);
	cout << '\n';
}

int main(void)
{
	Tree *T = NULL;
	int n;
	int key;
	string cmd;
	
	//freopen("out.txt", "w", stdout);
	
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cmd;
		if (cmd == "insert") {
			cin >> key;
			insert(&T, key);
			//print(T);
		} else if (cmd == "print"){
			print(T);
		} else if (cmd == "find") {
			cin >> key;
			if (find(T, key) == true) {
				cout << "yes\n";
			} else {
				cout << "no\n";
			}
		} else if (cmd == "delete") {
			cin >> key;
			deleteNode(&T, key);
		}
	}
	
	
	return 0;
}
