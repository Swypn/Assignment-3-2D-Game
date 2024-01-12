#pragma once
#include <unordered_map>
#include <memory>
#include <vector>
#include "batch.hpp"
class AssetsManagement
{
public:
	AssetsManagement();
	~AssetsManagement();
	
	AssetsManagement(const AssetsManagement&) = delete;
	AssetsManagement& operator=(const AssetsManagement&) = delete;

	bool LoadFontFile(const std::string& filePath);

	sf::Text SetText(const std::string& textSentence, int size, sf::Uint32 textStyle, float positionX, float positionY);

	int GetLength() const noexcept;

	sf::Texture* GetTexture(const std::string& name);

	void LoadTexture(const std::string& name,const std::string& path);
private:
	static std::unordered_map<std::string, sf::Texture> m_textures;
	sf::Font m_font;
	void loadAllResources();
};