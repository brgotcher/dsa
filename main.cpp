#include <iostream>
#include "Binary_node.h"
#include "Binary_tree.h"
#include "errorcode.h"

int main() {
    
    Binary_node<int> rt = Binary_node<int>(1);
    rt.left = new Binary_node<int>(2);
    rt.right = new Binary_node<int>(3);
    
    Binary_tree<int> tree = Binary_tree<int>();
    
    std::cout << "test" << endl;
    return 0;
    
}