#pragma once
#include <mutex>

// FOLLOW THIS DESIGN PATTERN FOR ALL SINGLETONS IN THIS PROJECT
// This is a thread-safe implementation of the Singleton design pattern in C++. 
// It ensures that only one instance of the class is created and provides a 
// global point of access to that instance. The use of std::mutex ensures that 
// the instance creation is thread-safe
class IThreadSafeSingleton
{
private:
	static IThreadSafeSingleton* m_Instance;
	static std::mutex m_Mutex;
protected:
	IThreadSafeSingleton() {}
	~IThreadSafeSingleton() {}
public:
	// Delete copy constructor and assignment operator to prevent copying
	IThreadSafeSingleton(const IThreadSafeSingleton&) = delete;
	IThreadSafeSingleton& operator=(const IThreadSafeSingleton&) = delete;

	static IThreadSafeSingleton* Instance() {
		std::lock_guard<std::mutex> lock(m_Mutex);
		if (m_Instance == nullptr) {
			m_Instance = new IThreadSafeSingleton();
		}
		return m_Instance;
	}
};