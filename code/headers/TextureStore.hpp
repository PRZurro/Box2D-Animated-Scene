/**
 * @file TextureStore.hpp
 * @author Pablo Rodr�guez Zurro (przuro@gmail.com)
 * @brief Class to load and store textures. 
 * @version 0.1
 * @date 2019-04-20
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
	/**
	 * @brief Class to load and store textures
	 * 
	 */
	class TextureStore
	{
	public:

		/**
		 * @brief Get a static instance object of this class
		 * 
		 * @return TextureStore& 
		 */
		static TextureStore& instance()
		{
			static TextureStore instance;
			return instance;
		}

	public:
		
		/**
		 * @brief load a texture by path
		 * 
		 * @param texturePath 
		 * @return true 
		 * @return false 
		 */
		bool load_texture(PString& texturePath)
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

		/**
		 * @brief load multiple textures with paths 
		 * 
		 * @param texturesPaths 
		 * @return int of the number of textures loaded (when it fails loading breaks the loop)
		 */
		int load_textures(PBuffer<PString>& texturesPaths)
		{
			int i = 0; // Works as index and number of textures loaded

			for (i; i < texturesPaths.size(); ++i)
			{
				if (!load_texture(texturesPaths[i]))
					break;
			}

			return i;
		}

	public:

		/**
		 * @brief returns the texture by path 
		 * 
		 * @param path 
		 * @return Texture* 
		 */
		Texture* get_texture_by_path(PString& path)
		{
			if (is_texture_loaded(path))
			{
				return &textures_[path];
			}

			return  nullptr;
		}

		/**
		 * @brief returns the texture by name
		 * 
		 * @param name 
		 * @return Texture* 
		 */
		Texture* get_texture_by_name(const PString & name)
		{
			if (is_texture_with_name_loaded(name))
			{
				return texturesByName_[name];
			}

			return  nullptr;
		}

	public:

		/**
		 * @brief Check if a texture is loaded by path
		 * 
		 * @param texturePath 
		 * @return true 
		 * @return false 
		 */
		bool is_texture_loaded(const PString& texturePath) const
		{
			if (textures_.find(texturePath) != textures_.end())
				return true;

			return false;
		}

		/**
		 * @brief check if a texture is loaded by name
		 * 
		 * @param textureName 
		 * @return true 
		 * @return false 
		 */
		bool is_texture_with_name_loaded(const PString & textureName) const
		{
			if (texturesByName_.find(textureName) != texturesByName_.end())
				return true;

			return false;
		}

	private:

		/**
		 * @brief Construct a new Texture Store object. Private to avoid undesired instantiation
		 * 
		 */
		TextureStore() :
			textures_(),
			texturesByName_()
		{}

	private:

		PMap< PString, Texture > textures_;
		PMap< PString, Texture* > texturesByName_;
	};

} // !namespace prz
#endif // !BOX2D_ANIMATED_SCENE_TEXTURE_STORE_H_