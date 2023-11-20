#include <GLFW/glfw3.h>
#include <map>
#include <vector>

class Input
{
public:
    Input(std::vector<int> keys);
    ~Input();

    bool keyDown(int key);

    
private:
    std::map<int, bool> m_keys;

};

