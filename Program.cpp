#include <iostream>
#include "Debug.h"
#include "ApplicationManager.h"

void SimpleUnitTest() {
	int x = 10;
	ASSERT(x == 12)
	LOGGING("This is a log message for testing purposes.")
	ASSERT(x == 19)
	LOGGING("This is another log message for testing purposes.")
}

int main() {
	ApplicationManager::Instance()->Startup();

	ApplicationManager::Instance()->Shutdown();

	SimpleUnitTest();
	return 0;
}