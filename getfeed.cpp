//Gets the live stream and then writes it to an avi file until user hits Esc

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>

using namespace std;
using namespace cv;


int main(){

VideoCapture cap(0);
cv::VideoWriter writer;

    if(!cap.isOpened())                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }
char* windowName="Webcam Feed";
    namedWindow( "windowName", CV_WINDOW_AUTOSIZE );// Create a window for display.
string filename="MyVideo.avi";

int fcc = CV_FOURCC('D','I','V','3');
int fps=7;

cv::Size frameSize(cap.get(CV_CAP_PROP_FRAME_WIDTH),cap.get(CV_CAP_PROP_FRAME_HEIGHT));
writer =VideoWriter(filename,fcc,fps,frameSize);
if(!writer.isOpened()){
cout<<"Error while opening for write"<<endl;
waitKey(0);
return -1;
}

Mat frame; 
while(1){
bool bSuccess=cap.read(frame);
if (!bSuccess){
cout<<"Error reading frame from camera"<<endl;
 break;
}
writer.write(frame);
imshow(windowName,frame);

switch(waitKey(1)){
case 27:
return 0;
}
}
return 0;
}
