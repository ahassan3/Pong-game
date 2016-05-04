//
//  DrawPolygons.cpp
//  Lab1-DrawPolygons
//
//  Created by Aimen Hassan on 02/07/2016
//

#include <cstdlib>

#include <GL/glew.h>

#ifndef __APPLE__
#include <GL/freeglut.h>
#endif

#include <GLFW/glfw3.h>

#include "Lab6.h"

#include <string>
#include "Angel.h"

#include "Utils.h"
#include "Lab6.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using std::vector;
using std::ifstream;
using std::istringstream;
using std::string;
using std::cout;
using std::cin;
using std::cerr;
using std::endl;

//----------------------------------------------------------------------

// must initlaize GLFWBase with window parameter
DrawPolygons::DrawPolygons(GLFWwindow* window) : GLFWBase(window)
{
	glfwGetWindowSize(window, &_windowWidth, &_windowHeight);
}

//----------------------------------------------------------------------

DrawPolygons::~DrawPolygons()
{
	dealloc();
}

//----------------------------------------------------------------------

void DrawPolygons::dealloc()
{
	if (_buffers) {
		glDeleteBuffers(5, _buffers);
		delete[] _buffers;
	}
}

//----------------------------------------------------------------------

void DrawPolygons::setup()
{
// black background
glClearColor(0.0, 0.0, 0.0, 1.0);
// default draw as filled triangles
_drawType = GL_TRIANGLE_FAN;

// set point size to 5 so easy to see
glPointSize(5);

// initiallize pos variable
size_t pos;

// call srand function
srand(NULL);

// initialize points for triangle 0

// initialize points for triangle 1
pos = 0;

// specify x, y, r, g, b for each point
// point 0
_poly1[pos++] = -1.0;
_poly1[pos++] = -1.0;
_poly1[pos++] = 1.0;
_poly1[pos++] = 0;
_poly1[pos++] = 0;

// point 1
_poly1[pos++] = 1.0;
_poly1[pos++] = -1.0;
_poly1[pos++] = 1.0;
_poly1[pos++] = 0;
_poly1[pos++] = 0;

// point 2
_poly1[pos++] = 1.0;
_poly1[pos++] = -0.99;
_poly1[pos++] = 1.0;
_poly1[pos++] = 0;
_poly1[pos++] = 0;


// points 3
_poly1[pos++] = -1.0;
_poly1[pos++] = -0.99;
_poly1[pos++] = 1.0;
_poly1[pos++] = 0;
_poly1[pos++] = 0;

// initialize points for triangle 2
pos = 0;

// specify x, y, r, g, b for each point
// point 0
_poly2[pos++] = 1.0;
_poly2[pos++] = 1.0;
_poly2[pos++] = 1.0;
_poly2[pos++] = 0;
_poly2[pos++] = 0;

// point 1
_poly2[pos++] = -1.0;
_poly2[pos++] = 1.0;
_poly2[pos++] = 1.0;
_poly2[pos++] = 0;
_poly2[pos++] = 0;

// point 2
_poly2[pos++] = -1.0;
_poly2[pos++] = 0.99;
_poly2[pos++] = 1.0;
_poly2[pos++] = 0;
_poly2[pos++] = 0;


// points 3
_poly2[pos++] = 1.0;
_poly2[pos++] = 0.99;
_poly2[pos++] = 1.0;
_poly2[pos++] = 0;
_poly2[pos++] = 0;


// paddle coordinates

// point 0
pos = 0;
_paddle[pos++] = .99;
_paddle[pos++] = .125;
_paddle[pos++] = .99;
_paddle[pos++] = -.125;
_paddle[pos++] = 1.0;
_paddle[pos++] = -.125;
_paddle[pos++] = 1.0;
_paddle[pos++] = .125;

// ball
pos = 0;
_ball[pos++] = -.85;
_ball[pos++] = .01;

// point 1
_ball[pos++] = -.85;
_ball[pos++] = -.01;


// point 2
_ball[pos++] = -.84;
_ball[pos++] = -.01;


// points 3
_ball[pos++] = -.84;
_ball[pos++] = .01;

pos = 0;
// specify x, y, r, g, b for each point
// point 0
_poly0[pos++] = -.99;
_poly0[pos++] = .125;
_poly0[pos++] = 1.0;
_poly0[pos++] = 0.0;
_poly0[pos++] = 0.0;

// point 1
_poly0[pos++] = -1.0;
_poly0[pos++] = .125;
_poly0[pos++] = 1.0;
_poly0[pos++] = 0.0;
_poly0[pos++] = 0.0;

// point 2
_poly0[pos++] = -1.0;
_poly0[pos++] = -.125;
_poly0[pos++] = 1.0;
_poly0[pos++] = 0.0;
_poly0[pos++] = 0.0;

// point 3
_poly0[pos++] = -0.99;
_poly0[pos++] = -.125;
_poly0[pos++] = 1.0;
_poly0[pos++] = 0.0;
_poly0[pos++] = 0.0;





// Create and initialize a buffer object
// (cache data in graphics card memory
glGenBuffers(1, &_buffers[0]);
glBindBuffer(GL_ARRAY_BUFFER, _buffers[0]);
glBufferData(GL_ARRAY_BUFFER, 20 * sizeof(GLfloat), _poly0, GL_STATIC_DRAW);

// Create and initialize a buffer object
// (cache data in graphics card memory)
glGenBuffers(1, &_buffers[1]);
glBindBuffer(GL_ARRAY_BUFFER, _buffers[1]);
glBufferData(GL_ARRAY_BUFFER, 20 * sizeof(GLfloat), _poly1, GL_STATIC_DRAW);

// Create and initialize a buffer object
// (cache data in graphics card memory)
glGenBuffers(1, &_buffers[2]);
glBindBuffer(GL_ARRAY_BUFFER, _buffers[2]);
glBufferData(GL_ARRAY_BUFFER, 20 * sizeof(GLfloat), _poly2, GL_STATIC_DRAW);

// Create and initialize a buffer object for paddle
glGenBuffers(1, &_buffers[3]);
glBindBuffer(GL_ARRAY_BUFFER, _buffers[3]);
glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(GLfloat), _paddle, GL_STATIC_DRAW);

