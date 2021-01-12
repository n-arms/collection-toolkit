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
        listnode<T>* next() const;
        void setnext(listnode<T>* next) ;
        T& get(unsigned long index);
        const T& value() const ;
        const long find(const T& element, unsigned long index) const;
        void print() const;
        ~listnode() ;
        void remove(unsigned long index) ;
    } ;
    template<typename T>
    class linkedlist{
    private:
        listnode<T>* first_ = NULL;
        unsigned long size_;
    public:
        void add(T element) ;
        T& get(unsigned long index) ;
        const unsigned long& size() const ;
        long find(const T& element) const;
        void print() const;
        void remove(unsigned long index) ;
        ~linkedlist() ;
        listnode<T>* first() ;
    } ;
}




#endif
