#include <iostream>

template<typename T>
void f(T& t)
{
    std::cout << t << std::endl;
}

template<typename T>
struct Node
{
    T value;
    Node<T>* left;
    Node<T>* right;
    Node<T>* parent;
};

template<typename T>
void traverse_tree(Node<T>* root)
{
    Node* current = root;
    Node* previous = root->parent;

    while (current != nullptr) {
        if (current->left == nullptr) {
            f(current->value);

            // Go to right subtree
            current = current->right;
        }
        else {
            // Find the rightmost node in the left subtree
            previous = current->left;

            while (previous->right != nullptr && previous->right != current) {
                previous = previous->right;
            }

            // If right node is not set
            if (previous->right == nullptr) {
                // Set right node
                previous->right = current;

                // Go to left subtree
                current = current->left;
            }
            else {
                // Set right node to null
                previous->right = nullptr;

                // Print node value
                f(current->value);
            }
        }
    }
}

void insert_node(Node<int>* root, int value)
{
    Node<int>* current = root;
    Node<int>* previous = nullptr;

    while (current != nullptr) {
        previous = current;

        if (value < current->value) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }

    Node<int>* node = new Node<int>;
    node->value = value;
    node->left = nullptr;
    node->right = nullptr;
    node->parent = previous;

    if (previous == nullptr) {
        root = node;
    }
    else if (value < previous->value) {
        previous->left = node;
    }
    else {
        previous->right = node;
    }
}

void test_tree()
{
    Node<int>* root = nullptr;

    insert_node(root, 5);
    insert_node(root, 3);
    insert_node(root, 7);
    insert_node(root, 2);
    insert_node(root, 4);
    insert_node(root, 6);
    insert_node(root, 8);

    traverse_tree(root);
}

int main()
{
    test_tree();
    return 0;
}
