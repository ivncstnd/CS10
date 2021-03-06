#include <iostream>
#include <string>

using namespace std;

#ifndef __PLAYLIST_H__
#define __PLAYLIST_H__

// Data Type (Node)
class PlaylistNode {
    private:
        string uniqueID;
        string songName;
        string artistName;
        int songLength;
        PlaylistNode* nextNodePtr;
    public:
        PlaylistNode();
        PlaylistNode(string, string, string, int);
        void InsertAfter(PlaylistNode*);
        void SetNext(PlaylistNode*);
        string GetID() const;
        string GetSongName() const;
        string GetArtistName() const;
        int GetSongLength() const;
        PlaylistNode* GetNext() const;
        void PrintPlaylistNode() const;
};

// Data Structure (Singly Linked List)
class Playlist {
    private:
        PlaylistNode* head;
        PlaylistNode* tail;
    public:
        Playlist();
        void push_back(PlaylistNode*);
        void RemoveSong(string);
        void ChangePositon(int, int);
        void PrintPlaylist() const;
        void PrintSpecificArtist(string) const;
        void PrintTotalTime() const;
};

#endif