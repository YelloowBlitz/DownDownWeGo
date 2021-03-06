#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <box2d/box2d.h>
#include <iostream>
#include <fmt/core.h>
#include <tmxlite/Map.hpp>
#include "Tile/SFMLOrthogonalLayer.h"
#include "Tile/myTilemap.h"
#include "Tile/tilemapManager.h"
#include "myContactListener.h"
#include "player.h"
#include "camera.h"
#include "uiManager.h"

class GameManager {
private:
	//Physics parameters
	const float GRAVITY = 100;
	const int32 velocityIterations = 10;
	const int32 positionIterations = 10;
	float timeStep;

	//Variables
	b2World world;
	MyContactListener listener;
	TilemapManager tmxManager;
	Player player;
	
	sf::RenderWindow* window = nullptr;
	Camera camera;
	UIManager uiManager;

	float cameraZoom;
	const int MAX_FPS;
	int fps = 0;

	bool paused = false;
	int zone = 1;
	int score = 0;
	int depth = 0;
	std::array<int, 4> zonesDepths = {0, 1, 600, 1500};

public:
	GameManager(float cameraZoom, int maxFps);
	void SetWindow(sf::RenderWindow* window_p);

	void Pause(sf::Music* music);
	bool isRunning() const;
	int GetZone();

	void Update(float deltaTime);
	void UpdateScore();

	void DisplayPause();
	void DisplayUI(float deltaTime);
	void DisplayGameOver();
	void Draw(float deltaTime);
	
	void HandleInput(sf::Event event);

	void UpdateCamera(float deltaTime);
	sf::View getCameraView() const;

	float getMapWidth() const;
	float getMapHeight() const;
};