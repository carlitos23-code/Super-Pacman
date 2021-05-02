#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <string>
#include <string>
#include <stack>
#include <ctime>
#include <deque>
#include "Textbox.h"
#include "Button.h"
#include "RoundButton.h"

using namespace std;
using namespace sf;


class estrella{
	public:
	Sprite est;
	int x;
	int y;
	
};

class enemigo{
	public:
	int x;
	int y;
	int band;
	int movimiento;
	Sprite malo;
	Texture img;

	public:
	enemigo(){
		x=332;
        y=352;
        this->band=0;
        movimiento=2;
	}
	void cero(){
		this->band=0;
	}
	void moverse(long unsigned int mat[750][670]);
};

void enemigo::moverse(long unsigned int mat[750][670]){
   	   int x1, y1;
   		   
	   for(int i=0;i<1;i++){
		if(mat[y][x] == 3){
			movimiento=1+rand()%(4-1+1);
			break;
		}
		else if(mat[y][x-i]==3){
			movimiento=1+rand()%(4-1+1);
			break;
		}
		else if(mat[y][x+i]==3){
			movimiento=1+rand()%(4-1+1);
			break;
		}
		else if(mat[y+i][x]==3){
        	movimiento=1+rand()%(4-1+1);
			break;
		}
		else if(mat[y+i][x-i]==3){
        	movimiento=1+rand()%(4-1+1);
			break;
		}
		else if(mat[y-i][x]==3){
         	movimiento=1+rand()%(4-1+1);
			break;
		}
		else if(mat[y-i][x+i]==3){
			movimiento=1+rand()%(4-1+1);
			break;
		}
		else if( mat[y-i][x-i] ==3){
			movimiento=1+rand()%(4-1+1);
			break;
		}
	}
	
    if ( mat[y][x-3] == 1 && mat[y][x+3]==0 && mat[y+3][x]==0 &&mat[y-3][x]==0){
		do{
		 movimiento=1+rand()%(4-1+1);	
		}while(movimiento==1);
	}
	
	if ( mat[y][x-3] == 0 && mat[y][x+3]==1 && mat[y+3][x]==0 && mat[y-3][x]==0){
		do{
		movimiento=1+rand()%(4-1+1);	
		}while(movimiento==2);
	}

	if ( mat[y][x-3] == 0 && mat[y][x+3]== 0 && mat[y+3][x]==1 && mat[y-3][x]==0){
		do{
		 movimiento=1+rand()%(4-1+1);	
		}while(movimiento==4);
	}
	
	if ( mat[y][x-3] == 0 && mat[y][x+3]== 0 && mat[y+3][x]==0 && mat[y-3][x]==1){
		do{
		 movimiento=1+rand()%(4-1+1);	
		}while(movimiento==3);
	}
	
	
	if ( mat[y][x-3] == 1 && mat[y][x+3]==0 && mat[y+3][x]==1 && mat[y-3][x]==0){
		do{
		 movimiento=1+rand()%(4-1+1);	
		}while(movimiento==1 || movimiento==4);
	}
	
	
	if ( mat[y][x-3] == 1 && mat[y][x+3]==0 && mat[y+3][x]==0 && mat[y-3][x]==1){
		do{
		 movimiento=1+rand()%(4-1+1);	
		}while(movimiento==1 || movimiento==3);
	}
	
	if ( mat[y][x-3] == 0 && mat[y][x+3]==1 && mat[y+3][x]==1 && mat[y-3][x]==0){
		do{
		 movimiento=1+rand()%(4-1+1);	
		}while(movimiento==2 || movimiento==4);
	}
	
	if ( mat[y][x-3] == 0 && mat[y][x+3]==1 && mat[y+3][x]==0 && mat[y-3][x]==1){
		do{
		 movimiento=1+rand()%(4-1+1);	
		}while(movimiento==2 || movimiento==3);
	}
	

	if(x==298 && y==563 && movimiento==4){
		movimiento=1;
	}	
	
	if(x==385 && y==352){
		movimiento=1;
	}
	
	if(x==283 && y==352){
		movimiento=2;
	}
	
	if(x==655 && y==352){
		x=13;
		y=352;
		movimiento=2;
	}
	
	if(x==11 && y==352){
		x=650;
		y=352;
		movimiento=1;
	}
	
	if(x==334 && y== 276){
		this->band=1;
	}
	
	if(x==334 && y==276 && band==1){
		movimiento=1+rand()%(2-1+1);
	}
	
	if(movimiento==1){
		x-=1;
	}else if(movimiento==2){
		x+=1;
	}else if(movimiento==3){
		y-=1;
	}else if(movimiento==4){
		y+=1;
	}
	
}



class Game{
	private:
	RenderWindow window;
	Sprite portada;
	Texture porta;
	Music tema;
	Music paco;
	int band;
	enemigo bowser;
	enemigo bala;
	enemigo gomba;
	enemigo fantasma;
	int vidas;
	Texture life;
	Sprite vida[3];
	int monedas;
	estrella e1;
	estrella e2;
	estrella e3;
	estrella e4;
	Texture estre;
	Texture n;
	int poder;
	int band1;
	int band2;
	int band3;
	int band4;
	int timer;
	string nombre;
	
	public:
	Game();
	void rec();
	void instrucc();
	void credit();
	void run();
	void menu();
	void nivel_1();
	void nivel_2();
	void nivel_3();
	void guardar_mat(long unsigned int mat[750][670]);
	bool revisar(int x,int y,long unsigned int mat[750][670]);
	void move(int x, int y, Sprite [3]);
	void checar_mon1(int x, int y, long unsigned int mat[750][670]);
	void checar_mon2(int x, int y, long unsigned int mat[750][670]);
	void checar_mon3(int x, int y, long unsigned int mat[750][670]);
	void setband(int n){
		this->band=n;
	}
	bool choque(Sprite maio);
	void setMonedas(int n){
		this->monedas=n;
	}
	void niveles();
	void loser();
	void winner();
	void chocar_star(Sprite mario,long unsigned int mat[750][670] );
	void capturar();
};

void Game::capturar(){
	RenderWindow window1 (sf::VideoMode(800, 600), "Capturar Texto");
	window.setKeyRepeatEnabled(true);
	
	int b=0;
	
	Texture reg;
	reg.loadFromFile("registro.png");
	Sprite regs; 
	regs.setTexture(reg);
	
	Font font;
	font.loadFromFile("Pixeled.ttf");
	
	Textbox text1(20, Color::Red, false, {150,50});
	text1.setPosition({ 295, 350});
	text1.setLimit(true, 12);
	text1.setFont(font);
	Vector2i position;
	
		while(window1.isOpen()){
			Event Event;

		//Event Loop:
		while (window1.pollEvent(Event)){
			switch (Event.type) {

				case Event::Closed:
					window1.close();
					
				case Event::TextEntered:
					text1.typedOn(Event);
					break;
					
				case Event::MouseButtonPressed:
					if(text1.isMouseOverBox(window1)){
						text1.setSelected(true);
						
					}
				
				}
		}
		window1.clear();
		if(Keyboard::isKeyPressed(Keyboard::Return)){ //Return es la tecla Enter
			this->nombre=text1.getText();
		   window1.close();
		   this->niveles();
		}
	
		window1.draw(regs);
		
		text1.drawTo(window1);
		
		window1.display();
	}

}

