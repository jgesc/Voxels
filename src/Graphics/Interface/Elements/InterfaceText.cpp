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

void InterfaceText::setText(std::string text)
{
  this->text = Text(text);
  this->regenerateVBO();
}

void InterfaceText::regenerateVBO()
{
  // Update buffer
  std::vector<float> vertices = text.generateVertexInfo(2.0, -0.975, 0.925);
  glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
  this->vertexCount = vertices.size() / 4;
}

void InterfaceText::render()
{
  // Bind atlas texture
  TextureStore::getInstance()->fontAtlas.bind();
  // Bind interface element VAO
  glBindVertexArray(this->VAO);
  // Bind shader
  ShaderStore::I->textShader.use();
  // Draw vertices
  glDrawArrays(GL_TRIANGLES, 0, this->vertexCount);
}
