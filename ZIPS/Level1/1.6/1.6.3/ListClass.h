class ListClass
{
private:
	int pos[3];
public:
	ListClass(int x, int y, int z)
		: pos{ x, y ,z } {
			std::cout << " construction with List Class" << std::endl;
		};
};


