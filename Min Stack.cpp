class MinStack {
private:
    stack<int> arr, minValue;
public:
    void push(int x) {
        arr.push(x);
		if (minValue.empty() || x <= minValue.top())
			minValue.push(x);
    }

    void pop() {
        if (!arr.empty())
		{
			if (arr.top() == minValue.top())
				minValue.pop();
			arr.pop();
		}
    }

    int top() {
        return arr.top();
    }

    int getMin() {
        return minValue.top();
    }
};