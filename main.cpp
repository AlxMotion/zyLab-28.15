#include <iostream>
#include "PlaylistNode.h"
#include "string.h"

using namespace std;

void PrintMenu(const string playlistTitle) {
   //Step 3: Implement Print Menu Function - prints out each line of menu
   cout << playlistTitle << " PLAYLIST MENU" << endl;
   cout << "a - Add song" << endl;
   cout << "d - Remove song" << endl;
   cout << "c - Change position of song" << endl;
   cout << "s - Output songs by specific artist" << endl;
   cout << "t - Output total time of playlist (in seconds)" << endl;
   cout << "o - Output full playlist" << endl;
   cout << "q - Quit" << endl;
   
}

PlaylistNode* ExecuteMenu(char option, string playlistTitle, PlaylistNode* headNode) {
   
   if(option == 'o'){
      cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
      
      PlaylistNode* currNode = headNode->GetNext();

      if(headNode->GetNext() == NULL){
         cout << "Playlist is empty" << endl;
      }else{    
         int iteration = 1;
         cout << iteration << "." << endl;
         currNode->PrintPlaylistNode();
         
         
         while(currNode->GetNext() != NULL){
            currNode = currNode->GetNext();
            iteration++;
            cout << iteration << "." << endl;
            currNode->PrintPlaylistNode();  
         }
         
      }
   } else if(option == 'a'){
      cout << endl << "ADD SONG" << endl;
      PlaylistNode* currNode = headNode;
      PlaylistNode* lastNode = NULL;   
      string songName;
      string artistName;
      int songLength;
      string ID;

      //Prompting User and Getting Inputs
      cout << "Enter song's unique ID:" << endl;
      cin >> ID;
      
      cin.ignore();
      
      cout << "Enter song's name:" << endl;
      getline(cin, songName);
      
      cout << "Enter artist's name:" << endl;
      getline(cin, artistName);
      
      cout << "Enter song's length (in seconds):" << endl << endl;
      cin >> songLength;

      // Creates new node with inputs
      PlaylistNode* newNode = new PlaylistNode(ID, songName, artistName, songLength);
      

      //Finding last node in list
      while(currNode != nullptr){
         
         if(currNode != NULL){
            lastNode = currNode;
         } 
         currNode = currNode->GetNext();
      }
      lastNode->InsertAfter(newNode);
      
   } else if(option == 'd'){
         string IDLook = "";
         PlaylistNode* currNode = headNode;
         PlaylistNode* previous = headNode;
         
         cout << "REMOVE SONG" << endl;
         cout << "Enter song's unique ID:" << endl;

         cin >> IDLook;
         
         while(currNode->GetNext() != NULL){
            if(currNode->GetID() == IDLook){
               cout << "\"" << currNode->GetSongName() << "\"" << " removed." << endl << endl;
               previous->SetNext(currNode->GetNext());
               delete currNode;
               break;
            }
            previous =  currNode;
            currNode = currNode->GetNext();
      }
   } else if(option == 's'){
         PlaylistNode* currNode = headNode;
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
         
   } else if(option == 't'){
      PlaylistNode* currNode = headNode->GetNext();
      int totalTime = 0;
      cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
      
      totalTime = currNode->GetSongLength();

      while(currNode->GetNext() != NULL){
            currNode = currNode->GetNext();
            totalTime += currNode->GetSongLength();
            cout << currNode->GetSongLength() << endl;
            
         }
         
      cout << "Total time: " << totalTime << " seconds" << endl << endl;
         
   } else if(option == 'c'){
      int positionOriginal = 0;
      int positionTarget = 0;
      PlaylistNode* preActiveNode = headNode; // Node before one being moved
      PlaylistNode* activeNode = headNode; // Node being moved
      PlaylistNode* targetNode = headNode; // Node currently occupying new position
      PlaylistNode* previous = targetNode; // Node currently occupying new position
      
      cout << endl << "CHANGE POSITION OF SONG" << endl;
      
      cout << "Enter song's current position:" << endl;
      cin >> positionOriginal;
      
      cout << "Enter new position for song:" << endl;
      cin >> positionTarget;
      
      for(int j = 0; j < positionOriginal; j++){
         preActiveNode = activeNode;
         activeNode = activeNode->GetNext();
      }
      
      /*
      if(positionOriginal == 1){
         activeNode->SetNext(headNode->GetNext());
         headNode->SetNext(activeNode);
      }
      */
      
      preActiveNode->SetNext(activeNode->GetNext());
      
      for(int i = 0; i < positionTarget; i++){
            previous = targetNode;
            targetNode = targetNode->GetNext();  
      }
      
      
      activeNode->SetNext(targetNode);
      if(previous != nullptr){
         previous->SetNext(activeNode);
      }
      
      cout << "\"" << activeNode->GetSongName() << "\"" << " moved to position " << positionTarget << endl << endl;
      //cout << endl << endl;
      
      
   }
   return headNode;
}

int main() {
   char option;
   PlaylistNode* headNode = new PlaylistNode();
   string playlistTitle = "";
   
   //Step 2: Prompting user for title of playlist
   cout << "Enter playlist's title:" << endl << endl;
   getline(cin, playlistTitle);
   
   while(option != 'q'){
   //Step 5 call print menu
   PrintMenu(playlistTitle);
   
   //Prompt user for input
   cout << endl << "Choose an option:" << endl;
   
   cin >> option;

   ExecuteMenu(option, playlistTitle, headNode);
   }
   
   return 0;
}

