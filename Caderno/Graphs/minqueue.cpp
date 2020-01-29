struct MinQueue {
    deque<pair<int, int> > d;
    int ini, fim;

    MinQueue() { ini = 1; fim = 0; }

    void push(int v){
        while(!d.empty() && d.back().first >= v) d.pop_back();

        d.push_back(make_pair(v, ++fim));
    }

    void pop() {
    if(!d.empty() && d.front().second == ini++)
        d.pop_front();
    }

    int getMin() {
        return d.front().first;
    }
}