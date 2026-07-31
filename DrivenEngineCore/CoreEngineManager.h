#pragma once
#include <mutex>
#include "IGraphicsWrapper.h"

class CoreEngineManager
{
private:
	static CoreEngineManager* m_Instance;
	static std::mutex m_Mutex;
	IGraphicsWrapper* m_GraphicsWrapper = nullptr;

protected:
	CoreEngineManager();
	~CoreEngineManager();

public:
	// RULE OF 5:
	// Delete copy constructor, assignment operator, move constructor, 
	// and move assignment operator to prevent copying and moving
	CoreEngineManager(const CoreEngineManager&) = delete;
	CoreEngineManager& operator=(const CoreEngineManager&) = delete;
	CoreEngineManager(CoreEngineManager&&) = delete;
	CoreEngineManager& operator=(CoreEngineManager&&) = delete;

	static CoreEngineManager* Instance();

	void Initialize();
	void Startup();
	void Shutdown();

};