#include <opencv2/opencv.hpp>
#include "BMP.h"
#define ll long long
using namespace cv;

int main()
{
    ll colorx=0,colory=0,c=0;
    VideoCapture cap;
    if (!cap.open(0)) return 0;
    Mat frame;
    cap>>frame;
    imwrite("image.bmp",frame);
    BMP bmp("image.bmp");
    vector<uint8_t> data=bmp.getdata().first;
    int w=bmp.bmp_info_header.width,h=bmp.bmp_info_header.height;
    for (int i=0;i<h;i++)
    {
        for (int j=0;j<w;j++)
        {
            int r=data[3*(i*w+j)+2],g=data[3*(i*w+j)+1],b=data[3*(i*w+j)];
            if (r>200 && g<100 && b<100)
            {
                colorx+=j;
                colory+=i;
                c++;
            }
        }
    }
    if (c==0) cout<<"NO RED COLOR DETECTED"<<endl;
    else
    {
        colorx/=c;
        colory/=c;
        cout<<colorx<<" "<<colory<<endl;
    }
    return 0;
}
