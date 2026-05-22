#include "GraphicsWrapper_Vulkan_GLFW.h"
#include "Debug.h"

#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include <iostream>

GraphicsWrapper_Vulkan_GLFW::GraphicsWrapper_Vulkan_GLFW()
{
	LOGGING("GraphicsWrapper_Vulkan_GLFW Constructor called.")
    m_Window = nullptr;
	m_Instance = VK_NULL_HANDLE;
}

GraphicsWrapper_Vulkan_GLFW::~GraphicsWrapper_Vulkan_GLFW()
{
	LOGGING("GraphicsWrapper_Vulkan_GLFW Destructor called.")
	m_Window = nullptr;
	m_Instance = VK_NULL_HANDLE;
}

void GraphicsWrapper_Vulkan_GLFW::Initialize()
{
    LOGGING("GraphicsWrapper_Vulkan_GLFW Initialize called.")
    InitializeWindow();
	InitializeVulkan();
}

void GraphicsWrapper_Vulkan_GLFW::InitializeWindow()
{
    LOGGING("GraphicsWrapper_Vulkan_GLFW InitializeWindow called.")
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    m_Window = glfwCreateWindow(WIDTH, HEIGHT, "VK_WINDOW", nullptr, nullptr);
}

void GraphicsWrapper_Vulkan_GLFW::InitializeVulkan()
{
    LOGGING("GraphicsWrapper_Vulkan_GLFW InitializeVulkan called.")
    CreateInstance();
}

void GraphicsWrapper_Vulkan_GLFW::CreateInstance()
{
    LOGGING("GraphicsWrapper_Vulkan_GLFW CreateInstance called.")
    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Hello Triangle";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;
    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    createInfo.enabledExtensionCount = glfwExtensionCount;
    createInfo.ppEnabledExtensionNames = glfwExtensions;

    createInfo.enabledLayerCount = 0;

    if (vkCreateInstance(&createInfo, nullptr, &m_Instance) != VK_SUCCESS) {
        throw std::runtime_error("failed to create instance!");
    }
}

void GraphicsWrapper_Vulkan_GLFW::Shutdown()
{
    LOGGING("GraphicsWrapper_Vulkan_GLFW Shutdown called.")

    vkDestroyInstance(m_Instance, nullptr);
    glfwDestroyWindow(m_Window);
    glfwTerminate();

}

void GraphicsWrapper_Vulkan_GLFW::Run()
{
	LOGGING("GraphicsWrapper_Vulkan_GLFW Run called.")

    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

    std::cout << extensionCount << " extensions supported\n";

    glm::mat4 matrix;
    glm::vec4 vec;
    auto test = matrix * vec;

    while (!glfwWindowShouldClose(m_Window)) {
        glfwPollEvents();
    }

}