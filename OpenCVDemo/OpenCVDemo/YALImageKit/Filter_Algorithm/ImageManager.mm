//
//  ImageManager.m
//  OpenCVDemo
//
//  Created by 于玮 on 2018/1/15.
//  Copyright © 2018年 于玮. All rights reserved.
//

#import "ImageManager.h"
#import <opencv2/imgproc/types_c.h>
#import <opencv2/imgcodecs/ios.h>
using namespace cv;
using namespace std;
@implementation ImageManager

+(UIImage *)handleImage:(UIImage *)image Filter:(cv::Mat (^)(cv::Mat))filter{
    Mat frame;
    UIImageToMat(image,frame);
    //因为opencv 使用的是bgr 所以做算法前要做转换 算完再转换回来
    cvtColor(frame, frame, CV_RGB2BGR);
    frame = filter(frame);
    cvtColor(frame, frame, CV_BGR2RGB);
    return MatToUIImage(frame);
}

@end
