#ifndef ARRAYLIST_DEC_H
#define ARRAYLIST_DEC_H

namespace toolkit{
  template<typename T>
  class arraylist{
  private:
    T* data_;
    unsigned long capacity_;
    unsigned long size_;
  public:
    arraylist<T>() ;
    void add(const T& element) ;
    const T& operator[](unsigned long index) const;
    

  } ;
}

#endif
