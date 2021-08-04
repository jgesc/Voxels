#include "Crosshair.hpp"

Crosshair::Crosshair()
{
  float vertices[] = {
    0.0f,  0.02f, 0.0f,
    0.02f, -0.02f, 0.0f,
    -0.02f, -0.02f, 0.0f
  };

  glGenBuffers(1, &this->VBO);
  glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  unsigned int VAO;
  glGenVertexArrays(1, &(this->VAO));
  glBindVertexArray(this->VAO);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
}

void Crosshair::render()
{
  glClear(GL_DEPTH_BUFFER_BIT);

  glEnable(GL_BLEND);
  glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ZERO);
  ShaderStore::I->userInterface.use();
  glBindVertexArray(this->VAO);
  glDrawArrays(GL_TRIANGLES, 0, 3);
  glDisable(GL_BLEND);
}
