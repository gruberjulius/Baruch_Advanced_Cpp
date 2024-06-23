#include<iostream>
#include<type_traits> 


template<typename T>
void checkType(const T& t){
	if(std::is_pointer<T>::value){
		    std::cout << " This is a ptr" << std::endl;
    }
    else if(std::is_null_pointer<T>::value){
			std::cout << "This is a null_ptr" << std::endl;
	
	}else if(std::is_rvalue_reference<T>::value){
		std::cout << " This is a rvalue reference" << std::endl;
	}else if(std::is_lvalue_reference<T>::value){
		std::cout << " This is a lvalue reference" << std::endl;
	}else{
        std::cout << "No type detected" << std::endl;
    }
}		

//Part B

template<typename T>
void checkMember(const T& t){
    if(std::is_member_function_pointer<T>::value){
        std::cout << "This i  a member function pointer" << std::endl;
    }else if(std::is_member_object_pointer<T>::value){
        std::cout << "This is a member object pointer" << std::endl;
    }else{
        std::cout << "Cannot determine the pointer " << std::endl;
    }
}

class TestClass{
public:
    int a =3;
    static int b ;
    //member function
    int f(){return 0;};
    //member function pointer: it is necessary to use 
    void member(){};
};

int TestClass::b = 4;

int main(){

    int a = 10;
	int *null_ptr = NULL;
	int *ptr = &a;	
    std::nullptr_t b;
    
    if(false){

    // Part A
	checkType(ptr);
	checkType(b);
    checkType<int &>(a);
    checkType<int &&>(a);

   //Part B
    checkMember(&TestClass::f);
    checkMember(&TestClass::a);
    checkMember(&TestClass::b);

    } 
    //Part C
    std::shared_ptr<int> ptr1 = std::make_shared<int>(42);
    checkType(ptr1);
    checkType(ptr1.get());

    
    return 0;
}