// Create and initialize a buffer object for ball
glGenBuffers(1, &_buffers[4]);
glBindBuffer(GL_ARRAY_BUFFER, _buffers[4]);
glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(GLfloat), _ball, GL_STATIC_DRAW);


// read and compile shaders
string vshaderPath = "vshader.txt";
string fshaderPath = "fshader.txt";
vshaderPath = pathUsingEnvironmentVariable(vshaderPath, "GL_SHADER_DIR");
fshaderPath = pathUsingEnvironmentVariable(fshaderPath, "GL_SHADER_DIR");
_shaderProgram.makeProgramFromShaderFiles(vshaderPath, fshaderPath);
_shaderProgram.useProgram();
}

//----------------------------------------------------------------------

void DrawPolygons::reset() {
	// paddle coordinates

	// point 0
	int pos = 0;
	_paddle[pos++] = .99;
	_paddle[pos++] = .125;
	_paddle[pos++] = .99;
	_paddle[pos++] = -.125;
	_paddle[pos++] = 1.0;
	_paddle[pos++] = -.125;
	_paddle[pos++] = 1.0;
	_paddle[pos++] = .125;

	// ball
	pos = 0;
	_ball[pos++] = -.85;
	_ball[pos++] = .01;

	// point 1
	_ball[pos++] = -.85;
	_ball[pos++] = -.01;


	// point 2
	_ball[pos++] = -.84;
	_ball[pos++] = -.01;


	// points 3
	_ball[pos++] = -.84;
	_ball[pos++] = .01;

	// initialize points for triangle 0
	pos = 0;
	// specify x, y, r, g, b for each point
	// point 0
	_poly0[pos++] = -1.0;
	_poly0[pos++] = .125;
	_poly0[pos++] = 1.0;
	_poly0[pos++] = 0.0;
	_poly0[pos++] = 0.0;

	// point 1
	_poly0[pos++] = -1.0;
	_poly0[pos++] = -.125;
	_poly0[pos++] = 1.0;
	_poly0[pos++] = 0.0;
	_poly0[pos++] = 0.0;

	// point 2
	_poly0[pos++] = -0.99;
	_poly0[pos++] = -.125;
	_poly0[pos++] = 1.0;
	_poly0[pos++] = 0.0;
	_poly0[pos++] = 0.0;

	// point 3
	_poly0[pos++] = -0.99;
	_poly0[pos++] = .125;
	_poly0[pos++] = 1.0;
	_poly0[pos++] = 0.0;
	_poly0[pos++] = 0.0;

	
	glBindBuffer(GL_ARRAY_BUFFER, _buffers[3]);
	glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(GLfloat), _paddle, GL_STATIC_DRAW);

	
	glBindBuffer(GL_ARRAY_BUFFER, _buffers[4]);
	glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(GLfloat), _ball, GL_STATIC_DRAW);

	// Create and initialize a buffer object
	// (cache data in graphics card memory)
	
	glBindBuffer(GL_ARRAY_BUFFER, _buffers[0]);
	glBufferData(GL_ARRAY_BUFFER, 20 * sizeof(GLfloat), _poly0, GL_STATIC_DRAW);

}
void DrawPolygons::render()
{
	// clear the window
	glClear(GL_COLOR_BUFFER_BIT);
	// if the game is in session
	if (_mood) 
	{
		// if the ball hits the top or bottom walls
		if (_ball[1] >= .99 || _ball[1] <= -.99)
		{
			// change the direction of the ball to go down
			_changeY = _changeY * -1;
		}
		// if the ball hits the left paddle
		if ((_ball[0] <= -1.0) && ((_poly0[16] >= _ball[1]) && (_ball[5] >= _poly0[11])))
		{
			//change the x direction of the ball
			_changeX *= -1;
		}
		// if the oppenet misses the ball
		if (_ball[0] > -1.0 && (_poly0[16] < _ball[3])) {
			_moveup = GL_FALSE;
			_movedown2 = GL_FALSE;
			_moveup2 = GL_FALSE;
			// change move down variable to false
			_movedown = GL_FALSE;
			// call reset function to bring back the ball and paddle to their original position
			reset();
			// set mood to false since the game ended
			_mood = FALSE;
		}
		if (_ball[0] > -1.0 && (_poly0[11] > _ball[1])) {
			_moveup = GL_FALSE;
			_movedown2 = GL_FALSE;
			_moveup2 = GL_FALSE;
			// change move down variable to false
			_movedown = GL_FALSE;
			// call reset function to bring back the ball and paddle to their original position
			reset();
			// set mood to false since the game ended
			_mood = FALSE;
		}
		// if the ball hits the paddle
		if ((_ball[4] >= _paddle[0]) && (_paddle[1] >= _ball[5]) && (_ball[5] >= _paddle[3]) )
		{
			_changeX *= -1;
		}
		// if the paddle misses the ball from the top
		if (_ball[4] > 1 && (_paddle[1] < _ball[7])) {
			// change move up variable to false
			_moveup = GL_FALSE;
			_movedown2 = GL_FALSE;
			_moveup2 = GL_FALSE;
			// change move down variable to false
			_movedown = GL_FALSE;
			// call reset function to bring back the ball and paddle to their original position
			reset();
			// set mood to false since the game ended
			_mood = FALSE;
		}
		// if the paddle misses the ball from the bottom
		if (_ball[4] > 1 && (_paddle[3] > _paddle[1])) {
			_moveup = GL_FALSE;
			_movedown2 = GL_FALSE;
			_moveup2 = GL_FALSE;
			_movedown = GL_FALSE;
			reset();
			_mood = FALSE;
		}
		// if we are moving up the paddle
		if (_moveup) 
		{
			// if the paddle isnt touching the top
			if (_paddle[1] < .99) 
			{
				// increment the y values of the points
				_paddle[1] += (abs(_changeY) + abs(_changeX)) / 2;
				_paddle[3] += (abs(_changeY) + abs(_changeX)) / 2;
				_paddle[5] += (abs(_changeY) + abs(_changeX)) / 2;
				_paddle[7] += (abs(_changeY) + abs(_changeX)) / 2;
				
			}
		}
		// if we are moving down
		if (_movedown)
		{
			// as long as the bottom of the paddle isnt touching the bottom
			if (_paddle[3] > -.99) 
			{
				// decrement the y-values of the polygon
				_paddle[1] += -(abs(_changeY) + abs(_changeX)) / 2;
				_paddle[3] += -(abs(_changeY) + abs(_changeX)) / 2;
				_paddle[5] += -(abs(_changeY) + abs(_changeX)) / 2;
				_paddle[7] += -(abs(_changeY) + abs(_changeX)) / 2;
			}
		}


		if (_twoPlayers) {

			if (_moveup2)
			{
				// if the paddle isnt touching the top
				if (_poly0[1] < .99)
				{
					// increment the y values of the points
					_poly0[1] += (abs(_changeY) + abs(_changeX)) / 2;
					_poly0[6] += (abs(_changeY) + abs(_changeX)) / 2;
					_poly0[11] += (abs(_changeY) + abs(_changeX)) / 2;
					_poly0[16] += (abs(_changeY) + abs(_changeX)) / 2;

				}
			}
			// if we are moving down
			if (_movedown2)
			{
				// as long as the bottom of the paddle isnt touching the bottom
				if (_poly0[3] > -.99)
				{
					// decrement the y-values of the polygon
					_poly0[1] += -(abs(_changeY) + abs(_changeX)) / 2;
					_poly0[6] += -(abs(_changeY) + abs(_changeX)) / 2;
					_poly0[11] += -(abs(_changeY) + abs(_changeX)) / 2;
					_poly0[16] += -(abs(_changeY) + abs(_changeX)) / 2;
				}
			}
		}
		// if the game is in session
		if (_mood) {
			// increment the x and y-values of the ball by our change variable
			int pos = 0;
			// this will occur 95% of the time
			if (rand() % 100 < 95   &&  _twoPlayers != GL_TRUE){

				// specify x, y, r, g, b for each point
				// point 0
				_poly0[pos++] = -1.0;
				_poly0[pos++] += _changeY;
				_poly0[pos++] = 1.0;
				_poly0[pos++] = 0.0;
				_poly0[pos++] = 0.0;

				// point 1
				_poly0[pos++] = -1.0;
				_poly0[pos++] += _changeY;
				_poly0[pos++] = 1.0;
				_poly0[pos++] = 0.0;
				_poly0[pos++] = 0.0;

				// point 2
				_poly0[pos++] = -0.99;
				_poly0[pos++] += _changeY;
				_poly0[pos++] = 1.0;
				_poly0[pos++] = 0.0;
				_poly0[pos++] = 0.0;

				// point 3
				_poly0[pos++] = -0.99;
				_poly0[pos++] += _changeY;
				_poly0[pos++] = 1.0;
				_poly0[pos++] = 0.0;
				_poly0[pos++] = 0.0;
			}
			pos = 0;
			// point 0
			_ball[pos++] += _changeX;
			_ball[pos++] += _changeY;

			// point 1
			_ball[pos++] += _changeX;
			_ball[pos++] += _changeY;


			// point 2
			_ball[pos++] += _changeX;
			_ball[pos++] += _changeY;


			// points 3
			_ball[pos++] += _changeX;
			_ball[pos++] += _changeY;
		}

	}


	// layout value for vPosition
	glEnableVertexAttribArray(0);
	// layout value for vColor
	glEnableVertexAttribArray(1);

	// buffer for first triangle
	glBindBuffer(GL_ARRAY_BUFFER, _buffers[0]);
	glBufferData(GL_ARRAY_BUFFER, 20 * sizeof(GLfloat), _poly0, GL_STATIC_DRAW);

	// specify the actual vertex data from the buffer
	// first parameter is 0 because the layout value for vPosition in the vertex shader is 0
	// second and third parameters are 2 and GL_FLOAT because there are two values (x, y) per pixel that are floats
	// fourth parameter is GL_FALSE since the values are not normalized
	// fifth parameter is the number of bytes (stride) to get to the next vertex
	//   it is 5 * sizeof(GLfloat) since there are 5 (x, y, r, g, b) float values per pixel
	// sixth parameter is 0 bytes since since first value in array is the x coordinate
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), BUFFER_OFFSET(0));

	// note: the shader does not actually use this data but just showing how to pass additional information

	// specify the actual vertex data from the buffer
	// first parameter is 1 because the layout value for vColor in the vertex shader is 1
	// second and third parameters are 3 and GL_FLOAT because there are three values (r, g, b) per pixel that are floats
	// fourth parameter is GL_FALSE since the values are not normalized
	// fifth parameter is the number of bytes (stride) to get to the next vertex
	//   it is 5 * sizeof(GLfloat) since there are 5 (x, y, r, g, b) float values per pixel
	// sixth parameter is 2 * sizeof(GLfloat) bytes since since need to move past x, y values to get to r, g, b value
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), BUFFER_OFFSET(2 * sizeof(GLfloat)));

	GLint polyColorLocation;

	// get location for communicating polyColor
	polyColorLocation = glGetUniformLocation(_shaderProgram.program(), "polyColor");
	// draw polygon red
	glUniform3f(polyColorLocation, 1.0, 0.0, 0.0);

	// draw the buffer for the first triangle
	glDrawArrays(_drawType, 0, 4);


	//---------------------------------------------------------------------------


	// draw the second the floor
	// switch to buffer for second triangle
	glBindBuffer(GL_ARRAY_BUFFER, _buffers[1]);

	// after glBindBuffer, must call glVertexAttribPointer again
	// see comments for above calls for meaning of parameters
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), BUFFER_OFFSET(0));
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), BUFFER_OFFSET(2 * sizeof(GLfloat)));

	//polyColorLocation = glGetUniformLocation(_shaderProgram.program(), "polyColor");
	// draw polygon blue
	glUniform3f(polyColorLocation, 1.0, 0.0, 0.0);

	// draw using the buffer for the second triangle
	glDrawArrays(_drawType, 0, 4);

	//-----------------------------------------------------------------------


	// draw the third triangle
	// switch to buffer for second triangle
	glBindBuffer(GL_ARRAY_BUFFER, _buffers[2]);

	// after glBindBuffer, must call glVertexAttribPointer again
	// see comments for above calls for meaning of parameters
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), BUFFER_OFFSET(0));
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), BUFFER_OFFSET(2 * sizeof(GLfloat)));

	//polyColorLocation = glGetUniformLocation(_shaderProgram.program(), "polyColor");
	// draw polygon blue
	glUniform3f(polyColorLocation, 1.0, 0.0, 0.0);

	// draw using the buffer for the second triangle
	glDrawArrays(_drawType, 0, 4);


	//-----------------------------------------------------------------------

	// draw the fourt triangle fan
	// switch to buffer for second triangle
	glBindBuffer(GL_ARRAY_BUFFER, _buffers[3]);
	glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(GLfloat), _paddle, GL_STATIC_DRAW);

	// after glBindBuffer, must call glVertexAttribPointer again
	// see comments for above calls for meaning of parameters
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), BUFFER_OFFSET(0));

	// draw polygon blue
	glUniform3f(polyColorLocation, 1.0, 0.0, 0.0);

	// draw using the buffer for the second triangle
	glDrawArrays(_drawType, 0, 4);


	//--------------------------------------------------------------
	
	// draw the ball
	// switch to buffer for second triangle
	glBindBuffer(GL_ARRAY_BUFFER, _buffers[4]);
	glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(GLfloat), _ball, GL_STATIC_DRAW);

	// after glBindBuffer, must call glVertexAttribPointer again
	// see comments for above calls for meaning of parameters
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), BUFFER_OFFSET(0));

	//polyColorLocation = glGetUniformLocation(_shaderProgram.program(), "polyColor");
	// draw polygon blue
	glUniform3f(polyColorLocation, 1.0, 0.0, 0.0);

	// draw using the buffer for the second triangle
	glDrawArrays(_drawType, 0, 4);

	// to not let the triangle to be drawn
	if (_never)
	{ 
		_mood = GL_TRUE;  
		_never = GL_FALSE;
	}

}

