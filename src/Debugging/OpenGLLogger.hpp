#define GL_CHECK(expr) do { expr; glCheckError(__FILE__, __LINE__, __FUNCTION__, #expr); } while (false)

void glCheckError(const char* file, unsigned int line, const char* method, const char * op)
{
  // Get the last error
  GLenum lastError = glGetError();

  if (lastError != GL_NO_ERROR) {
    std::string error = "UNDEFINED";

    switch (lastError)
    {
      case GL_INVALID_ENUM:
        error = "GL_INVALID_ENUM";
        break;

      case GL_INVALID_VALUE:
        error = "GL_INVALID_VALUE";
        break;

      case GL_INVALID_OPERATION:
        error = "GL_INVALID_OPERATION";
        break;

      case GL_STACK_OVERFLOW:
        error = "GL_STACK_OVERFLOW";
        break;

      case GL_STACK_UNDERFLOW:
        error = "GL_STACK_UNDERFLOW";
        break;

      case GL_OUT_OF_MEMORY:
        error = "GL_OUT_OF_MEMORY";
        break;

      case GL_INVALID_FRAMEBUFFER_OPERATION:
        error = "GL_INVALID_FRAMEBUFFER_OPERATION";
        break;
    }
    std::stringstream  err;
    err << error << " from " << op << " in " << file << ":" << line << " (inside " << method << ")" << std::endl;
    KERR(err.str().c_str());
  }
}
