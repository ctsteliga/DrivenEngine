#include "CoreEngineManager.h"
#include "GraphicsWrapper_Vulkan_GLFW.h"
#include "Debug.h"

CoreEngineManager* CoreEngineManager::m_Instance = nullptr;
std::mutex CoreEngineManager::m_Mutex;

CoreEngineManager::CoreEngineManager()
{
	LOGGING("CoreEngineManager Constructor called.")
	//TODO - Make this dynamic based on config file settings
	m_GraphicsWrapper = new GraphicsWrapper_Vulkan_GLFW();
}

CoreEngineManager::~CoreEngineManager()
{
	LOGGING("CoreEngineManager Destructor called.")
	if (m_Instance != nullptr) {
		delete m_Instance;
		m_Instance = nullptr;
	}
}

CoreEngineManager* CoreEngineManager::Instance()
{
	std::lock_guard<std::mutex> lock(m_Mutex);
	if (m_Instance == nullptr) {
		m_Instance = new CoreEngineManager();
	}
	return m_Instance;
}

void CoreEngineManager::Initialize()
{
	LOGGING("CoreEngineManager Initialize called.")
}

void CoreEngineManager::Startup()
{
	LOGGING("CoreEngineManager Startup called.")
	if (m_GraphicsWrapper != nullptr) {
		m_GraphicsWrapper->Run();
	}
}

void CoreEngineManager::Shutdown()
{
	LOGGING("CoreEngineManager Shutdown called.")
	delete m_GraphicsWrapper;
	m_GraphicsWrapper = nullptr;
}