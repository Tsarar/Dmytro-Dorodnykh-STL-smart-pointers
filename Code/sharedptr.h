#ifndef SHAREDPTR_H
#define SHAREDPTR_H

#include <iostream>

template<class T>
class SharedPtr
{
    T* objectPointer;
    int *amount;

    public:
        SharedPtr() { objectPointer=nullptr; amount = new int; *amount=0; }
        SharedPtr(const SharedPtr& other) { objectPointer=dynamic_cast<T*>(other.objectPointer); amount=other.amount; *amount=*amount+1; }
        SharedPtr(T* ptr) { objectPointer=dynamic_cast<T*>(ptr); amount = new int; *amount=1; }

        const SharedPtr& operator = (const SharedPtr& p) {
                    if (this!=&p) {
                        if (objectPointer!=nullptr) { if (*amount<=1) { delete objectPointer; delete amount; } else *amount=*amount-1; };
                        objectPointer=dynamic_cast<T*>(p.ptr());
                        amount=p.getPtrAmount();
                        *amount=*amount+1;
                    }
                return *this;
            }

        T& operator * () const { return *objectPointer; }
        T& operator -> () const { return *objectPointer; }
        bool isNull() const { return (objectPointer==nullptr); }
        int getAmount() const { return *amount; }
        int* getPtrAmount() const { return amount; }
        T* ptr() const { return objectPointer; }
        ~SharedPtr() { if (*amount<=1) { if (objectPointer!=nullptr) delete objectPointer; delete amount; std::cout << "Object of shared pointer was succesfully deleted!\n"; } else { objectPointer=nullptr; *amount=*amount-1; } }
};

#endif // SHAREDPTR_H
