#ifndef BinarySearchTree_H
#define BinarySearchTree_H

#include <utility>
#include <cstdio>
#include <tuple>
#include <iostream>
using std::move;

template<class ValueT>
struct Node {
    ValueT value;
    Node* left;
    Node* right;
};

template<class ValueT>
class BinarySearchTree
{
    // typedefs
private:
    typedef Node<ValueT> node_type;

public:
    typedef ValueT value_type;

    // fields
private:
    node_type* m_root { nullptr };

    // interface
public:
    BinarySearchTree()
        : m_root(nullptr) {
    }
    void insert(value_type _v) {
        if (!m_root) {
            m_root = new node_type { move(_v), nullptr, nullptr };
        } else {
            node_type* new_node = new node_type { move(_v), nullptr, nullptr };
            node_type* iter = m_root;
            for (;;) {
                if (_v < iter->value) {
                    if (iter->left) {
                        iter = iter->left;
                    } else {
                        iter->left = new_node;
                    }
                } else if (_v > iter->value) {
                    if (iter->right) {
                        iter = iter->right;
                    } else {
                        iter->right = new_node;
                    }
                } else {
                    break; // value already in tree
                }
            }
        }
    }

    void print_path(value_type _v) {
        std::cout << "path to " << _v << ": \n\t";
        BinarySearchTree::print_path_recursive(m_root, _v);
    }

    static void print_path_recursive(node_type* node, value_type _v) {
        if (!node) {
            std::cout << " nullptr\n";
            return;
        }
        std::cout << node->value;
        if (_v < node->value) {
            std::cout << " < ";
            print_path_recursive(node->left, _v);
        } else if (_v > node->value) {
            std::cout << " > ";
            print_path_recursive(node->right, _v);
        } else {
            std::cout << " .\n";
        }
    }

    std::tuple<node_type*, size_t> find(value_type _v) {
        node_type* iter = m_root;
        size_t depth = 0;
        while (iter) {
            depth++;
            if (_v < iter->value) {
                iter = iter->left;
            } else if (_v > iter->value) {
                iter = iter->right;
            } else {
                return { iter, depth };
            }
        }
        return { nullptr, 0 };
    }

    bool contains(value_type _v) {
        auto [result, depth] = find(_v);
        return result != nullptr;
    }

    size_t depth_of(value_type _v) {
        auto [result, depth] = find(_v);
        return depth;
    }
};

#endif // BinarySearchTree_H
