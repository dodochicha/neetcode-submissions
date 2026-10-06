#include <stack>
#include <algorithm>

class MinStack {
private:
    std::stack<int> dataStack; // 存放實際數據
    std::stack<int> minStack;  // 存放當下的最小值

public:
    /** 初始化物件 */
    MinStack() {
        // 建構子保持空白即可，std::stack 會自行初始化
    }
    
    /** 將元素 val 推入棧 */
    void push(int val) {
        dataStack.push(val);
        
        // 如果最小棧為空，直接推入 val
        // 否則，推入 val 與目前最小值的較小者
        if (minStack.empty()) {
            minStack.push(val);
        } else {
            minStack.push(std::min(val, minStack.top()));
        }
    }
    
    /** 移除棧頂元素 */
    void pop() {
        // 兩個棧必須同步彈出，以維持狀態一致
        dataStack.pop();
        minStack.pop();
    }
    
    /** 獲取棧頂元素 */
    int top() {
        return dataStack.top();
    }
    
    /** 獲取棧中最小值 */
    int getMin() {
        return minStack.top();
    }
};