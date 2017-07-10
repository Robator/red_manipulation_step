#include <trajectory_generator/TrajectoryGenerator.h>
#include <fstream>

int main(int argc, char const *argv[])
{
    Vector3d curPos, curVel, curAcc, curRot;
    JointValues angles;
    Pose startPose, endPose;
    ArmKinematics solver;
    double alpha = -3.1415;

    // Main trajectory params
    double maxAcc = 0.05, maxVel = 0.01, timeStep = 0.01;


    startPose.position(0) = -0.3;
    startPose.position(2) = 0.1;
    startPose.orientation(2) = alpha;
    if (!solver.solveFullyIK(startPose, angles)) {
        ROS_ERROR_STREAM("Solution start pose not found!");
        return 1;
    }

    endPose = startPose;
    endPose.position(2) = 0.0;
    endPose.orientation(2) = alpha;
    if (!solver.solveFullyIK(endPose, angles)) {
        ROS_ERROR_STREAM("Solution end pose not found!");
        return 1;
    }

    ROS_INFO_STREAM("[WST test] Start position (" << startPose.position(0) << ", " 
        << startPose.position(1) << ", " <<  startPose  .position(2) << ")");
    ROS_INFO_STREAM("[WST test] End position (" << startPose.position(0) << ", " 
        << endPose.position(1) << ", " <<  endPose.position(2) << ")");
    Trajectory traj;
    traj.calculateWorkSpaceTrajectory(maxVel, maxAcc, startPose, endPose, timeStep);

    std::ofstream logFile;
    std::string logDirPath = "/home/senex/youbot_ws/src/red_manipulation_step/trajectory_generator/";
    std::stringstream filename;
    filename << logDirPath << "logs/WorkSpaceTraj" << ".log";
    std::string file = filename.str();
    logFile.open(file.c_str());

    ROS_INFO_STREAM("Size: " << traj.posTra.size());
    for (uint i = 0; i < traj.posTra.size(); ++i) {
        curPos = traj.posTra[i];

        logFile << curPos(0) << "\t" << curPos(1) << "\t" << curPos(2) 
        << "\t" << traj.time[i] << "\n";
    }

    return 0;
}