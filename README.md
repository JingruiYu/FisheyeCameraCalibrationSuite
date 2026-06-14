# Fisheye Camera Calibration Suite

A compact C++/OpenCV toolkit for calibrating **fisheye** and **pinhole** cameras from image streams or saved calibration images.

This repository is part of my earlier robotics and autonomous-driving perception work. It focuses on the practical camera-calibration layer that often sits before SLAM, visual odometry, BEV perception, and multi-camera spatial understanding.

## Why this repository exists

Accurate camera calibration is a prerequisite for many downstream robotics tasks:

- visual odometry and SLAM;
- bird's-eye-view transformation;
- 3D reconstruction;
- autonomous-driving perception;
- multi-camera geometric consistency.

This project provides small, readable calibration utilities that can be used as a reference implementation or as a starting point for camera-model experiments.

## Features

- **Fisheye camera calibration** using OpenCV fisheye camera model.
- **Pinhole camera calibration** using the standard OpenCV camera model.
- C++ implementation with a minimal dependency footprint.
- Useful as an educational reference for camera geometry and calibration workflows.

## Repository structure

```text
.
├── camera_calibrate.cpp      # Pinhole camera calibration
├── fisheye_calibrate.cpp     # Fisheye camera calibration
├── CMakeLists.txt            # CMake build configuration
└── README.md
```

## Requirements

- C++ compiler with C++11 support or later
- CMake
- OpenCV

## Build

```bash
mkdir -p build
cd build
cmake ..
make -j
```

## Run

```bash
./fisheye_calibrate
# or
./camera_calibrate
```

Please check the source files for the expected image input path, calibration-board configuration, and camera-model parameters before running on your own data.

## Notes

This is a historical research/engineering repository. I keep it public because it shows a concrete part of my long-term work in camera geometry, 3D vision, and robotics perception.

For my more recent work, see:

- [pyCuSFM: CUDA-accelerated Structure-from-Motion](https://github.com/nvidia-isaac/pyCuSFM)
- [NVIDIA Isaac Neural Reconstruction](https://docs.nvidia.com/nurec/robotics/neural_reconstruction_stereo.html)
