//救命谁懂 屎山代码
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
       std::stack<int> s;
    
    for (int ast : asteroids) {
        bool destroyed = false;
        while (!s.empty() && ast < 0 && s.top() > 0) {
            int top = s.top();
            s.pop();
            if (top + ast == 0) {
                destroyed = true;
                break;
            } else if (top + ast > 0) {
                s.push(top);
                destroyed = true;
                break;
            }
        }
        if (!destroyed) {
            s.push(ast);
        }
    }
    
    std::vector<int> result(s.size());
    for (int i = s.size() - 1; i >= 0; i--) {
        result[i] = s.top();
        s.pop();
    }
    
    return result;

    }
};