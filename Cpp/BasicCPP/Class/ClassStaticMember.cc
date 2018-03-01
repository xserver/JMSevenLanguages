// ClassStaticMember.cc
#include "stdio.h"

class ClassStaticMember
{
public:
	// ClassStaticMember();
	// ~ClassStaticMember();

	static int getCount() {
		// this->id;	不能用
		return count;
	}
	static const int id = 66;

private:
	static int count;
};

//	类静态属性
int ClassStaticMember::count = 8;


//	静态函数和属性
int main(int argc, char const *argv[])
{
	ClassStaticMember csm;
	printf("%d\n", csm.getCount());

	printf("%d\n", ClassStaticMember::getCount());

	printf("%d\n", ClassStaticMember::id);
	return 0;
}