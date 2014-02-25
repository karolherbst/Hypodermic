#include "common.h"

#include <Hypodermic/ContainerBuilder.h>

class GH2TestClass : public IGH2TestClass
{
public:
	void test();
};

void GH2TestClass::test()
{

}

static std::shared_ptr<Hypodermic::IContainer> container;

Hypodermic::IContainer & getContainer()
{
	Hypodermic::ContainerBuilder containerBuilder;
	containerBuilder.registerType<GH2TestClass>()->as<IGH2TestClass>()->singleInstance();
	container = containerBuilder.build();
	return *container;
}
