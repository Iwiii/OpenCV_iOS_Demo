//
//  opencv_filter.cpp
//  OpenCVDemo
//
//  Created by 于玮 on 2018/1/15.
//  Copyright © 2018年 于玮. All rights reserved.
//

#include "opencv_filter.hpp"
#include <iostream>
#define pi 3.1415926
using namespace std;
using namespace cv;

cv::Mat ellipsoid(cv::Mat src){
    
    cv::Mat Img_out(src.size(), CV_8UC3);
    src.copyTo(Img_out);
    int width = src.cols;
    int height = src.rows;
    
    float e;
    float a,b,a0,b0,a1,b1;
    float alpha = 1.0;
    float K = pi/2;
    
    a = width/2;
    b = height/2;
    e = (float)width/(float)height;
    
    cv::Point2i Center(width/2,height/2);
    
    float new_x,new_y;
    float p,q,x1,y1,x0,y0;
    float theta;
    
    for (int y=0; y<height; y++)
    {
        for (int x=0; x<width; x++)
        {
            y0=Center.y-y;
            x0=x-Center.x;
            
            
            theta=atan(y0*e/(x0+0.0001));
            if(x0<0)   theta=theta+pi;
            
            a0=x0/cos(theta);
            b0=y0/sin(theta+0.0001);
            
            if(a0>a || b0>b)  continue;
            
            a1=a*sin(a0/a*K);
            b1=b*sin(b0/b*K);
            
            a1=(a1-a0)*(alpha)+a0;
            b1=(b1-b0)*(alpha)+b0;
            
            new_x=a1*cos(theta);
            new_y=b1*sin(theta);
            
            new_x=Center.x+new_x;
            new_y=Center.y-new_y;
            
            if(new_x<0)         new_x=0;
            if(new_x>=width-1)  new_x=width-2;
            if(new_y<0)         new_y=0;
            if(new_y>=height-1) new_y=height-2;
            
            x1=(int)new_x;
            y1=(int)new_y;
            
            p=new_x-x1;
            q=new_y-y1;
            
            
            for (int k=0; k<3; k++)
            {
                Img_out.at<Vec3b>(y, x)[k]=(1-p)*(1-q)*src.at<Vec3b>(y1, x1)[k]+
                (p)*(1-q)*src.at<Vec3b>(y1,x1+1)[k]+
                (1-p)*(q)*src.at<Vec3b>(y1+1,x1)[k]+
                (p)*(q)*src.at<Vec3b>(y1+1,x1+1)[k];
                
            }
            
            
        }
    }
    
    return Img_out;
    
}

// TO DO
cv::Mat sketch(cv::Mat src){
//    //string Img_name("4.jpg");
//    Mat Image_in;
//    Image_in=src.clone();
//    // Show_Image(Image_in, Img_name);
//
//    Mat Image_out(Image_in.size(), CV_32FC3);
//    Image_in.convertTo(Image_out, CV_32FC3);
//
//    Mat I(Image_in.size(), CV_32FC1);
//
//    cv::cvtColor(Image_out, I, CV_BGR2GRAY);
//    I=I/255.0;
//    // Show_Image(I, "gray");
//
//    Mat I_invert;
//    I_invert=-I+1.0;
//    // Show_Image(I_invert, "Inv");
//
//    Mat I_gau;
//    GaussianBlur(I_invert, I_gau, Size(25,25), 0, 0);
//    //Show_Image(I_gau, "gau1");
//
//    float delta=0.01;
//    I_gau=-I_gau+1.0+delta;
//    //Show_Image(I_gau, "gau");
//
//    Mat I_dst;
//    cv::divide(I, I_gau, I_dst);
//   // I_dst=I_dst;
//   // Show_Image(I_dst, "dst");
//
//    Mat b(Image_in.size(), CV_32FC1);
//    Mat g(Image_in.size(), CV_32FC1);
//    Mat r(Image_in.size(), CV_32FC1);
//
//    Mat rgb[]={b,g,r};
//
//    float alpha=0.75;
//
//    r=alpha*I_dst+(1-alpha)*200.0/255.0;
//    g=alpha*I_dst+(1-alpha)*205.0/255.0;
//    b=alpha*I_dst+(1-alpha)*105.0/255.0;
//
//    cv::merge(rgb, 3, Image_out);
//    return Image_out;
    return src;
}
