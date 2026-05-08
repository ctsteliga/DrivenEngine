#pragma once
#include <string>
#include <mutex>

class FileUtilities
{
private:
	std::string m_DebugLogPath;
	std::string m_EventLogPath;
	static FILE* m_DebugLogFile;
	static FILE* m_EventLogFile;
	static FileUtilities* m_Instance;
	static std::mutex m_Mutex;
protected:
	FileUtilities();
	~FileUtilities();
public:
	// Delete copy constructor and assignment operator to prevent copying
	FileUtilities(const FileUtilities&) = delete;
	FileUtilities& operator=(const FileUtilities&) = delete;

	static FileUtilities* Instance();
	void WriteToDebugLog(const std::string& message);
	void WriteToDebugLog(const char* message);

	void WriteToEventLog(const std::string& message);
	void WriteToEventLog(const char* message);
};