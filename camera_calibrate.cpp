/*************************************************************************
	> File Name: camera_calibrate.cpp
	> Author: OpenCv
	> Mail: 
    > Created Time: 2017年10月06日 星期五 14时33分54秒
 ************************************************************************/

#include <iostream>
#include <opencv2/opencv.hpp>
#include <cv.h>
#include <highgui.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
using namespace cv;

int n_boards = 20;
const int board_dt = 20;
const int board_w = 9;
const int board_h = 6;

int main(int argc, char* argv[])
{
    int board_n = board_w * board_h;
    CvSize board_sz = cvSize( board_w, board_h );
    CvCapture* capture = cvCreateCameraCapture(0);
    assert( capture );

    cvNamedWindow("Calibration");
    CvMat* image_points     = cvCreateMat(n_boards*board_n,2,CV_32FC1);
    CvMat* object_points    = cvCreateMat(n_boards*board_n,3,CV_32FC1);
    CvMat* point_counts     = cvCreateMat(n_boards,1,CV_32SC1);
    CvMat* intrinsic_matrix = cvCreateMat(3,3,CV_32FC1);
    CvMat* distortion_coeffs= cvCreateMat(5,1,CV_32FC1);

    CvPoint2D32f* corners = new CvPoint2D32f[ board_n ];
    int corner_count;
    int successes = 0;
    int step, frame = 0;
    IplImage *image = cvQueryFrame( capture );
    IplImage *gray_image = cvCreateImage(cvGetSize(image),8,1);

    while(successes < n_boards){

        if(frame++ % board_dt == 0){
            cvCvtColor(image, gray_image, CV_BGR2GRAY);
            int found = cvFindChessboardCorners( gray_image, board_sz, corners, &corner_count, CV_CALIB_CB_ADAPTIVE_THRESH);

            printf("have found corners? found = %d.\n",found);

            cvFindCornerSubPix(gray_image, corners, corner_count, cvSize(11,11), cvSize(-1,-1), cvTermCriteria(CV_TERMCRIT_EPS+CV_TERMCRIT_ITER,30,0.1));

            printf("have found SubPix\n");

            cvDrawChessboardCorners(image, board_sz, corners, corner_count, found);
            cvShowImage("Calibration",image);

            printf("have draw\n");
            printf("corner_count = %d. \n", corner_count);


            if(corner_count == board_n){

                step = successes*board_n;
                
                for( int i=step, j=0; j<board_n; ++i,++j){
                    CV_MAT_ELEM(*image_points, float, i, 0) = corners[j].x;
                    CV_MAT_ELEM(*image_points, float, i, 1) = corners[j].y;
                    CV_MAT_ELEM(*object_points,float, i, 0) = j/board_w;
                    CV_MAT_ELEM(*object_points,float, i, 1) = j%board_w;
                    CV_MAT_ELEM(*object_points,float, i, 2) = 0.0f;
                }
                CV_MAT_ELEM(*point_counts, int, successes, 0) = board_n;
                successes++;

                printf("is successes changed?\n");
            }
        }
    
        printf("test waitkey! successes = %d .\n", successes);

        int c = cvWaitKey(15);
        if(c == 'p'){
            c = 0;
            while(c!='p' && c!=27){
                c = cvWaitKey(250);
            }
        }
        if(c == 27)
            return 0;
        image = cvQueryFrame( capture );
    }
    
    CvMat* object_points2   = cvCreateMat(successes*board_n, 3, CV_32FC1);
    CvMat* image_points2    = cvCreateMat(successes*board_n, 2, CV_32FC1);
    CvMat* point_counts2    = cvCreateMat(successes, 1, CV_32SC1);

    for( int i = 0; i < successes*board_n; ++i ){
        CV_MAT_ELEM( *image_points2, float, i, 0) = CV_MAT_ELEM( *image_points, float, i, 0);
        CV_MAT_ELEM( *image_points2, float, i, 1) = CV_MAT_ELEM( *image_points, float, i, 1);
        CV_MAT_ELEM( *object_points2,float, i, 0) = CV_MAT_ELEM( *object_points,float, i, 0);
        CV_MAT_ELEM( *object_points2,float, i, 1) = CV_MAT_ELEM( *object_points,float, i, 1);
        CV_MAT_ELEM( *object_points2,float, i, 2) = CV_MAT_ELEM( *object_points,float, i, 2);
    }

    printf("computing\n");

    for( int i = 0; i < successes; ++i){
        CV_MAT_ELEM( *point_counts2, int, i, 0) = CV_MAT_ELEM( *point_counts, int, i, 0);
    }

    cvReleaseMat(&object_points);
    cvReleaseMat(&image_points);
    cvReleaseMat(&point_counts);

    CV_MAT_ELEM( *intrinsic_matrix, float, 0, 0 ) = 1.0f;
    CV_MAT_ELEM( *intrinsic_matrix, float, 1, 1 ) = 1.0f;

    cvCalibrateCamera2(object_points2, image_points2, point_counts2, cvGetSize(image), intrinsic_matrix, distortion_coeffs, NULL, NULL,0);

    printf("Calibration\n");

    cvSave("intrinsics.xml",intrinsic_matrix);
    cvSave("distortion.xml",distortion_coeffs);

    CvMat *intrinsic =  (CvMat*)cvLoad("intrinsics.xml");
    CvMat *distortion = (CvMat*)cvLoad("distortion.xml");

    IplImage* mapx = cvCreateImage( cvGetSize(image), IPL_DEPTH_32F, 1);
    IplImage* mapy = cvCreateImage( cvGetSize(image), IPL_DEPTH_32F, 1);
    cvInitUndistortMap(intrinsic,distortion,mapx,mapy);

    printf("Undistort\n");

    cvNamedWindow("Undistort");
    while(image){
        IplImage *t = cvCloneImage(image);
        cvShowImage( "Calibration", image );
        cvRemap( t, image, mapx, mapy);
        cvReleaseImage(&t);
        cvShowImage("Undistort",image);

        int c = cvWaitKey(15);
        if(c == 'p'){
            c = 0;
            while(c!='p' && c!=27){
                c = cvWaitKey(250);
            }
        }
        if(c == 27)
            break;
        image = cvQueryFrame( capture );

        printf("show Undistort image\n");

    }
    
    return 0;
}
