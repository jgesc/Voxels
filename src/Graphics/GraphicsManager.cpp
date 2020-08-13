#include "GraphicsManager.hpp"

GLFWwindow * GraphicsManager::window = NULL;

void GraphicsManager::initialize()
{
  // Initialize GLFW
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Create window
  GraphicsManager::window = glfwCreateWindow(800, 600, "Voxels", NULL, NULL);
  if (window == NULL)
  {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return;
  }
  glfwMakeContextCurrent(window);

  // Initialize GLAD
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return;
  }

  // Set viewport
  glViewport(0, 0, 800, 600);
  glEnable(GL_DEPTH_TEST);

  // Initialize shader store
  ShaderStore::initialize();
}

void GraphicsManager::terminate()
{
  // Terminate GLFW
  glfwTerminate();
}
