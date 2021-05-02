#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>


using namespace std;
using namespace sf;

class RoundButton {
	
	public:
	
		RoundButton(float buttonRadius, Color bgColor = Color::Transparent, Color olColor = Color::Transparent, float olThick = 0) { 
			button.setRadius(buttonRadius);
			button.setFillColor(bgColor);
			button.setOutlineColor(olColor);
			button.setOutlineThickness(olThick);
			
			btnRadius = buttonRadius;
	
		}
	
		void setBackColor(Color color) { button.setFillColor(color); }
		
		void setPosition(Vector2f point) { button.setPosition(point); }
		
		void drawTo(RenderWindow &window) { window.draw(button); }
	
		bool isMouseOverButton(RenderWindow &window) {
			int mouseX = Mouse::getPosition(window).x;
			int mouseY = Mouse::getPosition(window).y;
	
			int btnPosX = button.getPosition().x;
			int btnPosY = button.getPosition().y;
	
			int btnxPosWidth = button.getPosition().x + btnRadius * 2;
			int btnyPosHeight = button.getPosition().y + btnRadius * 2;
			
			return mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY ? true : false;
		}
	
	private:
		
		CircleShape button;
		float btnRadius;
};
