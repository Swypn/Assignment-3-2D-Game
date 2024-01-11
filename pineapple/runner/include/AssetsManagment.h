#pragma once
#include <unordered_map>
#include "batch.hpp"
class AssetsManagement
{

public:
	AssetsManagement();
	~AssetsManagement();
	
	static std::unordered_map<std::string, sf::Texture*> m_textures;
	static std::vector<std::string> m_order;
	sf::Font m_font;
	bool LoadFontFile(const std::string& filePath);

	sf::Text SetText(std::string textSentence, int size, sf::Uint32 textStyle, float positionX, float positionY);
	int GetLength();

	sf::Texture* GetTexture(std::string name);

	sf::Texture* GetTexture(int index);

	sf::Texture* LoadTexture(std::string name, std::string path);	
};