#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "linkedlist_declaration.hpp"
namespace toolkit{
    template<typename T>
    class listnode{
    private:
        listnode<T>* next_ = NULL;
        T* value_ = NULL;
    public:
        listnode(T* value){
            value_ = value;
        }
        void setnext(listnode<T>* next){
            next_ = next;
        }
        listnode<T>* next(){
            return next_;
        }
        T& get(unsigned long index){
            return ((index==0L) ? *value_ : next_->get(index-1L));
        }
        T& value(){
            return *value_;
        }
    } ;

    template<typename T>
    class linkedlist{

    } ;

}

#endif