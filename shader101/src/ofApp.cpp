#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	shader.load("shader/shaderInterac");
	float planeScale = 0.75;
	int planeWidth = ofGetWidth()*planeScale;
	int planeHeight = ofGetHeight()*planeScale;
	int planeGridSize = 20;
	int planeColumns = planeWidth / planeGridSize;
	int planeRows = planeHeight / planeGridSize;

	plane.set(planeWidth, planeHeight, planeColumns, planeRows, OF_PRIMITIVE_TRIANGLES);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	
	shader.begin();
	//center of picture
	float cX = ofGetWidth() / 2.0;
	float cY = ofGetHeight() / 2.0;
	// mouse distance from the center
	float mX = mouseX - cX;
	float mY = mouseY - cY;
	// set uniform1
	shader.setUniform1f("mouseRange", 150.0);
	// set uniform2
	shader.setUniform2f("mousePos", mX, mY);

	float percentX = mouseX / (float)ofGetWidth();
	percentX = ofClamp(percentX, 0, 1.0);
	ofFloatColor colorLeft = ofColor::yellow;
	ofFloatColor colorRight = ofColor::red;
	ofFloatColor colorMix = colorLeft.getLerped(colorRight, percentX);
	
	float mouseColor[4] = {colorMix.r,colorMix.g ,colorMix.b ,colorMix.a};
	
	shader.setUniform4fv("mouseColor", &mouseColor[0]);

	ofTranslate(cX, cY);

	plane.drawWireframe();
	shader.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
