#include "GraphicsManager.h"
#include "Debug.h"

GraphicsManager* GraphicsManager::m_Instance = nullptr;
std::mutex GraphicsManager::m_Mutex;

GraphicsManager::GraphicsManager()
{
	LOGGING("GraphicsManager Constructor called.")
}

GraphicsManager::~GraphicsManager()
{
	LOGGING("GraphicsManager Destructor called.")
}

GraphicsManager* GraphicsManager::Instance()
{
	std::lock_guard<std::mutex> lock(m_Mutex);
	if (m_Instance == nullptr) {
		m_Instance = new GraphicsManager();
	}
	return m_Instance;
}

GraphicsManager* GraphicsManager::DestoryInstance()
{
	std::lock_guard<std::mutex> lock(m_Mutex);
	if (m_Instance != nullptr) {
		delete m_Instance;
		m_Instance = nullptr;
	}
	return m_Instance;
}

void GraphicsManager::Initialize()
{
	LOGGING("GraphicsManager Initialize called.")
}

void GraphicsManager::Startup()
{
	LOGGING("GraphicsManager Startup called.")
}

void GraphicsManager::Update()
{
	LOGGING("GraphicsManager Update called.")
}

void GraphicsManager::Shutdown()
{
	LOGGING("GraphicsManager Shutdown called.")
}