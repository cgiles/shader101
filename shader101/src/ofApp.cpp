#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	shader.load("shader/shaderPlane");
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
	float percentX = mouseX / (float)ofGetWidth();
	percentX = ofClamp(percentX, 0.0, 1.0);
	ofColor colorLeft = ofColor::magenta;
	ofColor colorRight = ofColor::cyan;
	ofColor colorMix = colorLeft.getLerped(colorRight, percentX);
	

	ofSetColor(colorMix);
	
	shader.begin();
	shader.setUniform1f("time", ofGetElapsedTimef());
	float tx = ofGetWidth() / 2;
	float ty = ofGetHeight() / 2;
	float percentY = mouseY / (float)ofGetHeight();
	float rotation = ofMap(percentY, 0.0, 1.0, -60, 60) + 60;
	ofTranslate(tx, ty);
	ofRotate(rotation, 1, 0, 0);

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
