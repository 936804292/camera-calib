# Camera Calibration #

This is the camera calibration script provided in the OpenCV examples and the necessary cmake file to be able to build the code.

Details on the camera calibration script, how to use it, how to configure different parts of it, etc, can be [found here in the OpenCV documenation](https://docs.opencv.org/3.2.0/d4/d94/tutorial_camera_calibration.html).

Some worthy notes:

 - the Raspberry Pi's already have OpenCV installed (running OpenCV version 3.2)


## Getting the Code ##

```sh
cd ~/Documents/
git clone https://github.com/aa241x/camera_calib.git
```


## Building the Code ##

The code is designed to be built with cmake.  To build it, here are the steps:

```sh
cd ~/Documents/camera_calib
mkdir build
cmake ..
make
```

Once the code is built, you will see many new files in the build directory, one of which is called `camera_calibration`.  This is the file you use to run the program:

```sh
./camera_calibration
```

**Note:** there are inputs required for the camera calibration script as is.  To understand how the camera calibration script works and the required inputs, etc, make sure to [look at and read through the OpenCV documentation](https://docs.opencv.org/3.2.0/d4/d94/tutorial_camera_calibration.html).
