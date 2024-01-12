#include "AssetsManagment.h"
#pragma warning(push)
#pragma warning(disable : 26455)
AssetsManagement::AssetsManagement()
{
        loadAllResources();
}
#pragma warning(pop)
AssetsManagement::~AssetsManagement()
{
    m_textures.clear();
}
std::unordered_map< std::string, sf::Texture> AssetsManagement::m_textures;

bool AssetsManagement::LoadFontFile(const std::string& filePath)
{
    if(!m_font.loadFromFile(filePath))
    {
        //error
        return false;
    }
    return true;
}

sf::Text AssetsManagement::SetText(const std::string& textSentence, int size, sf::Uint32 textStyle, float positionX, float positionY)
{
    sf::Text text;
    text.setFont(m_font);
    text.setCharacterSize(size);
    text.setStyle(textStyle);
    text.setPosition(positionX, positionY);
    text.setString(textSentence);
    return text;
}

int AssetsManagement::GetLength() const noexcept
{
	return toInt((m_textures.size()));
}

sf::Texture* AssetsManagement::GetTexture(const std::string& name)
{
    auto it = m_textures.find(name);
    if (it != m_textures.end()) {
        return &it->second;
    }
    return nullptr;
}

void AssetsManagement::LoadTexture(const std::string& name,const std::string& path)
{
    sf::Texture texture;
    if (texture.loadFromFile(path)) {
        m_textures[name] = std::move(texture);
    }
}

void AssetsManagement::loadAllResources()
{

    LoadTexture("player", "assets/player.png");
    LoadTexture("ball", "assets/Ball.png");
    LoadTexture("brick", "assets/WhiteHitBrick.png");
    LoadTexture("fallingStar", "assets/FallingStar.png");

    LoadFontFile("assets/sunny-spells-font/SunnyspellsRegular-MV9ze.otf");
}