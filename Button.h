#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Button {
	
	public:
	
		Button(string btnText, Vector2f buttonSize, int charSize, Color bgColor, Color textColor, Color olColor = Color::Transparent, float olThick = 0) { 
			button.setSize(buttonSize);
			button.setFillColor(bgColor);
			button.setOutlineColor(olColor);
			button.setOutlineThickness(olThick);
	
			btnWidth = buttonSize.x;
			btnHeight = buttonSize.y;
	
			text.setString(btnText);
			text.setCharacterSize(charSize);
			text.setColor(textColor);
		}
		
		void setFont(Font &fonts) { text.setFont(fonts); }
	
		void setBackColor(Color color) { button.setFillColor(color); }
	
		void setTextColor(Color color) { text.setColor(color); }
		
		void setPosition(Vector2f point) {
			button.setPosition(point);
	
			float xPos = (point.x + btnWidth / 2) - (text.getLocalBounds().width / 2);
			float yPos = (point.y + btnHeight / 2.2) - (text.getLocalBounds().height / 2);
			text.setPosition(xPos, yPos);
		}
		
		void drawTo(RenderWindow &window) {
			window.draw(button);
			window.draw(text);
		}
	
		bool isMouseOverButton(RenderWindow &window) {
			int mouseX = Mouse::getPosition(window).x;
			int mouseY = Mouse::getPosition(window).y;
	
			int btnPosX = button.getPosition().x;
			int btnPosY = button.getPosition().y;
	
			int btnxPosWidth = button.getPosition().x + btnWidth;
			int btnyPosHeight = button.getPosition().y + btnHeight;
	
			return mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY ? true : false;
		}
	
	private:
		
		RectangleShape button;
		Text text;
		int btnWidth, btnHeight;
};
