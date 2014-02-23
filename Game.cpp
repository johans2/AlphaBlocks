#include "Game.h"

CGame::CGame()
    :mCurrentScene(nullptr),
     mScenes()
{
}

CGame::~CGame(){
    delete mCurrentScene;
}

void CGame::Update(){
}

void CGame::addScene(CScene *){
}

void CGame::removeScene(CScene *){
}

void CGame::setCurrentScene(){
}
