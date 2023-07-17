#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Worker
{
private:
    int _index;
    int _idleTime;
    int _leftToRight;
    int _rightToLeft;
    int _pickOld;
    int _putNew;

public:
    struct EfficiencyComparator
    {
        bool operator()(Worker *lhs, Worker *rhs)
        {
            return !(lhs->getLeftToRight() + lhs->getRightToLeft() > rhs->getLeftToRight() + rhs->getRightToLeft()) ||
                   ((lhs->getLeftToRight() + lhs->getRightToLeft() == rhs->getLeftToRight() + rhs->getRightToLeft()) && lhs->getIndex() > rhs->getIndex());
        }
    };

    struct IdleTimeComparator
    {
        bool operator()(Worker *lhs, Worker *rhs)
        {
            return lhs->getIdleTime() < rhs->getIdleTime();
        }
    };

    Worker(int index, vector<int> times)
        : _index(index),
          _idleTime(0),
          _leftToRight(times[0]),
          _pickOld(times[1]),
          _rightToLeft(times[2]),
          _putNew(times[3])
    {
    }

    int getIndex() const
    {
        return _index;
    }

    int getIdleTime() const
    {
        return _idleTime;
    }

    int getLeftToRight() const
    {
        return _leftToRight;
    }

    int getRightToLeft() const
    {
        return _rightToLeft;
    }

    int getPickOld() const
    {
        return _pickOld;
    }

    int getPutNew() const
    {
        return _putNew;
    }

    void updateIdleTime(int newIdleTime)
    {
        _idleTime = newIdleTime;
    }
};

class Solution
{
public:
    int findCrossingTime(int n, int k, vector<vector<int>> &time)
    {
        // Initialize Priority Queues
        cout << "正在初始化优先队列" << endl;
        priority_queue<Worker *, vector<Worker *>, Worker::EfficiencyComparator> leftIdle, rightIdle;
        priority_queue<Worker *, vector<Worker *>, Worker::IdleTimeComparator> leftBusy, rightBusy;

        // Create Instances of Workers and Push into leftIdle 
        cout << "正在实例化工人" << endl;
        for (int i = 0; i < k; ++i)
        {
            leftIdle.push(new Worker(i, time[i]));
        }

        // Start Simulation
        cout << "开始模拟" << endl;
        int currentTime = 0;
        int bridgeIdleTime = 0;

        while (n > 0 || currentTime < bridgeIdleTime || !leftBusy.empty() || !rightBusy.empty())
        {
            // Update Current Time
            currentTime = bridgeIdleTime;
            if (!leftBusy.empty()) currentTime = min(currentTime, leftBusy.top()->getIdleTime());
            if (!rightBusy.empty()) currentTime = min(currentTime, rightBusy.top()->getIdleTime());
            cout << "时间：" << currentTime << endl;

            // Check If Any Worker in Busy Queue had Finished Working
            while (!leftBusy.empty() && leftBusy.top()->getIdleTime() <= currentTime)
            {
                cout << "工人" << leftBusy.top()->getIndex() << "完成将箱子放入新仓库" << endl;
                leftIdle.push(leftBusy.top());
                leftBusy.pop();
            }
            while (!rightBusy.empty() && rightBusy.top()->getIdleTime() <= currentTime)
            {
                cout << "工人" << rightBusy.top()->getIndex() << "完成从旧仓库搬起一个箱子" << endl;
                rightIdle.push(rightBusy.top());
                rightBusy.pop();
            }

            // Check If Any Worker can Start Crossing Bridge
            if (bridgeIdleTime <= currentTime)
            {
                // Check If Right has Worker Waiting
                if (!rightIdle.empty())
                {
                    leftBusy.push(rightIdle.top());
                    bridgeIdleTime = currentTime + rightIdle.top()->getRightToLeft();
                    rightIdle.top()->updateIdleTime(currentTime + rightIdle.top()->getRightToLeft() + rightIdle.top()->getPutNew());
                    rightIdle.pop();
                }
                else if (!leftIdle.empty() && n > 0)
                {
                    rightBusy.push(leftIdle.top());
                    bridgeIdleTime = currentTime + leftIdle.top()->getLeftToRight();
                    leftIdle.top()->updateIdleTime(currentTime + leftIdle.top()->getLeftToRight() + leftIdle.top()->getPickOld());
                    --n;
                    leftIdle.pop();
                }
            }

            if (currentTime > 10) break;
        }

        return bridgeIdleTime;
    }
};

int main()
{
    int n = 1, k = 3;
    vector<vector<int>> time = {{1, 1, 2, 1}, {1, 1, 3, 1}, {1, 1, 4, 1}};
    Solution *obj = new Solution();
    cout << "Result: " << obj->findCrossingTime(n, k, time) << endl;
    delete obj;
    return 0;
}