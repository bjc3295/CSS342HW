#include "BinaryTree.h"
#include "gtest/gtest.h"

TEST(tree, demo) {
    TreeNode<int>* root = new TreeNode<int>(3);
    root->setLeft(new TreeNode<int>(1));
    root->setRight(new TreeNode<int>(5));

    root->getLeft()->setLeft(new TreeNode<int>(2));
    root->getLeft()->setRight(new TreeNode<int>(7));

    root->getRight()->setLeft(new TreeNode<int>(5));

    BinaryTree<int> tree(root);

    ASSERT_EQ(tree.height(),3);
}

TEST(iterative_traversal, in_order) {
    TreeNode<int>* root = new TreeNode<int>(6);
    root->setLeft(new TreeNode<int>(2));
    root->setRight(new TreeNode<int>(7));

    root->getLeft()->setLeft(new TreeNode<int>(1));
    root->getLeft()->setRight(new TreeNode<int>(4));

    root->getLeft()->getRight()->setLeft(new TreeNode<int>(3));
    root->getLeft()->getRight()->setRight(new TreeNode<int>(5));

    root->getRight()->setRight(new TreeNode<int>(9));

    root->getRight()->getRight()->setLeft(new TreeNode<int>(8));

    //          6
    //        /   \
    //       2     7
    //      / \     \
    //     1   4     9
    //        / \   /
    //       3   5 8

    BinaryTree<int> actual(root);

    std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    ASSERT_EQ(actual.traverseInOrder(), expected);
}

TEST(iterative_traversal, post_order) {
    TreeNode<int>* root = new TreeNode<int>(1);
    root->setLeft(new TreeNode<int>(4));
    root->setRight(new TreeNode<int>(2));

    root->getLeft()->setLeft(new TreeNode<int>(6));
    root->getLeft()->setRight(new TreeNode<int>(5));

    root->getRight()->setLeft(new TreeNode<int>(3));

    //          1
    //        /   \
    //       4     2
    //      / \   /
    //     6   5 3

    BinaryTree<int> actual(root);

    std::vector<int> expected = {6, 5, 4, 3, 2, 1};
    ASSERT_EQ(actual.traversePostOrder(), expected);
}

TEST(lowest_common_ancestor, LCA) {
    TreeNode<int>* root = new TreeNode<int>(4);
    root->setLeft(new TreeNode<int>(8));
    root->setRight(new TreeNode<int>(6));

    root->getLeft()->setLeft(new TreeNode<int>(7));
    root->getLeft()->setRight(new TreeNode<int>(3));

    root->getRight()->setLeft(new TreeNode<int>(2));
    root->getRight()->setRight(new TreeNode<int>(9));

    //          4
    //        /   \
    //       8     6
    //      / \   / \
    //     7   3 2   9

    BinaryTree<int> actual(root);

    ASSERT_TRUE(actual.LCA(4,4) == 4);
    ASSERT_TRUE(actual.LCA(7,7) == 7);
    ASSERT_TRUE(actual.LCA(7,3) == 8);
    ASSERT_TRUE(actual.LCA(7,8) == 8);
    ASSERT_TRUE(actual.LCA(8,6) == 4);
    ASSERT_TRUE(actual.LCA(3,2) == 4);
}