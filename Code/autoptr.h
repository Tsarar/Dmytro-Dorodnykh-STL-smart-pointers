#ifndef AUTOPTR_H
#define AUTOPTR_H


template <class T>
class AutoPtr
{
    T* objectPointer;

    public:
        AutoPtr() { objectPointer=nullptr; };
        AutoPtr(const AutoPtr& other) { objectPointer=dynamic_cast<T*>(other.objectPointer); other.objectPointer=nullptr; };\
        AutoPtr(T* ptr) : objectPointer(dynamic_cast<T*>(ptr)) {}
        const AutoPtr& operator = (AutoPtr& p) {
                    if (this!=&p) {
                        if (objectPointer!=nullptr) delete objectPointer;
                        objectPointer=dynamic_cast<T*>(p.ptr());
                        p.nullPtr();
                    }
                    return *this;
                }
        T& operator * () const { return *objectPointer; }
        T& operator -> () const { return *objectPointer; }
        bool isNull() const { return (objectPointer==nullptr); }
        T* ptr() const { return objectPointer; }
        void nullPtr() { objectPointer=nullptr; }
        ~AutoPtr() { if (objectPointer!=nullptr) delete objectPointer; }
};

#endif // AUTOPTR_H
