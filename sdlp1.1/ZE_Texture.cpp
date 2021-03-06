#include "ZE_Core.h"
#include "ZE_Texture.h"

using namespace std;

void Texture::Init(string name, std::unique_ptr<SDL_Texture, decltype(SDL_DestroyTexture)*>& texture, int width, int height, deque<SubTexture> subData)
{
	this->name = name;
	this->mTexture.swap(texture);
	this->mWidth = width;
	this->mHeight = height;
	this->subTextures = subData;
	this->mySubInfo.name = name;
	this->mySubInfo.x = 0;
	this->mySubInfo.y = 0;
	this->mySubInfo.width = mWidth;
	this->mySubInfo.height = mHeight;
}

int Texture::getWidth() { return mWidth; }
int Texture::getHeight() { return mHeight; }

std::unique_ptr<SDL_Texture, decltype(SDL_DestroyTexture)*>& Texture::getTexture()
{
	return mTexture;
}

Texture::~Texture()
{
}