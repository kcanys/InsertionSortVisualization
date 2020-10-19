#include "insert.h"

insert::insert()
{
	this->initVar();
	this->initWindow();
	this->initData();
}

insert::~insert()
{
	this->window->close();
}

void insert::initVar()
{
	this->window = nullptr;
	this->clock = new sf::Clock();
	this->font = new sf::Font();
	this->font->loadFromFile("BRLNSR.TTF");
	this->i = 1;
	this->j = 1;
	this->sortLoop = true;
	this->comparisonsCount = 0;
	this->switchesCount = 0;
	
}

void insert::initWindow()
{	
	this->videoMode.height = 800;
	this->videoMode.width = 1202;

	this->window = new sf::RenderWindow(this->videoMode, "Insertion sort", sf::Style::Close | sf::Style::Titlebar);
}

void insert::initData()
{
	for (int i = 1; i <= 200; i++)
	{
		this->shapes.push_back(sf::RectangleShape(sf::Vector2f(5, this->randomNumGen(1, 700))));
		this->shapes.back().rotate(180);
		this->shapes.back().setPosition(sf::Vector2f(1+i*6, 800));
		this->shapes.back().setFillColor(sf::Color(i%255, 0,i % 255,100));
	}
}

void insert::drawData()
{
	for (int i = 0; i < 200; i++)
	{
		this->window->draw(this->shapes[i]);
	}
}
 
const bool insert::running() const
{
	return this->window->isOpen();
}

void insert::update()
{
	this->pollEvent();
	this->timeHandling();
}

void insert::render()
{
	this->window->clear(sf::Color(127,127,127,255));
	this->drawData();
	this->sortLogic();
	this->text(this->passedTime(), 0, 0, 25);
	this->text(this->switches(), 0, 30, 25);
	this->text(this->comparisons(), 0, 60, 25);
	this->text("O(N^2)", 0, 90, 25);
	this->text("Insertion Sort Visualization", 410, 0, 30);
	if (!this->sortLoop)
	{
		this->text(this->finalString(), 320, 350, 40);
		this->text(this->closingTime(), 450, 380, 40);
		
	}
	this->window->display();
}

void insert::pollEvent()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
			case sf::Event::Closed:
				this->window->close();
				break;
			case sf::Event::KeyPressed:
				if (this->ev.key.code == sf::Keyboard::Escape)
					this->window->close();
				break;
		}
	}
}

void insert::timeHandling()
{
	if(this->sortLoop)
		this->elapsed = this->clock->getElapsedTime();
}

std::string insert::passedTime()
{
	std::string returnValue = "Elapsed time: " + std::to_string(this->elapsed.asSeconds()) + " s";
	return returnValue;
}

std::string insert::switches()
{
	std::string returnValue = "Switches done: " + std::to_string(this->switchesCount);
	return returnValue;
}

std::string insert::comparisons()
{
	std::string returnValue = "Comparisons done: " + std::to_string(this->comparisonsCount);
	return returnValue;
}

std::string insert::finalString()
{
	std::string returnValue = "200 elements sorted in " + std::to_string(this->elapsed.asSeconds()) + " s";
	return returnValue;
}

void insert::text(std::string t, int x, int y, int size)
{
	sf::Text returnText;
	returnText.setString(t);
	returnText.setPosition(x, y);
	returnText.setCharacterSize(size);
	returnText.setFont(*(this->font));
	this->window->draw(returnText);
}

int insert::randomNumGen(int f, int c)
{
	return rand() % c + f;
}

void insert::sortLogic()
{
	int temp;
	if (this->i < 200)
	{
		this->comparisonsCount++;
		if (this->j > 0 && this->shapes[j - 1].getSize().y > this->shapes[j].getSize().y)
		{
			temp = this->shapes[j - 1].getSize().y;
			this->shapes[j - 1].setSize(sf::Vector2f(this->shapes[j - 1].getSize().x, this->shapes[j].getSize().y));
			this->shapes[j].setSize(sf::Vector2f(this->shapes[j].getSize().x, temp));
			this->switchesCount++;
		}
		this->j--;
		if (this->j == -1)
		{
			this->shapes[i-1].setFillColor(sf::Color(this->shapes[i-1].getFillColor().r, this->shapes[i-1].getFillColor().g, this->shapes[i-1].getFillColor().b, 255));
			this->i++;
			this->j = this->i;
		}
		if (this->j == 200 && this->i == 200 && this->sortLoop)
		{
			this->shapes[199].setFillColor(sf::Color(this->shapes[199].getFillColor().r, this->shapes[199].getFillColor().g, this->shapes[199].getFillColor().b, 255));
			this->sortLoop = false;
			this->clock->restart();
		}
	}
}

std::string insert::closingTime()
{
	int val = 5 - (int)this->clock->getElapsedTime().asSeconds();
	if (val == -1)
		this->quit();
	std::string returnValue = "Closing in " + std::to_string(val) + " seconds...";

	return returnValue;
}

void insert::quit()
{
	this->window->close();
}


