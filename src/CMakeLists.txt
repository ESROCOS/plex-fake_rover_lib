rock_library(fake_rover_lib
    SOURCES fake_rover.cpp
    HEADERS fake_rover.hpp
    DEPS_PKGCONFIG base-types)

rock_executable(test_fake_rover Main.cpp
    DEPS fake_rover_lib)