void Game::chocar_star(Sprite mario,long unsigned int mat[750][670]){
	FloatRect ma= mario.getGlobalBounds();
	FloatRect star1=this->e1.est.getGlobalBounds();
	FloatRect star2=this->e2.est.getGlobalBounds();
	FloatRect star3=this->e3.est.getGlobalBounds();
	FloatRect star4=this->e4.est.getGlobalBounds();
	
	if(ma.intersects(star1) && this->band1==0){
		mat[e1.x][e1.y]=0;
		this->poder=1;
		this->band1=1;
	}else if(ma.intersects(star2) && this->band2==0){
		mat[e2.x][e2.y]=0;
		this->poder=1;
		this->band2=1;
	}else 	if(ma.intersects(star3) && this->band3==0){
		mat[e3.x][e3.y]=0;
		this->poder=1;
		this->band3=1;
	} else 	if(ma.intersects(star4) && this->band4==0){
		mat[e4.x][e4.y]=0;
		this->poder=1;
		this->band4=1;
	}
	
	if(this->poder==1){
		this->bowser.malo.setTexture(n);
		this->fantasma.malo.setTexture(n);
		this->bala.malo.setTexture(n);
		this->gomba.malo.setTexture(n);
		this->timer++;
	}else{
		this->bowser.malo.setTexture(this->bowser.img);
		this->bala.malo.setTexture(this->bala.img);
		this->fantasma.malo.setTexture(this->fantasma.img);
		this->gomba.malo.setTexture(this->gomba.img);
	}
	
	if(this->timer==600){
		this->poder=0;
		this->timer=0;
	}
	
	
}

void Game::winner(){
	RenderWindow per(VideoMode(1000,800),"Eres un Crack hermos@ :3");
   	per.setFramerateLimit(60);
   	Texture gameObo;
   	Sprite pegdedor;
   	Music perder;
   	
   	fstream file;
   	file.open("registros.txt",ios::out|ios::app);
   	file <<this->nombre<<" "<<this->monedas<<endl;
   	file.close();
   	
   	perder.openFromFile("victoria.ogg");
   	gameObo.loadFromFile("Victoria.jpg");
   	pegdedor.setTexture(gameObo);
   	perder.play();
   	while(per.isOpen()){
   				Event xd;
		while(per.pollEvent(xd)){
				if(Keyboard::isKeyPressed(Keyboard::C)){
	    			per.close();
				}
			}
		
	
		
		per.clear();
		per.draw(pegdedor);
   		per.display();
   	}
}

void Game::loser(){
   RenderWindow per(VideoMode(1000,800),"Vales madre xd");
   	per.setFramerateLimit(60);
   	Texture gameObo;
   	Sprite pegdedor;
   	Music perder;
   	
   	perder.openFromFile("perder.ogg");
   	gameObo.loadFromFile("game_over.jpg");
   	pegdedor.setTexture(gameObo);
   	perder.play();
   	fstream file;
   	file.open("registros.txt",ios::out|ios::app);
   	file <<this->nombre<<" "<<this->monedas<<endl;
   	file.close();
   	
   	
   	while(per.isOpen()){
   				Event xd;
		while(per.pollEvent(xd)){
				if(Keyboard::isKeyPressed(Keyboard::C)){
	    			per.close();
				}
			}
		
		per.clear();
		per.draw(pegdedor);
   		per.display();
   	}
	}



void Game::niveles(){
	Texture nv;
	Sprite nivel;
	nv.loadFromFile("niveles.png");
	nivel.setTexture(nv);
	while(this->window.isOpen()){
		
		Event xd;
		while(window.pollEvent(xd)){
			if(xd.type==Event::Closed){
				window.close();
			}
		}		
		if (Keyboard::isKeyPressed(sf::Keyboard::Num1)){
			nivel_1();
		}

        if (Keyboard::isKeyPressed(sf::Keyboard::Num2)){
			nivel_2();
		}
		
		
		if (Keyboard::isKeyPressed(sf::Keyboard::Num3)){
			nivel_3();
		}
		this->window.clear();
		
		this->window.draw(nivel);
		
		this->window.display();
	}
}

bool Game::choque(Sprite mario){
	Music uff;
	

	FloatRect ma= mario.getGlobalBounds();
	FloatRect bows= this->bowser.malo.getGlobalBounds();
	FloatRect fanta = this->fantasma.malo.getGlobalBounds();
	FloatRect bal = this->bala.malo.getGlobalBounds();
	FloatRect gom=this->gomba.malo.getGlobalBounds();
	
    int c=0;

	
	if(ma.intersects(bows) && this->poder==1){
			    this->bowser.x=332;
			   	this->bowser.y=352;
			   	this->bowser.cero();
			   	this->bowser.movimiento=1;
			   	return false;
	}
	
	if(ma.intersects(fanta) && this->poder==1){
			    this->fantasma.x=332;
			   	this->fantasma.y=352;
			   	this->fantasma.cero();
			   	this->fantasma.movimiento=1;
			   	return false;
	}
	
		if(ma.intersects(bal) && this->poder==1){
			    this->bala.x=332;
			   	this->bala.y=352;
			   	this->bala.cero();
			   	this->bala.movimiento=1;
			   	return false;
	}
	
	
		if(ma.intersects(gom) && this->poder==1){
			    this->gomba.x=332;
			   	this->gomba.y=352;
			   	this->gomba.cero();
			   	this->gomba.movimiento=1;
			   	return false;
	}
	
	if(c==0){
		if(ma.intersects(gom)|| ma.intersects(bal) || ma.intersects(bows) || ma.intersects(fanta)){
			 this->gomba.x=332;
			   	this->gomba.y=352;
			   	this->gomba.cero();
			   	this->gomba.movimiento=1;
			   	this->bala.x=332;
			   	this->bala.y=352;
			   	this->bala.cero();
			   	this->bala.movimiento=1;
			   	   this->fantasma.x=332;
			   	this->fantasma.y=352;
			   	this->fantasma.cero();
			   	this->fantasma.movimiento=1;
			    this->bowser.x=332;
			   	this->bowser.y=352;
			   	this->bowser.cero();
			   	this->bowser.movimiento=1;
			   	if(this->poder==0){
			   		this->vidas--;
				   }
			   
			return true;
		}else{
			return false;
		}
	}
	
}


void Game::instrucc(){
		RenderWindow ins(VideoMode(357,200),"Instrucciones");
		ins.setFramerateLimit(60);
   		
   		Texture panel;
   		Sprite fondo;
   		Texture panel2;
   		
   		panel.loadFromFile("instruc_1.png");
   		panel2.loadFromFile("instruc_2.png");
   		fondo.setTexture(panel);
	
		
		while(ins.isOpen()){
		Event vent;
		while(ins.pollEvent(vent)){
			
			while(ins.pollEvent(vent)){
				if(Keyboard::isKeyPressed(Keyboard::C)){
	    			ins.close();
				}
			}
			
			ins.clear();
			ins.draw(fondo);
			ins.display();
		}
		if(Keyboard::isKeyPressed(Keyboard::Right)){
	    			fondo.setTexture(panel2);
				}	
	
		}
}

void Game::rec(){
	window.setMouseCursorVisible(false);
    View fixed = window.getView();
	Texture records;
	Texture mouse;
	Sprite fondo;
	Music tub;
	string nom;
	string num;
	//char aux[3];
	//int n;
	Font fuente;
	fuente.loadFromFile("04B_30_.ttf");
     int i=0;
	tub.openFromFile("tuberia.ogg");
	mouse.loadFromFile("mose.png");
	records.loadFromFile("records.png");
	fondo.setTexture(records);
	Sprite ohyeye(mouse);
	tub.play();
	char line[100];
	fstream file;
	file.open("registros.txt",ios::in);
		while(file.getline(line,100)){
		   i++;
		}
	file.close();	
	
	Text no[i];
	Text nu[i];
	for(int j=0; j<i; j++){
	no[j].setFont(fuente);
	nu[j].setFont(fuente);
	}
	
	int xno=254;
	int y=161;
	int xnu=515;
	int po=0;
	fstream file1;
	file1.open("registros.txt",ios::in);

	
	
	Vector2i raton;
	while(this->window.isOpen()){
		raton=Mouse::getPosition(this->window);
		ohyeye.setPosition(static_cast<Vector2f>(raton));
		Event x;
			while(window.pollEvent(x)){
				if(x.type==Event::Closed){
					window.close();
				}
			}
		
		if(Keyboard::isKeyPressed(Keyboard::M)){
	    		run();
		}
		this->window.clear();
		while(file1 >> nom >> num){
			nu[po].setString(num);
			nu[po].setPosition(xnu,y);
			no[po].setString(nom);
			no[po].setPosition(xno,y);
			y+=50;
			po++;
		}
		
		file1.close();
		this->window.setView(fixed);
		this->window.draw(fondo);
		this->window.draw(ohyeye);
		for(int k=0; k<i; k++){
		this->window.draw(nu[k]);
		this->window.draw(no[k]);	
		}
		this->window.display();
	}
}

