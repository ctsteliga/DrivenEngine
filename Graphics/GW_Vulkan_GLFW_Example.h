#pragma once
#include "IGraphicsWrapper.h"

class GW_Vulkan_GLFW_Example : public IGraphicsWrapper
{
public:
	GW_Vulkan_GLFW_Example();
	~GW_Vulkan_GLFW_Example();

	//Remove assignment operator and copy constructor to prevent copying
	GW_Vulkan_GLFW_Example(const GW_Vulkan_GLFW_Example&) = delete;
	GW_Vulkan_GLFW_Example& operator=(const GW_Vulkan_GLFW_Example&) = delete;

	void Initialize() override {};
	void Shutdown() override {};	
	void Run() override;
};