//#define TEST_OF_SFML
#ifdef TEST_OF_SFML
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <bits/stdc++.h>
//#include "my_window.h"

void fun1();
void check_keyboard(const sf::Event &event);
void check_mouse(const sf::Event &event);
sf::Texture init_texture(const std::string &s);
sf::Sprite init_sprite(const sf::Texture & tex);
void modify_sprite(sf::Sprite &spr);
sf::Text init_text(const std::wstring & s, const sf::Font & font);
sf::Font init_font(const std::string & s);
sf::VertexArray init_vertexarray();
sf::View init_view();
sf::SoundBuffer init_buffer(const std::string & s);
template<typename T1, typename T2>
bool check_collision(const T1 &a, const T2 &b);
#endif