void Game::credit(){
	window.setMouseCursorVisible(false);
    View fixed = window.getView();
	Texture creditos;
	Sprite fondo;
	Texture mouse;
	Music sonidoperro;

	sonidoperro.openFromFile("yahoo.ogg");	
	mouse.loadFromFile("mose.png");
	creditos.loadFromFile("creditos.png");
	Sprite ohyeye(mouse);
	sonidoperro.play();
	fondo.setTexture(creditos);
	
		Vector2i raton;
		while(this->window.isOpen()){
			raton=Mouse::getPosition(this->window);
			ohyeye.setPosition(static_cast<Vector2f>(raton));
			Event x;
			while(window.pollEvent(x)){
				if(x.type==Event::Closed){
					window.close();
				}
			}
		
		if(Keyboard::isKeyPressed(Keyboard::M)){
			sonidoperro.stop();
	    		run();
		}
		this->window.clear();
		this->window.setView(fixed);
		this->window.draw(fondo);
		this->window.draw(ohyeye);
		this->window.display();
		}	
}


Game::Game(){
	this->window.create(VideoMode(700,700),"Pac-Man");
	this->window.setFramerateLimit(60);
	this->porta.loadFromFile("portada.jpg");
	this->portada.setTexture(this->porta);
	this->tema.openFromFile("musica.ogg");
	this->paco.openFromFile("1.ogg");
    this->band=0;
    this->life.loadFromFile("vidas.png");
    for(int i=0; i<3; i++){
    this->vida[i].setTexture(this->life);
    this->vida[i].setOrigin(23,23);	
	}
	vida[0].setPosition(733,369);
	vida[1].setPosition(783,369);
	vida[2].setPosition(833,369);
    this->vidas=3;
    this->monedas=0;

	this->n.loadFromFile("lol.png");
    if(!this->estre.loadFromFile("Estrelluki.png")){
    	system("&pause");
	}
    this->e1.est.setTexture(this->estre);
    this->e2.est.setTexture(this->estre);
    this->e3.est.setTexture(this->estre);
    this->e4.est.setTexture(this->estre);
    
    this->e1.est.setOrigin(15,15);
    this->e2.est.setOrigin(15,15);
    this->e3.est.setOrigin(15,15);
    this->e4.est.setOrigin(15,15);

    this->e1.x=34;
    this->e1.y=711;
    
    this->e2.x=630;
    this->e2.y=711;
    
    this->e3.x=630;
    this->e3.y=40;
    
    this->e4.x=41;
    this->e4.y=40;
    
    this->e1.est.setPosition(this->e1.x,this->e1.y);
    this->e2.est.setPosition(this->e2.x,this->e2.y);
    this->e3.est.setPosition(this->e3.x,this->e3.y);
    this->e4.est.setPosition(this->e4.x,this->e4.y);

    this->band1=0;
    this->band2=0;
    this->band3=0;
    this->band4=0;
    this->timer=0;
    this->poder=0;
}

void Game::move(int x, int y, Sprite ma[3]){
	for (int i=0; i<3;i++){
		ma[i].setPosition(x,y);
	}
}

bool Game::revisar(int x,int y, long unsigned int mat[750][670]){
	if (mat[y][x] == 0 || mat[y][x-3] == 0 || mat[y][x+3] == 0 || mat[y+3][x] == 0 || mat[y+3][x-3] == 0 || mat[y+3][x+3] == 0 || mat[y-3][x] == 0 || mat[y-3][x+3] == 0 || mat[y-3][x-3] == 0){
		return true;
	}else{
		return false;
	}
}


void Game::guardar_mat(long unsigned int mat[750][670]){
	fstream file;
	file.open("jala wey.txt", ios::out|ios::app);
	
	for(int i=0; i<750; i++){
		for(int j=0; j<670; j++){
			file<<mat[i][j];
		}
		file<<'\n';
	}
	
	file.close();
}


void Game::checar_mon1(int x, int y, long unsigned int mat[750][670]){
     setband(0);
   
	for(int i=0;i<10;i++){
		if(mat[y][x] == 2){
			this->monedas=+10;
			this->paco.play();
			mat[y][x]=0;
			break;
		}
		else if(mat[y][x-i]==2){
			this->paco.play();
			mat[y][x-i]=0;
			this->monedas+=10;
			break;
		}
		else if(mat[y][x+i]==2){
			this->paco.play();
			mat[y][x+i]=0;
			this->monedas+=10;
			break;
		}
		else if(mat[y+i][x]==2){
			this->paco.play();
			mat[y+i][x]=0;
			this->monedas+=10;
			break;
		}
		else if(mat[y+i][x-i]==2){
			this->paco.play();
			mat[y+i][x+i]=0;
			this->monedas+=10;
			break;
		}
		else if(mat[y-i][x]==2){
			this->paco.play();
			mat[y-i][x]=0;
			this->monedas+=10;
			break;
		}
		else if(mat[y-i][x+i]==2){
			this->paco.play();
			mat[y-i][x+i]=0;
			this->monedas+=10;
			break;
		}
		else if( mat[y-i][x-i] == 2){
			this->paco.play();
			mat[y-i][x-i]=0;
			this->monedas+=10;
			break;
		}
	}

}

void Game::checar_mon2(int x, int y, long unsigned int mat[750][670]){
     setband(0);
   
	for(int i=0;i<10;i++){
		if(mat[y][x] == 2){
			this->monedas+=20;
			this->paco.play();
			mat[y][x]=0;
			break;
		}
		else if(mat[y][x-i]==2){
			this->paco.play();
			mat[y][x-i]=0;
			this->monedas+=20;
			break;
		}
		else if(mat[y][x+i]==2){
			this->paco.play();
			mat[y][x+i]=0;
			this->monedas+=20;
			break;
		}
		else if(mat[y+i][x]==2){
			this->paco.play();
			mat[y+i][x]=0;
			this->monedas+=20;
			break;
		}
		else if(mat[y+i][x-i]==2){
			this->paco.play();
			mat[y+i][x+i]=0;
			this->monedas+=20;
			break;
		}
		else if(mat[y-i][x]==2){
			this->paco.play();
			mat[y-i][x]=0;
			this->monedas+=20;
			break;
		}
		else if(mat[y-i][x+i]==2){
			this->paco.play();
			mat[y-i][x+i]=0;
			this->monedas+=20;
			break;
		}
		else if( mat[y-i][x-i] == 2){
			this->paco.play();
			mat[y-i][x-i]=0;
			this->monedas+=20;
			break;
		}
	}

}

