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
      int numIterations = 1;

      if(headNode->GetNext() == nullptr){
         cout << "Playlist is empty" << endl;
      }else{    
         cout << "1." << endl;
         currNode->PrintPlaylistNode();
         /*
         //Prints out each node's info
         while(currNode->GetNext() != NULL){
            cout << numIterations << "." << endl;
            currNode->PrintPlaylistNode();
            
   
            currNode = currNode->GetNext();
            numIterations++;    
         }   
         */
         
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
