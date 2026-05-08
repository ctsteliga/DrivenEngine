#pragma once
#include <mutex>
#include "CoreEngineManager.h"

class ApplicationManager {
private:
	static ApplicationManager* m_Instance;
	static std::mutex m_Mutex;
	//map of subsystems
	//AssetManagement --> AssetManager 
protected:
	ApplicationManager();
	~ApplicationManager();
public:
	// Delete copy constructor and assignment operator to prevent copying
	ApplicationManager(const ApplicationManager&) = delete;
	ApplicationManager& operator=(const ApplicationManager&) = delete; 

	static ApplicationManager* Instance();
	void Startup();
	void Shutdown();
};