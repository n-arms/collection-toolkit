#ifndef LINKEDLIST_DEC_H
#define LINKEDLIST_DEC_H

namespace toolkit{
    template <typename T>
    class listnode{
    public:
        listnode() ;
        listnode<T>* next() ;
        T& get(unsigned long index) ;
        T& value() ;
    } ;
    template<typename T>
    class linkedlist{
    public:
        linkedlist() ;
        void add(T element) ;
        T get(unsigned long index) ;
        bool contains(T element) ;
    } ;
}




#endif