void Game::checar_mon3(int x, int y, long unsigned int mat[750][670]){
     setband(0);
   
	for(int i=0;i<10;i++){
		if(mat[y][x] == 2){
			this->monedas=+30;
			this->paco.play();
			mat[y][x]=0;
			break;
		}
		else if(mat[y][x-i]==2){
			this->paco.play();
			mat[y][x-i]=0;
			this->monedas+=30;
			break;
		}
		else if(mat[y][x+i]==2){
			this->paco.play();
			mat[y][x+i]=0;
			this->monedas+=30;
			break;
		}
		else if(mat[y+i][x]==2){
			this->paco.play();
			mat[y+i][x]=0;
			this->monedas+=30;
			break;
		}
		else if(mat[y+i][x-i]==2){
			this->paco.play();
			mat[y+i][x+i]=0;
			this->monedas+=30;
			break;
		}
		else if(mat[y-i][x]==2){
			this->paco.play();
			mat[y-i][x]=0;
			this->monedas+=30;
			break;
		}
		else if(mat[y-i][x+i]==2){
			this->paco.play();
			mat[y-i][x+i]=0;
			this->monedas+=30;
			break;
		}
		else if( mat[y-i][x-i] == 2){
			this->paco.play();
			mat[y-i][x-i]=0;
			this->monedas+=30;
			break;
		}
	}

}

	void Game::nivel_1(){
	this->window.close();
	RenderWindow w(VideoMode(1000,800),"Pac-Man");
	w.setFramerateLimit(180);
	long unsigned int mapa[750][670];
	Image tablero;
	Texture lab;
	Sprite laberinto;
	Sprite marioD[3];
	Texture texturasD[3];
	Sprite marioI[3];
	Texture texturasI[3];
	Music Rola;
	Music wego;
	Rola.openFromFile("chida.ogg");
	wego.openFromFile("here_wego.ogg");
	Texture m;
	Sprite marioA;
	
	m.loadFromFile("Mario_a.png");
	marioA.setTexture(m);
	
	lab.loadFromFile("mapa.png");
    laberinto.setTexture(lab);
	Color color;
	tablero.loadFromFile("PTHR_00.png");

   
	
	
	for(int i=0; i<750; i++){
		for(int j=0; j<670; j++){
			color=tablero.getPixel(j,i);
			mapa[i][j]=color.r;
			if(mapa[i][j]!=0){
				if(color.r==255){
					mapa[i][j]=1;
				}else if(color.r==254){
					mapa[i][j]=2;
				}else if(color.r==128){
					mapa[i][j]=3;
				}else{
					mapa[i][j]=1;
				}
			}
		}
	}
	
    mapa[34][711]=4;
	mapa[630][711]=4;
    mapa[630][40]=4;
    mapa[this->e4.x][this->e4.y]=4;

	guardar_mat(mapa);
    
    texturasD[0].loadFromFile("Mario_der2.png");
    texturasD[1].loadFromFile("Mario_der1.png");
    texturasD[2].loadFromFile("Mario_der3.png");
    
    marioD[0].setTexture(texturasD[0]);
    marioD[1].setTexture(texturasD[1]);
    marioD[2].setTexture(texturasD[2]);
    
    m.loadFromFile("Mario_a.png");
	marioA.setTexture(m);
	
    texturasI[0].loadFromFile("Mario_izq2.png");
    texturasI[1].loadFromFile("Mario_izq1.png");
    texturasI[2].loadFromFile("Mario_izq3.png");
    
    marioI[0].setTexture(texturasI[0]);
    marioI[1].setTexture(texturasI[1]);
    marioI[2].setTexture(texturasI[2]);
    
    Texture moneda;
    Sprite mon;
    
    moneda.loadFromFile("moneda.png");
    mon.setTexture(moneda);
    mon.setOrigin(10,10);
    
    
    
    
    int cardenales=0;
    stack <int> pila;
    int sb=0;
    int x=335;
    int x1=0;
    int y=563;
    int y1=0;
    int j=0;
    int segundos=0;
    marioD[0].setOrigin(17,17);
    marioD[1].setOrigin(17,17);
    marioD[2].setOrigin(17,17);
    
    marioA.setOrigin(17,17);
    
    marioI[0].setOrigin(17,17);
    marioI[1].setOrigin(17,17);
    marioI[2].setOrigin(17,17);
    
    
    bowser.img.loadFromFile("Bowser_Der.png");
    bowser.malo.setTexture(bowser.img);
    bowser.malo.setOrigin(19,17);
    bowser.malo.setPosition(bowser.x,bowser.y);
    
    gomba.img.loadFromFile("Gumbax.png");
    gomba.malo.setTexture(gomba.img);
    gomba.malo.setOrigin(15,15);
    gomba.malo.setPosition(gomba.x, gomba.y);
    
    bala.img.loadFromFile("Bala_Der.png");
    bala.malo.setTexture(bala.img);
    bala.malo.setOrigin(13,12);
    bala.malo.setPosition(bala.x,bala.y);
    
    fantasma.img.loadFromFile("Fantasma_Der.png");
    fantasma.malo.setTexture(fantasma.img);
    fantasma.malo.setOrigin(12,13);
    fantasma.malo.setPosition(fantasma.x,fantasma.y);
    
    char aux[10];
    string cadena;
    Text pu;

    Font fuente;
    fuente.loadFromFile("pixeled.ttf");
    
    pu.setFont(fuente);
    pu.setColor(Color::White);
    pu.setPosition(731,265);
    Rola.play();
    wego.play();
    int cont=0;
    for(int i=0; i<750; i++){
	         	for(int j=0; j<670; j++){
			    if(mapa[i][j]==2){
			    	cont++;
				}
		    }
	    }
    
	while(w.isOpen()){
		itoa(this->monedas,aux,10);
		cadena=aux;
		pu.setString(cadena);
		Event xd;
		while(w.pollEvent(xd)){
			if(xd.type==Event::Closed){
				w.close();
			}
		}		
	    

		w.clear();
		if(Keyboard::isKeyPressed(Keyboard::Left)){
			if(revisar(x-1,y,mapa))
			sb=1;
		}
		else if(Keyboard::isKeyPressed(Keyboard::Right)){
			if(revisar(x+1,y,mapa))
			sb=2;
		}
		else if(Keyboard::isKeyPressed(Keyboard::Up)){
			if(revisar(x,y-1,mapa))
			sb=3;
		}
		else if(Keyboard::isKeyPressed(Keyboard::Down)){
			if(revisar(x,y+1,mapa))
			sb=4;
		}
		pila.push(sb);
		
		
		if (pila.top()==1){
			x1= -1;
			y1= 0;
			if(revisar(x+x1,y+y1,mapa))
            cardenales=1;
			if (pila.top()==3){
				y1= -1;
				if(revisar(x+x1,y+y1,mapa)){
				cardenales=2;
				sb=3;	
				}
			}
			else if (pila.top()==4){
				y1= 1;
				if(revisar(x+x1,y+y1,mapa)){
				cardenales=2;
				sb=4;
			    }
			}
		}
		else if (pila.top()==2){
			x1= 1;
			y1= 0;
			if(revisar(x+x1,y+y1,mapa))
			cardenales=0;
			if (pila.top()==3){	
				y1=	-1;
				if(revisar(x+x1,y+y1,mapa)){
				cardenales=2;
				sb=3;
			   }
			}
			else if (pila.top()==4){
				y1= 1;
				if(revisar(x+x1,y+y1,mapa)){
					cardenales=2;
					sb=4;
				}
			}
		}
		else if (pila.top()==3){
			x1= 0;
			y1= -1;
			if(revisar(x+x1,y+y1,mapa))
			cardenales=2;
			if (pila.top()==2){
				x1= 1;
				if(revisar(x+x1,y+y1,mapa)){
				cardenales=0;
				sb=2;
			   }
			}
			else if (pila.top()==1){
				x1= -1;
				if(revisar(x+x1,y+y1,mapa)){
						cardenales=1;
						sb=1;
				}
			}
		}
		else if (pila.top()==4){
			x1= 0;
			y1= 1;
			if(revisar(x+x1,y+y1,mapa))
				cardenales=2;
	
			if (pila.top()==2){
				x1= 1;
				if(revisar(x+x1,y+y1,mapa)){
					cardenales=0;
					sb=2;
				}
			}
			else if (pila.top()==1){
				x1= -1;
				if(revisar(x+x1,y+y1,mapa)){
					cardenales=1;
					sb=1;
				}
				
			}
		}
		
		if(revisar(x+x1,y+y1,mapa)){
			checar_mon1(x+x1,y+y1,mapa);
			x+=x1;
			y+=y1;
		}else{
			pila.pop();
		}
		if(cardenales==0){
			move(x,y,marioD);
		   }else if(cardenales==1){
		   	   move(x,y,marioI);
		   }else if(cardenales==2){
		   	  marioA.setPosition(x,y);
		   }
		
		if(x>=662 && x<=669 && (y>= 331 && y<=370)){
				x=11;
				y=352;
				if(cardenales==0){
				for (int i=0; i<3;i++){
		          marioD[i].setPosition(x+=x1,y+=y1);
	            }
	           }else if(cardenales==1){
	           	   	for (int i=0; i<3;i++){
		            marioI[i].setPosition(x+=x1,y+=y1);
	               }
			   }else if(cardenales==2){
		   	  marioA.setPosition(x,y);
		   }
		}
			if(x>=0 && x<=10 && (y>= 331 && y<=370)){
				x=662;
				y=352;
				if(cardenales==0){
					for (int i=0; i<3;i++){
		            marioD[i].setPosition(x+=x1,y+=y1);
	               }
	           }else if(cardenales==1){
	           	    for (int i=0; i<3;i++){
		            marioI[i].setPosition(x+=x1,y+=y1);
	               }
			   }else if(cardenales==2){
		   	  marioA.setPosition(x,y);
		   }
		}
		
	    fantasma.moverse(mapa);
	    gomba.moverse(mapa);
	    bala.moverse(mapa);
	    bowser.moverse(mapa);
	    
		w.draw(laberinto);
		w.draw(pu);
		
	    for(int r=0; r<vidas; r++){
	    	w.draw(this->vida[r]);

		}
			for(int i=0; i<750; i++){
	         	for(int j=0; j<670; j++){
			    if(mapa[i][j]==2){
			    	mon.setPosition(j,i);
			    	w.draw(mon);
				}
		    }
	    }
		
	if(mapa[this->e1.x][this->e1.y]==4){
			w.draw(this->e1.est);
		}
		
		if(mapa[this->e2.x][this->e2.y]==4){
			w.draw(this->e2.est);
		}
		
		
		if(mapa[this->e3.x][this->e3.y]==4){
			w.draw(this->e3.est);
		}
		
		if(mapa[this->e4.x][this->e4.y]==4){
			w.draw(this->e4.est);
		}
		
	    //Sleep(10);
		segundos++;
		if (segundos==10){
			segundos=0;
			j++;
			if (j==3){
				j=0;
			}
		}
		if(cardenales==0){
		w.draw(marioD[j]);
	    }else if(cardenales==1){
	    	w.draw(marioI[j]);
		}else if(cardenales==2){
		   	  w.draw(marioA);
		   } 
		   fantasma.malo.setPosition(fantasma.x,fantasma.y);
		   bala.malo.setPosition(bala.x,bala.y);
		   bowser.malo.setPosition(bowser.x,bowser.y);
		   gomba.malo.setPosition(gomba.x,gomba.y);
		   
		   w.draw(bowser.malo);
		   w.draw(fantasma.malo);
		   w.draw(bala.malo);
		   w.draw(gomba.malo);
		     
		 if(cardenales==0){
		w.draw(marioD[j]);
			this->chocar_star(marioD[j],mapa);
		 if(choque(marioD[j])){
		   	  	if(this->vidas<=0){
				Rola.stop();
				this->loser();
				w.close();
			   }else{
			   	if(this->poder==0){
			   	x=335;
                y=563;
			   }
		     }
			}
	    }else if(cardenales==1){
	    	w.draw(marioI[j]);
	    		this->chocar_star(marioI[j],mapa);
	    	 if(choque(marioI[j])){
		   	  	if(this->vidas<=0){
		   	  	w.close();
				Rola.stop();
				this->loser();
			   }else{
			   	if(this->poder==0){
			   	x=335;
                y=563;
			   }
		     }
			}
		}else if(cardenales==2){
		   	  w.draw(marioA);
		   	  	this->chocar_star(marioA,mapa);
		   	  if(choque(marioA)){
		   	  	if(this->vidas<=0){
				Rola.stop();
				w.close();
				this->loser();
			   }else{
			   	if(this->poder==0){
			   	x=335;
                y=563;
			   }
		     }
			}
		}    
		int band=0;
	for(int i=0; i<750; i++){
	         	for(int j=0; j<670; j++){
			    if(mapa[i][j]==2){
			    	band=1;
			    	break;
				}
		    }
		    if(band==1){
		    	break;
			}
		}
		    if(band==0){//duncion ganar
		       Rola.stop();
		       w.close();
		    	this->winner();
			}
	
		w.display();
	}
}

