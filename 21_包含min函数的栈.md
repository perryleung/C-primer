### 问题21：定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））

课本思路：

第一反应是每次压入一个新元素进栈时将栈里的元素排序，让最小的元素放栈顶，但这样已经不是栈了；

要利用数据栈和辅助栈，辅助栈负责压入当前最小的值，当最小值被弹出后，接下来就是次小值

课本代码：
```c++

//=====数据栈：m_data 辅助栈：m_min
template<typename T>
void StackWithMin<T>::push(const T& value)
{
    m_data.push(value);
    if( m_min.size() == 0 || value < m_min.top() )
        m_min.push(value);
    else
        m_min.push(m_min.top());
}

template<typename T>
void StackWithMin<T>::pop()
{
    assert(m_data.size() > 0 && m_min.size() > 0)
    m_data.pop();
    m_min.pop();
}

template<typename T> 
const T& StackWithMin<T>::min() const
{
    assert(m_data.size() > 0 && m_min.size() > 0);
    return m_min.top();
}

//======提交，就是stack的成员函数，包好了min函数
class Solution {
public:
    stack<int> data, result;
    void push(int value) {
        data.push(value);
        if(result.empty() || result.top() >= value)
            result.push(value);
    }
    void pop() {
        if(data.top() == result.top()){
            data.pop();
            result.pop();
        }else
            data.pop();
    }
    int top() {
        return data.top();
    }
    int min() {
        return result.top();
    }
};
```