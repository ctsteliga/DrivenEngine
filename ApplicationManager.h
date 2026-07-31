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
	// RULE OF 5:
	// Delete copy constructor, assignment operator, move constructor, 
	// and move assignment operator to prevent copying and moving
	ApplicationManager(const ApplicationManager&) = delete;
	ApplicationManager& operator=(const ApplicationManager&) = delete; 
	ApplicationManager(ApplicationManager&&) = delete;
	ApplicationManager& operator=(ApplicationManager&&) = delete;

	static ApplicationManager* Instance();
	void Startup();
	void Shutdown();
};