//----------------------------------------------------------------------

void DrawPolygons::keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	// if the game isnt in session
	if (_mood == GL_FALSE) {
		// if s key is hit
		if (key == GLFW_KEY_S && action == GLFW_PRESS) {
			// set the game checker boolean to true
			_mood = GL_TRUE;
			// check statment to make only in the beginning of the game
			_start = GL_TRUE;
		}
	}
	// if the escape or Q key is pressed, exit the appication
	if ((key == GLFW_KEY_ESCAPE || key == GLFW_KEY_Q) && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
	// if game is in session
	if (_mood) {
		// if I key is pressed
		if (key == GLFW_KEY_I && action == GLFW_PRESS) {
			// if statment to limit how much the user can seed up the game
			if (abs(_changeX) < .004 && abs(_changeY) < .004) {
				_changeX *= 2;
				_changeY *= 2;
			}
		}
		// if D key is pressed
		if (key == GLFW_KEY_D && action == GLFW_PRESS) {
			// check statment to limit how much slower the game can go
			if (abs(_changeX) > .00005 && abs(_changeY) > .00005) {
				// divide the changes by 2
				_changeX /= 2;
				_changeY /= 2;
			}
		}
		// if the start is true
		if (_start)
		{
			// get a random number
			int direction = rand();
			// if its an even number, the ball will go up (y-value will equal postive number)
			if (direction % 2 == 0) {
				_changeX = .001;
				_changeY = .001 * (rand() % 3 + 1) + .0005;
			}
			// other wise, the ball would go down (y-value is negative)
			else {
				_changeX = .001;
				_changeY = -.001 * (rand() %  + 1) + .0005;
			}
			// set start to negative  to only do this in the beginning of the game
			_start = GL_FALSE;
		}
		// if the up key is pressed, set the move up to true
		if (key == GLFW_KEY_UP && action == GLFW_PRESS) {
			_moveup = GL_TRUE;
		}
		// if the up key is released, set moveup to false
		if (key == GLFW_KEY_UP && action == GLFW_RELEASE) {
			_moveup = GL_FALSE;
		}
		// if the down key is pressed, set the movedown to true
		if (key == GLFW_KEY_DOWN && action == GLFW_PRESS) {
			_movedown = GL_TRUE;
		}
		// if the down button is released, set the movedown to false
		if (key == GLFW_KEY_DOWN && action == GLFW_RELEASE) {
			_movedown = GL_FALSE;
		}
		if (key == GLFW_KEY_2 && action == GLFW_PRESS) {
			_twoPlayers = GL_TRUE;
		}
		if (key == GLFW_KEY_W && action == GLFW_PRESS) {
			_moveup2 = GL_TRUE;
		}
		// if the up key is released, set moveup to false
		if (key == GLFW_KEY_W && action == GLFW_RELEASE) {
			_moveup2 = GL_FALSE;
		}
		// if the down key is pressed, set the movedown to true
		if (key == GLFW_KEY_X && action == GLFW_PRESS) {
			_movedown2 = GL_TRUE;
		}
		// if the down button is released, set the movedown to false
		if (key == GLFW_KEY_X && action == GLFW_RELEASE) {
			_movedown2 = GL_FALSE;
		}
	}
}

