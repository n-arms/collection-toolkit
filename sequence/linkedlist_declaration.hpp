#ifndef LINKEDLIST_DEC_H
#define LINKEDLIST_DEC_H

namespace toolkit{
    template <typename T>
    class listnode{
    private:
        listnode<T>* next_ = NULL;
        T* value_ = NULL;
    public:
        listnode(T* value) ;
        listnode<T>* next() ;
        void setnext(listnode<T>* next) ;
        T& get(unsigned long index) ;
        T& value() ;
    } ;
    template<typename T>
    class linkedlist{
    private:
        listnode<T>* first_;
    public:
        linkedlist() ;
        void add(T element) ;
        T get(unsigned long index) ;
        bool contains(T element) ;
    } ;
}




#endif