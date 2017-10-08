# Fisheye_Calibrate

The file named fisheye_calibrate.cpp is used to calibrate the fisheye camera online or using image file.
The file named camere_calibrate.cpp is used to calibrate the pin-hole camera online, which I refer to the book <Learning OpenCv>.

## Requirements
* Opencv2

## Tutorial
### For fisheye_calibrate.cpp:
You can use cmake to use this project.

    mkdir build
    cd build
    cmake ..
    make
    ./fiseye_calibrate

### For camere_calibrate.cpp:
You need to edit the CMakeLists.txt first and then compile the code.
