## Exercise 3 — Using ROS2

ROS2 is the robotics framework we use to control the rover. To complete this exercise you need to install **ROS2 Jazzy**.

### Installing ROS2

Installing ROS2 requires the **Ubuntu 24.04** operating system. You can follow [this tutorial](https://www.youtube.com/watch?v=qq-7X8zLP7g) on how to install Linux alongside Windows on your PC (the ISO download link in the video description no longer works, use [this one](https://releases.ubuntu.com/noble/ubuntu-24.04.5.1-desktop-amd64.iso) instead). Alternatively, you can use **WSL2**, Windows' official Linux virtual machine.

### Exercise

The exercise consists of using the data from the sensor implemented in Exercise 2 within ROS2. This exercise is also open-ended and you are free to choose how to approach it. Here is how the examples given in Exercise 2 could be used for this exercise:

 - **A: Camera implementation:** Read data from a webcam and publish it on a ROS topic so it can be used by other nodes; subscribe to several topics that allow changing camera parameters, such as resolution, brightness, ...

 - **B: Keyboard or joystick teleoperation:** Use a peripheral to drive a mobile robot, implementing velocity commands on 3 axes (x, y, rotation). The commands are published on a topic and used by another node, which computes an acceleration profile to reach the requested velocity smoothly and finally republishes the velocity values to be sent to the motors.

 - **C: Mouse-controlled gimbal rotation:** Use your mouse to generate position commands for the 2 axes (roll, pitch) of a gimbal. The command is published on a topic and used by a node that, through a PID controller, computes the velocity commands to be sent to the motors (to close the feedback loop you can assume ideal motors, i.e. between one velocity command and the next they will have moved exactly `dt * vel_cmd`).

When you have finished the exercise, record a short demo video showing it working (about 15 seconds) and include it in this folder.

### Tips

- To view images published on ROS topics you can use the `rqt_image_view` tool.
- The exercise described in example B is similar to [this package](https://index.ros.org/r/teleop_twist_keyboard/).
