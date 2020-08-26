#ifndef TREE_H
#define TREE_H

using namespace std;

namespace Tree {
	template <class T>
	struct Node {
		unsigned indexNumber;
		T indexData;
		shared_ptr <Node <T> > leftChild = nullptr;
		shared_ptr <Node <T> > rightChild = nullptr;
	};

	template <class T>
	class BinarySearchTree {
	private:
		shared_ptr <Node <T> > root;
		unsigned treeSize;
		void preorderTraversal(shared_ptr < Node <T> > currentNode);
		void inorderTraversal(shared_ptr < Node <T> > currentNode);
		void postorderTraversal(shared_ptr < Node <T> > currentNode);
	public:
		BinarySearchTree();
		BinarySearchTree(const BinarySearchTree<T>& copy);
		~BinarySearchTree();
		void insert(T key);
		void preorder();
		void inorder();
		void postorder();
	};

	template <class T>
	BinarySearchTree<T>::BinarySearchTree() {
		cout << "Constructor called!" << endl;
		treeSize = 0;
		root = make_shared<Node <T> >();
		root = nullptr;
	}

	template <class T>
	BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& copy) {
		cout << "Copy constructor called!";
		
		// Walk through tree and insert into new tree
	}

	template <class T>
	BinarySearchTree<T>::~BinarySearchTree() {
		cout << "Destructor called!" << endl;
	}

	template <class T>
	void BinarySearchTree<T>::insert(T key) {
		shared_ptr < Node <T> > insertNode = make_shared<Node <T> >();
		insertNode->indexNumber = 100;
		
		// Construct the node to be insrted
		insertNode->indexNumber = treeSize;
		insertNode->indexData = key;
		insertNode->leftChild = nullptr;
		insertNode->rightChild = nullptr;

		// If root is null, this node will be the root
		if (root == nullptr) {
			this->root = insertNode;
			this->root->leftChild = nullptr;
			this->root->rightChild = nullptr;
		}
		else {
			shared_ptr < Node <T> > currentNode = make_shared < Node <T> >();
			shared_ptr < Node <T> > prevNode = make_shared < Node <T> >();

			currentNode = root;
			while (currentNode != nullptr) {
				prevNode = currentNode;
				if (key < currentNode->indexData) {
					currentNode = currentNode->leftChild;
				}
				else {
					currentNode = currentNode->rightChild;
				}
			}

			// We have found our insertion location
			currentNode = insertNode;
			currentNode->leftChild = nullptr;
			currentNode->rightChild = nullptr;
			
			// Update our links
			if (key < prevNode->indexData) {
				prevNode->leftChild = insertNode;
			}
			else {
				prevNode->rightChild = insertNode;
			}
		}

		treeSize++;
	}

	template <class T>
	void BinarySearchTree<T>::preorderTraversal(shared_ptr < Node <T> > currentNode) {
		if (currentNode == nullptr) {
			return;
		}

		cout << "Index " << currentNode->indexNumber << " --> " << currentNode->indexData << endl;
		preorderTraversal(currentNode->leftChild);
		preorderTraversal(currentNode->rightChild);
	}

	template <class T>
	void BinarySearchTree<T>::inorderTraversal(shared_ptr < Node <T> > currentNode) {
		if (currentNode == nullptr) {
			return;
		}

		inorderTraversal(currentNode->leftChild);
		cout << "Index " << currentNode->indexNumber << " --> " << currentNode->indexData << endl;
		inorderTraversal(currentNode->rightChild);
	}

	template <class T>
	void BinarySearchTree<T>::postorderTraversal(shared_ptr < Node <T> > currentNode) {
		if (currentNode == nullptr) {
			return;
		}

		postorderTraversal(currentNode->leftChild);
		postorderTraversal(currentNode->rightChild);
		cout << "Index " << currentNode->indexNumber << " --> " << currentNode->indexData << endl;
	}

	template <class T>
	void BinarySearchTree<T>::preorder() {
		cout << "Beginning preorder traversal of tree..." << endl;
		preorderTraversal(root);
	}

	template <class T>
	void BinarySearchTree<T>::inorder() {
		cout << "Beginning inorder traversal of tree..." << endl;
		inorderTraversal(root);
	}

	template <class T>
	void BinarySearchTree<T>::postorder() {
		cout << "Beginning postorder traversal of tree..." << endl;
		postorderTraversal(root);
	}

}

#endif
