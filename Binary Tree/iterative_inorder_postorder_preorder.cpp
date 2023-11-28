#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int

struct Node {
	int data;
	Node *left;
	Node *right;

	Node(int data){
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

void inorder(Node *root){
	
}

void preorder(Node *root){

}

void postorder(Node *root){

}

void solve(){
	vector<int> arr = {50,25,12,-1,-1,37,30,-1,-1,-1,75,62,-1,70,-1,-1,87,-1,-1};

	stack<pair<Node*, int>> s;
	Node *root = new Node(arr[0]);
	s.push({root,1});

	int index = 0;
	while(!s.empty()){
		auto *node = s.top().first;
		auto state = s.top().second;

		if(state == 1){
			index++;
			if(index < arr.size() and arr[index] != -1){
				// cout << "left of " << node->data << " " << "is " << arr[index];
				Node *leftNode = new Node(arr[index]);
				// cout << " this nodes data " << leftNode->data << endl;
				node->left = leftNode;
				// update the state of top node first before pushing this left node in stack
				s.top().second++;
				s.push({leftNode,1});
			}
			// no need for else statement cause tops default left and right pointers are already
			// pointing to NULL
			// else{
			// 	top.first->left = NULL;
			// }

			// if arr[index] == -1 which means NULL then simply update the state of topmost node
			else s.top().second++;
		}
		else if(state == 2){
			index++;
			if(index < arr.size() and arr[index] != -1){
				// cout << "right of " << node->data << " " << "is " << arr[index] << endl;
				Node *rightNode = new Node(arr[index]);
				node->right = rightNode;
				// update the state of top most node first before pushing this right node in stack
				s.top().second++;
				s.push({rightNode,1});
			}
			// else{
			// 	top.first->right = NULL;
			// }

			// if arr[index] == -1 which means it is NULL then simple update the state of top node in stack
			else s.top().second++;

		}
		else s.pop();
	}

	inorder(root);
	preorder(root);
	postorder(root);
}

int32_t main(){

// #ifndef ONLINE_JUDGE
// 	freopen('input.txt', 'r', stdin);
// 	freopen('output.txt', 'w', stdout);
// #endif
	
	int t = 1;
	while(t--){
		solve();
	}
}