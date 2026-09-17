#include <iostream>
#include <memory>
#include <string>
using namespace std;

class AudioClip
{
private:
    string name;
    double duration;

public:
    AudioClip(string n, double d)
    {
        name = n;
        duration = d;
    }

    string getName()
    {
        return name;
    }
};

int main()
{
    // Create AudioClip using shared_ptr
    auto audio = make_shared<AudioClip>("explosion", 3.5);

    // Create weak_ptr observer
    weak_ptr<AudioClip> observer = audio;

    // Access the clip using lock()
    if (auto clip = observer.lock())
    {
        cout << "Clip alive: " << clip->getName() << endl;
    }

    // Release the shared_ptr
    audio.reset();

    // Check whether the object still exists
    if (observer.expired())
    {
        cout << "Clip already unloaded." << endl;
    }

    return 0;
}




