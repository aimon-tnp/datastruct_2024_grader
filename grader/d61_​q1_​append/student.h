#include "stack.h"
#include "queue.h"

namespace CP {
    template<typename T>
    void stack<T>::appendStack(stack<T> s) {
        stack<T> temp;
        while(!this->empty()){
            temp.push(this->top());
            this->pop();
        }
        while(!s.empty()){
            temp.push(s.top());
            s.pop();
        }

        stack<T> temp2;
        while(!temp.empty()){
            temp2.push(temp.top());
            temp.pop();
        }
        *this = temp2;
    }

    template<typename T>
    void stack<T>::appendQueue(queue<T> q) {
        stack<T> temp;
        while(!this->empty()){
            temp.push(this->top());
            this->pop();
        }
        while(!q.empty()){
            temp.push(q.front());
            q.pop();
        }

        stack<T> temp2;
        while(!temp.empty()){
            temp2.push(temp.top());
            temp.pop();
        }
        *this = temp2;
    }

    template<typename T>
    void queue<T>::appendStack(stack<T> s) {
        while(!s.empty()){
            this->push(s.top());
            s.pop();
        }
    }

    template<typename T>
    void queue<T>::appendQueue(queue<T> q) {
        while(!q.empty()){
            this->push(q.front());
            q.pop();
        }
    }
}
