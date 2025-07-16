#include <iostream>
#include <string>
using namespace std;

class BNode{
public:
	int value;
	BNode *right,*left;
};

class BTree{
	BNode *root;
	void Inorder(BNode *cur){
		if(cur){
			Inorder(cur->left);
			cout << " " << cur->value;
			Inorder(cur->right);
		}
	}
	void Preorder(BNode *cur){
		if(cur){
			cout << " " << cur->value;
			Preorder(cur->left);
			Preorder(cur->right);
		}
	}
public:
	BTree(){
		root = NULL;
	}
	void Insert(int v){
		BNode *cur = root;
		BNode *prt = NULL;
		BNode *node = new BNode();
		node->value = v;
		
		while(cur){
			prt = cur;
			if(cur->value < v){
				cur = cur->right;
			}else{
				cur = cur->left;
			}
		}
		if(prt){
			if(prt->value > v){
				prt->left = node;
			}else{
				prt->right = node;
			}
		}
		if(!root){
			root = node;
		}
	}
	void PrintInorder(){
		Inorder(root);
		cout<<endl;
	}
	void PrintPreorder(){
		Preorder(root);
		cout<<endl;
	}
	void Find(int v){
		BNode *cur = root;
		
		while(cur){
			if(cur->value == v){
				cout<<"yes"<<endl;
				return;
			}else if(cur->value > v){
				cur = cur->left;
			}else{
				cur = cur->right;
			}
		}
		cout<<"no"<<endl;
	}
	BNode* Next(BNode *cur){
		cur = cur->right;
		while(cur->left){
			cur = cur->left;
		}
		return cur;
	}
	void Delete(int v){
		BNode *cur = root;
		BNode *prt = NULL;
		
		while(cur){
			if(cur->value == v){
				if(cur->left==NULL && cur->right==NULL){
					if(prt){
						if(prt->value > v){
							prt->left = NULL;
						}else{
							prt->right = NULL;
						}
					}else{
						root = NULL;
					}
				}else if(cur->left!=NULL && cur->right==NULL){
					if(prt){
						if(prt->value > v){
							prt->left = cur->left;
						}else{
							prt->right = cur->left;
						}
					}else{
						root = cur->left;
					}
				}else if(cur->left==NULL && cur->right!=NULL){
					if(prt){
						if(prt->value > v){
							prt->left = cur->right;
						}else{
							prt->right = cur->right;
						}
					}else{
						root = cur->right;
					}
				}else{
					int temp = Next(cur)->value;
					Delete(temp);
					cur->value = temp;
				}
				return;
			}else if(cur->value > v){
				prt = cur;
				cur = cur->left;	
			}else{
				prt = cur;
				cur = cur->right;
			}
		}
	}
};

int main() {
	BTree bt;
	int m, v;
	string com;
	
	cin>>m;
	for(int i=0;i<m;++i){
		cin>>com;
		if(com=="insert"){
			cin>>v;
			bt.Insert(v);
		}else if(com=="print"){
			bt.PrintInorder();
			bt.PrintPreorder();
		}else if(com=="find"){
			cin>>v;
			bt.Find(v);
		}else if(com=="delete"){
			cin>>v;
			bt.Delete(v);
		}
	}
	
	return 0;
}