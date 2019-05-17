#ifndef _FAKE_ROVER_HPP_
#define _FAKE_ROVER_HPP_
#include <base/commands/Motion2D.hpp>
#include <base/samples/RigidBodyState.hpp>

namespace fake_rover
{
    class FakeRover
    {
        public:
            FakeRover();
            void setMotionCommand(const base::commands::Motion2D& cmd);
            base::samples::RigidBodyState getOdometry();
            base::Vector3d getPosition();
            double getOrientation();
            //If dt is negative, system clock is used
            void step(double dt=-1);
        protected:
            base::samples::RigidBodyState odometry;
            base::commands::Motion2D command;
            base::Time previousCallOfStep;
    };

} // end namespace fake_rover

#endif
