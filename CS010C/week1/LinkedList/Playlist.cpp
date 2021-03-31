#include <iostream>
#include <string>
#include "Playlist.h"

using namespace std;

PlaylistNode::PlaylistNode() {
    this->uniqueID = "none";
    this->songName = "none";
    this->artistName = "none";
    this->songLength = 0;
    this->nextNodePtr = 0;
}

PlaylistNode::PlaylistNode(string uniqueID, string songName, string artistName, int songLength) {
    this->uniqueID = uniqueID;
    this->songName = songName;
    this->artistName = artistName;
    this->songLength = songLength;
    this->nextNodePtr = 0;
}

void PlaylistNode::InsertAfter(PlaylistNode* node) {
    this->SetNext(node->GetNext());
    node->SetNext(this);
}

void PlaylistNode::SetNext(PlaylistNode* node) {
    nextNodePtr = node;
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

void PlaylistNode::PrintPlaylistNode() {
    cout << "Unique ID: " << uniqueID << endl
         << "Song Name: " << songName << endl
         << "Artist Name: " << artistName << endl
         << "Song Length (in seconds): " << songLength << endl;
}

Playlist::Playlist() : head(nullptr), tail(nullptr) 
{}

void Playlist::PrintPlaylist() const {
    if(!head) {
        cout << "Playlist is empty" << endl 
             << endl;
    } else {
        int intIndex = 1;
        for(PlaylistNode* i = head; i; i = i->GetNext()) {
            cout << intIndex << "." << endl;
            i->PrintPlaylistNode();
            cout << endl;
            ++intIndex;
        }
    }
}

void Playlist::push_back(PlaylistNode* node) {
    if(!head) {
        head = tail = node;
    } else {
        tail->SetNext(node);
        tail = node;
    }
}