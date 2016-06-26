#version 130

// Input data from the vertex buffer object : each vertex is 2 floats vector
in vec2 vertexPosition;

void main()
{
	// Set the x, y, z position on the screen
	gl_Position.xy = vertexPosition;
	gl_Position.z = 0;
	
	// Indicate that the coordinates are normalized
	gl_Position.w = 1.0;
}