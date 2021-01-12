#ifndef ARRAYLIST_DEC_H
#define ARRAYLIST_DEC_H

namespace toolkit{
  template<typename T>
  class arraylist{
  private:
    T* data_ = NULL;
    unsigned long capacity_ = 0;
    unsigned long size_ = 0;
  public:
    void add(const T& element) ;
    const T& operator[](unsigned long index) const ;
    const unsigned long size() const ;
    void remove(unsigned long index) const ;
  } ;
}

#endif
