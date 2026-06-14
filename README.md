# Fisheye Camera Calibration Suite

<p align="center">
  <img src="https://img.shields.io/badge/language-C++-blue" />
  <img src="https://img.shields.io/badge/OpenCV-camera--calibration-brightgreen" />
  <img src="https://img.shields.io/badge/topic-fisheye--camera-orange" />
  <img src="https://img.shields.io/badge/license-Apache--2.0-green" />
</p>

[中文](#中文说明) | [English](#english)

## Contents

- [Overview](#english)
- [Repository structure](#repository-structure)
- [Citation](#citation)
- [License](#license)
- [中文说明](#中文说明)


## English

A compact C++ / OpenCV toolkit for calibrating **fisheye** and **pinhole** cameras with chessboard observations.

This repository focuses on the practical camera-calibration workflow: collecting chessboard corners, estimating intrinsic parameters, estimating distortion coefficients, and saving calibration results for downstream computer-vision or robotics applications.

## Highlights

- Supports both **fisheye camera calibration** and **standard pinhole camera calibration**.
- Uses OpenCV chessboard corner detection and sub-pixel refinement.
- Provides small, readable C++ examples for understanding the full calibration pipeline.
- Useful for robotics, autonomous-driving perception, visual odometry, SLAM, BEV projection, and multi-camera geometry experiments.

## Repository structure

```text
.
├── camera_calibrate.cpp      # Standard pinhole-camera calibration example
├── fisheye_calibrate.cpp     # Fisheye-camera calibration example
├── CMakeLists.txt            # CMake build configuration
└── README.md
```

## Requirements

- CMake
- C++ compiler
- OpenCV

The code was originally written with an older OpenCV API. If you build it with a modern OpenCV version, a small API migration may be needed, especially around legacy headers such as `cv.h` and `highgui.h`.

## Build

```bash
mkdir -p build
cd build
cmake ..
make -j
```

## Usage

Run the fisheye calibration example:

```bash
./fisheye_calibrate
```

Run the standard pinhole calibration example:

```bash
./camera_calibrate
```

Before running on your own data, check these parameters in the source files:

- camera index or image path;
- chessboard size;
- square size;
- number of calibration images;
- output file path.

## Keywords

`camera calibration`, `fisheye calibration`, `pinhole camera`, `OpenCV`, `chessboard calibration`, `intrinsic parameters`, `distortion coefficients`, `robotics perception`, `visual odometry`, `SLAM`


## Citation

If you use this repository, please cite or acknowledge it using the metadata in [`CITATION.cff`](CITATION.cff).

## License

This repository is released under the [Apache License 2.0](LICENSE). Please retain the license and notice files when redistributing or reusing the code.

---

## 中文说明

这是一个基于 **C++ / OpenCV** 的相机标定小工具，支持 **鱼眼相机标定** 和 **普通针孔相机标定**。

项目主要覆盖相机标定中的基础流程：采集棋盘格角点、亚像素角点优化、估计相机内参、估计畸变参数，并输出可供后续视觉任务使用的标定结果。

## 功能特点

- 支持鱼眼相机和普通针孔相机两类标定流程；
- 使用 OpenCV 的棋盘格角点检测与亚像素优化；
- 代码结构较小，适合作为理解相机标定流程的参考实现；
- 可用于机器人感知、自动驾驶感知、视觉里程计、SLAM、BEV 投影、多相机几何等前置实验。

## 说明

该项目使用的是较早期 OpenCV API。如果在新版本 OpenCV 上编译，可能需要对头文件和部分接口做少量适配。

## 引用与许可

如果你使用该仓库，请通过 [`CITATION.cff`](CITATION.cff) 引用或致谢该项目。许可协议见 [`LICENSE`](LICENSE)。
