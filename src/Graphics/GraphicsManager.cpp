#include "GraphicsManager.hpp"

GLFWwindow * GraphicsManager::window = NULL;
int GraphicsManager::fullScreenWindow = 0;
int GraphicsManager::windowWidth = DEFAULT_WINDOW_WIDTH;
int GraphicsManager::windowHeight = DEFAULT_WINDOW_HEIGHT;

void GraphicsManager::initialize()
{
  // Initialize GLFW
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Create window
  GraphicsManager::window = glfwCreateWindow(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, "Voxels", NULL, NULL);
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
  glViewport(0, 0, DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT);

  // Enable depth test
  glEnable(GL_DEPTH_TEST);

  // Face culling
  glEnable(GL_CULL_FACE);
  glCullFace(GL_FRONT);

  // Initialize graphics stores
  ShaderStore::initialize();
  TextureStore::initialize();
}

void GraphicsManager::terminate()
{
  // Terminate GLFW
  glfwTerminate();
}
