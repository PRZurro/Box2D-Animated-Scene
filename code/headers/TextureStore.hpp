/**
 * @file ParticleEmitterFactory.hpp
 * @author Pablo Rodríguez Zurro (przuro@gmail.com)
 * @brief
 * @version 0.1
 * @date 2019-03-14
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef BOX2D_ANIMATED_SCENE_TEXTURE_STORE_H_
#define BOX2D_ANIMATED_SCENE_TEXTURE_STORE_H_

#include "internal/declarations/Declarations.hpp"
#include "Internal/Utilities.hpp"



namespace prz
{
	class TextureStore
	{
	public:

		TextureStore() :
			textures_(),
			texturesByName_()
		{}

	public:

		static TextureStore& instance()
		{
			static TextureStore instance;
			return instance;
		}

	public:

		bool create_texture(PString& texturePath)
		{
			Texture texture;
			
			if (texture.loadFromFile(texturePath))
			{
				textures_[texturePath] = texture;
				
				texturesByName_[split_file_name(texturePath, "/")] = &textures_[texturePath];

				return true;
			}

			return false;
		}

		int create_textures(PBuffer<PString>& texturesPaths)
		{
			int i = 0; // Works as index and number of textures loaded

			for (i; i < texturesPaths.size(); ++i)
			{
				if (!create_texture(texturesPaths[i]))
					break;
			}

			return i;
		}

	public:

		Texture* get_texture_by_path(PString& path)
		{
			if (exists_texture(path))
			{
				return &textures_[path];
			}

			return  nullptr;
		}

		Texture* get_texture_by_name(const PString & name)
		{
			if (exists_texture_with_name(name))
			{
				return texturesByName_[name];
			}

			return  nullptr;
		}

	public:

		bool exists_texture(const PString& texturePath) const
		{
			if (textures_.find(texturePath) != textures_.end())
				return true;

			return false;
		}

		bool exists_texture_with_name(const PString & textureName) const
		{
			if (texturesByName_.find(textureName) != texturesByName_.end())
				return true;

			return false;
		}

	private:

		PMap< PString, Texture > textures_;
		PMap< PString, Texture* > texturesByName_;
	};

} // !namespace prz
#endif // !BOX2D_ANIMATED_SCENE_TEXTURE_STORE_H_