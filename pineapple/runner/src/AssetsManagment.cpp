#include "AssetsManagment.h"

// Most of the method and logic from another project

AssetsManagement::AssetsManagement()
{
    loadAllResources();
}
AssetsManagement::~AssetsManagement()
{
    m_textures.clear();
}
;

std::unordered_map< std::string, sf::Texture> AssetsManagement::m_textures;
std::vector<std::string> AssetsManagement::m_order;
std::unordered_map < std::string, sf::Text*> m_text;

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

int AssetsManagement::GetLength() const
{
	return static_cast<int>(m_textures.size());
}

// Get Texture by Name
sf::Texture* AssetsManagement::GetTexture(const std::string& name)
{
    auto it = m_textures.find(name);
    if (it != m_textures.end()) {
        return &it->second;
    }
    return nullptr;
}

// Assign a Texture a Name (for accessing via get) and path (to load from)
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

    // Load font file
    LoadFontFile("assets/sunny-spells-font/SunnyspellsRegular-MV9ze.otf");
}
