//
//  VirualQuery.hpp
//  MinimalistSUBD
//
//  Created by Hristo Todorov on 26.12.20.
//

#ifndef VirualQuery_hpp
#define VirualQuery_hpp
#include <string>
#include <stdio.h>
#include <vector>
#include "Columns.hpp"

class VirtualQuery {    
    public:
        virtual void execute() = 0;
        virtual void parse() = 0;
};
#endif /* VirualQuery_hpp */
