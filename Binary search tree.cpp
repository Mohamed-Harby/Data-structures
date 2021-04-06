// In the name of ALLAH the most Gracious the most Merciful
#include <iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
#define all(v) v.begin(), v.end()
#define vi vector<int>

struct BstNode {
	int data;
	BstNode* left;
	BstNode* right;
};

BstNode* getNewNode(int data) {
	BstNode* newNode = new BstNode();
	newNode -> data = data;
	newNode -> left = newNode -> right = NULL;

	return newNode;
}

BstNode* insert(BstNode* root,int data) {
	if(root == NULL) {
		root = getNewNode(data);
	}
	else if(data <= root -> data) root -> left = insert(root -> left, data);
	else root -> right = insert(root -> right, data);

	return root;
}
bool Search(BstNode* root, int data) {
	if(root == NULL) return false;
	else if(root -> data == data) return true;
	else if(data <= root -> data) return Search(root -> left, data);
	else return Search(root -> right, data);
}

int getMin(BstNode* root) {
	if(root == NULL) return -1;
	else if(root -> left == NULL) return root -> data;
	else return getMin(root -> left);
}
int getMax(BstNode* root) {
	if(root == NULL) return -1;
	else if(root -> right == NULL) return root -> data;
	else return getMax(root -> right);
}
int getHeight(BstNode* root) {	// 0(n)
	if(root == NULL) return -1;

	int left_height = getHeight(root->left);
	int right_height = getHeight(root->right);

	return max(left_height, right_height) + 1;
}
void get_preorder(BstNode* root, vi &v) {
	if(root == NULL) return;
	v.push_back(root -> data);
	get_preorder(root->left, v);
	get_preorder(root->right, v);
}
void get_inorder(BstNode* root, vi &v) {
	if(root == NULL) return;
	get_inorder(root->left, v);
	v.push_back(root -> data);
	get_inorder(root->right, v);
}
void get_postorder(BstNode* root, vi &v) {
	if(root == NULL) return;
	get_inorder(root->left, v);
	get_inorder(root->right, v);
	v.push_back(root -> data);
}

void print_preorder(BstNode* root) {
	if(root == NULL) return;

	cout << root -> data << ' ';
	print_preorder(root->left);
	print_preorder(root->right);
}
void print_inorder(BstNode* root) {
	if(root == NULL) return;
	print_inorder(root->left);
	cout << root -> data << ' ';
	print_inorder(root->right);
}
void print_postorder(BstNode* root) {
	if(root == NULL) return;
	print_postorder(root->left);
	print_postorder(root->right);
	cout << root -> data << ' ';
}
void breadth_traversal(BstNode* root) {
	if(root == NULL) return;
	queue<BstNode*> Q;
	Q.push(root);
	while(!Q.empty()) {
		BstNode* cur = Q.front();
		cout << cur -> data << ' ';
		if(cur -> left != NULL) Q.push(cur -> left);
		if(cur -> right != NULL) Q.push(cur -> right);
		Q.pop();
	}
}
void breadth_traversal_by_level(BstNode* root) {
	if(root == NULL) return;
	queue<BstNode*> Q;
	Q.push(root);
	queue <BstNode*> temp;
	while(!Q.empty()) {
		BstNode* cur = Q.front();
		cout << cur -> data << ' ';
		temp.push(cur);
		Q.pop();
		if(Q.empty()) {
			cout << '\n';
			while(!temp.empty()){
				cur = temp.front();
				temp.pop();
				if(cur -> left != NULL) Q.push(cur -> left);
				if(cur -> right != NULL) Q.push(cur -> right);

			}
		}
	}
}
bool is_BST(BstNode* root) {
	vi res;
	get_inorder(root, res);
	for(int i = 1;i < int(res.size()); i++){
			if(res[i] < res[i-1]) return false;
	}
	return true;
}

int main() {

	BstNode* root;
	root = NULL;
	root = insert(root, 15);
	root = insert(root, 11);
	root = insert(root, 20);
	root = insert(root, 5);
	root = insert(root, 13);
	root = insert(root, 17);
	root = insert(root, 23);

	cout << "preorder ";  print_preorder(root);		cout << '\n';
	cout << "postorder "; print_postorder(root);	cout << '\n';
	cout << "inorder ";   print_inorder(root);		cout << '\n';

	puts(is_BST(root)? "BST\n":"Not BST\n");
	vi rr;
	get_inorder(root, rr);
	for(auto i: rr) {
		cout << i << ' ';
	}
	cout << endl;
	breadth_traversal(root); cout << '\n';
	breadth_traversal_by_level(root);

}