void DrawPolygons::windowSizeCallback(GLFWwindow *window, int width, int height)
{
	_windowWidth = width;
	_windowHeight = height;
	glViewport(0, 0, width, height);
}

//----------------------------------------------------------------------




//----------------------------------------------------------------------

static void errorCallback(int error, const char* description)
{
	cerr << description << endl;
	//fputs(description, stderr);
}

//----------------------------------------------------------------------

int main(int argc, const char * argv[]) {

	GLFWwindow* window;
	glfwSetErrorCallback(errorCallback);
	if (!glfwInit())
		exit(EXIT_FAILURE);

	// try to get a fairly recent version of OpenGL
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	//  create the GLFW window
	window = glfwCreateWindow(900, 600, "OpenGL Demo", NULL, NULL);
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	// set it to be the current OpenGL context
	glfwMakeContextCurrent(window);

	// Initialize GLEW
	// global variable declared in GLEW files
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		cerr << "failed to initialize GLEW\n";
		exit(EXIT_FAILURE);
	}

	// specify refresh rate (normally 1)
	glfwSwapInterval(1);

	// output some information about OpenGL version
	int major, minor, rev;
	glfwGetVersion(&major, &minor, &rev);
	fprintf(stderr, "OpenGL version received: %d.%d.%d\n", major, minor, rev);
	fprintf(stderr, "%s", glfwGetVersionString());
	cerr << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
	cerr << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
	cerr << "Vendor: " << glGetString(GL_VENDOR) << endl;
	cerr << "Renderer: " << glGetString(GL_RENDERER) << endl;
	GLint textureUnits;
	glGetIntegerv(GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS, &textureUnits);
	cerr << "Num texture units: " << textureUnits << endl;

	// create the class
	DrawPolygons *glBase = new DrawPolygons(window);
	glBase->setup();
	// and enter the run loop
	glBase->runLoop(false);
}
//----------------------------------------------------------------------