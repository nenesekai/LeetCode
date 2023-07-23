#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Worker
{
    int _index, _leftToRight, _pickOld, _rightToLeft, _putNew, _idleTime;
    Worker(int index, int leftToRight, int pickOld, int rightToLeft, int putNew)
        : _index(index), _leftToRight(leftToRight), _pickOld(pickOld), _rightToLeft(rightToLeft), _putNew(putNew), _idleTime(0)
    {}
    Worker(int index, vector<int> time)
        : _index(index), _leftToRight(time[0]), _pickOld(time[1]), _rightToLeft(time[2]), _putNew(time[3]), _idleTime(0)
    {}
};

struct Bridge
{
    constexpr static int UNOCCUPIED = 0;
    constexpr static int LEFT_TO_RIGHT = 1;
    constexpr static int RIGHT_TO_LEFT = 2;

    Worker *_occupier;
    int _direction;
    bool _occupied;

    Bridge() : _occupier(nullptr), _direction(UNOCCUPIED), _occupied(false) {}

    void startCrossing(Worker *worker, int direction)
    {
        _occupier = worker;
        _direction = direction;
        _occupied = true;
    }
    void finishCrossing()
    {
        _occupier = nullptr;
        _direction = UNOCCUPIED;
        _occupied = false;
    }
};

struct EfficiencyComparator
{
    bool operator()(Worker *lhs, Worker *rhs)
    {
        return !((lhs->_leftToRight + lhs->_rightToLeft > rhs->_leftToRight + rhs->_rightToLeft)
            || ((lhs->_leftToRight + lhs->_rightToLeft == rhs->_leftToRight + rhs->_rightToLeft) && lhs->_index > rhs->_index));
    }
};

struct IdleTimeComparator
{
    bool operator()(Worker *lhs, Worker *rhs)
    {
            return lhs->_idleTime > rhs->_idleTime;
    }
};

class Solution
{
public:
    int findCrossingTime(int cargosRemaining, int n, vector<vector<int>> &time)
    {
        priority_queue<Worker *, vector<Worker *>, EfficiencyComparator> leftIdle, rightIdle;
        priority_queue<Worker *, vector<Worker *>, IdleTimeComparator> leftBusy, rightBusy;

        // Create Workers
        cout << "Creating Workers" << endl;
        for (int i = 0; i < n; ++i)
        {
            leftIdle.push(new Worker(i, time[i]));
        }

        // Start Simulating
        int currentTime = -1, lastFinishedCrossing = 0;
        Bridge *bridge = new Bridge();
        while (cargosRemaining > 0 || bridge->_occupied || !leftBusy.empty() || !rightBusy.empty() || !rightIdle.empty())
        {
            if (!bridge->_occupied && leftBusy.empty() && rightBusy.empty())
            {
                ++currentTime;
            }
            else
            {
                currentTime = INT_MAX;
                if (bridge->_occupied) currentTime = min(currentTime, bridge->_occupier->_idleTime);
                if (!leftBusy.empty()) currentTime = min(currentTime, leftBusy.top()->_idleTime);
                if (!rightBusy.empty()) currentTime = min(currentTime, rightBusy.top()->_idleTime);
            }

            cout << "时间: " << currentTime << endl;
            // Check if busy workers finished tasks
            while (!leftBusy.empty() && leftBusy.top()->_idleTime <= currentTime)
            {
                cout << "Worker " << leftBusy.top()->_index << " finished putting new;" << endl;
                leftIdle.push(leftBusy.top());
                leftBusy.pop();
            }
            while (!rightBusy.empty() && rightBusy.top()->_idleTime <= currentTime)
            {
                cout << "Worker " << rightBusy.top()->_index << " finished picking old;" << endl;
                rightIdle.push(rightBusy.top());
                rightBusy.pop();
            }
            // Check if anyone has finished crossing bridge
            if (bridge->_occupied && bridge->_occupier->_idleTime <= currentTime)
            {
                if (bridge->_direction == Bridge::LEFT_TO_RIGHT)
                {
                    cout << "Worker " << bridge->_occupier->_index << " finished crossing bridge from left to right, start picking old;" << endl;
                    rightBusy.push(bridge->_occupier);
                    bridge->_occupier->_idleTime = currentTime + bridge->_occupier->_pickOld;
                    --cargosRemaining;
                    cout << cargosRemaining << " cargos left;" << endl;
                }
                else if (bridge->_direction == Bridge::RIGHT_TO_LEFT)
                {
                    cout << "Worker " << bridge->_occupier->_index << " finished crossing bridge from right to left, start putting new;" << endl;
                    leftBusy.push(bridge->_occupier);
                    bridge->_occupier->_idleTime = currentTime + bridge->_occupier->_putNew;
                }
                bridge->finishCrossing();
                lastFinishedCrossing = currentTime;
            }
            // Check if anyone can start crossing the bridge
            if (!bridge->_occupied)
            {
                if (!rightIdle.empty())
                {
                    cout << "Worker " << rightIdle.top()->_index << " start crossing the bridge from right to left;" << endl;
                    bridge->startCrossing(rightIdle.top(), Bridge::RIGHT_TO_LEFT);
                    bridge->_occupier->_idleTime = currentTime + bridge->_occupier->_rightToLeft;
                    rightIdle.pop();
                }
                else if (!leftIdle.empty() && cargosRemaining > 0)
                {
                    cout << "Worker " << leftIdle.top()->_index << " start crossing the bridge from left to right;" << endl;
                    bridge->startCrossing(leftIdle.top(), Bridge::LEFT_TO_RIGHT);
                    bridge->_occupier->_idleTime = currentTime + bridge->_occupier->_leftToRight;
                    leftIdle.pop();
                }
            }
        }
        // Free Allocated Memory
        while (!leftIdle.empty())
        {
            delete leftIdle.top();
            leftIdle.pop();
        }
        delete bridge;
        return lastFinishedCrossing;
    }
};

int main()
{
    int n = 1;
    int k = 3;
    vector<vector<int>> time = {{1,1,2,1},{1,1,3,1},{1,1,4,1}};
    Solution *obj = new Solution();
    cout << obj->findCrossingTime(n, k, time) << endl;
    delete obj;
    return 0;
}