#ifndef TEXTURE_2D_H
#define TEXTURE_2D_H

#include <glad/glad.h>

class Texture2D {
	public:

		Texture2D();

		void generate(GLuint width, GLuint height, unsigned char* data);
		void bind() const;

		// Accessors
		GLuint getTextureID() const;
		GLuint getWidth() const;
		GLuint getHeight() const;
		GLuint getInternalFormat() const;
		GLuint getImageFormat() const;
		GLuint getWrapS() const;
		GLuint getWrapT() const;
		GLuint getFilterMin() const;
		GLuint getFilterMax() const;

		// Mutators
		void setWidth(GLuint width);
		void setHeight(GLuint height);
		void setInternalFormat(GLuint internalFormat);
		void setImageFormat(GLuint imageFormat);
		void setWrapS(GLuint wrapS);
		void setWrapT(GLuint wrapT);
		void setFilterMin(GLuint filterMin);
		void setFilterMax(GLuint filterMax);

	private:
		GLuint ID;
		GLuint width, height;

		GLuint internalFormat;
		GLuint imageFormat;

		GLuint wrapS;
		GLuint wrapT;
		GLuint filterMin;
		GLuint filterMax;

		void setTextureID(GLuint ID); // Texture ID should be set only in Texture class
};

#endif // !TEXTURE_2D_H
