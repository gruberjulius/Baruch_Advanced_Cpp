#include<iostream>

#include "DefaultClass.h"
#include "ValueClass.h"
#include "DirectClass.h"
#include "CopyClass.h"
#include "ListClass.h"
#include "AggregateClass.h"

struct S
{
	int x;
	struct Foo
	{
		int i; int j; int a[3];
	} b;
};

int main(){
	// Part a
	DefaultClass c1;

	ValueClass c2;

	int init_val{4};
	DirectClass c3(init_val);
	//copy class
	CopyClass c4(init_val);
	CopyClass c5(c4);

	ListClass c6 {init_val, init_val + 4, init_val + 8};

	AggregateClass c7  {init_val, 's', 3.14};
	
	// Part b 
	//method 1: default
	S s1;
	//method 2: value
	S s2{};
	//method 3: direct
	S s3();
	//method 4: copy
	S s4(s2);
	//method 5: list
	S s5{0, {0, 0, {0, 0, 0}}};
	
	return 0;
}
