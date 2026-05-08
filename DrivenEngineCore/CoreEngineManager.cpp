#include "CoreEngineManager.h"
#include "GraphicsWrapper_Vulkan_GLFW.h"
#include "Debug.h"

CoreEngineManager* CoreEngineManager::m_Instance = nullptr;
//GraphicsManager* CoreEngineManager::m_GraphicsManager = nullptr;
std::mutex CoreEngineManager::m_Mutex;

CoreEngineManager::CoreEngineManager()
{
	LOGGING("CoreEngineManager Constructor called.")
	//TODO - Make this dynamic based on config file settings
	m_GraphicsWrapper = new GraphicsWrapper_Vulkan_GLFW();

	// NA
	//m_GraphicsManager = GraphicsManager::Instance(); 
	// m_InputManager = new InputManager(); 
	// m_AudioManager = new AudioManager();
	// m_PhysicsManager = new PhysicsManager();
}

CoreEngineManager::~CoreEngineManager()
{
	LOGGING("CoreEngineManager Destructor called.")
	// Clean up subsystems here
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
	//m_GraphicsManager->Initialize();
	// m_InputManager->Initialize();
	// m_AudioManager->Initialize();
	// m_PhysicsManager->Initialize();
}

void CoreEngineManager::Startup()
{
	LOGGING("CoreEngineManager Startup called.")
	if (m_GraphicsWrapper != nullptr) {
		m_GraphicsWrapper->Run();
	}
	//m_GraphicsManager->Startup();
	// m_InputManager->Startup();
	// m_AudioManager->Startup();
	// m_PhysicsManager->Startup();
}

/*void CoreEngineManager::Run()
{
	LOGGING("CoreEngineManager Run called.")
	// Main game loop would go here, calling Update on each subsystem
	while (!m_IsDone) {
	// Poll events
    // Update application/game state
    // Render contents into a framebuffer
		//GraphicsManager::Instance()->Update();
    // Swap/Present framebuffer to the screen
    // Wait some time (e.g. 1/60 of a second)
	}
}*/

void CoreEngineManager::Shutdown()
{
	LOGGING("CoreEngineManager Shutdown called.")
	delete m_GraphicsWrapper;
	m_GraphicsWrapper = nullptr;

	//GraphicsManager::DestoryInstance();
	//m_GraphicsManager = nullptr;
	// delete m_InputManager;
	// m_InputManager = nullptr;
	// delete m_AudioManager;
	// m_AudioManager = nullptr;
	// delete m_PhysicsManager;
	// m_PhysicsManager = nullptr;
}