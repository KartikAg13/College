#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
	public:
	int data;
	Node *left;
	Node *right;

	Node(int data) {
		this->data = data;
		left = right = nullptr;
	}

	void traverse(Node *root, vector<string> &result, string temp) {
		if(root->left == nullptr && root->right == nullptr) {
			result.push_back(temp);
			return ;
		}
		traverse(root->left, result, temp + '0');
		traverse(root->right, result, temp + '1');
	}
};

class compare {
	public:
	bool operator()(Node *a, Node *b) {
		return a->data > b->data;
	}
};

vector<string> encode(string value, vector<int> frequency, int size) {
	priority_queue<Node *, vector<Node *>, compare> pq;
	for(int index = 0; index < size; index++) {
		Node *temp = new Node(frequency[index]);
		pq.push(temp);
	}
	while(pq.size() > 1) {
		Node *left = pq.top();
		pq.pop();

		Node *right = pq.top();
		pq.pop();

		Node *newNode = new Node(left->data + right->data);
		newNode->left = left;
		newNode->right = right;
		pq.push(newNode);
	}
	Node *root = pq.top();
	vector<string> result;
	string temp = "";
	root->traverse(root, result, temp);
	return result;
}

int main() {
	string value = "abcdef";
	vector<int> frequency = {5, 9, 12, 13, 16, 45};
	int size = frequency.size();
	vector<string> result;
	result = encode(value, frequency, size);
	for(auto value: result)
		cout << value << " ";
	cout << endl;
	return 0;
}