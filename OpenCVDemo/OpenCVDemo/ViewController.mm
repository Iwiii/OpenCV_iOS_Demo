//
//  ViewController.m
//  OpenCVDemo
//
//  Created by 于玮 on 2018/1/15.
//  Copyright © 2018年 于玮. All rights reserved.
//
#import "ImageManager.h"
#import "ViewController.h"

using namespace cv;
@interface ViewController ()
@property (nonatomic,strong) UIImageView *imageView;
@end

@implementation ViewController

- (void)viewDidLoad {
    _imageView = [[UIImageView alloc] initWithFrame:self.view.bounds];
    [super viewDidLoad];
    UIImage *image = [UIImage imageNamed:@"pic_1"];
    UIImage *final =  [ImageManager handleImage:image Filter:^(cv::Mat tmpMat){
        return sketch(tmpMat);
        //return tmpMat;
        
    }];
    _imageView.contentMode = UIViewContentModeScaleAspectFit;
    _imageView.image = final;
    [self.view addSubview:_imageView];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
