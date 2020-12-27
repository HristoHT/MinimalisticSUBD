//
//  HeterogenicList.cpp
//  MinimalistSUBD
//
//  Created by Hristo Todorov on 27.12.20.
//

#include "HeterogenicList.hpp"

class VirtualColumn { };

template <class type>
class SubColumnVisitor;

template <class columnType>
class ColumnVisitor {
public:
    VirtualColumn *column;

    ColumnVisitor(VirtualColumn *column = nullptr) {
        this->column = column;
    }
    
    columnType get() {
        SubColumnVisitor<columnType> a(this);
        return a.get();
    }
};

template <class columnType>
class SubColumn: public VirtualColumn {
    columnType value;
public:
    ColumnVisitor<columnType> *vistor;

    SubColumn(columnType value){
        this->value = value;
        vistor = new ColumnVisitor<columnType>(this);
    }
    
    columnType get() {
        return value;
    }
};

template <class type>
class SubColumnVisitor: public ColumnVisitor<type> {
public:
    SubColumnVisitor(ColumnVisitor<type> *columnVisitor) {
        this->column = columnVisitor->column;
    }
    
    type get() {
        return static_cast<SubColumn<type>*>(this->column)->get();
    }
};
