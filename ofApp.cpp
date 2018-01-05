#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);
	ofBackground(0);
	ofSetWindowTitle("Insta");

	this->image.loadImage("Lenna.png");
	this->font_size = 300;
	this->fbo.allocate(ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::update() {
	this->font.loadFont("fonts/Kazesawa-Bold.ttf", this->font_size , true, false, true);

	this->fbo.begin();
	ofClear(0);

	string word = "LENNA";
	int x = ofGetWidth() - ((ofGetFrameNum() * 5) % (ofGetWidth() + (int)this->font.stringWidth(word)));
	int y = ofGetHeight() / 2 + this->font.stringHeight(word) / 2;
	this->font.drawString(word, x, y);

	this->fbo.end();

	this->image.getTextureReference().setAlphaMask(this->fbo.getTexture());
}

//--------------------------------------------------------------
void ofApp::draw() {
	this->image.update();
	this->image.draw(0, 0);
}

//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(512, 512, OF_WINDOW);
	ofRunApp(new ofApp());
}
