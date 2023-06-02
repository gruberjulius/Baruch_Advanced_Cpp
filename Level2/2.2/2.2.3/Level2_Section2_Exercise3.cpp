#include <iostream>
#include <type_traits>

template <typename T>
using MapToUnsigned = std::conditional_t<std::is_integral_v<T>, std::make_unsigned_t<T>, T>;

template <typename T>
using MapToSigned = std::conditional_t<std::is_unsigned_v<T>, std::make_signed_t<T>, T>;

template <typename T>
using AddConst = const T;

template <typename T>
using RemoveConst = std::remove_const_t<T>;

template <typename T>
using AddPointer = T*;

template <typename T>
using RemovePointer = std::remove_pointer_t<T>;

template <typename T>
using AddVolatile = volatile T;

template <typename T>
using RemoveVolatile = std::remove_volatile_t<T>;

int main()
{
    // Mapping integers to unsigned integers and vice versa
    int signedValue = -43;
    unsigned int unsignedValue = 123;

    unsigned int mappedUnsigned = static_cast<MapToUnsigned<decltype(signedValue)>>(signedValue);
    int mappedSigned = static_cast<MapToSigned<decltype(unsignedValue)>>(unsignedValue);

    std::cout << "Mapped unsigned value: " << mappedUnsigned << std::endl;
    std::cout << "Mapped signed value: " << mappedSigned << std::endl;
    
    // Adding/removing the const specifier
    using OriginalType = int;
    using AddedConstType = AddConst<OriginalType>;
    using RemovedConstType = RemoveConst<AddedConstType>;

    std::cout << "Original type: " << std::is_const_v<OriginalType> << std::endl;
    std::cout << "Added const type: " << std::is_const_v<AddedConstType> << std::endl;
    std::cout << "Removed const type: " << std::is_const_v<RemovedConstType> << std::endl;

    // Adding/removing a pointer
    using OriginalType2 = int;
    using AddedPointerType = AddPointer<OriginalType2>;
    using RemovedPointerType = RemovePointer<AddedPointerType>;

    std::cout << "Original type: " << std::is_pointer_v<OriginalType2> << std::endl;
    std::cout << "Added pointer type: " << std::is_pointer_v<AddedPointerType> << std::endl;
    std::cout << "Removed pointer type: " << std::is_pointer_v<RemovedPointerType> << std::endl;

    // Adding/removing the volatile specifier
    using OriginalType3 = int;
    using AddedVolatileType = AddVolatile<OriginalType3>;
    using RemovedVolatileType = RemoveVolatile<AddedVolatileType>;

    std::cout << "Original type: " << std::is_volatile_v<OriginalType3> << std::endl;
    std::cout << "Added volatile type: " << std::is_volatile_v<AddedVolatileType> << std::endl;
    std::cout << "Removed volatile type: " << std::is_volatile_v<RemovedVolatileType> << std::endl;
    //works as expected
    return 0;
}

