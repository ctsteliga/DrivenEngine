#pragma once
#include "IGraphicsWrapper.h"

class GraphicsWrapper_Vulkan_GLFW : public IGraphicsWrapper
{
private:

public:
	GraphicsWrapper_Vulkan_GLFW();
	~GraphicsWrapper_Vulkan_GLFW();

	//Remove assignment operator and copy constructor to prevent copying
	GraphicsWrapper_Vulkan_GLFW(const GraphicsWrapper_Vulkan_GLFW&) = delete;
	GraphicsWrapper_Vulkan_GLFW& operator=(const GraphicsWrapper_Vulkan_GLFW&) = delete;

	void Run() override;
};