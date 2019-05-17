#include "fake_rover.hpp"
#include <iostream>

using namespace std;
using namespace fake_rover;

FakeRover::FakeRover()
{
   command.rotation = 0;
   command.translation = 0;
   odometry.initUnknown();
}

void FakeRover::setMotionCommand(const base::commands::Motion2D &cmd)
{
    command = cmd;
}

base::samples::RigidBodyState FakeRover::getOdometry()
{
    return odometry;
}

base::Vector3d FakeRover::getPosition()
{
    return odometry.position;
}

double FakeRover::getOrientation()
{
    base::getYaw(odometry.orientation);
}

void FakeRover::step(double dt)
{
    base::Time now = base::Time::now();
    if(dt < 0){
        dt = (now - previousCallOfStep).toSeconds();
    }
    const double x = odometry.position[0];
    const double y = odometry.position[1];

    const double f_orientation = getOrientation();

    const double x_ = command.translation * cos(f_orientation);
    const double y_ = command.translation * sin(f_orientation);
    const double f_orientation_ = fmod((f_orientation + command.rotation*M_PI/4.0*dt),2*M_PI);

    odometry.position = base::Vector3d(x+x_*dt,y+y_*dt,0.0);
    odometry.orientation = base::Quaterniond (base::AngleAxisd(f_orientation_,
                                                               base::Vector3d::UnitZ()));
}
