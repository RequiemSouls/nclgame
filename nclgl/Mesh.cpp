#include "Mesh.h"


Mesh::Mesh()
{
	for (int bufferIndex = 0; bufferIndex < MAX_BUFFER; bufferIndex++) {
		bufferObject[bufferIndex] = 0;
	}

	glGenVertexArrays(1, &arrayObject);

	numVertices = 0;
	type = GL_TRIANGLES;
	vertices = NULL;
	colours = NULL;
}


Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &arrayObject);
	glDeleteBuffers(MAX_BUFFER, bufferObject);
	delete[]vertices;
	delete[]colours;
}

void Mesh::Draw() {
	glBindVertexArray(arrayObject);
	glDrawArrays(type, 0, numVertices);
	glBindVertexArray(0);
}

Mesh* Mesh::GenerateTriangle() {
	Mesh* mesh = new Mesh();
	mesh->numVertices = 3;
	mesh->vertices = new Vector3[mesh->numVertices];
	mesh->vertices[0] = Vector3(-0.5, -0.5, 0.0);
	mesh->vertices[1] = Vector3(0.5, -0.5, 0.0);
	mesh->vertices[2] = Vector3(0.0, 0.36, 0.0);

	mesh->colours = new Vector4[mesh->numVertices];
	mesh->colours[0] = Vector4(1.0, 0.0, 0.0, 1.0);
	mesh->colours[1] = Vector4(0.0, 1.0, 0.0, 1.0);
	mesh->colours[2] = Vector4(0.0, 0.0, 1.0, 1.0);

	mesh->BufferData();

	return mesh;
}

void Mesh::BufferData() {
	glBindVertexArray(arrayObject);
	glGenBuffers(1, &bufferObject[VERTEX_BUFFER]);
	glBindBuffer(GL_ARRAY_BUFFER, bufferObject[VERTEX_BUFFER]);
	glBufferData(GL_ARRAY_BUFFER, numVertices*sizeof(Vector3), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(VERTEX_BUFFER, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(VERTEX_BUFFER);

	if (colours) {
		glGenBuffers(1, &bufferObject[COLOUR_BUFFER]);
		glBindBuffer(GL_ARRAY_BUFFER, bufferObject[COLOUR_BUFFER]);
		glBufferData(GL_ARRAY_BUFFER, numVertices*sizeof(Vector4), colours, GL_STATIC_DRAW);
		glVertexAttribPointer(COLOUR_BUFFER, 4, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(COLOUR_BUFFER);
	}

	glBindVertexArray(0);
}
