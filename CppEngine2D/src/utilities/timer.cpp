#include <utility/timer.h>

namespace utility
{
	timer::timer(bool auto_restart, float interval) :
		callback{ nullptr },
		m_auto_restart{ auto_restart },
		m_is_started{ false },
		m_interval{ interval },
		m_accumulated_time{ 0 }
	{ }

	void timer::tick(float delta_time)
	{
		if (!m_is_started)
			return;

		m_accumulated_time += delta_time;

		if (is_time_elapsed())
		{
			callback();

			if (m_auto_restart)
			{
				m_accumulated_time -= m_interval;
			}
			else
			{
				stop();
			}
		}
	}

	void timer::start()
	{
		if (callback == nullptr)
		{
			exit(1);
		}
		m_is_started = true;
	}

	void timer::stop()
	{
		m_is_started = false;
	}

	void timer::set_auto_restart(bool auto_restart)
	{
		m_auto_restart = auto_restart;
	}

	bool timer::is_time_elapsed()
	{
		return m_accumulated_time >= m_interval;
	}

	float timer::missing_time() const
	{
		return m_interval - m_accumulated_time;
	}

	float timer::get_interval()
	{
		return m_interval;
	}
}
