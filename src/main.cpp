#include "vulkan-renderer/entry.h"

class Demo : public vr::AppI
{
public:
	Demo(const char* _name, const char* _description, const char* _url)
		: vr::AppI(_name, _description, _url)
	{
		m_width = 1280;
		m_height = 720;
	}

	~Demo()
	{
	}

	void init(int32_t _argc, const char* const* _argv, uint32_t _width, uint32_t _height)
	{
	}

	int  shutdown()
	{
		return 0;
	}

	bool update()
	{
		if (!vr::processEvents(m_width, m_height, &m_mouse))
		{
			return true;
		}

		return false;
	}

private:
	uint32_t m_width, m_height;
	vr::MouseState m_mouse;
};

ENTRY_IMPLEMENT_MAIN(
	Demo
	, "Demo"
	, "Demo of the vulkan renderer"
	, "https://github.com/marcusnessemadland/vulkan-renderer"
);