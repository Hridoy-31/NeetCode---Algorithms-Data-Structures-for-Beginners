/*
Leetcode 682 : Baseball Game
*/


/*
Bruteforce approach: (Stack based)

Time complexity: O(n), where n is the number of elements in operations vector.
Space complexity: O(n), where n is the number of elements in operations vector.
*/


int calPoints(vector<string>& operations) {
    stack <int> record;
    for (int i=0; i<operations.size(); i++) {
        if (operations[i] == "C") {
            record.pop();
        }
        else if (operations[i] == "D") {
            record.push(record.top()*2);
        }
        else if (operations[i] == "+") {
            int first = record.top();
            record.pop();
            int second = record.top();
            record.push(first);
            record.push(first + second);
        }
        else {
            record.push(stoi(operations[i]));
        }
    }

    int sum = 0;

    while (!(record.empty())) {
        sum += record.top();
        record.pop();
    } 

    return sum;
}