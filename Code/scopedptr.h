#ifndef SCOPEDPTR_H
#define SCOPEDPTR_H

template <class T>
class ScopedPtr
{
    T* objectPointer;

    ScopedPtr();
    ScopedPtr(const ScopedPtr& other);
    const ScopedPtr& operator = (const ScopedPtr& p);
    public:
        ScopedPtr(T* ptr) { objectPointer=dynamic_cast<T*>(ptr);  }
        T& operator * () const { return *objectPointer; }
        T& operator -> () const { return *objectPointer; }
        bool isNull() const { return (objectPointer==nullptr); }
        T* ptr() { return objectPointer; }
        ~ScopedPtr() { if (objectPointer!=nullptr) delete objectPointer; }
};

#endif // SCOPEDPTR_H
