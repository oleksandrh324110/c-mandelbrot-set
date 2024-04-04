#include "vao.h"

VAO vao_create() {
  VAO self;
  glGenVertexArrays(1, &self.handle);
  return self;
}

void vao_destroy(VAO self) {
  glDeleteVertexArrays(1, &self.handle);
}

void vao_bind(VAO self) {
  glBindVertexArray(self.handle);
}

void vao_attrib(VAO self, VBO vbo, GLuint index, GLint size, GLenum type, GLsizei stride, size_t offset) {
  vao_bind(self);
  vbo_bind(vbo);

  switch (type) {
    case GL_BYTE:
    case GL_UNSIGNED_BYTE:
    case GL_SHORT:
    case GL_UNSIGNED_SHORT:
    case GL_INT:
    case GL_UNSIGNED_INT:
    case GL_INT_2_10_10_10_REV:
    case GL_UNSIGNED_INT_2_10_10_10_REV:
      glVertexAttribIPointer(index, size, type, stride, (void*)offset);
      break;
    default:
      glVertexAttribPointer(index, size, type, GL_FALSE, stride, (void*)offset);
      break;
  }
  glEnableVertexAttribArray(index);
}