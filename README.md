# FisheyeCameraCalibrationSuite

FisheyeCameraCalibrationSuite is a repository that provides tools for online calibration of both fisheye and pin-hole cameras. The calibration process is crucial for accurate image capture and further image processing tasks.

## Features

- **Fisheye Camera Calibration**: The `fisheye_calibrate.cpp` file is used for online calibration of fisheye cameras or using image files.
- **Pin-hole Camera Calibration**: The `camera_calibrate.cpp` file is used for online calibration of pin-hole cameras.

## Requirements

- OpenCV2

## Usage

### Fisheye Camera Calibration

To use the fisheye camera calibration tool, follow these steps:

1. Create a build directory and navigate into it
2. Run cmake and make
3. Run the calibration tool

```bash
mkdir build
cd build
cmake ..
make
./fisheye_calibrate
```