void Game::nivel_2(){
	this->window.close();
	RenderWindow w(VideoMode(1000,800),"Pac-Man");
	w.setFramerateLimit(120);
	long unsigned int mapa[750][670];
	Image tablero;
	Texture lab;
	Sprite laberinto;
	Sprite marioD[3];
	Texture texturasD[3];
	Sprite marioI[3];
	Texture texturasI[3];
	Music Rola;
	Music wego;
	Rola.openFromFile("Nivel_2.ogg");
	wego.openFromFile("here_wego.ogg");
	Texture m;
	Sprite marioA;
	
	m.loadFromFile("Mario_a.png");
	marioA.setTexture(m);
	
	lab.loadFromFile("mapa.png");
    laberinto.setTexture(lab);
	Color color;
	tablero.loadFromFile("PTHR_00.png");

   
	
	
	for(int i=0; i<750; i++){
		for(int j=0; j<670; j++){
			color=tablero.getPixel(j,i);
			mapa[i][j]=color.r;
			if(mapa[i][j]!=0){
				if(color.r==255){
					mapa[i][j]=1;
				}else if(color.r==254){
					mapa[i][j]=2;
				}else if(color.r==128){
					mapa[i][j]=3;
				}else{
					mapa[i][j]=1;
				}
			}
		}
	}
	
    mapa[34][711]=4;
	mapa[630][711]=4;
    mapa[630][40]=4;
    mapa[this->e4.x][this->e4.y]=4;

	guardar_mat(mapa);
    
    texturasD[0].loadFromFile("Mario_der2.png");
    texturasD[1].loadFromFile("Mario_der1.png");
    texturasD[2].loadFromFile("Mario_der3.png");
    
    marioD[0].setTexture(texturasD[0]);
    marioD[1].setTexture(texturasD[1]);
    marioD[2].setTexture(texturasD[2]);
    
    m.loadFromFile("Mario_a.png");
	marioA.setTexture(m);
	
    texturasI[0].loadFromFile("Mario_izq2.png");
    texturasI[1].loadFromFile("Mario_izq1.png");
    texturasI[2].loadFromFile("Mario_izq3.png");
    
    marioI[0].setTexture(texturasI[0]);
    marioI[1].setTexture(texturasI[1]);
    marioI[2].setTexture(texturasI[2]);
    
    Texture moneda;
    Sprite mon;
    
    moneda.loadFromFile("moneda.png");
    mon.setTexture(moneda);
    mon.setOrigin(10,10);
    
    
    
    
    int cardenales=0;
    stack <int> pila;
    int sb=0;
    int x=335;
    int x1=0;
    int y=563;
    int y1=0;
    int j=0;
    int segundos=0;
    marioD[0].setOrigin(17,17);
    marioD[1].setOrigin(17,17);
    marioD[2].setOrigin(17,17);
    
    marioA.setOrigin(17,17);
    
    marioI[0].setOrigin(17,17);
    marioI[1].setOrigin(17,17);
    marioI[2].setOrigin(17,17);
    
    
    bowser.img.loadFromFile("Bowser_Der.png");
    bowser.malo.setTexture(bowser.img);
    bowser.malo.setOrigin(19,17);
    bowser.malo.setPosition(bowser.x,bowser.y);
    
    gomba.img.loadFromFile("Gumbax.png");
    gomba.malo.setTexture(gomba.img);
    gomba.malo.setOrigin(15,15);
    gomba.malo.setPosition(gomba.x, gomba.y);
    
    bala.img.loadFromFile("Bala_Der.png");
    bala.malo.setTexture(bala.img);
    bala.malo.setOrigin(13,12);
    bala.malo.setPosition(bala.x,bala.y);
    
    fantasma.img.loadFromFile("Fantasma_Der.png");
    fantasma.malo.setTexture(fantasma.img);
    fantasma.malo.setOrigin(12,13);
    fantasma.malo.setPosition(fantasma.x,fantasma.y);
    
    char aux[10];
    string cadena;
    Text pu;

    Font fuente;
    fuente.loadFromFile("pixeled.ttf");
    
    pu.setFont(fuente);
    pu.setColor(Color::White);
    pu.setPosition(731,265);
    Rola.play();
    wego.play();
    int cont=0;
    for(int i=0; i<750; i++){
	         	for(int j=0; j<670; j++){
			    if(mapa[i][j]==2){
			    	cont++;
				}
		    }
	    }
    
	while(w.isOpen()){
		itoa(this->monedas,aux,10);
		cadena=aux;
		pu.setString(cadena);
		Event xd;
		while(w.pollEvent(xd)){
			if(xd.type==Event::Closed){
				w.close();
			}
		}		
	    

		w.clear();
		if(Keyboard::isKeyPressed(Keyboard::Right)){
			if(revisar(x-1,y,mapa))
			sb=1;
		}
		else if(Keyboard::isKeyPressed(Keyboard::Left)){
			if(revisar(x+1,y,mapa))
			sb=2;
		}
		else if(Keyboard::isKeyPressed(Keyboard::Down)){
			if(revisar(x,y-1,mapa))
			sb=3;
		}
		else if(Keyboard::isKeyPressed(Keyboard::Up)){
			if(revisar(x,y+1,mapa))
			sb=4;
		}
		pila.push(sb);
		
		
		if (pila.top()==1){
			x1= -1;
			y1= 0;
			if(revisar(x+x1,y+y1,mapa))
            cardenales=1;
			if (pila.top()==3){
				y1= -1;
				if(revisar(x+x1,y+y1,mapa)){
				cardenales=2;
				sb=3;	
				}
			}
			else if (pila.top()==4){
				y1= 1;
				if(revisar(x+x1,y+y1,mapa)){
				cardenales=2;
				sb=4;
			    }
			}
		}
		else if (pila.top()==2){
			x1= 1;
			y1= 0;
			if(revisar(x+x1,y+y1,mapa))
			cardenales=0;
			if (pila.top()==3){	
				y1=	-1;
				if(revisar(x+x1,y+y1,mapa)){
				cardenales=2;
				sb=3;
			   }
			}
			else if (pila.top()==4){
				y1= 1;
				if(revisar(x+x1,y+y1,mapa)){
					cardenales=2;
					sb=4;
				}
			}
		}
		else if (pila.top()==3){
			x1= 0;
			y1= -1;
			if(revisar(x+x1,y+y1,mapa))
			cardenales=2;
			if (pila.top()==2){
				x1= 1;
				if(revisar(x+x1,y+y1,mapa)){
				cardenales=0;
				sb=2;
			   }
			}
			else if (pila.top()==1){
				x1= -1;
				if(revisar(x+x1,y+y1,mapa)){
						cardenales=1;
						sb=1;
				}
			}
		}
		else if (pila.top()==4){
			x1= 0;
			y1= 1;
			if(revisar(x+x1,y+y1,mapa))
				cardenales=2;
	
			if (pila.top()==2){
				x1= 1;
				if(revisar(x+x1,y+y1,mapa)){
					cardenales=0;
					sb=2;
				}
			}
			else if (pila.top()==1){
				x1= -1;
				if(revisar(x+x1,y+y1,mapa)){
					cardenales=1;
					sb=1;
				}
				
			}
		}
		
		if(revisar(x+x1,y+y1,mapa)){
			checar_mon1(x+x1,y+y1,mapa);
			x+=x1;
			y+=y1;
		}else{
			pila.pop();
		}
		if(cardenales==0){
			move(x,y,marioD);
		   }else if(cardenales==1){
		   	   move(x,y,marioI);
		   }else if(cardenales==2){
		   	  marioA.setPosition(x,y);
		   }
		
		if(x>=662 && x<=669 && (y>= 331 && y<=370)){
				x=11;
				y=352;
				if(cardenales==0){
				for (int i=0; i<3;i++){
		          marioD[i].setPosition(x+=x1,y+=y1);
	            }
	           }else if(cardenales==1){
	           	   	for (int i=0; i<3;i++){
		            marioI[i].setPosition(x+=x1,y+=y1);
	               }
			   }else if(cardenales==2){
		   	  marioA.setPosition(x,y);
		   }
		}
			if(x>=0 && x<=10 && (y>= 331 && y<=370)){
				x=662;
				y=352;
				if(cardenales==0){
					for (int i=0; i<3;i++){
		            marioD[i].setPosition(x+=x1,y+=y1);
	               }
	           }else if(cardenales==1){
	           	    for (int i=0; i<3;i++){
		            marioI[i].setPosition(x+=x1,y+=y1);
	               }
			   }else if(cardenales==2){
		   	  marioA.setPosition(x,y);
		   }
		}
		
	    fantasma.moverse(mapa);
	    gomba.moverse(mapa);
	    bala.moverse(mapa);
	    bowser.moverse(mapa);
	    
		w.draw(laberinto);
		w.draw(pu);
		
	    for(int r=0; r<vidas; r++){
	    	w.draw(this->vida[r]);

		}
			for(int i=0; i<750; i++){
	         	for(int j=0; j<670; j++){
			    if(mapa[i][j]==2){
			    	mon.setPosition(j,i);
			    	w.draw(mon);
				}
		    }
	    }
		
	if(mapa[this->e1.x][this->e1.y]==4){
			w.draw(this->e1.est);
		}
		
		if(mapa[this->e2.x][this->e2.y]==4){
			w.draw(this->e2.est);
		}
		
		
		if(mapa[this->e3.x][this->e3.y]==4){
			w.draw(this->e3.est);
		}
		
		if(mapa[this->e4.x][this->e4.y]==4){
			w.draw(this->e4.est);
		}
		
	    //Sleep(10);
		segundos++;
		if (segundos==10){
			segundos=0;
			j++;
			if (j==3){
				j=0;
			}
		}
		if(cardenales==0){
		w.draw(marioD[j]);
	    }else if(cardenales==1){
	    	w.draw(marioI[j]);
		}else if(cardenales==2){
		   	  w.draw(marioA);
		   } 
		   fantasma.malo.setPosition(fantasma.x,fantasma.y);
		   bala.malo.setPosition(bala.x,bala.y);
		   bowser.malo.setPosition(bowser.x,bowser.y);
		   gomba.malo.setPosition(gomba.x,gomba.y);
		   
		   w.draw(bowser.malo);
		   w.draw(fantasma.malo);
		   w.draw(bala.malo);
		   w.draw(gomba.malo);
		     
		 if(cardenales==0){
		w.draw(marioD[j]);
			this->chocar_star(marioD[j],mapa);
		 if(choque(marioD[j])){
		   	  	if(this->vidas<=0){
				Rola.stop();
				this->loser();
				w.close();
			   }else{
			   	if(this->poder==0){
			   	x=335;
                y=563;
			   }
		     }
			}
	    }else if(cardenales==1){
	    	w.draw(marioI[j]);
	    		this->chocar_star(marioI[j],mapa);
	    	 if(choque(marioI[j])){
		   	  	if(this->vidas<=0){
		   	  	w.close();
				Rola.stop();
				this->loser();
			   }else{
			   	if(this->poder==0){
			   	x=335;
                y=563;
			   }
		     }
			}
		}else if(cardenales==2){
		   	  w.draw(marioA);
		   	  	this->chocar_star(marioA,mapa);
		   	  if(choque(marioA)){
		   	  	if(this->vidas<=0){
				Rola.stop();
				w.close();
				this->loser();
			   }else{
			   	if(this->poder==0){
			   	x=335;
                y=563;
			   }
		     }
			}
		}    
		int band=0;
	for(int i=0; i<750; i++){
	         	for(int j=0; j<670; j++){
			    if(mapa[i][j]==2){
			    	band=1;
			    	break;
				}
		    }
		    if(band==1){
		    	break;
			}
		}
		    if(band==0){//duncion ganar
		       Rola.stop();
		       w.close();
		    	this->winner();
			}
	
		w.display();
	}
}
	
	void Game::nivel_3(){
	this->window.close();
	RenderWindow w(VideoMode(1000,800),"Pac-Man");
	w.setFramerateLimit(180);
	long unsigned int mapa[750][670];
	Image tablero;
	Texture lab;
	Sprite laberinto;
	Sprite marioD[3];
	Texture texturasD[3];
	Sprite marioI[3];
	Texture texturasI[3];
	Music Rola;
	Music wego;
	Rola.openFromFile("Nivel_3.ogg");
	wego.openFromFile("here_wego.ogg");
	Texture m;
	Sprite marioA;
	
	m.loadFromFile("Mario_a.png");
	marioA.setTexture(m);
	
	lab.loadFromFile("mapa.png");
    laberinto.setTexture(lab);
	Color color;
	tablero.loadFromFile("PTHR_00.png");

   
	
	
	for(int i=0; i<750; i++){
		for(int j=0; j<670; j++){
			color=tablero.getPixel(j,i);
			mapa[i][j]=color.r;
			if(mapa[i][j]!=0){
				if(color.r==255){
					mapa[i][j]=1;
				}else if(color.r==254){
					mapa[i][j]=2;
				}else if(color.r==128){
					mapa[i][j]=3;
				}else{
					mapa[i][j]=1;
				}
			}
		}
	}
	
    mapa[34][711]=4;
	mapa[630][711]=4;
    mapa[630][40]=4;
    mapa[this->e4.x][this->e4.y]=4;
	guardar_mat(mapa);
    
    texturasD[0].loadFromFile("Mario_der2.png");
    texturasD[1].loadFromFile("Mario_der1.png");
    texturasD[2].loadFromFile("Mario_der3.png");
    
    marioD[0].setTexture(texturasD[0]);
    marioD[1].setTexture(texturasD[1]);
    marioD[2].setTexture(texturasD[2]);
    
    m.loadFromFile("Mario_a.png");
	marioA.setTexture(m);
	
    texturasI[0].loadFromFile("Mario_izq2.png");
    texturasI[1].loadFromFile("Mario_izq1.png");
    texturasI[2].loadFromFile("Mario_izq3.png");
    
    marioI[0].setTexture(texturasI[0]);
    marioI[1].setTexture(texturasI[1]);
    marioI[2].setTexture(texturasI[2]);
    
    Texture moneda;
    Sprite mon;
    
    moneda.loadFromFile("moneda.png");
    mon.setTexture(moneda);
    mon.setOrigin(10,10);
    
    
    
    
    int cardenales=0;
    stack <int> pila;
    int sb=0;
    int x=335;
    int x1=0;
    int y=563;
    int y1=0;
    int j=0;
    int segundos=0;
    marioD[0].setOrigin(17,17);
    marioD[1].setOrigin(17,17);
    marioD[2].setOrigin(17,17);
    
    marioA.setOrigin(17,17);
    
    marioI[0].setOrigin(17,17);
    marioI[1].setOrigin(17,17);
    marioI[2].setOrigin(17,17);
    
    
    bowser.img.loadFromFile("Bowser_Der.png");
    bowser.malo.setTexture(bowser.img);
    bowser.malo.setOrigin(19,17);
    bowser.malo.setPosition(bowser.x,bowser.y);
    
    gomba.img.loadFromFile("Gumbax.png");
    gomba.malo.setTexture(gomba.img);
    gomba.malo.setOrigin(15,15);
    gomba.malo.setPosition(gomba.x, gomba.y);
    
    bala.img.loadFromFile("Bala_Der.png");
    bala.malo.setTexture(bala.img);
    bala.malo.setOrigin(13,12);
    bala.malo.setPosition(bala.x,bala.y);
    
    fantasma.img.loadFromFile("Fantasma_Der.png");
    fantasma.malo.setTexture(fantasma.img);
    fantasma.malo.setOrigin(12,13);
    fantasma.malo.setPosition(fantasma.x,fantasma.y);
    
    char aux[10];
    string cadena;
    
    Font fuente;
    Font fuente2;
    
    fuente2.loadFromFile("04B_30_.ttf");
    fuente.loadFromFile("pixeled.ttf");
    Text chepe1;
    Text chepe2;
    Text pu;
    string puntos;
    string hongos;
    
    pu.setFont(fuente);
    pu.setColor(Color::White);
    chepe1.setFont(fuente2);
    chepe2.setFont(fuente2);
    chepe1.setColor(Color::White);
    chepe2.setColor(Color::White);
    pu.setPosition(731,265);
    chepe1.setPosition(725, 210);
    chepe2.setPosition(725, 310);
    puntos="PUNTOS:";
    hongos="VIDAS:";
    chepe1.setString(puntos);
    chepe2.setString(hongos);
    Rola.play();
    wego.play();
    int cont=0;
    for(int i=0; i<750; i++){
	         	for(int j=0; j<670; j++){
			    if(mapa[i][j]==2){
			    	cont++;
				}
		    }
	    }
    
	while(w.isOpen()){
		itoa(this->monedas,aux,10);
		cadena=aux;
		pu.setString(cadena);
		Event xd;
		while(w.pollEvent(xd)){
			if(xd.type==Event::Closed){
				w.close();
			}
		}		
	    

		w.clear();
		if(Keyboard::isKeyPressed(Keyboard::Left)){
			if(revisar(x-1,y,mapa))
			sb=1;
		}
		else if(Keyboard::isKeyPressed(Keyboard::Right)){
			if(revisar(x+1,y,mapa))
			sb=2;
		}
		else if(Keyboard::isKeyPressed(Keyboard::Up)){
			if(revisar(x,y-1,mapa))
			sb=3;
		}
		else if(Keyboard::isKeyPressed(Keyboard::Down)){
			if(revisar(x,y+1,mapa))
			sb=4;
		}
		pila.push(sb);
		
		
		
		
		if (pila.top()==1){
			x1= -1;
			y1= 0;
			if(revisar(x+x1,y+y1,mapa))
            cardenales=1;
			if (pila.top()==3){
				y1= -1;
				if(revisar(x+x1,y+y1,mapa)){
				cardenales=2;
				sb=3;	
				}
			}
			else if (pila.top()==4){
				y1= 1;
				if(revisar(x+x1,y+y1,mapa)){
				cardenales=2;
				sb=4;
			    }
			}
		}
		else if (pila.top()==2){
			x1= 1;
			y1= 0;
			if(revisar(x+x1,y+y1,mapa))
			cardenales=0;
			if (pila.top()==3){	
				y1=	-1;
				if(revisar(x+x1,y+y1,mapa)){
				cardenales=2;
				sb=3;
			   }
			}
			else if (pila.top()==4){
				y1= 1;
				if(revisar(x+x1,y+y1,mapa)){
					cardenales=2;
					sb=4;
				}
			}
		}
		else if (pila.top()==3){
			x1= 0;
			y1= -1;
			if(revisar(x+x1,y+y1,mapa))
			cardenales=2;
			if (pila.top()==2){
				x1= 1;
				if(revisar(x+x1,y+y1,mapa)){
				cardenales=0;
				sb=2;
			   }
			}
			else if (pila.top()==1){
				x1= -1;
				if(revisar(x+x1,y+y1,mapa)){
						cardenales=1;
						sb=1;
				}
			}
		}
		else if (pila.top()==4){
			x1= 0;
			y1= 1;
			if(revisar(x+x1,y+y1,mapa))
				cardenales=2;
	
			if (pila.top()==2){
				x1= 1;
				if(revisar(x+x1,y+y1,mapa)){
					cardenales=0;
					sb=2;
				}
			}
			else if (pila.top()==1){
				x1= -1;
				if(revisar(x+x1,y+y1,mapa)){
					cardenales=1;
					sb=1;
				}
				
			}
		}
		
		if(revisar(x+x1,y+y1,mapa)){
			checar_mon3(x+x1,y+y1,mapa);
			x+=x1;
			y+=y1;
		}else{
			pila.pop();
		}
		if(cardenales==0){
			move(x,y,marioD);
		   }else if(cardenales==1){
		   	   move(x,y,marioI);
		   }else if(cardenales==2){
		   	  marioA.setPosition(x,y);
		   }
		
		if(x>=662 && x<=669 && (y>= 331 && y<=370)){
				x=11;
				y=352;
				if(cardenales==0){
				for (int i=0; i<3;i++){
		          marioD[i].setPosition(x+=x1,y+=y1);
	            }
	           }else if(cardenales==1){
	           	   	for (int i=0; i<3;i++){
		            marioI[i].setPosition(x+=x1,y+=y1);
	               }
			   }else if(cardenales==2){
		   	  marioA.setPosition(x,y);
		   }
		}
			if(x>=0 && x<=10 && (y>= 331 && y<=370)){
				x=662;
				y=352;
				if(cardenales==0){
					for (int i=0; i<3;i++){
		            marioD[i].setPosition(x+=x1,y+=y1);
	               }
	           }else if(cardenales==1){
	           	    for (int i=0; i<3;i++){
		            marioI[i].setPosition(x+=x1,y+=y1);
	               }
			   }else if(cardenales==2){
		   	  marioA.setPosition(x,y);
		   }
		}
		
	    fantasma.moverse(mapa);
	    gomba.moverse(mapa);
	    bala.moverse(mapa);
	    bowser.moverse(mapa);
	    
		//w.draw(laberinto);
		w.draw(pu);
		w.draw(chepe1);
		w.draw(chepe2);
	    for(int r=0; r<vidas; r++){
	    	w.draw(this->vida[r]);

		}
			for(int i=0; i<750; i++){
	         	for(int j=0; j<670; j++){
			    if(mapa[i][j]==2){
			    	mon.setPosition(j,i);
			    	w.draw(mon);
				}
		    }
	    }
		
		
		if(mapa[this->e1.x][this->e1.y]==4){
			w.draw(this->e1.est);
		}
		
		if(mapa[this->e2.x][this->e2.y]==4){
			w.draw(this->e2.est);
		}
		
		
		if(mapa[this->e3.x][this->e3.y]==4){
			w.draw(this->e3.est);
		}
		
		if(mapa[this->e4.x][this->e4.y]==4){
			w.draw(this->e4.est);
		}
		
		
		
	    //Sleep(10);
		segundos++;
		if (segundos==10){
			segundos=0;
			j++;
			if (j==3){
				j=0;
			}
		}
		if(cardenales==0){
		w.draw(marioD[j]);
	    }else if(cardenales==1){
	    	w.draw(marioI[j]);
		}else if(cardenales==2){
		   	  w.draw(marioA);
		   }
		   fantasma.malo.setPosition(fantasma.x,fantasma.y);
		   bala.malo.setPosition(bala.x,bala.y);
		   bowser.malo.setPosition(bowser.x,bowser.y);
		   gomba.malo.setPosition(gomba.x,gomba.y);
		   
		   w.draw(bowser.malo);
		   w.draw(fantasma.malo);
		   w.draw(bala.malo);
		   w.draw(gomba.malo);
		     
	if(cardenales==0){
		w.draw(marioD[j]);
			this->chocar_star(marioD[j],mapa);
		 if(choque(marioD[j])){
		   	  	if(this->vidas<=0){
				Rola.stop();
				this->loser();
				w.close();
			   }else{
			   	if(this->poder==0){
			   	x=335;
                y=563;
			   }
		     }
			}
	    }else if(cardenales==1){
	    	w.draw(marioI[j]);
	    		this->chocar_star(marioI[j],mapa);
	    	 if(choque(marioI[j])){
		   	  	if(this->vidas<=0){
		   	  	w.close();
				Rola.stop();
				this->loser();
			   }else{
			   	if(this->poder==0){
			   	x=335;
                y=563;
			   }
		     }
			}
		}else if(cardenales==2){
		   	  w.draw(marioA);
		   	  	this->chocar_star(marioA,mapa);
		   	  if(choque(marioA)){
		   	  	if(this->vidas<=0){
				Rola.stop();
				w.close();
				this->loser();
			   }else{
			   	if(this->poder==0){
			   	x=335;
                y=563;
			   }
		     }
			}
		}    
		int band=0;
	for(int i=0; i<750; i++){
	         	for(int j=0; j<670; j++){
			    if(mapa[i][j]==2){
			    	band=1;
			    	break;
				}
		    }
		    if(band==1){
		    	break;
			}
		}
		    if(band==0){//duncion ganar
		       Rola.stop();
		       w.close();
		    	this->winner();
			}
	
		w.display();
	}
}

