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
	// Delete copy constructor and assignment operator to prevent copying
	CoreEngineManager(const CoreEngineManager&) = delete;
	CoreEngineManager& operator=(const CoreEngineManager&) = delete;

	static CoreEngineManager* Instance();

	void Initialize();
	void Startup();
	void Shutdown();

};