#include <iostream>
#include <string>
#include "Playlist.h"

using namespace std;

/* Constructors */
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

/* Mutators */
void PlaylistNode::InsertAfter(PlaylistNode* node) {
    node->SetNext(this->GetNext());
    this->SetNext(node);
}

void PlaylistNode::SetNext(PlaylistNode* node) {
    nextNodePtr = node;
}

/* Accessors */
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

void PlaylistNode::PrintPlaylistNode() const {
    cout << "Unique ID: " << uniqueID << endl
         << "Song Name: " << songName << endl
         << "Artist Name: " << artistName << endl
         << "Song Length (in seconds): " << songLength << endl;
}

/* Constructor */
Playlist::Playlist() : head(nullptr), tail(nullptr) 
{}

/* Mutators */
void Playlist::push_back(PlaylistNode* node) {
    if (!head) {
        head = tail = node;
    } else {
        tail->SetNext(node);
        tail = node;
    }
}

void Playlist::RemoveSong(string UID) {
    if (!head) {
        cout << "Playlist is empty" << endl << endl;
    } else {
        PlaylistNode* i = head;
        if (i->GetID() == UID) {
            head = i->GetNext();
            cout << "\"" << i->GetSongName() << "\" removed." << endl << endl;
            delete i;
        } else {
            PlaylistNode* j = nullptr;
            for (; i->GetNext(); i = i->GetNext()) {
                if( i->GetNext()->GetID() == UID) {
                    j = i->GetNext();
                    if (j == tail) {
                        tail = i;
                        i->SetNext(nullptr);
                    } else {
                        i->SetNext(j->GetNext());
                    }
                    cout << "\"" << j->GetSongName() << "\" removed." << endl << endl;
                    delete j;
                    return;
                }
            }
        }   
    }
}

void Playlist::ChangePositon(int origPos, int newPos) {
    PlaylistNode* prevOrig = nullptr;
    PlaylistNode* currOrig = head;
    int posIndex = 1;
    // find the node to be changed and its previous
    while (origPos > posIndex && currOrig) {
        prevOrig = currOrig;
        currOrig = currOrig->GetNext();
        posIndex++;
    }
    // readjust list accounting for ends
    if (prevOrig) {
        prevOrig->SetNext(currOrig->GetNext());
    } else {
        head = currOrig->GetNext();
    }

    if (currOrig == tail) {
        tail = prevOrig;
    }
    // insert into new positon and readjust list
    if (newPos <= 1) {
        currOrig->SetNext(head);
        head = currOrig;
        cout << "\"" << currOrig->GetSongName() << "\" moved to position 1" << endl << endl;
    } else {
        posIndex = 2;
        PlaylistNode* prevNew = head;
        PlaylistNode* currNew = head->GetNext();
        while (newPos > posIndex && currNew) {
            prevNew = currNew;
            currNew = currNew->GetNext();
            posIndex++;
        }
        prevNew->InsertAfter(currOrig);
        if (!currNew) {
            tail = currOrig;
            tail->SetNext(nullptr);
        }
        cout << "\"" << currOrig->GetSongName() << "\" moved to position " << posIndex << endl << endl;
    }
}

/* Accessors */
void Playlist::PrintPlaylist() const {
    if (!head) {
        cout << "Playlist is empty" << endl 
             << endl;
    } else {
        int pos = 1;
        for(PlaylistNode* i = head; i; i = i->GetNext()) {
            cout << pos << "." << endl;
            i->PrintPlaylistNode();
            cout << endl;
            ++pos;
        }
    }
}

void Playlist::PrintSpecificArtist(string AN) const {
    int pos = 1;
    for (PlaylistNode* i = head; i; i = i->GetNext()) {
        if (i->GetArtistName() == AN) {
            cout << pos << "." << endl;
            i->PrintPlaylistNode();
            cout << endl;
        }
         ++pos;
    }
}

void Playlist::PrintTotalTime() const {
    int totalTime = 0;
    for (PlaylistNode* i = head; i; i = i->GetNext()) {
        totalTime += i->GetSongLength();
    }
    cout << "Total time: " << totalTime << " seconds" << endl << endl;
}