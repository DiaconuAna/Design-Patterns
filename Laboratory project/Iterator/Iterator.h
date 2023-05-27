//
// Created by amina on 3/9/2023.
//

#ifndef LABORATORY_PROJECT_ITERATOR_H
#define LABORATORY_PROJECT_ITERATOR_H

#include <string>
#include <vector>

template <typename T, typename U>
class Iterator {
public:
    typedef typename std::vector<T>::iterator iter_type;

    Iterator(U* p_data): myData{p_data}{
        myIterator = myData->_data.begin();
    }

    void first(){
        myIterator = myData->_data.begin();
    }

    void next(){
        myIterator ++;
    }

    bool hasNext(){
        return (myIterator != myData->_data.end());
    }

    iter_type current(){
        return myIterator;
    }
private:
    U* myData;
    iter_type myIterator;

};

template <typename T>
class Container{
    friend class Iterator<T, Container>;

private:
    std::vector<T> _data;

public:
    void add(T new_data){
        _data.push_back(new_data);
    }

    Iterator<T, Container>* createIterator(){
        return new Iterator<T, Container>(this);
    }
};


#endif //LABORATORY_PROJECT_ITERATOR_H
