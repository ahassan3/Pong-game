//
//  DrawPolygons.h
//  Lab-DrawPolygons
//
//  Created by Aimen Hassan on 01/23/2016
//	

#ifndef DrawPolygons_hpp
#define DrawPolygons_hpp

#include "ShaderProgram.h"
#include "GLFWBase.h"
#include <vector>
#include "Angel.h"

class DrawPolygons : public GLFWBase {

public:
	DrawPolygons(GLFWwindow* window);
	~DrawPolygons();

	// override the render method
	virtual void render();

	// override the keyboard callback
	virtual void keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

	virtual void windowSizeCallback(GLFWwindow *window, int width, int height);

	void reset();

	// new method to initalize the data
	void setup();

private:
	void dealloc();

	// width and height of window
	int _windowWidth, _windowHeight;

	ShaderProgram _shaderProgram;

	std::vector<int> _speed;
	// type for how to draw the data
	GLenum _drawType;


	// buffer IDs
	GLuint _buffers[4];

	// data for polygon 0
	GLfloat _poly0[20];

	// data for polygon 1
	GLfloat _poly1[20];

	// data for polygon 2
	GLfloat _poly2[20];

	// data for paddle
	GLfloat _paddle[8];

	// data for ball
	GLfloat _ball[8];

	// values to increament or decremant the values of the ball
	GLfloat _changeX;
	GLfloat _changeY;

	// boolean for the game state
	bool _mood;

	bool _never = GL_TRUE;
	//boolean to move up the paddle
	bool _moveup;
	// boolean to move down
	bool _movedown;

	// boolean to change the x and y-values only once
	bool _start;

	bool _twoPlayers;

	bool _moveup2;

	bool _movedown2;

	// declare copy constructor and operator= private but do not implement
	DrawPolygons(const DrawPolygons &src);
	DrawPolygons& operator=(const DrawPolygons & src);
};

#endif /* DrawPolygons_hpp */#pragma once
