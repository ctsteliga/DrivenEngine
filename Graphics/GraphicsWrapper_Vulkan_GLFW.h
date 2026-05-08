#pragma once
#include "IGraphicsWrapper.h"

class GraphicsWrapper_Vulkan_GLFW : public IGraphicsWrapper
{
private:

public:
	GraphicsWrapper_Vulkan_GLFW();
	~GraphicsWrapper_Vulkan_GLFW();
	void Run() override;
};