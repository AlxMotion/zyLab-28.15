#ifndef PLAYLISTNODE_H
#define PLAYLISTNODE_H

#include <string>
using namespace std;
class PlaylistNode {
public:
    PlaylistNode();  
    PlaylistNode(string id, string song, string artist, int length);  

    // Accessors
    string GetID() const;
    string GetSongName() const;
    string GetArtistName() const;
    int GetSongLength() const;
    PlaylistNode* GetNext() const;

    

