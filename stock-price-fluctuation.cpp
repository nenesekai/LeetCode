#include <iostream>
#include <list>

using namespace std;

class StockPrice
{

private:

    int latest_timestamp, latest_price;

    list<pair<int, int>> records; // sorted with price

public:

    StockPrice()
    {
        latest_timestamp = 0;
        latest_price = 0;
    }

    void update(int timestamp, int price)
    {
        auto iter = records.begin();

        for (;;)
        {
            if (iter == records.end()) break;

            if (iter->first == timestamp)
            {
                records.erase(iter);
                break;
            }
            
            iter++;
        }

        if (records.size() == 0) records.emplace_back(make_pair(timestamp, price));

        else if (price < records.front().second) 
        {
            records.emplace_front(make_pair(timestamp, price));
        }
        else if (price > records.back().second)
        {
            records.emplace_back(make_pair(timestamp, price));
        }
        else
        {
            auto iter1 = records.begin();
            iter1++;
            auto iter2 = records.begin();
            for (;;)
            {
                if (iter1 == records.end()) break;

                if (iter1->second > price && iter2->second < price)
                {
                    records.insert(iter1, make_pair(timestamp, price));
                    break;
                }
            }
        }

        if (timestamp >= latest_timestamp)
        {
            latest_timestamp = timestamp;
            latest_price = price;
        }
    }

    int current()
    {
        return latest_price;
    }

    int maximum()
    {
        return records.back().second;
    }

    int minimum()
    {
        return records.front().second;
    }

};

int main()
{
    StockPrice* obj = new StockPrice();

    obj->update(1, 10);
    obj->update(2, 5);

    cout << obj->current() << endl;
    cout << obj->maximum() << endl;

    obj->update(1, 3);

    cout << obj->maximum() << endl;

    obj->update(4, 2);

    cout << obj->minimum() << endl;

    return 0;
}