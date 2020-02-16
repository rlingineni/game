#include "label_manager.h"
#include "renderer.h"
#include "score_manager.h"

LabelManager::LabelManager(Renderer* ren) : ItemManager(ren)
{
  objects.push_back(new ScoreManager(renderer));
}

LabelManager::~LabelManager()
{

}
