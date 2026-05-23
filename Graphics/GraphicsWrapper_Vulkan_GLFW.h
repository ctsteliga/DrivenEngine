#pragma once
#include "IGraphicsWrapper.h"

#define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"

// TEMP
const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

class GraphicsWrapper_Vulkan_GLFW : public IGraphicsWrapper
{
private:
	// Could Interface out to IWINDOW* - Removes dependency on GLFW & Vulkan
	GLFWwindow* m_Window;
	VkInstance m_Instance;

	// ADD DEBUG MACRO - ?
	VkDebugUtilsMessengerEXT m_DebugMessenger;

	void InitializeWindow(); 
	void InitializeVulkan(); 
	void CreateInstance();
public:
	GraphicsWrapper_Vulkan_GLFW();
	~GraphicsWrapper_Vulkan_GLFW();

	// Remove assignment operator and copy constructor to prevent copying
	GraphicsWrapper_Vulkan_GLFW(const GraphicsWrapper_Vulkan_GLFW&) = delete;
	GraphicsWrapper_Vulkan_GLFW& operator=(const GraphicsWrapper_Vulkan_GLFW&) = delete;

	// IGraphicsWrapper interface implementation
	void Initialize() override;
	void Run() override;
	void Shutdown() override;

	// Validation Layer
	void PopulateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
	void SetupDebugMessenger();
	static VKAPI_ATTR VkBool32 VKAPI_CALL DebugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData);

};