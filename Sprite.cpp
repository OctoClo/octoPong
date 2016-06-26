#include "Sprite.h"

Sprite::Sprite() :
    vertexBufferObjectID(0)
{

}

Sprite::~Sprite()
{
    // Delete the buffer if it has not been deleted yet
    if (!this->vertexBufferObjectID)
        glDeleteBuffers(1, &this->vertexBufferObjectID);
}

void Sprite::init(float newX, float newY, float newWidth, float newHeight)
{
    this->x = newX;
    this->y = newY;
    this->width = newWidth;
    this->height = newHeight;

    // Generate the buffer if it has not been generated yet
    if (!this->vertexBufferObjectID)
        glGenBuffers(1, &this->vertexBufferObjectID);

    // Array of vertexes
    float vertexData[12];

    // *** First triangle ***
    // Top-left corner
    vertexData[0] = this->x;
    vertexData[1] = this->y;

    // Top-right corner
    vertexData[2] = this->x + this->width;
    vertexData[3] = this->y;

    // Bottom-left corner
    vertexData[4] = this->x;
    vertexData[5] = this->y + this->height;

    // *** Second triangle ***
    // Top-right corner
    vertexData[6] = this->x + this->width;
    vertexData[7] = this->y;

    // Bottom-right corner
    vertexData[8] = this->x + this->width;
    vertexData[9] = this->y + this->height;

    // Bottom-left corner
    vertexData[10] = this->x;
    vertexData[11] = this->y + this->height;

    // Bind the buffer (activate it)
    glBindBuffer(GL_ARRAY_BUFFER, this->vertexBufferObjectID);

        // Upload the buffer on the GPU
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

    // Unbind the buffer
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Sprite::draw()
{
    // Bind the buffer (activate it)
    glBindBuffer(GL_ARRAY_BUFFER, this->vertexBufferObjectID);

        // Indicate we use only one attribute to draw the buffer : its position (no color, no lighting...)
        glEnableVertexAttribArray(0);

            // Indicate what to draw (entire buffer)
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

            // Draw the data
            glDrawArrays(GL_TRIANGLES, 0, 6);

        // Disable the attribute
        glDisableVertexAttribArray(0);

    // Unbind the buffer
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
