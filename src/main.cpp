#include <iostream>
#include "TutorialConfig.h"
#include "Utility.h"
#include "stack.h"
#include <chrono>
#include <thread>

using namespace std;

int main () {

    using namespace std::this_thread;
    using namespace std::chrono;


    cout << "Hello world........................" << endl;
    if(user_says_yes()) {
        cout << "Hello user!" << endl;
    } else {
        cout << "sad face :(" << endl;
    }


    sleep_for(seconds(2));
}