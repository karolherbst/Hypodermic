#include <Hypodermic/IContainer.h>

struct IGH2TestClass
{
	virtual void test() = 0;
};

Hypodermic::IContainer & getContainer();
