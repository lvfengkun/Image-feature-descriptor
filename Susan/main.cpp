#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <iostream> 
using namespace std;
using namespace cv;
Mat  MySusan(Mat img);

int main(int argc, char **argv)
{
    Mat image1 = imread("../1.jpg", 1);//读取图像
    
    Mat imageGray1,image_2;
    cvtColor(image1,imageGray1,COLOR_RGB2GRAY);//将彩色图转化为灰度图
    image_2=MySusan(imageGray1);
       imshow("image",image_2);
    imwrite("image_1.jpg",image_2);
     waitKey();
    return 0;
}


//susan角点检测
//输入灰度图,输出角点
Mat  MySusan(Mat img)
{ 
     //susan模板

       int OffSetX[37] = { -1, 0, 1,

                              -2,-1, 0, 1, 2,

                              -3,-2,-1, 0, 1, 2, 3,

                              -3,-2,-1, 0, 1, 2, 3,

                              -3,-2,-1, 0, 1, 2, 3,

                              -2,-1, 0, 1, 2,

                              -1, 0, 1 };

 

       int OffSetY[37] = { -3,-3,-3,

                              -2,-2,-2,-2,-2,

                              -1,-1,-1,-1,-1,-1,-1,

                               0, 0, 0, 0, 0, 0, 0,

                               1, 1, 1, 1, 1, 1, 1,

                               2, 2, 2, 2, 2,

                               3, 3, 3 };

 

       int mHeight = img.rows;

       int mWidth = img.cols;

       unsigned char *ucDataImg = (unsigned char *)img.data;

       Mat nImg(img.rows,img.cols,CV_8UC1);

       unsigned char *ucDatanImg = (unsigned char *)nImg.data;

 

       int k,pixelSum,thresh,sameNum;

       for(int i=3;i<mHeight-3;i++)

       {

              for (int j=3;j<mWidth-3;j++)

              {

                     pixelSum = 0;

                     sameNum = 0;

                     for (k=0;k<37;k++)

                     {

                            pixelSum += ucDataImg[(i+OffSetY[k])*mWidth+(j+OffSetX[k])];

                           // thresh = pixelSum/37;//数量
                            thresh = 25;

                            if (abs(ucDataImg[(i+OffSetY[k])*mWidth+(j+OffSetX[k])]-ucDataImg[i*mWidth+j])<=thresh)

                            {

                                   sameNum ++;

                            }

                     }

 

                     if (sameNum<33)//质量34

                     {

                            ucDatanImg[i*mWidth+j] = 0;

                     }

                     else

                     {

                            ucDatanImg[i*mWidth+j] = 255;

                     }

              }

       }

       return nImg;
}

