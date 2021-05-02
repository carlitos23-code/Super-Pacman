#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

// Define keys:
#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class Textbox {
	
	public:
		
		Textbox(int size, Color color, bool sel, Vector2f txtSize ) {
			
			textbox.setCharacterSize(size);
			textbox.setColor(color);
			
			isSelected = sel;
			
			txtArea.setSize(txtSize);
			
			txtWidth = txtSize.x;
			txtHeight = txtSize.y;
	
			if(isSelected)
				textbox.setString("_");
			else
				textbox.setString("");
		}
	
		void setFont(Font &fonts) { textbox.setFont(fonts); }
	
		void setPosition(Vector2f point) { 
			textbox.setPosition(point);
			txtArea.setPosition(point); 
		}
	
		void setLimit(bool ToF) { hasLimit = ToF; }
	
		void setLimit(bool ToF, int lim) {
			hasLimit = ToF;
			limit = lim - 1;
		}
	
		void setSelected(bool sel) {
			isSelected = sel;
			textbox.setString(text.str() + "_");
			
			if (!sel) {
				string t = text.str();
				string newT = "";
				for (int i = 0; i < t.length(); i++) {
					newT += t[i];
				}
				textbox.setString(newT);
			}
		}
	
		string getText() { return text.str(); }
	
		void drawTo(RenderWindow &window) { window.draw(textbox); }
	
		bool isMouseOverBox(RenderWindow &window) {
			int mouseX = Mouse::getPosition(window).x;
			int mouseY = Mouse::getPosition(window).y;
	
			int txtPosX = txtArea.getPosition().x;
			int txtPosY = txtArea.getPosition().y;
	
			int txtxPosWidth = txtArea.getPosition().x + txtWidth;
			int txtyPosHeight = txtArea.getPosition().y + txtHeight;
		
			return mouseX < txtxPosWidth && mouseX > txtPosX && mouseY < txtyPosHeight && mouseY > txtPosY ? true : false;
		}
	
		void typedOn(Event input) {
			if (isSelected) {
				int charTyped = input.text.unicode;
	
				if (charTyped < 128) {
					if (hasLimit) {
						if (text.str().length() <= limit) {
							inputLogic(charTyped);
						}
						else if (text.str().length() > limit && charTyped == DELETE_KEY) {
							deleteLastChar();
						}
					}
					else {
						inputLogic(charTyped);
					}
				}
			}
		}
		
	private:
		
		Text textbox;
		RectangleShape txtArea;
		ostringstream text;
		bool isSelected = false;
		bool hasLimit = false;
		int limit = 0,  txtWidth, txtHeight;
	
		void deleteLastChar() {
			string t = text.str();
			string newT = "";
			for (int i = 0; i < t.length() - 1; i++) {
				newT += t[i];
			}
			text.str("");
			text << newT;
			textbox.setString(text.str() + "_");
		}
	
		void inputLogic(int charTyped) {
			if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY) {
				text << static_cast<char>(charTyped);
			}
			else if (charTyped == DELETE_KEY) {
				if (text.str().length() > 0) {
					deleteLastChar();
				}
			}
			textbox.setString(text.str() + "_");
		}
};
