//#define TEST_OF_SFML
#ifdef TEST_OF_SFML
#include "test.h"
void check_keyboard(const sf::Event &event) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { //��������Ϣ
		std::cout << "up\n";
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		std::cout << "down\n";
	}
}

void check_mouse(const sf::Event &event)
{
	if (event.type == sf::Event::MouseButtonPressed) { //������
		if (event.mouseButton.button == sf::Mouse::Right) {
			std::cout << event.mouseButton.x << std::endl;
			std::cout << event.mouseButton.y << std::endl;
		}
	}

	if (event.type == sf::Event::MouseButtonReleased) { //�������ͷ�
		std::cout << "realease" << std::endl;
	}

}

sf::Sprite init_sprite(const sf::Texture & tex) {
	sf::Sprite spr;
	spr.setTexture(tex);//��������
	spr.setTextureRect(sf::IntRect(0, 0, 100, 100));//ѡ����������
	spr.setColor(sf::Color(255, 0, 0, 120));//������ɫ͸����
	spr.setPosition(sf::Vector2f(100, 100));//����λ��
	spr.setRotation(90);//��ת
	spr.setScale(sf::Vector2f(2, 2));//���ô�С
	spr.setOrigin(sf::Vector2f(50, 50));//�������ĵ�
	return spr;
}

sf::Texture init_texture(const std::string &s) {
	sf::Texture tex;//����
	if (tex.loadFromFile(s)) std::cout << "texture success\n";//��ͼƬ��Ϊ���� s ΪͼƬ·��
	tex.setSmooth(true); //ƽ��
	tex.setRepeated(false); //�ظ� ��ѡ����������ͼƬʱ�Ƿ��ظ�
	return tex;
}

void modify_sprite(sf::Sprite &spr) {
	spr.move(sf::Vector2f(0.01, 0.01));//�ƶ�
	spr.rotate(0.1);//��ת
	spr.scale(sf::Vector2f(0.9999, 0.9999));//��С
}

sf::Text init_text(const std::wstring & s, const sf::Font & font) {
	sf::Text text;
	text.setString(s); //�����ַ���
	text.setFont(font); //��������
	text.setCharacterSize(36); //���ִ�С
	text.setFillColor(sf::Color::Blue); //��ɫ
	text.setStyle(sf::Text::Bold | sf::Text::Underlined | sf::Text::Italic | sf::Text::StrikeThrough);
	//����
	return text;
}

sf::Font init_font(const std::string & s) {
	sf::Font font;
	if (font.loadFromFile(s)) std::cout << "font success\n";
	return font;
}

sf::VertexArray init_vertexarray() {
	/*
		��ʼ��һ��vertex
		sf::Vertex ver (sf::Vector2f(20,20),sf::Color::Magenta,sf::Vector2f(30,40));
		ver.position = sf::Vector2f(20,20);
		ver.color = sf::Color::Magenta;
		ver.texCoords = sf::Vector2(30,40);
	*/
	sf::VertexArray ver(sf::Triangles, 3);
	ver[0] = sf::Vertex(sf::Vector2f(20, 20), sf::Color::Blue, sf::Vector2f(0, 0));
	ver[1] = sf::Vertex(sf::Vector2f(100, 100), sf::Color::Green, sf::Vector2f(0, 0));
	ver[2] = sf::Vertex(sf::Vector2f(100, 20), sf::Color::Red, sf::Vector2f(0, 0));

	return ver;
}

sf::View init_view() {
	sf::View vi(sf::Vector2f(0, 0), sf::Vector2f(1000, 1000));// �����ӽǵ����ĺʹ�С
	vi.setViewport(sf::FloatRect(0, 0, 0.9, 0.9)); // �����ӽ��ڴ��ڵ����λ�� (��ʼx,��ʼy,x��С,y��С)
	return vi;
}

template<typename T1, typename T2>
bool check_collision(const T1 &a, const T2 &b) { //��ײ���
	sf::FloatRect box1 = a.getGlobalBounds();
	sf::FloatRect box2 = b.getGlobalBounds();
	return box1.intersects(box2);
}

sf::SoundBuffer init_buffer(const std::string & s) {
	sf::SoundBuffer buf;
	if (buf.loadFromFile(s)) std::cout << "buffer success\n";
	return buf;
}

void test(sf::Transformable & x) {
	x.move(sf::Vector2f(0, -0.01));
}

void fun1() {
	sf::RenderWindow window(sf::VideoMode(500, 500), "new window"); //RenderWindow ����ͼ��
	sf::Color co(123, 123, 123, 255); //������ɫ
	auto tex = init_texture("assert\\tex.png");
	auto spr = init_sprite(tex); //����Ͷ�Ӧ������Ҫ��һ��������������
	auto font = init_font("assert\\font.ttf");
	auto text = init_text(L"123��hello��world��!", font); //������Ҫ���ַ�
	auto ver = init_vertexarray();
	auto vi = init_view();
	sf::SoundBuffer buf = init_buffer("assert\\buf.wav");
	sf::Sound sou;
	sou.setBuffer(buf);
	sou.play(); // ������Ƶ
/*	sf::View vi(sf::Vector2f(0,0),sf::Vector2f(300,300));// �����ӽǵ����ĺʹ�С
	vi.setViewport(sf::FloatRect(0,0,0.5,0.5)); // �����ӽ��ڴ��ڵ����λ�� (��ʼx,��ʼy,x��С,y��С)

	sf::View vi2(sf::Vector2f(0,0),sf::Vector2f(300,300));// �����ӽǵ����ĺʹ�С
	vi2.setViewport(sf::FloatRect(0.5,0.5,0.5,0.5)); // �����ӽ��ڴ��ڵ����λ�� (��ʼx,��ʼy,x��С,y��С)
*/	while (window.isOpen()) {
	sf::Event event;
	while (window.pollEvent(event)) {
		check_keyboard(event);
		check_mouse(event);
		if (event.type == sf::Event::Closed) { // ���ر�
			window.close();
		}
	}

	window.clear(co);//����
	modify_sprite(spr);
	test(spr);
	//vi.zoom(1.0002);//�ı���ͼ��С
//		window.setView(vi2); //��������ͼ ��draw
//		window.draw(text);
//		window.draw(ver);
//		window.draw(spr);
	window.setView(vi);
	if (check_collision(spr, text)) window.draw(ver);
	window.draw(text);
	window.draw(spr);
	window.display();//��ʾ��������
}

}
#endif