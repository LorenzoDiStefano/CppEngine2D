#ifndef ENGINE_TIMER
#define ENGINE_TIMER

#include <functional>

namespace utility
{
	class timer
	{

	public:
		timer(bool auto_restart, float interval);
		timer() = delete;
		~timer() = default;

		void tick(float delta_time);

		void start();
		void stop();

		bool is_time_elapsed();
		float missing_time() const;

		//setters
		void set_auto_restart(bool auto_restart);

		//getters
		float get_interval();//const

		std::function<void(void)> callback;

	private:

		bool m_auto_restart;
		bool m_is_started;
		float m_interval;
		float m_accumulated_time;
	};
}

#endif