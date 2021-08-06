#include "Crosshair.hpp"

Crosshair::Crosshair()
{
  float vertices[] = {
     0.0f / 800,   20.0f / 600,
     0.0f / 800,  -20.0f / 600,
     20.0f / 800,   0.0f / 600,
    -20.0f / 800,   0.0f / 600
  };

  glGenBuffers(1, &this->VBO);
  glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  glGenVertexArrays(1, &(this->VAO));
  glBindVertexArray(this->VAO);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
}

void Crosshair::render()
{
  glClear(GL_DEPTH_BUFFER_BIT);

  glEnable(GL_BLEND);
  glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ZERO);
  ShaderStore::I->userInterface.use();
  glBindVertexArray(this->VAO);
  glLineWidth(4.0);
  glDrawArrays(GL_LINES, 0, 4);
  glDisable(GL_BLEND);
}
