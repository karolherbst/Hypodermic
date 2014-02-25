
#define BOOST_TEST_MODULE Hypodermic_GH2

#include <boost/test/results_reporter.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/config.hpp>

#if defined(BOOST_MSVC)
# pragma warning (disable: 4231) // nonstandard extension used : 'extern' before template explicit instantiation
#endif

#include "common.h"

struct GlobalFixture
{
    GlobalFixture()
    {
        boost::unit_test::results_reporter::set_level(boost::unit_test::SHORT_REPORT);
    }
};

BOOST_GLOBAL_FIXTURE(GlobalFixture);

BOOST_AUTO_TEST_SUITE(GH2Tests);

BOOST_AUTO_TEST_CASE(getFromDllAndResolve)
{
	std::shared_ptr<IGH2TestClass> testClass = getContainer().resolve<IGH2TestClass>();
	BOOST_CHECK(testClass.get() != nullptr);
}

BOOST_AUTO_TEST_SUITE_END();
