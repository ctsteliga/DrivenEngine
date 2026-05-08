#pragma once
#include <mutex>
#include "IGraphicsWrapper.h"

class CoreEngineManager
{
private:
	static CoreEngineManager* m_Instance;
	static std::mutex m_Mutex;
	IGraphicsWrapper* m_GraphicsWrapper;

	//static GraphicsManager* m_GraphicsManager;
	//InputManager* m_InputManager;
	//AudioManager* m_AudioManager;
	//PhysicsManager* m_PhysicsManager;

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

	// TODO - Remove due to unnessary complexity
	
	//void Run();
	//GraphicsManager* GetGraphicsManager() const;
	//InputManager* GetInputManager() const;
	//AudioManager* GetAudioManager() const;
	//PhysicsManager* GetPhysicsManager() const;

};