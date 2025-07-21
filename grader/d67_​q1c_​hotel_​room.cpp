#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int main(){
    int floors, m, totalroom = 0;
    cin >> floors >> m;

    set<pair<int,int>> room; // {(rooms available, -floor)} ex. (10, -5) = fifth floor has 10 rooms.
    for (int i = 1; i <= floors; i++){
        int n_of_room;
        cin >> n_of_room;
        totalroom += n_of_room;
        room.insert({n_of_room, (-1)*i});
    }

    // print available room
    // cout << "\n";
    // for (auto &e : room)
    // {
    //     cout << "Room(s): " << e.first << " [Floor: " << (-1)*e.second << "]\n";
    // }

    queue<int> customer;
    for (int i = 0; i < m; i++){
        int wantedroom;
        cin >> wantedroom;
        customer.push(wantedroom);
    }

    // print customer order
    // cout << "Customers':\n";
    // while (!customer.empty()){
    //     cout << customer.front() << " \n";
    //     customer.pop();
    // }

    while(!customer.empty()){
        if (totalroom < customer.front()){ // not enough room
            cout << "-1\n";
            continue;
        }

        int remaining = customer.front();
        set<int, int> bookingdata;
        while (remaining > 0){
            auto it = room.lower_bound({remaining, (-1)*floors});
            if (it != room.end()){ // enough room in 1 floor

            } else { // need multiple floors to satisfied request

            }
        }
    }

    // not done, too lazy eiei

    return 0;
}