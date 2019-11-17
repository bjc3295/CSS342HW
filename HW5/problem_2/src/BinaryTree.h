#pragma once

#include "Tree.h"
#include "TreeNode.h"
#include <vector>
#include "LinkedStack.h"

template<class T>
class BinaryTree :  public Tree<T> {
private:
    TreeNode<T>* root;

    int height(TreeNode<T>* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + std::max(height(root->left), height(root->right));
    }

public:
    BinaryTree() : root(nullptr) {};

    BinaryTree(std::vector<T> &array) {
        // not implemented yet
    }

    BinaryTree(TreeNode<T>* root) : root(root) {
    }

    bool contains(T val) override {
        // not implemented yet
        return false;
    }

    std::vector<T> traverseInOrder() override {
        // homework, to be done iteratively
        std::vector<T> result;
        LinkedStack<TreeNode<T>*> stack;
        TreeNode<T> *node = root;

        while (node != nullptr || !stack.isEmpty()) {

            // traverse all the way left while adding node to the stack
            while (node != nullptr) {
                stack.push(node);
                node = node->left;
            }
            // node is null

            // node = top of stack
            node = stack.peek();
            stack.pop();

            result.push_back(node->val);

            node = node->right;
        }
        return result;
    }

    std::vector<T> traversePreOrder() override {
        // don't bother
    }

    std::vector<T> traversePostOrder() override {
        // homework, to be done iteratively
        std::vector<T> result;
        LinkedStack<TreeNode<T>*> stack;
        TreeNode<T> *node = root;
        while (node != nullptr || !stack.isEmpty()) {

            // traverse all the way left while adding right and root to the stack
            while (node != nullptr) {
                if (node->right != nullptr) {
                    stack.push(node->right);
                }
                stack.push(node);
                node = node->left;
            }
            // node is null

            // node = top of stack
            node = stack.peek();
            stack.pop();

            // if node->right is the top of the stack
            // put the node on top of the stack and proceed with the right node first
            if (!stack.isEmpty() && node->right == stack.peek()) {
                stack.pop();
                stack.push(node);
                node = node->right;
            } else {
                result.push_back(node->val);

                // node = null to allow the loop to make it the top of the stack
                node = nullptr;
            }
        }
        return result;
    }

    // pre-order traversal
    void _destruct(LinkedStack<TreeNode<T>*> &stack, TreeNode<T> *node) {
        if (node == nullptr) {
            return;
        }
        stack.push(node);
        _destruct(stack, node->left);
        _destruct(stack, node->right);
    }

    virtual ~BinaryTree() override {
        // homework
        LinkedStack<TreeNode<T>*> stack;

        // push nodes onto a stack utilizing pre-order traversal
        _destruct(stack, root);

        while (!stack.isEmpty()) {
            delete stack.peek();
            stack.pop();
        }
    }

    TreeNode<T>* _LCA(TreeNode<T> *node, T val1, T val2) {
        // from your lecture
        if (node == nullptr) {
            return nullptr;
        }
        if (node->val == val1 || node->val == val2) {
            return node;
        }
        TreeNode<T> *left = _LCA(node->left, val1, val2);
        TreeNode<T> *right = _LCA(node->right, val1, val2);
        if (left != nullptr && right != nullptr) {
            return node;
        }
        if (left == nullptr && right == nullptr) {
            return nullptr;
        }
        // not sure what this next line does exactly...
        return left == nullptr ? right : left;
    }

    T LCA(T node1, T node2) {
        // homework
        TreeNode<T> *node = _LCA(root, node1, node2);
        return node->val;
    }

    bool add(const T &) override {
        // not implemented yet
    }

    bool remove(const T &) override {
        // not implemented yet
    }

    int height() override {
        return height(root);
    }

};
