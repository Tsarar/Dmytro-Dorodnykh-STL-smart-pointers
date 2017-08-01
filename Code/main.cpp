#include <iostream>
#include "scopedptr.h"
#include "autoptr.h"
#include "sharedptr.h"
#include "object.h"

int main()
{
    ScopedPtr<Object> ptr1(new Object(1,"Water",10));
    ScopedPtr<Object> ptr2(new Object(2,"Grass",15));

    AutoPtr<Object> ptr3(new Object(3,"Sky",25));
    AutoPtr<Object> ptr4;
    ptr4=ptr3;
    std::cout << "Pointer 3 memory block is now " << ptr3.ptr() << '\n' ;
    std::cout << "Pointer 4 memory block is now " << ptr4.ptr() << '\n' ;

    SharedPtr<Object> ptr5(new Object(4,"Sky",25));
    SharedPtr<Object> ptr6;
    SharedPtr<Object> ptr7;
    SharedPtr<Object> ptr8;
    ptr6=ptr5;
    ptr7=ptr6;
    ptr8=ptr6;

    std::cout << "We have " << ptr8.getAmount() << " references on " << ptr8.ptr() << " object\n";

    std::cout << "Press any key and ENTER to quit\n";
    int Pause;
    std::cin >> Pause;
    return 0;
}
