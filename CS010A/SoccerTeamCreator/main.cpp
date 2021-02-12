#include <iostream>
#include <vector>
using namespace std;

void OutputRoster(const vector<int> &playerNumber, const vector<int> &playerRating);
void AddPlayer(vector<int> &playerNumber, vector<int> &playerRating);
void RemovePlayer(vector<int> &playerNumber, vector<int> &playerRating);
void UpdatePlayerRating(const vector<int> &playerNumber, vector<int> &playerRating);
void OutputPlayersAboveRating(const vector<int> &playerNumber, const vector<int> &playerRating);

int main() {

    // Preliminary code specifying variables / empty vectors and populating them.
    char selector = ' ';
    vector<int> number;
    vector<int> rating;

    AddPlayer(number, rating);
    OutputRoster(number, rating);

    /* A menu that checks for different character options.
     * Each specified character option when inputted will call stated function.
     * Character 'q' will end the program.
     * All other non-specified characters will replay the menu until
     * a valid character is inputted.
     */

    while(selector != 'q') {
        cout << "MENU" << endl;
        cout << "a - Add player" << endl;
        cout << "d - Remove player" << endl;
        cout << "u - Update player rating" << endl;
        cout << "r - Output players above a rating" << endl;
        cout << "o - Output roster" << endl;
        cout << "q - Quit" << endl;

        cout << endl;
        cout<< "Choose an option: ";
        cin >> selector;
        cout << endl;

        if(selector == 'a') {
            AddPlayer(number, rating);
        }
        else if(selector == 'd') {
            RemovePlayer(number, rating);
        }
        else if(selector == 'u') {
            UpdatePlayerRating(number, rating);
        }
        else if(selector == 'r') {
            OutputPlayersAboveRating(number, rating);
        }
        else if(selector == 'o') {
            OutputRoster(number, rating);
        }
    }

    return 0;
}

void OutputRoster(const vector<int> &playerNumber, const vector<int> &playerRating) {

    /* OutputRoster takes the existing two vectors and outputs them,
     * denotating the jersey number and player rating at stored index.
     */

    unsigned int i = 0;

    cout << "ROSTER" << endl;

    // The function interates through the vector, pritning out the stored index one at a time.
    for(i = 0; i < playerNumber.size(); ++i) {
        cout << "Player " << i+1 << " -- Jersey number: " << playerNumber.at(i) << ", Rating: " << playerRating.at(i) << endl;
    }
    cout << endl;
}

void AddPlayer(vector<int> &playerNumber, vector<int> &playerRating) {

    /* AddPlayer begins if the vector is empty when called.
     * If the vector is empty, it will append the user's input to the function five times using 'push_back'.
     * If called again and not empty, it will append the user's input once.
     */

    unsigned int i = 0;
    unsigned int size = 5;

    // Checks for if the function is empty.
    // If true, append user's values five times.
    if(playerNumber.empty()) {
        for(i = 0; i < size; ++i) {

            unsigned int temp = 0;
            cout << "Enter player " << i + 1 << "'s jersey number: " << endl;
            cin >> temp;
            playerNumber.push_back(temp);

            cout << "Enter player " << i + 1 << "'s rating: " << endl;
            cin >> temp;
            playerRating.push_back(temp);
            cout << endl;

        }
    }

        // If false, append user's value once.
    else {

        unsigned int temp = 0;

        cout << "Enter another player's jersey number: " << endl;
        cin >> temp;
        playerNumber.push_back(temp);

        cout << "Enter another player's rating: " << endl;
        cin >> temp;
        playerRating.push_back(temp);
        cout << endl;

    }
}

void RemovePlayer(vector<int> &playerNumber, vector<int> &playerRating) {

    /* RemovePlayer begins by inputting the jersery number the user wishes to delete.
     * When found, the function will remove both the jersey number and rating, reevaluating
     * the vector's size. If not found, do nothing.
     */

    unsigned int i = 0;
    unsigned int deleteNumber = 0;

    cout << "Enter a jersey number: " << endl;
    cin >> deleteNumber;
    cout << endl;

    // Iterates entire vector for jersey number matching user input.
    for(i = 0; i < playerNumber.size(); ++i) {

        /* When found, the function '.erase' will find the position by
         * taking the current index and adding it with the index beginning.
         * '.erase' will automatically readjust all elements after the removed index forward
         * and revaluate the vector size based on how many elements were removed.
         */

        if(playerNumber.at(i) == deleteNumber) {
            playerNumber.erase(playerNumber.begin()+i);
            playerRating.erase(playerRating.begin()+i);
        }
    }
}

void UpdatePlayerRating(const vector<int> &playerNumber, vector<int> &playerRating) {

    /* UpdatePlayerRating begins by inputting a jersey number the user wishes to edit rating for.
     * The user also inputs the new rating for inputed jersey number.
     * When found the index of the jersey is passed to the rating vector and the new rating is overwritten
     * If not found, do nothing.
     */

    unsigned int i = 0;
    unsigned int valueIndex = 0;
    unsigned int updatedRating = 0;

    cout << "Enter a jersey number: ";
    cin >> valueIndex;
    cout << endl;

    cout << "Enter a new rating for player: " << endl;
    cin >> updatedRating;
    cout << endl;

    // Iterates through entire vector for matching jersey. When found, update current jersey ranking with user input.
    for(i = 0; i < playerNumber.size(); ++i) {
        if(playerNumber.at(i) == valueIndex) {
            playerRating.at(i) = updatedRating;
        }
    }
}

void OutputPlayersAboveRating(const vector<int> &playerNumber, const vector<int> &playerRating) {

    /* OutputPlayersAboveRating begins by inputting a specific rating to see players who exceed input rating.
     * When found, both the jersey number and rating will be outputted.
     * If not found, the vector will continue to iterate until size is reached.
     */

    unsigned int i = 0;
    unsigned int aboveRating = 0;

    cout << "Enter a rating: " << endl;
    cin >> aboveRating;
    cout << endl;

    cout << "ABOVE " << aboveRating << endl;

    // Iterates through entire vector for player rating greater than input rating. When found, output jersey and ranking.
    for(i = 0; i < playerNumber.size(); ++i) {
        if(playerRating.at(i) > aboveRating) {
            cout << "Player " << i+1 << " -- Jersey number: " << playerNumber.at(i) << ", Rating: " << playerRating.at(i) << endl;
        }
    }
    cout << endl;
}
