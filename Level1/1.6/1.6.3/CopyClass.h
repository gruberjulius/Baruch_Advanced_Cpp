class CopyClass
{
private:
	int val;
public:
	CopyClass(int init_val) { 
		std::cout << "value assignment: copy class" << std::endl;	
		val = init_val; 
	};

	CopyClass(const CopyClass& copy) {
		std::cout << "copy construction: copy class" << std::endl;	
		val = copy.val;
	};
};


