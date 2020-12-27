//
//  main.cpp
//  MinimalistSUBD
//
//  Created by Hristo Todorov on 26.12.20.
//

#include <iostream>
#include "HeterogenicList.cpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    SubColumn<int> a(5);
    std::cout << a.vistor->get() << std::endl;
    
    SubColumn<double> b(5.5);
    std::cout << b.vistor->get() << std::endl;
    
    
    return 0;
}
