#include "PlaylistNode.h"
#include <iostream>

PlaylistNode::PlaylistNode(): 
      uniqueID("none"),
      songName("none"),
      artistName("none"),
      songLength(0),
      nextNodePtr(nullptr) {}

PlaylistNode::PlaylistNode(string id, string song, string artist, int length):
      uniqueID(id),
      songName(song),
      artistName(artist),
      songLength(length),
      nextNodePtr(nullptr) {}
void InsertAfter(PlaylistNode* nodePtr){
        PlaylistNode* tmpNext = nullPtr;
        tmpNext = this->nextNodePtr;
        this->nextNodePtr = nodePtr;
        nodePtr->nextNodePtr = tmpNext;
  }
    void SetNext(PlaylistNode* nodePtr){
          
    }
string PlaylistNode::GetID() const {
    return uniqueID;
}

string PlaylistNode::GetSongName() const {
    return songName;
}

string PlaylistNode::GetArtistName() const {
    return artistName;
}

int PlaylistNode::GetSongLength() const {
    return songLength;
}

PlaylistNode* PlaylistNode::GetNext() const {
    return nextNodePtr;
}
