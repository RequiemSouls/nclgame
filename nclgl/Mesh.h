#pragma once

#include "OGLRenderer.h"

enum MESH_BUFFERS {
	VERTEX_BUFFER, COLOUR_BUFFER, MAX_BUFFER
};

class Mesh
{
public:
	Mesh();
	~Mesh();

	virtual void Draw();

	static Mesh* GenerateTriangle();

protected:
	void BufferData();

	GLuint arrayObject;
	GLuint bufferObject[MAX_BUFFER];
	int numVertices;
	GLuint type;

	Vector3* vertices;
	Vector4* colours;
};

