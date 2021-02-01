#include<bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;	
};

Node* creatNode(int data) {
	Node* temp = new Node();
	temp->val = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void insert(Node* &root, int val) {
	if(root == NULL) {
		root = creatNode(val);
	} else if(root->val > val) {
		insert(root->left, val);
	} else {
		insert(root->right, val);
	}
}
/*
Inorder traversal - LPR // Sorted
Preorder traversal - PLR
Postorder traversal - LRP
*/
void display(Node* root) { 
	if(root!=NULL) {
		display(root->left);		//L
		cout << root->val << " ";	//P
		display(root->right);		//R
	}
}

void levelOrder(Node* root) {	//O(n)
	if (root == NULL) return;
	queue<Node*> q;
	q.push(root);
	while(!q.empty()) {
		Node* top = q.front();
		q.pop();
		cout << top->val << ' ';
		if (top->left != NULL) {
			q.push(top->left);	
		}
		if (top->right != NULL) {
			q.push(top->right);	
		}
	}
}

bool find(int x, Node* root) {
	if(root == NULL) return false;
	if(root->val == x) return true;
	else if(x < root->val) return find(x, root->left);
	else if(x > root->val) return find(x, root->right);
	return false;
}

bool isBST(Node* root, int min, int max) {
	if(root==NULL) return true;
	if(root->val < min || root->val > max) return false;
	return isBST(root->left, min, root->val) && isBST(root->right, root->val, max);
}

int height(Node* root) {
	if (root == NULL) return -1;
	return 1 + max(height(root->left), height(root->right));
}

bool isBalanced(Node* root) {
	if(root==NULL) return true;
	return (abs(height(root->left)-height(root->right))<=1 && isBalanced(root->left) && isBalanced(root->right));
}
/*
5
5 4 6 3 2
*/

int main() {
	Node* root = NULL;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		int num; cin >> num;
		insert(root, num);	
	}
	display(root);
	cout << endl;
	levelOrder(root);
	if(isBST(root, INT_MIN, INT_MAX)) cout << endl << "It is BST";
	else cout << endl << "It is not BST";
	int num = 5;
	if(find(num, root)) cout << endl << num << " is present in tree";
	else cout << endl << num << " is not present in tree";
	cout << endl << "Height : " << height(root);
	cout << endl << "isBalanced : " << isBalanced(root);
	/*
	Node* root1 = creatNode(7);
	root1->left = creatNode(6);
	root1->right = creatNode(8);
	root1->left->left = creatNode(3);
	root1->left->left->left = creatNode(2);
	root1->left->left->right = creatNode(10);
	cout << endl << "root 1 : " << isBST(root1, INT_MIN, INT_MAX);
	cout << endl << "Height " << height(root1);
	*/
}

/*
Sorted array into balances BST;

TreeNode* makeTree(const vector<int> &A, int s, int e) {
    if(s == e)    return new TreeNode(A[s]);
    if(s > e)   return NULL;
    int mid = (e+s)/2;
    TreeNode* root = new TreeNode(A[mid]);
    root->left = makeTree(A, s, mid-1);
    root->right = makeTree(A, mid+1, e);
    return root;
}

TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    return makeTree(A, 0, A.size()-1);
}
*/


/*

Find path from root to target

vector<int> res;
void findPath(TreeNode* A, int target, vector<int> ans) {
    if(A==NULL) return;
    ans.push_back(A->val);
    if(A->val == target) {
        res = ans;
        return;
    }
    findPath(A->left, target, ans);
    findPath(A->right, target, ans);
}
vector<int> Solution::solve(TreeNode* A, int B) {
    findPath(A, B, {});
    return res;
}
*/