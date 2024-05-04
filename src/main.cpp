#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    // Open the default camera
    VideoCapture cap(0);
    if (!cap.isOpened()) {
        cerr << "Error: Unable to open the webcam" << endl;
        return -1;
    }

    // Capture a frame from the camera
    Mat frame;
    cap >> frame;
    if (frame.empty()) {
        cerr << "Error: Unable to capture frame" << endl;
        return -1;
    }

    // Save the captured frame as an image
    string filename = "captured_image.jpg";
    imwrite(filename, frame);
    cout << "Image captured and saved as " << filename << endl;

    // Release the camera
    cap.release();

    return 0;
}
