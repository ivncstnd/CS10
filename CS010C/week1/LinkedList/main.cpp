#include <iostream>
#include "Playlist.h"

using namespace std;

void PrintMenu(string, Playlist*);

int main() {
    string PlaylistTitle;
    Playlist* Playlist1 = new Playlist();
    cout << "Enter playlist's title:" << endl;
    getline(cin, PlaylistTitle);
    cout << endl;
    PrintMenu(PlaylistTitle, Playlist1);
    return 0;
}

void PrintMenu(string PlaylistTitle, Playlist* list) {
    char option = ' ';
    while (option != 'q') {
        cout << PlaylistTitle << " PLAYLIST MENU" << endl
        << "a - Add song" << endl
        << "d - Remove song" << endl
        << "c - Change position of song" << endl
        << "s - Output songs by specific artist" << endl
        << "t - Output total time of playlist (in seconds)" << endl
        << "o - Output full playlist" << endl
        << "q - Quit" << endl << endl
        << "Choose an option:" << endl;
        cin >> option;
        if (option == 'a') {
            string UID;
            string SN;
            string AN;
            int SL;
            cout << "ADD SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            cin.ignore();
            getline(cin, UID);
            cout << "Enter song's name:" << endl; 
            getline(cin, SN);
            cout << "Enter artist's name:" << endl;
            getline(cin, AN);
            cout << "Enter song's length (in seconds):" << endl;
            cin >> SL;
            PlaylistNode* node = new PlaylistNode(UID, SN, AN, SL);
            list->push_back(node);
            cout << endl;
            option = 'q';
            PrintMenu(PlaylistTitle, list);
        }
        if (option == 'd') {
            string UID;
            cout << "REMOVE SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            cin.ignore();
            getline(cin, UID);
            list->RemoveSong(UID);
            option = 'q';
            PrintMenu(PlaylistTitle, list);
        }
        if (option == 'c') {
            int origPos = 0;
            int newPos = 0;
            cout << "CHANGE POSITION OF SONG" << endl;
            cout << "Enter song's current position:" << endl;
            cin.ignore();
            cin >> origPos;
            cout << "Enter new position for song:" << endl;
            cin >> newPos;
            list->ChangePositon(origPos, newPos);
            option = 'q';
            PrintMenu(PlaylistTitle, list);
        }
        if (option == 's') {
            string AN;
            cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
            cout << "Enter artist's name:" << endl;
            cin.ignore();
            getline(cin, AN);
            cout << endl;
            list->PrintSpecificArtist(AN);
            option = 'q';
            PrintMenu(PlaylistTitle, list);
        }
        if (option == 't') {
            cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
            list->PrintTotalTime();
            option = 'q';
            PrintMenu(PlaylistTitle, list);
        }
        if (option == 'o') {
            cout << PlaylistTitle << " - OUTPUT FULL PLAYLIST" << endl;
            list->PrintPlaylist();
            option = 'q';
            PrintMenu(PlaylistTitle, list);
        }
    }
}