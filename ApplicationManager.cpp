#include "ApplicationManager.h"
#include "Debug.h"


ApplicationManager* ApplicationManager::m_Instance = nullptr;
std::mutex ApplicationManager::m_Mutex;

ApplicationManager::ApplicationManager()
{
	LOGGING("ApplicationManager Constructor called.")
	CoreEngineManager::Instance()->Initialize();
}

ApplicationManager::~ApplicationManager()
{
	LOGGING("ApplicationManager Destructor called.")
}

ApplicationManager* ApplicationManager::Instance()
{
	std::lock_guard<std::mutex> lock(m_Mutex);
	if (m_Instance == nullptr) {
		m_Instance = new ApplicationManager();
	}
	return m_Instance;
}

void ApplicationManager::Startup()
{
	LOGGING("ApplicationManager Startup called.")
	CoreEngineManager::Instance()->Startup();
}

void ApplicationManager::Shutdown()
{
	LOGGING("ApplicationManager Shutdown called.")
	CoreEngineManager::Instance()->Shutdown();
}