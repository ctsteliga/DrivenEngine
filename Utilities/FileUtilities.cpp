#include "FileUtilities.h"
#include <iostream>

FileUtilities* FileUtilities::m_Instance = nullptr;
FILE* FileUtilities::m_DebugLogFile = nullptr;
FILE* FileUtilities::m_EventLogFile = nullptr;
std::mutex FileUtilities::m_Mutex;

FileUtilities::FileUtilities()
{
	// Read Config File to get log path
	// Create new log file and save stream
	m_DebugLogPath = "debug.log"; //TODO: make this path configurable
	m_EventLogPath = "event.log"; //TODO: make this path configurable
	m_DebugLogFile = fopen(m_DebugLogPath.c_str(), "w");
	if (m_DebugLogFile == nullptr) {
		std::cerr << "Failed to open debug log file at path: " << m_DebugLogPath << std::endl;
	}
	m_EventLogFile = fopen(m_EventLogPath.c_str(), "w");
	if (m_EventLogFile == nullptr) {
		std::cerr << "Failed to open event log file at path: " << m_EventLogPath << std::endl;
	}
}

FileUtilities::~FileUtilities()
{
	if (m_Instance != nullptr) {
		delete m_Instance;
		m_Instance = nullptr;
	}
	if (m_DebugLogFile != nullptr) {
		fclose(m_DebugLogFile);
		m_DebugLogFile = nullptr;
	}
}

FileUtilities* FileUtilities::Instance()
{
	std::lock_guard<std::mutex> lock(m_Mutex);
	if (m_Instance == nullptr) {
		m_Instance = new FileUtilities();
	}
	return m_Instance;
}

void FileUtilities::WriteToDebugLog(const std::string& message)
{
	if (m_DebugLogFile != nullptr) {
		fprintf(m_DebugLogFile, "%s\n", message.c_str());
		fflush(m_DebugLogFile); // Ensure the message is written to the file immediately
	}
}

void FileUtilities::WriteToDebugLog(const char* message)
{
	WriteToDebugLog(std::string(message));
}

void FileUtilities::WriteToEventLog(const std::string& message)
{
	if (m_EventLogFile != nullptr) {
		fprintf(m_EventLogFile, "%s\n", message.c_str());
		fflush(m_EventLogFile); // Ensure the message is written to the file immediately
	}
}

void FileUtilities::WriteToEventLog(const char* message)
{
	WriteToEventLog(std::string(message));
}
