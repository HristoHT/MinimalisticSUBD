//
//  Columns.hpp
//  MinimalistSUBD
//
//  Created by Hristo Todorov on 26.12.20.
//

#ifndef Columns_hpp
#define Columns_hpp
#include <string>
#include <vector>
#include <stdio.h>

template <class type>
class ColumnType {
    using columnType = ColumnType<type>;
    std::string name;
    
public:
    ColumnType(std::string name){
        this->name = name;
    }
    
    columnType create(type value){
        return  columnType{name, value};
    }
};

template <class columnType>
struct Column {
    std::string name;
    columnType value;
};

class Columns {
    std::vector<Column<int>> intColumns;
    std::vector<Column<double>> doubleColumns;
    std::vector<Column<std:: string>> stringColumns;
    
public:
    template <class columnType>
    void push(Column<columnType> newColumn) {
        if(typeid(columnType) == typeid(int)) {
            intColumns.push_back(newColumn);
        } else if (typeid(columnType) == typeid(double)) {
            doubleColumns.push_back(newColumn);
        } else if (typeid(columnType) == typeid(std::string)) {
            stringColumns.push_back(newColumn);
        }
    }
    
    template <class columnType>
    std::vector<columnType>&
    get() const {
        if(typeid(columnType) == typeid(int)) {
            return  intColumns;
        } else if (typeid(columnType) == typeid(double)) {
            return  doubleColumns;
        } else if (typeid(columnType) == typeid(std::string)) {
            return  stringColumns;
        }
    }
};

#endif /* Columns_hpp */
