workspaceTrajectory = read("/home/senserlex/youbot_ws/src/red_manipulation_step/trajectory_generator/logs/WorkSpaceTraj.log", -1, 10);
jointspaceTrajectory = read("/home/senserlex/youbot_ws/src/red_manipulation_step/trajectory_generator/logs/JointSpaceTraj.log", -1, 19);

x = workspaceTrajectory(:, 1);
y = workspaceTrajectory(:, 2);
z = workspaceTrajectory(:, 3);
dx = workspaceTrajectory(:, 4);
dy = workspaceTrajectory(:, 5);
dz = workspaceTrajectory(:, 6);
// t = workspaceTrajectory(:, 10);

q1 = jointspaceTrajectory(:, 1);
q2 = jointspaceTrajectory(:, 2);
q3 = jointspaceTrajectory(:, 3);
q4 = jointspaceTrajectory(:, 4);
q5 = jointspaceTrajectory(:, 5);
t = = jointspaceTrajectory(:, 19);

gray = color(200, 200, 200);

