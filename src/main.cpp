#include <opencv2/opencv.hpp>
#include <iostream>
#include <netinet/in.h> 
#include <sys/socket.h> 
#include <unistd.h> 

// using namespace cv;
using namespace std;

int main() {
    cout << "initializing socket\n";
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    cout << "defining server addrs\n";
    // define server addrs
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    cout << "binding socket\n";
    // binding socket
    bind(serverSocket, (struct sockaddr*)& serverAddress, sizeof(serverAddress));

    cout << "listing for connection\n";
    // listen
    listen(serverSocket, 5);

    cout << "binding to connection\n";
    // accept connection request
    int clientSocket = accept(serverSocket, nullptr, nullptr);

    /*
    cout << "receiving data\n";
    // receiving data
    char buffer[1024] = { 0 };
    recv(clientSocket, buffer, sizeof(buffer), 0);
    cout << "Message from client: " << buffer << endl;

    cout << "closing socket\n";
    // close the socket
    close(serverSocket);

    return 0;
    */


    /*
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
    */
}
