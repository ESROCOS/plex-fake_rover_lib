#include <iostream>
#include <fake_rover_lib/fake_rover.hpp>
#include <iostream>

int main(int argc, char** argv)
{
    fake_rover::FakeRover rover;
    base::samples::RigidBodyState odometry;

    base::commands::Motion2D cmd(0.1, 0.1);

    long step = 0;
    long max_steps = 100;
    while(step++ < max_steps){
        rover.setMotionCommand(cmd);
        rover.step(0.1);
        std::cout << "Step:"<<step<<"/"<<max_steps <<std::endl;
        std::cout << "Position: " << rover.getPosition() << std::endl;
        std::cout << "Orientation: " << rover.getOrientation() << std::endl;

    }

    return 0;
}
