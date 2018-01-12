#include <C:\Dev\ArUco\include\aruco\aruco.h>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\calib3d\calib3d.hpp>
#include <iostream>

using namespace cv;
using namespace std;
#define ESC_KEY 27
char key = 'a';

int cameraasked;

int main(){
	VideoCapture cap;
	cout<<"Quel numero de camera? ou -1 pour arreter"<<endl;
	cin>>cameraasked;
	if(cameraasked>=0){
		cap.open(cameraasked);
	}else{
		return EXIT_SUCCESS;
	}
	
	if(!cap.isOpened()){
		cout << "Erreur lors de la lecture de la video "<< endl;
		return EXIT_FAILURE;
	}
	string windowName	=	"aruco";
	namedWindow(windowName,	CV_WINDOW_AUTOSIZE);
	Mat image;

	while(key != ESC_KEY) {
		cap>>image;
		// creation d’un detecteur de marqueurs
		aruco::MarkerDetector myDetector ;
		//liste de marqueurs : sera remplie par ArUco
		vector<aruco::Marker> markers ;
		//detection
		myDetector.detect(image, markers) ;
		//on affiche le resultat de la detection sur une image
		for (unsigned int i =0; i<markers.size(); i++) {
			cout<<markers [i] ;
			markers[i].draw(image, Scalar(0, 0, 255), 2);
		}
		imshow(windowName, image);
		key = waitKey(1);
	}

	return 0;
}