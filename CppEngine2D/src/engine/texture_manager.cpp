#include <engine/texture_mananger.h>


namespace engine
{
	texture_manager::texture_manager() : m_stored_texture{ 0 }, m_renderer{ NULL } { }

	void texture_manager::set_renderer(gfx::my_renderer* renderer)
	{
		this->m_renderer = renderer;
	}

	//return index of texture
	int texture_manager::load_texture(const std::string& path)
	{
		gfx::image_info* texture_inf = new gfx::image_info();
		texture_inf->load_image(path);
		texture_inf->load_texture(m_renderer);
		textures[m_stored_texture] = *texture_inf;

		return m_stored_texture++;
	}
}