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
      PlaylistNode* currNode = headNode->GetNext();;
      PlaylistNode* lastNode = currNode;   

      //Finding last node in list
      while(currNode->GetNext != NULL){
         currNode = currNode->GetNext();
         if(currNode != NULL){
            lastNode = currNode;
         }
      }
      lastNode->InsertAfter(headNode); //Wrong need to get input from user, unsure
   }
   else if(option == 'b'){
      
   }
   
}

int main() {
   string playlistTitle = "";

   //Step 2: Prompting uesr for title of playlist
   cout << "Enter playlist's title: " << endl;
   cin >> playlistTitle;

   

   
   return 0;
}

