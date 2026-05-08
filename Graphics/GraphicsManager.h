#pragma once
#include <mutex>

class GraphicsManager {
private:
	static GraphicsManager* m_Instance;
	static std::mutex m_Mutex;
protected:
	GraphicsManager();
	~GraphicsManager();
public:
	// Delete copy constructor and assignment operator to prevent copying
	GraphicsManager(const GraphicsManager&) = delete;
	GraphicsManager& operator=(const GraphicsManager&) = delete;

	static GraphicsManager* Instance();
	static GraphicsManager* DestoryInstance();

	void Initialize();
	void Startup();
	void Update();
	void Shutdown();
};