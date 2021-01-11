#ifndef LINKEDLIST_DEC_H
#define LINKEDLIST_DEC_H

namespace toolkit{
    template <typename T>
    class listnode{
    private:
        listnode<T>* next_ = NULL;
        T value_;
    public:
        listnode(const T& value) ;
        listnode<T>* next() ;
        void setnext(listnode<T>* next) ;
        T& get(unsigned long index) ;
        T& value() ;
        listnode<T>* end() ;
    } ;
    template<typename T>
    class linkedlist{
    private:
        listnode<T>* first_;
        unsigned long size_;
    public:
        void add(T element) ;
        T& get(unsigned long index) ;
        const unsigned long& size() const;
    } ;
}




#endif
