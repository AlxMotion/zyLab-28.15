#include "PlaylistNode.h"
#include <iostream>

PlaylistNode::PlaylistNode(){
  string uniqueID = "none";
  string songName = "none";
string artistName = "none";
int songLength = 0;
PlaylistNode*nextNodePtr(0);
}
PLaylistNode::PlaylistNode(string id, string songName, string artistName, int songLength, 
