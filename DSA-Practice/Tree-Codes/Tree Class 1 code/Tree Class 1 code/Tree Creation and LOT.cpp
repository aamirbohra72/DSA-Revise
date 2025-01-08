#include <iostream>
#include<queue>
using namespace std;

class Node{
	public:
	int data;
	Node* left;
	Node* right;

	Node(int data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

Node* buildTree() {
	int data; 
	cout << "Enter the data: " << endl;
	cin >> data;

	if(data == -1) {
		return NULL;
	}

	//Step A , B and C
	Node* root = new Node(data);

	cout << "Enter data for left part of " << data << " node " << endl;
	root->left = buildTree();
	
	cout << "Enter data for right part of " << data << " node " << endl;
	root-> right = buildTree();

	return root;
	
}

void levelOrderTraversal(Node* root ) {
	queue<Node*> q;                                    //create a queue
	//initially
	q.push(root);                               //Push root to the queue
	q.push(NULL);                               //Push NULL to the queue

	while(!q.empty()) {                     //while queue is not empty
		//A
		Node* temp = q.front();                 //get the first element of the queue
		//B
		q.pop();                                //pop the first element of the queue
		
		if(temp == NULL) {
			cout << endl;
			if(!q.empty()) {               //if there is no more element in the queue then push NULL
				q.push(NULL);
			}	
		}
		else {                                    // if there is an element in the queue then print the data of the element and push the left and right child of the element to the queue
			//C
			cout << temp->data << " ";
			//D
			if(temp -> left) {                             //
				q.push(temp ->left);
			}
			if(temp ->right) {
				q.push(temp->right);
			}
		}
		
		
	}
}

void inorderTraversal(Node* root) {
	//base case
	if(root == NULL) {
		return ;
	}

	//LNR
	inorderTraversal(root->left);
	cout << root -> data << " ";
	inorderTraversal(root->right);
}

void preorderTraversal(Node* root) {
	//base case
	if(root == NULL) {
		return ;
	}

	//NLR
	cout << root -> data << " ";
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}

void postorderTraversal(Node* root) {
	if(root == NULL)
		return;

	//LRN
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	cout << root -> data << " ";
}

int height(Node* root) {
	if(root == NULL) 
		return 0;

	int leftHeight = height(root->left);
	int rightHeight = height(root->right);
	int ans = max(leftHeight, rightHeight) + 1;
	return ans;
}
 
int main() {
	Node* root = NULL;

	root = buildTree();
	levelOrderTraversal(root);
	cout << "height: "<< height(root) << endl;




	return 0;
}