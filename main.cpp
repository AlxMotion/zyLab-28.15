#include <iostream>
#include "PlaylistNode.h"

using namespace std;

void PrintMenu(const string playlistTitle) {
   //Step 3: Implement Print Menu Function - prints out each line of menu
   cout << playlistTitle << "PLAYLIST MENU" << endl;
   cout << "a - Add song" << endl;
   cout << "d - Remove song" << endl;
   cout << "c - Change position of song" << endl;
   cout << "s - Output songs by specific artist" << endl;
   cout << "t - Output total time of playlist (in seconds)" << endl;
   cout << "o - Output full playlist" << endl;
   cout << "q - Quit" << endl;
}

PlaylistNode* ExecuteMenu(char option, string playlistTitle, PlaylistNode* headNode) {
   //Step 4: Implement Execute Menu
   
   if(option == 'a'){
      cout << "ADD SONG" << endl;
      PlaylistNode* currNode = headNode;
      PlaylistNode* lastNode = NULL;   
      string songName;
      string artistName;
      int songLength;
      string ID;
   
      //Prompting User and Getting Inputs
      cout << "Enter song's unique ID:" << endl;
      cin >> ID;
      cout << "Enter song's name:" << endl;
      cin >> songName;
      cout << "Enter artist's name:" << endl;
      cin >> artistName;
      cout << "Enter song's length (in seconds):" << endl;
      cin >> songLength;

      // Creates new node with inputs
      PlaylistNode* newNode(ID, songName, artistName, songLength);
      

      //Finding last node in list
      while(currNode->GetNext != NULL){
         currNode = currNode->GetNext();
         if(currNode != NULL){
            lastNode = currNode;
         }
      }
      lastNode->InsertAfter(newNode);
   
   } else if(option == 'o'){
      cout << playlistTitle << " - OUTPUT FULL PLAYLISTS" << endl;
      
      PlaylistNode* currNode = headNode;
      int numIterations = 1;

      if(headNode == NULL){
         cout << "Playlist is empty" << endl;
      }
      
      //Prints out each node's info
      while(currNode->GetNext != NULL){
         cout << numIterations << "." << endl;
         currNode->PrintPlaylistNode();
         

         currNode = currNode->GetNext();
         numIterations++;
         
   //Deletes node
   } else if(option == 'd'){
         int IDLook = 0;
         PlaylistNode* currNode = headNode;
         PlaylistNode* previous = headNode;
         
         cout << "REMOVE SONG" << endl;
         cout << "Enter song's unique ID" << endl;

         cin >> IDLook;
         
         while(currNode->GetNext() != NULL){
            if(currNode->GetID() == IDLook){
               cout << "\"" << currNode->GetSongName() << "\"" << " removed." << endl;
               previous->SetNext(currNode->GetNext());
               delete currNode;
               break;
            }
            previous =  currNode;
            currNode = currNode->GetNext();
         }
   } else if(option == 's'){
         string artistLook = "";
         int numIter = 1;
         
         cout << "OUTPUT SONGS BY SPECIFIC ARTST" << endl;
         cout << "Enter artist's name:" << endl;

         cin >> artistLook;

         while(currNode->GetNext() != NULL){
            if(currNode->GetArtistName() == artistLook){
               cout << numIter << "." << endl;
               currNode->PrintPlaylistNode();
            }
            currNode = currNode->GetNext();
         }
         
   }
   
}

int main() {
   string playlistTitle = "";

   //Step 2: Prompting user for title of playlist
   cout << "Enter playlist's title: " << endl;
   cin >> playlistTitle;

   //Step 5 call print menu
   PrintMenu(playlistTitle);

   //Prompt user for input
   cout << "Choose an option: " << endl;
   

   
   return 0;
}

