//
//  ImageManager.h
//  OpenCVDemo
//
//  Created by 于玮 on 2018/1/15.
//  Copyright © 2018年 于玮. All rights reserved.
//
#import "opencv_filter.hpp"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@interface ImageManager : NSObject
+(UIImage *)handleImage:(UIImage*)image Filter:(cv::Mat(^)(cv::Mat))filter;
@end
