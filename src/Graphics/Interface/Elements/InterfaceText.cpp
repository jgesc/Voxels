#include "InterfaceText.hpp"

InterfaceText::InterfaceText(Text text) : text(text)
{
  glGenBuffers(1, &this->VBO);
  glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
  std::vector<float> vertices = text.generateVertexInfo(4.0, -0.95, 0.85);
  this->vertexCount = vertices.size() / 4;
  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
  glGenVertexArrays(1, &(this->VAO));
  glBindVertexArray(this->VAO);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
  glEnableVertexAttribArray(1);
};

void InterfaceText::render()
{
  TextureStore::getInstance()->fontAtlas.bind();
  glBindVertexArray(this->VAO);
  ShaderStore::I->textShader.use();
  glDrawArrays(GL_TRIANGLES, 0, this->vertexCount);
}