void Game::menu(){
	window.setMouseCursorVisible(false);
    View fixed = window.getView();
    
	Sprite fondo;
	Texture menu;
	Texture jugar;
	Texture records;
	Texture creditos;
	Texture instrucciones;
	Texture menu_records;
	Texture menu_creditos;
	Texture mouse;
	
	menu.loadFromFile("menu.png");
	jugar.loadFromFile("jugar_xd.png");
	instrucciones.loadFromFile("menu_instrucciones.png");
	menu_records.loadFromFile("menu_records.png");
	menu_creditos.loadFromFile("menu_creditos.png");
	mouse.loadFromFile("mose.png");
	
	Sprite ohyeye(mouse);
	Vector2i raton;
	
	while(this->window.isOpen()){
		raton=Mouse::getPosition(this->window);
		ohyeye.setPosition(static_cast<Vector2f>(raton));
		Event xd;
		while(window.pollEvent(xd)){
			if(xd.type==Event::Closed){
				window.close();
			}
		}		
	    
	     if(raton.x>=250 && raton.x<=497 && raton.y>=368 && raton.y<=408){
	    	fondo.setTexture(jugar);
	    	if(Mouse::isButtonPressed(Mouse::Left)){
	    		this->tema.stop();
        	capturar();
			}
		}else if(raton.x>=250 && raton.x<=497 && raton.y>=441 && raton.y<=470){
			fondo.setTexture(menu_records);
			if(Mouse::isButtonPressed(Mouse::Left)){
	    		rec();
			}
		}else if(raton.x>=250 && raton.x<=497 && raton.y>=495 && raton.y<=527){
			fondo.setTexture(menu_creditos);
				if(Mouse::isButtonPressed(Mouse::Left)){
					this->tema.stop();
					credit();
	
			}
			//fondo.setTexture(menu_creditos);
		}else if(raton.x>=8 && raton.x<=316 && raton.y>=5 && raton.y<=32){
			fondo.setTexture(instrucciones);
				if(Mouse::isButtonPressed(Mouse::Left)){
					instrucc();
			}
			//fondo.setTexture(menu_creditos);
		}
		else{
			fondo.setTexture(menu);
		}

		this->window.clear();
		
		this->window.setView(fixed);
		
		this->window.draw(fondo);
	
        this->window.draw(ohyeye);
		
		this->window.display();
	}
}



void Game::run(){
     this->tema.play();
	while(this->window.isOpen()){
		
		Event xd;
		while(window.pollEvent(xd)){
			if(xd.type==Event::Closed){
				window.close();
			}
		}		
		if (Keyboard::isKeyPressed(sf::Keyboard::Return)){
			menu();
		}

		this->window.clear();
		
		this->window.draw(this->portada);
		
		this->window.display();
	}
}
	
	
int main(){
	srand(time(0));
    Game juego;
   
    juego.run();
   
   
    return EXIT_SUCCESS;
}
