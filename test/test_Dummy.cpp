#include <boost/test/unit_test.hpp>
#include <fake_rover_lib/Dummy.hpp>

using namespace fake_rover_lib;

BOOST_AUTO_TEST_CASE(it_should_not_crash_when_welcome_is_called)
{
    fake_rover_lib::DummyClass dummy;
    dummy.welcome();
}
