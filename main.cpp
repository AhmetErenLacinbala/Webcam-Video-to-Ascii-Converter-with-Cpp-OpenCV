//Webcam video to ascii project.
//Made by Ahmet Eren Laçinbala in 06.10.2021

#include <opencv2/core/core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main() {


	char ascii_char[71] = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/|()1{}[]?-_+~<>i!lI;:,\"^`'. ";
	float parameter = 257 / 69;
	string ascii = "";
	VideoCapture cap(1);
	Mat frame;
	Mat resizedImage;
	Mat greyMat;

	while (true)
	{

		cap.read(frame);
		resize(frame, resizedImage, Size(128, 72));
		cvtColor(resizedImage, greyMat, COLOR_BGR2GRAY);
		imshow("camera", frame);
		
		for (int i = 1; i < greyMat.rows - 1 ; i++) {
			for (int j = 1; j < greyMat.cols - 1; j++) {
				
				
				ascii += ascii_char[int((greyMat.at<uint8_t>(i, j)) / parameter)];
			}
			ascii += "\n";
		}
		for (int i = 0; i < 71; i++) cout << "\n";
		cout << ascii;
		ascii = "";

		if (waitKey(30) == 27) {
			return 0;
		}
	}

}
