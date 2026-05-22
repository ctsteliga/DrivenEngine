#pragma once

class IGraphicsWrapper
{
private:

public:
	virtual ~IGraphicsWrapper() {};
	virtual void Initialize() = 0;
	virtual void Shutdown() = 0;
	void virtual Run() = 0;
};