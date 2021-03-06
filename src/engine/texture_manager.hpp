#ifndef ENGINE_TEXTURE_MANAGER
#define ENGINE_TEXTURE_MANAGER

#include "gfx/image_info.hpp"
#include <string>
//temporary, should use dynamic array/dictionary
#define TM_MAX_TEXTURES 100

namespace engine
{
	namespace gfx
	{
		struct my_renderer;
	}

	class texture_manager
	{
	public:

		engine::gfx::image_info textures[TM_MAX_TEXTURES];

		//return index of texture
		int load_texture(const std::string& path);
		void set_renderer(gfx::my_renderer* renderer);

		texture_manager();
		~texture_manager() = default;

	private:
		int m_stored_texture;
		gfx::my_renderer* m_renderer;
	};
}

#endif