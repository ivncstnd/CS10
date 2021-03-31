#include <iostream>
#include <string>

using namespace std;

#ifndef __PLAYLIST_H__
#define __PLAYLIST_H__

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
        void PrintPlaylistNode();
};

class Playlist {
    private:
        PlaylistNode* head;
        PlaylistNode* tail;
    public:
        Playlist();
        void PrintPlaylist() const;
        void push_back(PlaylistNode*);
        void RemoveSong(string);
};

#endif