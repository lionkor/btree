#include <iostream>
#include <cassert>
#include <cmath>
#include "BinarySearchTree.h"

int main(int, char**) {
    BinarySearchTree<int> tree;

    auto list = { 6, 3, 9, 1, 5, 8, -63, 226, 555, 0, 21, 23, 22, 25, 24, 26, 25 };

    for (int i : list) {
        tree.insert(i);
    }

    for (int i : list) {
        tree.print_path(i);
    }

    for (int i : list) {
        std::cout << i << ": " << (tree.contains(i) ? "true" : "false") << "\n";
    }


    std::cout << "expected depth: " << log(list.size()) / log(2) << "\n";
    double sum = 0;
    for (int i : list) {
        auto depth = tree.depth_of(i);
        sum += depth;
    }
    std::cout << "actual depth: " << sum / double(list.size()) << "\n";

    std::cout << std::flush;
}
